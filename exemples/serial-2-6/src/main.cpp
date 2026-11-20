#include <Arduino.h>
/* 
   -----------------------------------------------------------------------
   Projet:         Introduction à Arduino
   Nom du fichier: allumer LED avec bouton (momentary) V1.ino
   Auteur:         Alain Boudreault, Robert Turenne
   Date:           2021.08.13
   -----------------------------------------------------------------------
   Description:    Petit programme qui allume la DEL intégrée au
                   module Arduino Uno sur une broche (pin). Un bouton est placé 
                   sur une autre broche
   -----------------------------------------------------------------------
   M-A-J: 
   AB2021.07.26 - Modification du délai ON/OFF
   RT-21.8.13   - Version avec bouton
   -----------------------------------------------------------------------
*/


// Les MACROs sont définies au début du programme, avant toutes fonctions!
// La convention dicte de les nommer avec des caractères MAJUSCULES
#define DEL_ROUGE 3       // La broche de la DEL du projet
//#define BOUTON_PIN    2 // La broche pour le bouton (voir plus bas pour la mise en commentaire)
#define ALLUMER   1
#define ETEINDRE  0
#define DELAI    100     // Le délai de transition entre ON/OFF de la DEL

/*
  faire attention au branchement des pin 2 et 3. Les connecteurs D ont accès à 2 pins en général.
  Celle qui est à l'extérieure est souvent celle qui sera connectée dans notre montagne. Ainsi, 
  le connecteur D2 présente les pin 2 et 3, mais la pin 2 est à l'extérieur.
*/

// Les variables et dans certains cas, les constantes, sont définies au début du programme, 
// après les macros, avant toute fonction.
// La convention est de commencer en minuscules et mettre un majuscule au début de chaque nouveau mot
// Notez qu'on peut aussi utiliser des constantes, similaires au #define, par exemple:
const int boutonPin = 2;
// On pourrait être confus quant à l'utilisation de la mémoire, limitée dans le Arduino, entre #define et "const int".
// mais dans la plupart des cas, l'utilisation de la mémoire est identique. 
// voir https://forum.arduino.cc/t/the-difference-between-define-and-const/65169/16 à partir de l'intervention #18
// ou https://www.baldengineer.com/const-vs-define-when-do-you-them-and-why.html
// Mais on doit absolument utiliser la notation Arduino pour les variables, par exemple:
int boutonEnfonce = 0; //indicateur pour  le bouton. = 1 si enfoncé

// DÉBUT du code -->

// Cette fonction sera exécutée une seule fois, au démarrage du programme.
// Elle sert à renseigner, entre autre, la fonction des différentes
// broches du MCU.
void setup()
{
  // TOUJOURS initialiser TOUTES LES PINS UTILISÉES
  // Note:  Elles conserveront leur état durant toute la durée de l'application, 
  //        incluant dans les autres fonctions.
  pinMode(DEL_ROUGE, OUTPUT); // LED Externe
  pinMode(boutonPin, INPUT);  // bouton

// Initialiser (préparer) le port série (avec le USB) à une certaine vitesse
// L'instruction indiquera au compilateur d'intégrer le code nécessaire (invisible pour nous)
// La vitesse (ici 9600 bps - bits par secondes) doit être la même sur la console
  Serial.begin(9600);
  Serial.println("Clignoter led externe avec bouton et console V1"); // Imprimer sur la console
}

// Cette section est exécutée en boucle pour toujours
void loop()
{
  //lecture de la pin digitale: les valeurs peuvent seulement être 0 ou 1
  boutonEnfonce = digitalRead(boutonPin); 

  if (boutonEnfonce == 1) // Ne pas oublier le double ==
  // Il est aussi possible d'écrire: 
  //  if (boutonEnfonce == HIGH), if (boutonEnfonce == TRUE), if (boutonEnfonce)
  {
    Serial.println("Bouton Enfoncé : ON !");
    delay(100); //délais avant d'allumer la LED
    digitalWrite(DEL_ROUGE, HIGH); 
    delay(100);
    digitalWrite(DEL_ROUGE, LOW);
  } else 
  {
    //Serial.print(boutonPese);
    digitalWrite(DEL_ROUGE, LOW);
  }
}
