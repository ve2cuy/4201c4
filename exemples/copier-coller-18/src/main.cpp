#include <Arduino.h>
/*
 Code du transmetteur - sur le MEGA
 Note: Relier deux Arduino via le port D6
*/

#include <SoftwareSerial.h>
#include "rgb_lcd.h"
#include "Streaming.h"

#define UART_RX             6
#define UART_TX             7
#define UART_VITESSE        9600
#define MAX_NB_ALEATOIRE    99
#define UNE_SECONDE         1000
#define LCD_DEUXIEME_LIGNE  1
#define LCD_NB_LIGNE        2
#define LCD_NB_COL          16

#define UART_MEGA
#ifdef UART_MEGA
   #define portSerieTransmetteur Serial3
#else
  SoftwareSerial portSerieTransmetteur(UART_RX, UART_TX); // RX, TX
#endif

rgb_lcd lcd;  // Déclaration de l'objet de contrôle du LCD 

void setup() {
  Serial.begin(UART_VITESSE); // port natif utilisé pour le débogage
  Serial.println("Démarrage du transmetteur...");
  lcd.begin(LCD_NB_COL,LCD_NB_LIGNE);
  lcd.print("Transmetteur");
  // Initialiser le port serie 'SoftwareSerial'
  portSerieTransmetteur.begin(UART_VITESSE);
} // setup()

void loop() {
   // Transmettre un code à chaque seconde  
   // générer un nombre entre 0 et MAX_NB_ALEATOIRE - 1
   byte unCode = random(MAX_NB_ALEATOIRE); 
   portSerieTransmetteur.write(unCode);
   Serial << "Envoi du code suivant: " << unCode << endl;
   lcd.setCursor(0, LCD_DEUXIEME_LIGNE);
   lcd << "Envoi de: " << unCode;
   delay(UNE_SECONDE);
} // loop()
