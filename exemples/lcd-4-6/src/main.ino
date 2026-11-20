#include "Streaming.h"

#define CLIENT 1

#if (CLIENT == 2)
    const byte port_porte = 3;
#else
    const byte port_porte = 2;
#endif

void setup() {
  Serial.begin(9600);
  Serial << "port_porte = " << port_porte << endl;
}

void loop() {}
