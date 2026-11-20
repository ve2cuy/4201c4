/*
    Simulation d'un système d'alarme UNO, qui envoie des événements
    à une centrale de controle (MEGA) via le protocole UART.

    Le UNO est connecté par son port D8 au port UART2 du MEGA.

    Étant donné que le UNO n'a qu'un seul port UART et qu'il est utilisé
    pour déboger l'application, la librairie 'SoftwareSerial' est utilisée
    pour simuler un port UART à partir d'une GPIO.

*/

#include <SoftwareSerial.h>
#include "code.alarme.h"
#include "rgb_lcd.h"
#include "Streaming.h"


rgb_lcd lcd;

// Le RX du UNO doit être connecté au TX du MEGA et TX -> RX
// Il faut donc inverser les signaux:
SoftwareSerial mySerial(5, 4); // RX, TX

codesAlarme unCodeAlarme = evenement_systeme_enligne;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // S'assurer que le port serie est pret.  Ceci n'est pas requis pour un SoftwareSerial.
  }
  Serial.println("Demarrage du systeme d'alarme...");
  lcd.begin(16,2);
  lcd.print("Master");
  // Initialiser le port serie 'SoftwareSerial'
  mySerial.begin(9600);

  // Envoyer l'état du système d'alarme à la centrale (Mega)
  mySerial.write(unCodeAlarme); // Attention, pour envoyer un seul octet (Byte), il faut utiliser la méthode write et non pas print.
  delay(1000);
}

void loop() {  
  unCodeAlarme = evenement_dectection_mouvement;
  // Envoyer un code de détection du mouvement à toutes les secondes:
    byte i;
    i = random(evenement_nb_codes); 
   mySerial.write(i);
   Serial << "Envoi du code suivant: " << i << endl;
   delay(1000);

}
