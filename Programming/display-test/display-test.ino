#include <IRSendRev.h>
#include "data1363.cpp"

const int pinRecv = 0;

void setup() {
    //Serial.begin(115200);
    IR.Init(pinRecv);
    
    pinMode(0, INPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    //pinMode(8, OUTPUT);
    //pinMode(9, OUTPUT);
    pinMode(13, OUTPUT);

    digitalWrite(13, HIGH);
    PORTD = B00000000;
    delay(1000);
    PORTD = B11111110; //set pins 1 to 7 high, ie all segments OFF
}

unsigned char dta[20];
int sevsegset(int num); // function prototype
/* make an array of 8bit bytes
   the nth element of the array contains the bits to set the pins to display the numeral n */
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

void loop() {
  
    if(IR.IsDta()) {
        IR.Recv(dta);               // receive data to dta

        switch(dta[8]) //first byte of button data is unique for each button!
        {
            // number keys
            case B_1[0]:      // if the "1" key is pressed...
                sevsegset(1); // set 7 segment display to show a number 1
                break;
            case B_2[0]:
                sevsegset(2); // or a 2, in the case that the 2 key was pressed
                break;
            case B_3[0]:
                sevsegset(3); // etc etc...
                break;
            case B_4[0]:
                sevsegset(4);
                break;
            case B_5[0]:
                sevsegset(5);
                break;
            case B_6[0]:
                sevsegset(6);
                break;
            case B_7[0]:
                sevsegset(7);
                break;
            case B_8[0]:
                sevsegset(8);
                break;
            case B_9[0]:
                sevsegset(9);
                break;
            case B_0[0]:
                sevsegset(0);
                break;

            // other keys
            default:
                //cycle through all numbers for 1 sec
                for (int q = 0; q < 10; q++)
                {
                    PORTD = digits[q];
                    delay(100); 
                }
                PORTD = B11111110;
        }
    }
  

}

int sevsegset(int num)
{
    PORTD = digits[num];
}
