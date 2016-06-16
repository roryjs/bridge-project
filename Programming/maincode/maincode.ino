#include <IRSendRev.h>
#include "data1363.cpp"

const int pinRecv = 8;
bool waiting_for_numeric = false;
int numeric_order = 0;
int numeric_value = 0;
int current_angle = 0;

void setup() {
    IR.Init(pinRecv);

    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(13, OUTPUT);

    PORTD = B11111110;
}

unsigned char dta[20];

void loop() {  
    if(IR.IsDta()) {
        digitalWrite(13, HIGH);
        delay(100);
        digitalWrite(13, LOW);

        IR.Recv(dta);               // receive data to dta
  
        switch(dta[8]) {
            case B_AV[0]:
                waiting_for_numeric = true;
                numeric_order = 0;
                numeric_value = 0;
                break;
            case B_LEFT[0]:
                for (int i = 0; i < 200; i++) {
                  digitalWrite(9, HIGH);
                  delay(1);
                  digitalWrite(9, LOW);
                }
                break;
            default:
                if (waiting_for_numeric && button_numeric(dta[8]) >= 0) {
                  int value = button_numeric(dta[8]);
                  Serial.println(value);
                  switch (numeric_order) {
                    case 0:
                      sevsegset(value);
                      numeric_value += value * 100;
                      break;
                    case 1:
                      sevsegset(value);
                      numeric_value += value * 10;
                      break;
                    case 2: {
                      sevsegset(value);
                      numeric_value += value;
                      int initial_angle = current_angle;
                      int final_angle = boundary(numeric_value);
                      if (initial_angle == final_angle)
                        break;
                      
                      int rotation_angle; //the amount the motor will spin in the counter-clockwise direction                      
                      
                      if(final_angle - initial_angle <= 0){
                          rotation_angle = abs(initial_angle - final_angle);
                      }
                      else if(final_angle - initial_angle > 0){
                          rotation_angle = 360 - abs((initial_angle - final_angle));
                      }

                      current_angle = final_angle;
 
                      goto_angle(rotation_angle);
                    } break; 
                    default:
                      break;
                  }

                  numeric_order++;
                }
                break;
        }
    }
  
}

void goto_angle(int angle) {
    if (angle == 360)
      angle = 0;
    int step_no = (360 - angle) / 360.0 * 3250;
    for (int i = 0; i < step_no; i++) {
        digitalWrite(9, HIGH);
        delay(1);
        digitalWrite(9, LOW);
    }

    numeric_order = 0;
    waiting_for_numeric = false;
    PORTD = B11111110;
}

int boundary(int angle){
    //this simplifies the inputted angle, and puts it withing the range of 0 and 359
    
    bool limit = true;
    while(limit){
        if(angle >=0 and angle <= 359){
            limit = false;
        }
        else if(angle < 0){
            angle = angle + 360;
        }
        else if(angle > 0){
            angle = angle - 360;
        }
    }
    return angle;
}

int button_numeric(char button_hex) {
        switch(dta[8]) //first byte of button data is unique for each button!
        {
            case B_1[0]:
                return 1;
                break;
            case B_2[0]:
                return 2;
                break;
            case B_3[0]:
                return 3;
                break;
            case B_4[0]:
                return 4;
                break;
            case B_5[0]:
                return 5;
                break;
            case B_6[0]:
                return 6;
                break;
            case B_7[0]:
                return 7;
                break;
            case B_8[0]:
                return 8;
                break;
            case B_9[0]:
                return 9;
                break;
            case B_0[0]:
                return 0;
                break;
            default:
                return -1;     
                break;
        }
}

byte digits[10] = {B10000000, \
                  B11110010, \
                  B01001000, \
                  B01100000, \
                  B00110010, \
                  B00100100, \
                  B00000100, \
                  B11110000, \
                  B00000000, \
                  B00100000};

void sevsegset(int num)
{
        PORTD = digits[num];
}
