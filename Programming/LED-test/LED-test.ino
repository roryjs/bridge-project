#include <IRSendRev.h>

const int pinRecv = 2;
char B_MUTE[2] = {0xE8, 0x17};
char POWER[2] = {0xF8, 0x7};

void setup() {
    Serial.begin(115200);
    IR.Init(pinRecv);

    pinMode(13, OUTPUT);
}

unsigned char dta[20];

void loop() {
    if(IR.IsDta()) {
        IR.Recv(dta);               // receive data to dta

        char output[2] = {dta[8], dta[9]};

        Serial.print(output[0], HEX);
        Serial.print(output[1], HEX);
        Serial.println();
        Serial.print(B_MUTE[0], HEX);
        Serial.print(B_MUTE[1], HEX);
        Serial.println();
        
        if (output[0] == B_MUTE[0] && output[1] == B_MUTE[1]) {
          digitalWrite(13, HIGH);
        } else if (output[0] == POWER[0] && output[1] == POWER[1]) {
          digitalWrite(13, LOW);
        }
    }

}
