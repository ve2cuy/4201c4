/*
  Fichier:      afficher-entier.ino
  Auteur:       Alain Boudreault
  Date:         2021.09.07
  Description:  Afficher un entier en base 2, 8, 10 et 16.
  --------------------------------------------------------
  M-A-J:        A.B.2022.06.14 - Ajout de l'opérateur de résolution de portée ::
*/

// Définition des constantes
#define UN_ENTIER     0b01010101    // le nombre '85', représenté en format binaire.
#define UNE_SECONDE   1000          // 1000 milli-secondes = 1 seconde
#define VITESSE_UART  9600

// Définition des variables globales
int compteur = 1;                 // la variable compteur est définie de façon globale

// ------------------
void setup() {
  // 1 - Ouvrir le port série à 9600 bps:
  Serial.begin(VITESSE_UART);
  // 2 - Afficher un message dans la console de débogage
  Serial.print("La variable compteur vaut ");
  Serial.println(compteur);
  Serial.println("============================\n\n");
} // setup()

// ------------------
void loop() {
  // Définition d'une variable locale à la fonction loop()
  int compteur = ::compteur++;  // Initialisation de la variable locale 'compteur' 
                                // à partir de la valeur de la variable globale 'compteur'

  // Afficher un entier en utilisant tous les formats possibles:
  Serial.print(compteur);  
  Serial.print(" - UN_ENTIER = ");  
  Serial.print(UN_ENTIER);       // Afficher en notation décimale
  Serial.print(" , DEC: ");  
  Serial.print(UN_ENTIER, DEC);  // Afficher en notation décimale
  Serial.print(" , HEX: ");   
  Serial.print(UN_ENTIER, HEX);  // Afficher en notation hexadécimale
  Serial.print(" , OCT: "); 
  Serial.print(UN_ENTIER, OCT);  // Afficher en notation octale
  Serial.print(" , BIN: "); 
  Serial.println(UN_ENTIER, BIN);  // Afficher en notation binaire
  delay(UNE_SECONDE);

} // loop()

// FIN du fichier
