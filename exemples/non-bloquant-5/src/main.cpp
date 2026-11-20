/*
    Timer1 est un timer 16 bits. Il est possible de déclencher une interruption 
    à chaque fois que le compteur atteint une valeur donnée.

    Pour ce faire, il faut:
    1. Renseigner le 'prescaler' du timer
    2. Renseigner la valeur de comparaison
    3. Activer l'interruption sur comparaison

   Le prescaler est une division de la fréquence d'horloge du microcontrôleur.
   Il se peut que le prescaler soit de 1, 8, 64, 256 ou 1024.

   Pour le timer1, les valeurs de bits possibles sont:
    - CS10: pas de prescaler
    - CS11: prescaler de 8
    - CS12: prescaler de 64
    - CS13: prescaler de 256
    - CS10 | CS12: prescaler de 1024  
   
   Ces bits sont à renseigner dans le registre TCCR1B.

   Par exemple, pour un prescaler de 1024, il faut renseigner les bits CS10 et CS11 avec l'instruction suivante:
    TCCR1B = bit(CS10) | bit(CS11);

    Pour une fréquence de 16 MHz, le calcul est le suivant:
    1 tick = 1/16 000 000 = 62.5 ns
    1 ms = 1/0.0625 = 16 000 ticks
    1 s = 16 000 * 1000 = 16 000 000 ticks
*/

// Calcule pour le timer1 avec une période de 2000ms
// 2000ms correspond à une fréquence CTC de 0.5 Hz
// Pour une valeur de prescaler de 1024, le registre de comparaison, 
// OCR1A = 16000000/(2*1024*0.5) - 1 = 15624

#include <Arduino.h>
#define DECLENCHEUR_TEMPS   15624 // Donne une période d'environ une seconde

bool led_state = false;
#define LED 4
void setup() {
  pinMode(LED, OUTPUT);  
  digitalWrite(LED, 1);


  // Désactiver les interruptions globales
  cli();

  TCCR1A = 0;                                 //
  TCCR1B = 0;                                 //
  TCCR1B = bit(CS10) | bit(CS12);             // Renseigne le 'prescaler' de timer1 à 1024  
  TIMSK1 = bit(OCIE1A);                       // Active le déclenchement sur comparaison A avec timer1
  OCR1A = DECLENCHEUR_TEMPS;                  // Renseigne la valeur de comparaison pour timer1
  sei();  // Activer les interruptions.
}

void loop() {
  // Rien à faire ici ...
}

// Avec les paramètres définis plus haut, ce vecteur d'interruption (ISR) sera déclenché, environ, à chaque 1000ms.
// ISR = Interrupt Service Routine
ISR(TIMER1_COMPA_vect) {
  TCNT1 = 0;  // Remettre le compteur à 0
  led_state = !led_state;
  digitalWrite(LED,led_state);                // Allumer ou éteindre la DEL
  // Version alternative
  // digitalWrite(LED,!digitalRead(LED));     // Allumer ou éteindre la DEL
}
