#include <Arduino.h>
/*
  Projet: Opérations sur les bits
  Pour:   Le cours 420-1C4-JR: Objets connectés
  Auteur: Alain Boudreault (aka VE2CUY)
  Date:   2025.01.27
  --------------------------------------------------------------------
  Description:

    Expérimentation avec les opérateurs au niveau des bits; 
      & , | , ~ , ^ , << et >> .

  PlatformIO:

    Rappel: ctrl+alt+b = build
            ctrl+alt+u = upload
            ctrl+alt+s = serial terminal
  --------------------------------------------------------------------
  M-A-J:

  --------------------------------------------------------------------
  NOTE: Sous platformio, monitor_speed = 115200

*/

// Les déclarations
#include <projet.h>
void afficherBinaire(int nombre, byte nbBits = 8, bool ln = true);

// Début du programme
void setup() {
  Serial.begin(VITESSE_SERIAL);
    while (!Serial) {
    ; // Attendre que le port série soit connecté.
  }
  Serial.println(F("----> Début du programme\n"));
  
  // Exemple d'affichage en binaire
  exempleCompterBinaire();

  // Exemple de permutations de bits
  //shiftGauche();
  //shiftDroite();
  
  // Exemple d'opérations logiques sur les bits
  //exempleOp(AND);
  //exempleOp(OR);
  //exempleOp(XOR);
  //exempleOp(NOT); 

  // Afficher des nombres négatifs en binaire
  //exempleNegatif();

} // setup()

void loop() { // Rien à faire ici ...
}

// Implémentation des fonctions
//=================================================================
void shiftGauche(void) {
  byte nombre = 0b00000001;
  Serial.println(F("\n------------------------------------------------------------------")); 
  Serial.println(F("Démonstration d'une permutation vers la gauche avec l'opérateur << \n\n76543210\n--------"));
  afficherBinaire(nombre);
  for (int n = 1 ; n <= 7; n++) {
    afficherBinaire(nombre << n);
  }
} // shiftGauche()

//=================================================================
void shiftDroite(void) {
  Serial.println(F("\n------------------------------------------------------------------")); 
  Serial.println(F("Démonstration d'une permutation vers la droite avec l'opérateur >> \n\n76543210\n--------"));
  byte nombre = 0b10000000;
  afficherBinaire(nombre);
  for (int n = 1 ; n <= 7; n++) {
    afficherBinaire(nombre >> n);
  }
} // shiftDroite()

//=================================================================
void exempleOp(operateurBinaire op){
    
    int a         = 5;      // 0101 en binaire
    int b         = 3;      // 0011 en binaire
    int resultat  = 0;
    String strOp[]  = {"a & b", "a | b", "a ^ b ", "~a"};

    Serial.println(F("\n------------------------------------"));  
    Serial.print(F("Démonstration de "));
    Serial.print(strOp[op]);
    Serial.println(F("\n\n76543210\n--------"));  

    switch (op) {
    case AND:
      resultat  = a & b;  // // 0001 en binaire
      break;
    case OR:
      resultat  = a | b; 
      break;
    case XOR:
      resultat  = a ^ b; 
      break;
    case NOT:
      resultat  = ~a; 
      break;
    default:
      break;
    }

    afficherBinaire(a);
    if (op != NOT) afficherBinaire(b);
    afficherBinaire(resultat);  // Affiche 1
} // exempleOp()

//=================================================================
// Voici un exemple simplifié de exempleOp
void exempleAnd(void){
    Serial.println(F("\n------------------------------------"));  
    Serial.println(F("Démonstration de a & b\n\n76543210\n--------"));  
    int a         = 5;      // 0101 en binaire
    int b         = 3;      // 0011 en binaire
    int resultat  = a & b;  // 0001 en binaire
    afficherBinaire(a);
    afficherBinaire(b);
    afficherBinaire(resultat);  // Affiche 1
} //exempleAnd()

//=================================================================
void afficherBinaire(int nombre, byte nbBits, bool ln) {
  // NOTE: Utilisation des opérateurs sur les bits (>> et &)
  // pour afficher le nombre en format binaire.
  for (int i = nbBits - 1; i >= 0; i--) {
    Serial.print((nombre >> i) & 1); 
  }
  if (ln) Serial.println();
} // afficherBinaire

//=================================================================
void exempleNegatif(){
    // Afficher un nombre négatif en binaire:
    // Voir: https://fr.wikipedia.org/wiki/Compl%C3%A9ment_%C3%A0_deux
  Serial.println(F("\n------------------------------------"));  
  for (int i = -5; i < 1 ; i++) {  
  Serial.print(F("\nAffichage de : "));
    Serial.println(i);  
    afficherBinaire(i, 32);
  }
} // exempleNegatif()

//=================================================================
void exempleCompterBinaire() {
    // Compter en binaire (base 2)
    Serial.println("\n---------------------------------------"); 
    Serial.println("Démonstration d'un affichage en binaire\n\n8421\n3210\n----");
  for (int i=0; i<= 0b1111; i++) {
      afficherBinaire(i,4);
      delay(SECONDE/2);
  }
} //exempleCompterBinaire()

// FIN DU PROGRAMME
