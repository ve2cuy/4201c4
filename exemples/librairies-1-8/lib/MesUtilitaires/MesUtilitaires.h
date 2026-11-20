#ifndef MES_UTILITAIRES_H
#define MES_UTILITAIRES_H

#include <Arduino.h>

class MesUtilitaires {
  public:
    static void clignoterLED(int pin, int fois);
    static float convertirCelsiusVersF(float celsius);
};

#endif
