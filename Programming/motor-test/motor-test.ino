#include <IRSendRev.h>
#include "1363.cpp"

const int pinRecv = 0;
bool waiting_for_numeric = false;
int numeric_order = 0;
int numeric_value = 0;

void setup() {
    Serial.begin(115200);
    IR.Init(pinRecv);

    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(13, OUTPUT);
    digitalWrite(10, LOW);
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
            default:
                if (waiting_for_numeric && button_numeric(dta[8]) >= 0) {
                  int value = button_numeric(dta[8]);
                  Serial.println(value);
                  switch (numeric_order) {
                    case 0:
                      numeric_value += value * 100;
                      break;
                    case 1:
                      numeric_value += value * 10;
                      break;
                    case 2:
                      numeric_value += value;
                      goto_angle(numeric_value);
                      break;
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
    Serial.println(angle);
    int step_no = angle / 360.0 * 3200;
    for (int i = 0; i < step_no; i++) {
        digitalWrite(9, HIGH);
        delay(1);
        digitalWrite(9, LOW);
    }

    numeric_order = 0;
    numeric_value = 0;
    waiting_for_numeric = false;
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

