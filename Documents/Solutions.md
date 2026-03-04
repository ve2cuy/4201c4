## Laboratoires NeoPixel

### 2.3.3 – Laboratoire

```
#include <Adafruit_NeoPixel.h>

#define PIN           2 // GPIO de connexion de la barre de pixels
#define NUMPIXELS     10 // NB de pixels sur la barre
#define DELAYVAL      200 // Intervalle entre les pixels
#define COULEUR_DEL   50, 10, 20
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

void loop() {
  pixels.clear(); // Effacer tous les pixels.
 
  for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(COULEUR_DEL));
    pixels.show();   // Actualiser l'affichage
    delay(DELAYVAL);
  }

  for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();   // Actualiser l'affichage
    delay(DELAYVAL);
  }
}
```

---

### Laboratoire 2.4 

```
/*
    Solution du laboratoire 2.4
    Auteur:       Alain Boudreault
    Date:         2021.10.22
    Description:  Allumer une séquence de pixels rouge, vert, ...
*/

#include <Adafruit_NeoPixel.h>
#define PIN           2         // GPIO de connexion de la barre de pixels
#define NUMPIXELS     10        // NB de pixels sur la barre
#define DELAYVAL      250       // Intervalle entre les pixels
#define PIXEL_ROUGE   255,0,0   // r = 255, g = 0, b = 0
#define PIXEL_VERT    0,255,0   // r = 0, g = 255, b = 0
#define UNE_SECONDE   1000

// Création d'un objet de type Adafruit_NeoPixel pour le contrôle de la barre de pixels.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
} // setup

void loop() {
  pixels.clear(); // Effacer tous les pixels.
 
  for(int i=0; i<NUMPIXELS; i++) { 
    // Déterminer la couleur du pixel en fonction d'une division par 2.
    uint32_t couleur = (i % 2) ? pixels.Color(PIXEL_VERT):pixels.Color(PIXEL_ROUGE);
    pixels.setPixelColor(i, couleur);
    pixels.show();   // Actualiser l'affichage
    delay(DELAYVAL);
  } // for

  delay(UNE_SECONDE);

} // loop
```

---

### Laboratoire 2.5


```
/*
    Solution du laboratoire 2.5
    Auteur:       Alain Boudreault
    Date:         2021.10.22
    Description:  Varier la couleur des pixels en fonction de la température
*/
// Inclure la librairie pour I2C (le capteur SHT31 est de type I2C)
#include <Wire.h>
// Inclure la librairie pour le capteur de température et d'humidité SHT31
#include "SHT31.h"
// Inclure la librairie pour la barre de pixels
#include <Adafruit_NeoPixel.h>

#include "Streaming.h"

//#define DEBUG

#define PIN                   2           // GPIO de connexion de la barre de pixels
#define NUMPIXELS             10          // NB de pixels sur la barre
#define PIXEL_ROUGE           245,22,26   // r,g,b
#define PIXEL_BLEU            80,106,148  
#define TEMPERATURE_DE_BASE   24
#define TEMPERATURE_PALIER    0.75

// Création d'un objet SHT31 pour le contrôle du capteur de température/humidité
SHT31 capteurTemperature;  

// Création d'un objet de type Adafruit_NeoPixel pour le contrôle de la barre de pixels.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  capteurTemperature.begin();
  #ifdef DEBUG
  Serial << "Temperature de depart: " << capteurTemperature.getTemperature() << endl;
  #endif
  pixels.begin();
  pixels.clear(); // Effacer tous les DEL.
  pixels.setBrightness(50);
  for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(PIXEL_BLEU));
  } // for
  pixels.show();   // Actualiser l'affichage
} // setup

void loop() {
  uint32_t couleur;
  float temperature  = capteurTemperature.getTemperature();
  // Calculer le nombres de paliers de température supérieur à la température de base.
  int nbPixelsRouges = (temperature - TEMPERATURE_DE_BASE) / TEMPERATURE_PALIER;

  #ifdef DEBUG
  Serial << "Temp. = " << temperature << " ,NB pixels rouges = " << (nbPixelsRouges) << endl;
  delay(500);
  #endif

  // Renseigner la couleur des pixels en fonction des paliers de température
  for (int pixelCourant = NUMPIXELS; pixelCourant >= 0; pixelCourant--) {
    couleur = pixelCourant < (NUMPIXELS - nbPixelsRouges) ? pixels.Color(PIXEL_BLEU) : pixels.Color(PIXEL_ROUGE);
    pixels.setPixelColor(pixelCourant, couleur);
  } // for pixelCourant

  pixels.show();   // Actualiser l'affichage

 } // loop
```
