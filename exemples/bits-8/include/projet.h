#ifndef projet_h
#define projet_h

#include <arduino.h>
#define VITESSE_SERIAL  115200
#define SECONDE         1000
enum operateurBinaire {
    AND,    // &
    OR,     // |
    XOR,    // ^
    NOT,    // ~
    GAUCHE, // <<
    DROITE  // >>
};

// NOTE: Valeur par défaut seulement dans le prototype, pas dans l'implémentation
void shiftGauche(void);
void shiftDroite(void);
void exempleOp(operateurBinaire op);
void exempleNegatif();
void exempleCompterBinaire();
#endif
