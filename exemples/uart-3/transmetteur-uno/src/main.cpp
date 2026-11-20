/*
  Laboratoire 3: Réception/transmission d'une chaine de caractères
  Code du TRANSMETTEUR - sur le UNO
*/

#include <Arduino.h>
#include "rgb_lcd.h"
#include "Streaming.h"
#include <SoftwareSerial.h>

#define UART_RX             6
#define UART_TX             7

#define UART_VITESSE        9600
#define UNE_SECONDE         1000
#define LCD_DEUXIEME_LIGNE  1
#define LCD_NB_LIGNE        2
#define LCD_NB_COL          16

rgb_lcd lcd;
SoftwareSerial transmetteur(UART_RX, UART_TX); // RX, TX

const String messages[] = {
  "Haddock", 
  "Tournesol", 
  "Dupond et Dupont", 
  "Tintin",
  "Milou",
  "Bachi-bouzouk",
  "Boit-sans-soif",
  "Brontosaure",
  "Calembredaine",
  "Cataplasme",
  "Clysopompe",
  "Cornemuse",
  "Cornichon",
  "Cyclotron"
};

//--------------------------------------------------------
void setup() {
  Serial.begin(UART_VITESSE); // Disponible pour les traces dans cet exemple!
  Serial << "Démarrage du transmetteur..." << endl;
  Serial << "Il y a " << sizeof(messages) / sizeof(messages[0]) << " messages disponibles." << endl;  
  transmetteur.begin(UART_VITESSE); 
  lcd.begin(LCD_NB_COL,LCD_NB_LIGNE);
  lcd.print("Transmetteur");
} // setup()

//--------------------------------------------------------
void loop() {
   // Envoyer un message aléatoire à toutes les secondes:
   byte unCode = random(sizeof(messages) / sizeof(messages[0]));
   transmetteur.print(messages[unCode]);
   Serial << "Envoi du message suivant: " << messages[unCode] << endl;
   lcd.setCursor(0, LCD_DEUXIEME_LIGNE);
   lcd << "Envoi du msg: " << unCode << " ";
   delay(UNE_SECONDE * 2);
} // loop()
