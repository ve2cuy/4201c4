#include <Arduino.h>
#include "TM1637V2.h"

const int CLK = 6, DIO = 7;

TM1637V2 tm1637(CLK, DIO);

void setup() {
    tm1637.init();
    tm1637.set(7);  // Intensité maximum
} // setup

void loop() {
    static int nombre = 2;
    tm1637.displayNum(nombre);
    nombre *= 2;
    if (nombre > 8192) {
        while(true);  // Boucle sans fin ...
    } // if
    delay(500);
} // loop
