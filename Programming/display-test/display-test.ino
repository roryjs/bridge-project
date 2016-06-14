#include <IRSendRev.h>
#include "1363.cpp"

const int pinRecv = 2;

void setup() {
    Serial.begin(115200);
    IR.Init(pinRecv);

    pinMode(13, OUTPUT);
}

unsigned char dta[20];
int 

void loop() {
    if(IR.IsDta()) {
        IR.Recv(dta);               // receive data to dta

        switch(dta[8]) //first byte of button data is unique for each button!
        {
            /* number keys */
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

            /* other keys */
            default:
                // flash LED once
                digitalWrite(13, HIGH);
                delay(500);
                digitalWrite(13, LOW);              
                break;
        }
    }
}
