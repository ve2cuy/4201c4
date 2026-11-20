#include <arduino.h>
#define VITESSE_SERIAL 9600
#define BIT7 1 << 7 // Équivalent à #define BIT7 0b10000000
void setup() {
    Serial.begin(VITESSE_SERIAL);
    byte a = 0b10010011;   // 0101 en binaire
    // a <<= 1;  // Équivalent à a = a << 1;
    Serial.println(BIT7); 

    if (a & BIT7) {
      Serial.println("Le bit # 7 est à ON");
    } else
    {
      Serial.println("Le bit # 7 est à OFF");
    }

}
void loop(){}
