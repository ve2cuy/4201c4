#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN           5  // GPIO de connexion de la barre de DEL
#define NUMPIXELS     10 // NB de DEL sur la barre
#define DELAYVAL      200 // Intervalle entre les DEL
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
} // setup

void loop() {
  pixels.clear(); // Effacer tous les DEL.
  pixels.show();   // Actualiser l'affichage 

  int r = random(256);  // un nombre entre 0 et 255 pour le rouge
  int g = random(256);  // un nombre entre 0 et 255 pour le vert
  int b = random(256);  // un nombre entre 0 et 255 pour le bleu

  for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();   // Actualiser l'affichage
    delay(DELAYVAL);
  } // for

} // loop
