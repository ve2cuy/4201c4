#include <Arduino.h>

#define DECLENCHEUR_TEMPS   15624          // Donne une période d'environ une seconde
void setTimerINT();

volatile int etatD1 = LOW;
volatile int etatD2 = LOW;
volatile int etatD3 = LOW;
volatile int etatD4 = LOW;
volatile unsigned long tempsActuel = 0;
char message[] = "Hello World!";


void setup() {
  Serial.begin(9600);
  setTimerINT(); 
}

void loop() {
  tempsActuel++;
  delay(1000);
}

void setTimerINT(){
  TCCR1A = 0;                                 //
  TCCR1B = 0;                                 //
  TCCR1B = bit(CS12) | bit(CS10);             // Renseigne le 'prescaler' de timer1 à 1024  
  TIMSK1 = bit(OCIE1A);                       // Active le déclenchement sur comparaison A avec timer1
  OCR1A = DECLENCHEUR_TEMPS;                  //
  sei();  // Activer les interruptions.
}

// Avec les paramètres définis dans setTimerINT(), ce vecteur d'interruption (ISR)
// sera déclenché, environ, à chaque 1000ms.
// ISR = Interrupt Service Routine
ISR(TIMER1_COMPA_vect) {
  TCNT1 = 0;  // Remettre le compteur à 0
  if (tempsActuel % 5 == 0) { // afficher aux 5 secondes
    Serial.println(message);
    Serial.println(etatD1);
    Serial.println(etatD2);
    Serial.println(etatD3);
    Serial.println(tempsActuel);
  }
}
