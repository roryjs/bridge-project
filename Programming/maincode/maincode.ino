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
                /* code (function calls) in here */
                break;
            case B_2[0]:
                /* code */
                break;
            case B_3[0]:
                /* code */
                break;
            case B_4[0]:
                /* code */
                break;
            case B_5[0]:
                /* code */
                break;
            case B_6[0]:
                /* code */
                break;
            case B_7[0]:
                /* code */
                break;
            case B_8[0]:
                /* code */
                break;
            case B_9[0]:
                /* code */
                break;
            case B_0[0]:
                /* code */
                break;

            /* other keys */
            /* (more cases here) */
            
            default:
                /* code */              
                break;
        }
    }
}
