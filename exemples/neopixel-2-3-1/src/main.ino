// Constructeur:
// Adafruit_NeoPixel (uint16_t n, int16_t pin=6, neoPixelType type=NEO_GRB+NEO_KHZ800)
#include <Adafruit_NeoPixel.h>
#define PIN        5 // GPIO de connexion du LED Strip
#define NUMPIXELS 10 // Nombre de pixels disponibles

// Définir un objet de type NeoPixel
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();                                   // Initialiser le module
  pixels.clear();                                   // Éteindre tous les pixels
  pixels.setBrightness(50);                         // 0..255
  pixels.setPixelColor(5, pixels.Color(200, 0, 0)); // Configurer le pixel no 5 en rouge 200/255
  pixels.show();                                    // Actualiser, sur le module, le pixel modifié.
}

void loop() {}
