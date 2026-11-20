#include <arduino.h>
#define VITESSE_SERIAL 9600
void setup() {
    Serial.begin(VITESSE_SERIAL);
    int a = 5;   // 0101 en binaire
    int left_shift = a << 1;  // Décalage à gauche : 1010 en binaire (10 en décimal)
    int right_shift = a >> 1; // Décalage à droite : 0010 en binaire (2 en décimal)

    Serial.print("Décalage à gauche : "); Serial.println(left_shift);  // Affiche 10
    Serial.print("Décalage à droite : "); Serial.println(right_shift); // Affiche 2
}
void loop(){}
