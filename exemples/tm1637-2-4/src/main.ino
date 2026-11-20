#include "TM1637V2.h"
#define DELAI_ENTRE_LES_EXEMPLES  2000
#define DELAI_FIN                 500

// Définition des broches pour la TM1637
const int CLK = 6, DIO = 7;
TM1637V2 tm1637(CLK, DIO);

void setup() {
    tm1637.init();
    tm1637.set(BRIGHT_TYPICAL);

    Serial.begin(9600);
    Serial.println(tm1637.info());
   
    tm1637.displayStr("toto");
    delay(DELAI_ENTRE_LES_EXEMPLES);

    // loop
    tm1637.displayStr("Bonjour 420-1C4", 300);  // 500 est la valeur par défaut
    delay(DELAI_ENTRE_LES_EXEMPLES);

    // ON
    tm1637.displayStr("0N");
    delay(DELAI_ENTRE_LES_EXEMPLES);

    // OFF
    tm1637.displayStr("0FF");
    delay(DELAI_ENTRE_LES_EXEMPLES);
}

void loop() {
    // Effacer l'affichage
    tm1637.clearDisplay();
    delay(DELAI_FIN);
    tm1637.displayStr("Fin");
    delay(DELAI_FIN);
}
