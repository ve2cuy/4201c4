#include <Arduino.h>
// Définition de la struct Personnage
struct Personnage {
    char nom[50];     // nom du personnage, jusqu'à 49 caractères
    int x, y;         // position du personnage dans le jeu (coordonnées)
    int sante;        // santé du personnage
    char arme[30];    // nom de l'arme
};

void setup() {
    // Initialisation du moniteur série
    Serial.begin(9600);
    
    // Création et initialisation d'un personnage
    struct Personnage p1;

    // Assignation de valeurs aux attributs
    // Utilisation de méthodes simples pour la gestion de chaînes de caractères en Arduino
    strcpy(p1.nom, "Heros");  // Copie d'une chaîne dans le tableau 'nom'
    p1.x = 10;   // Position en X
    p1.y = 20;   // Position en Y
    p1.sante = 100;  // Santé maximale
    strcpy(p1.arme, "Epee");  // Nom de l'arme

    // Affichage des informations du personnage
    Serial.println("Informations du personnage :");
    Serial.print("Nom : ");
    Serial.println(p1.nom);
    Serial.print("Position : (");
    Serial.print(p1.x);
    Serial.print(", ");
    Serial.print(p1.y);
    Serial.println(")");
    Serial.print("Santé : ");
    Serial.println(p1.sante);
    Serial.print("Arme : ");
    Serial.println(p1.arme);
}

void loop() {
    // Pas de boucle continue nécessaire ici
}
