#include <Arduino.h>
// Définition de l'énumération pour les types d'ennemis
enum TypeEnnemi {
    GOBELIN,   // Le type d'ennemi est un gobelin
    DRAGON,    // Le type d'ennemi est un dragon
    SORCIER,   // Le type d'ennemi est un sorcier
    TROLL      // Le type d'ennemi est un troll
};

// Définition de la struct Ennemi
struct Ennemi {
    TypeEnnemi type;  // Type de l'ennemi, représenté par une énumération
    int x, y;              // Position dans le jeu
    int pointsDeVie;       // Points de vie de l'ennemi
};

void setup() {
    // Initialisation du moniteur série
    Serial.begin(9600);

    // Création et initialisation d'un ennemi
    struct Ennemi e1;

    // Assignation de valeurs aux attributs
    e1.type = GOBELIN;    // Le type de l'ennemi est un Gobelin
    e1.x = 50;            // Position X de l'ennemi
    e1.y = 60;            // Position Y de l'ennemi
    e1.pointsDeVie = 30;  // Points de vie de l'ennemi

    // Affichage des informations de l'ennemi
    Serial.println("Informations de l'ennemi :");
    Serial.print("Type : ");
    
    // Affichage du type d'ennemi en fonction de la valeur de l'énumération
    switch (e1.type) {
        case GOBELIN:
            Serial.println("Gobelin");
            break;
        case DRAGON:
            Serial.println("Dragon");
            break;
        case SORCIER:
            Serial.println("Sorcier");
            break;
        case TROLL:
            Serial.println("Troll");
            break;
        default:
            Serial.println("Inconnu");
            break;
    }

    Serial.print("Position : (");
    Serial.print(e1.x);
    Serial.print(", ");
    Serial.print(e1.y);
    Serial.println(")");
    Serial.print("Points de vie : ");
    Serial.println(e1.pointsDeVie);
}

void loop() {
    // Pas de boucle continue nécessaire ici
}
