#include <IRSendRev.h>
#include "1363.cpp"

const int pinRecv = 2;

void setup() {
    Serial.begin(115200);
    IR.Init(pinRecv);

    pinMode(13, OUTPUT);
}

unsigned char dta[20];

void loop() {
    if(IR.IsDta()) {
        IR.Recv(dta);               // receive data to dta

        unsigned char output[2] = {dta[8], dta[9]};

        Serial.print(output[0], HEX);
        Serial.print(output[1], HEX);
        Serial.println();
        Serial.print(B_MUTE[0], HEX);
        Serial.print(B_MUTE[1], HEX);
        Serial.println();

        switch(dta[8]) //first byte of button data is unique for each button!
        {
            case B_1[0]:
                digitalWrite(13, HIGH); //flash once
                delay(500);
                digitalWrite(13, LOW);
                break;
            case B_2[0]:
                digitalWrite(13, HIGH); // 1
                delay(500);
                digitalWrite(13, LOW);
                delay(500);
                digitalWrite(13, HIGH); // 2
                delay(500);
                digitalWrite(13, LOW);
                break;
            default:
                digitalWrite(13, HIGH); // 1
                delay(500);
                digitalWrite(13, LOW);
                delay(500);
                digitalWrite(13, HIGH); // 2
                delay(500);
                digitalWrite(13, LOW);
                delay(500);
                digitalWrite(13, HIGH); // 3
                delay(500);
                digitalWrite(13, LOW);                
                break;
        }
    }
    


}
