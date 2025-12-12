# Opérations non bloquantes

19 février 2025

## 1 – Utilisation de la fonction millis() pour clignoter une DEL

```
#include <Arduino.h>

/*
  Blink sans delay()
  Auteur: Alain Boudreault
  Date:   2025.02.19
  Pour:   420-1C4, Objets connectés 
*/

const int ledPin    = 2;    // Broche de la DEL
const long interval = 500;  // Intervale de clignotement de la DEL (milliseconds)
int ledState        = LOW;  // État de départ de la DEL

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();

  // Exécution de code non bloquant pour le clignotement de la LED
  if (currentMillis - previousMillis >= interval) {
    // Enregistrer le temps du dernier clignotement 
    previousMillis = currentMillis;

    ledState = !ledState;             // Permuter l'état de la DEL
    digitalWrite(ledPin, ledState);   // Appliquer de changement
  }
} // loop()
```

L'avantage de cette approche est que le programme principal (loop()) n'est pas bloqué par le délai de contrôle ON/OFF de la DEL. Par contre, le test if() sera exécuté à chaque itération d'appel de la fonction loop().

Dans certain cas, il pourrait être plus avantageux d'utiliser une interruption matériel ou de compteur.

---

## 2 – **Interruption**s

Les interruptions permettent de traiter des événements asynchrones. Elles permettent de sortir temporairement du programme principale, pour y exécuter une fonction, puis y retourner.

Les interruptions sont utiles avec les processeurs et les microcontrôleurs car elles permettent de résoudre des problèmes de synchronisation. Une bonne application d'une interruption est la lecture d'un encodeur rotatif ou l'observation d'une entrée utilisateur, par exemple, utilisation d'un bouton poussoir. En général, une ISR (routine de service d'interruption) doit être aussi courte et rapide que possible. Si un programme utilise plusieurs ISRs, une seule peut être exécutée à la fois. Les autres interruptions seront exécutées après que la routine en cours soit terminée, dans un ordre déterminé par la priorité.

Typiquement, des variables globales sont utilisées pour transmettre des données entre une ISR et le programme principal. Pour s'assurer que les variables partagées entre une ISR et le programme principal sont mises à jour correctement, il est recommandé de les déclarer comme `volatile`.

### 2.1 – Quelques caractéristiques importantes des interruptions :

* Les interruptions peuvent provenir de diverses sources. Dans ce cas, il s'agit d'une interruption matérielle déclenchée par un changement d'état sur l'un des pins numériques.
* L'**Arduino UNO** possèdent deux interruptions matérielles (appelées « interrupt0 » et « interrupt1 ») câblées respectivement sur les pins numériques **2 et 3**.
* L'**Arduino Mega** dispose de six interruptions matérielles, y compris les interruptions supplémentaires (« interrupt2 » à « interrupt5 ») sur les pins **21, 20, 19 et 18**.
* Il est possible de définir une routine en utilisant une fonction spéciale appelée « Routine de Service d'Interruption » (généralement appelée ISR).
* Il est possible de définir la routine et spécifier les conditions sur le front montant, le front descendant ou les deux. Dans ces conditions spécifiques, l'interruption sera traitée.
* Il est possible d'exécuter cette fonction automatiquement chaque fois qu'un événement se produit sur une broche d'entrée.

---

## 3 – **Types d'interruptions**

Il existe deux types d'interruptions :

1. **Interruptions matérielles** – Elles se produisent en réponse à un événement externe, comme un changement de niveau (haut ou bas) sur une broche d'interruption externe.
2. **Interruptions logicielles** – Elles se produisent en réponse à une instruction envoyée par le logiciel.

---

## 4 – Exemple – Traitement d'une interruption matérielle.

```
#include <Arduino.h>

void blink();
const int pin = 2;              // définir la broche d'interruption à 2
const int ledPin = 4;           // définir la broche de la LED à 4

volatile int state = LOW;      // Pour garantir que les variables partagées entre une ISR et le programme principal 
                               // soient mises à jour correctement, il faut les déclarer comme volatile.

void setup() {
   pinMode(ledPin, OUTPUT); // définir la broche 13 comme sortie
   attachInterrupt(digitalPinToInterrupt(pin), blink, CHANGE);
   // interruption à la broche 2, exécute l'ISR blink lorsque la broche change de valeur
} 

void loop() { 
  // digitalWrite(ledPin, state); // la broche 13 prend la valeur de 'state'
} 

void blink() { 
  // fonction ISR
  state = !state; // inverser l'état lorsque l'interruption se produit
  digitalWrite(ledPin, state); // la broche 13 prend la valeur de 'state'
}
```

---

## 5 – Interruption 'Timer' pour clignoter une DEL

```
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
```

<img src="../images/timer0-1024x528.png" alt="" width="500" />

**NOTE**: ISR() est une syntaxe universelle AVR. Sous Arduino, il est possible d'utiliser la fonction d'abstraction, attachInterrupt() pour les interruptions matériels. Par exemple, lorsqu'un bouton poussoir est appuyé.

La programmation des 'timers' d'un microcontrôleurs pose un défi plus grand que le traitement d'une interruption matérielle. Une documentation technique (anglaise) est disponible sur le site de [MicroChip](https://ww1.microchip.com/downloads/en/Appnotes/Atmel-2505-Setup-and-Use-of-AVR-Timers_ApplicationNote_AVR130.pdf).

Arduino.cc propose aussi une [introduction aux 'Timers'](https://docs.arduino.cc/tutorials/generic/secrets-of-arduino-pwm/) pour la production de signaux de type PWM.

---

## Exemple de trace programme avec un Timer.

```
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
```

---

## Crédits

**Document rédigé par Alain Boudreault © 2021-2026**
**Version 2025.02.26.01 - Révision 2025.12.12.1**

*Contenu par [VE2CUY](http://ve2cuy.com/blog)*