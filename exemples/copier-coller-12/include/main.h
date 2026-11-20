// main.h
#ifndef main_h
    #define main_h
    #define DEBUG
    #include <Arduino.h>
    #define VITESSE_UART 9600
    #include "rgb_lcd.h"
    #define UN_COURT_MOMENT  100

    #ifdef DEBUG
        #define AFFICHER(...)  Serial.print(__VA_ARGS__)
    #else 
        #define AFFICHER
    #endif
#endif
