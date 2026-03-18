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

---

## Laboratoire - Real Time Clock – DS1307

### Labo 5.1 

```
/*
    Solution du laboratoire: Afficher l'heure sur 4-Digit 

    Auteur: Alain Boudreault, aka VE2CUY 
    Date:   2021.10.26

    Description:  Afficher l'heure en temps réel en
                  utilisant le format HH:MM.

                  Le séparateur ':' clignote à la fréquence de 500 ms.
*/

#include <Wire.h>
#include "DS1307.h"
#include "Streaming.h"
#include "TM1637V2.h"

DS1307 horloge; // Définir un objet de type DS1307

// #define SET_TIME

#define CLK 2  //GPIO pour la TM1637V2
#define DIO 3
#define DEMI_SECONDE 500
TM1637V2 affichage(CLK, DIO);
boolean tick = false;

void setup()
{
  Serial.begin(9600);
  Serial << "Debut du programme ...\n"; 
  horloge.begin();
  affichage.init();
  affichage.clearDisplay();
  affichage.set(ECRAN_FORT);

  #ifdef SET_TIME
    horloge.fillByYMD(2021,10,26);
    horloge.fillByHMS(13,54,00);
    horloge.fillDayOfWeek(TUE);
    horloge.setTime();
  #endif
} // setup

void loop() {
  horloge.getTime();
  float heureDecimale = horloge.hour + float(horloge.minute) / 100 ;  // Pour affichage avec ':'
  int   heureInt      = horloge.hour * 100 + horloge.minute;          // Pour affichage sans ':'

  // En fonction de la valeur de 'tick' afficher l'heure int ou float à 2 dec.
  affichage.displayNum(tick ? heureInt : heureDecimale, tick ? 0 : 2);
  tick ^= true;  // Inverser la valeur de la variable boolean

  // Afficher une trace de l'heure
  Serial << "Il est " << horloge.hour << ":" << horloge.minute << ":" << horloge.second << endl;
  delay(DEMI_SECONDE);

} // loop
```