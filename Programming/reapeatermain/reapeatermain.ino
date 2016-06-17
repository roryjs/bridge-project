#include <IRSendRev.h>
#include "data1363.cpp"

const int pinRecv = 2;

unsigned char dta[20];
unsigned char dtaSend[20] = {9, 178, 44, 12, 32, 4, 0, 255, 8, 247};

void setup() {
    Serial.begin(115200);
    IR.Init(pinRecv);

    pinMode(13, OUTPUT);
}

void loop() {
    if(IR.IsDta()) {
        digitalWrite(13, HIGH);
        delay(500);
        digitalWrite(13, LOW);
        IR.Recv(dta);               // receive data to dta

        unsigned char output[2] = {dta[8], dta[9]};

        switch(dta[8]) { //first byte of button data is unique for each button!
            case B_1[0]:
                dtaSend[8] = 0x8;
                IR.Send(dtaSend, 38);
                break;
            case B_2[0]:
                dtaSend[8] = 0x88;
                IR.Send(dtaSend, 38);
                break;
            case B_3[0]:
                dtaSend[8] = 0x48;
                IR.Send(dtaSend, 38);
                break;
            case B_4[0]:
                dtaSend[8] = 0x30;
                IR.Send(dtaSend, 38);
                break;
            case B_5[0]:
                dtaSend[8] = 0xB0;
                IR.Send(dtaSend, 38);
                break;
            case B_6[0]:
                dtaSend[8] = 0x70;
                IR.Send(dtaSend, 38);
                break;
            case B_7[0]:
                dtaSend[8] = 0x10;
                IR.Send(dtaSend, 38);
                break;
            case B_8[0]:
                dtaSend[8] = 0x90;
                IR.Send(dtaSend, 38);
                break;
            case B_9[0]:
                dtaSend[8] = 0x50;
                IR.Send(dtaSend, 38);
                break;
            case B_0[0]:
                dtaSend[8] = 0x60;
                IR.Send(dtaSend, 38);
                break;
            case B_AV[0]:
                dtaSend[8] = 0x18;
                IR.Send(dtaSend, 38);
                break;
            case B_VMINUS[0]:
                Serial.println("l");
                break;
            case B_VPLUS[0]:
                Serial.println("r");
                break;
            default:         
                break;
        }
    }


}
