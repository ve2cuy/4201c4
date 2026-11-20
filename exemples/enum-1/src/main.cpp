// Exemple 01
#include <Arduino.h> 
#include <Streaming.h>
enum  Etat {VRAI = 1, FAUX = 0}; 
// Convention de noms: LeType, les membres (VRAI|FAUX ou vrai|faux)

// Exemple 02
enum JourDeLaSemaine { 
       dimanche,    // 0
       lundi,       // 1 ...
       mardi, 
       mercredi, 
       jeudi, 
       vendredi, 
       samedi
};


// Explication de la syntaxe en classe ...
char *jours[] = {"dimanche", "lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi"};  

void setup() {
    // Initialisation du moniteur série
    Serial.begin(9600);
    
    Serial << "État VRAI : " << VRAI << endl; // Affiche "État VRAI : 1"

    JourDeLaSemaine jour = lundi; // Exemple d'utilisation de l'énumération
    Serial << "Jour de la semaine : " << jours[jour] << endl; // Affiche "lundi"
}

void loop(){}
