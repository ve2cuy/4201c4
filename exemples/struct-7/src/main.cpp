#include <Arduino.h>

#define FRANCAIS  1
#define ANGLAIS   2
#define ESPAGNOL  3

#define LANGUE ESPAGNOL

#if (LANGUE == FRANCAIS)
#define TEXTE_EPEE          "Épée"           // Description pour EPEE
#define TEXTE_BATON_MAGIQUE "Bâton magique"  // Description pour BATON_MAGIQUE
#define TEXTE_ARC           "Arc"            // Description pour ARC
#define TEXTE_HACHE         "Hache"          // Description pour HACHE
#endif

#if (LANGUE == ANGLAIS)
#define TEXTE_EPEE          "Sword"          // Description pour EPEE
#define TEXTE_BATON_MAGIQUE "Magic staff"    // Description pour BATON_MAGIQUE
#define TEXTE_ARC           "Bow"            // Description pour ARC
#define TEXTE_HACHE         "Axe"            // Description pour HACHE
#endif

#if (LANGUE == ESPAGNOL)
#define TEXTE_EPEE          "Espada"          // Description pour EPEE
#define TEXTE_BATON_MAGIQUE "Bastón mágico"   // Description pour BATON_MAGIQUE
#define TEXTE_ARC           "Arco"            // Description pour ARC
#define TEXTE_HACHE         "Hacha"           // Description pour HACHE
#endif

// Définition de l'énumération pour les armes
enum Arme {
    EPEE,          // Épée
    BATON_MAGIQUE, // Bâton magique
    ARC,           // Arc
    HACHE          // Hache
};

// Définition de la struct Personnage
struct Personnage {
    char nom[50];     // Nom du personnage
    int x, y;         // Position dans le jeu
    int sante;        // Santé du personnage
    enum Arme arme;   // Arme du personnage (utilisation de l'énumération)
};

// Taille maximale du tableau de personnages
#define MAX_PERSONNAGES 10  

// Table de chaînes de caractères pour décrire les armes
const char* descriptionsArmes[] = {
    TEXTE_EPEE,
    TEXTE_BATON_MAGIQUE,
    TEXTE_ARC,
    TEXTE_HACHE
};

// Fonction pour ajouter un nouveau personnage
int ajouterPersonnage(Personnage personnages[], int nbPersonnages, const char* nom, int x, int y, int sante, enum Arme arme) {
    if (nbPersonnages < MAX_PERSONNAGES) {
        // Ajouter un nouveau personnage dans le tableau
        strcpy(personnages[nbPersonnages].nom, nom);
        personnages[nbPersonnages].x = x;
        personnages[nbPersonnages].y = y;
        personnages[nbPersonnages].sante = sante;
        personnages[nbPersonnages].arme = arme; // Assignation de l'arme
        nbPersonnages++;  // Incrémenter le nombre de personnages
    } else {
        Serial.println("Erreur : Tableau de personnages plein !");
    }

    return nbPersonnages; // Retourner le nouveau nombre de personnages
}

// Fonction pour afficher les informations des personnages
void afficherPersonnages(Personnage personnages[], int nbPersonnages) {
    for (int i = 0; i < nbPersonnages; i++) {
        Serial.print("Nom \t\t: ");
        Serial.println(personnages[i].nom);
        Serial.print("Position \t: (");
        Serial.print(personnages[i].x);
        Serial.print(", ");
        Serial.print(personnages[i].y);
        Serial.println(")");
        Serial.print("Santé \t\t: ");
        Serial.println(personnages[i].sante);
        
        // Utiliser la table de chaînes pour afficher la description de l'arme
        Serial.print("Arme \t\t: ");
        Serial.println(descriptionsArmes[personnages[i].arme]);

        Serial.println();
    }
}

void setup() {
    // Initialisation du moniteur série
    Serial.begin(9600);
    
    // Déclaration d'un tableau de personnages
    struct Personnage personnages[MAX_PERSONNAGES]; 
    int nbPersonnages = 0; // Initialisation du nombre de personnages

    // Ajouter quelques personnages
    nbPersonnages = ajouterPersonnage(personnages, nbPersonnages, "Héros", 10, 20, 100, EPEE);
    nbPersonnages = ajouterPersonnage(personnages, nbPersonnages, "Mage", 15, 25, 80, BATON_MAGIQUE);
    nbPersonnages = ajouterPersonnage(personnages, nbPersonnages, "Archer", 30, 40, 90, ARC);

    // Afficher les informations de tous les personnages
    afficherPersonnages(personnages, nbPersonnages);
}

void loop() {
    // Pas de boucle continue nécessaire ici
}
