# L'instruction 'enum' du langage 'C'

<p align="center">
    <img src="../images/number_enumeration_calculation_reckoning_digit_count_numeration-512.webp.crdownload" alt="" width="400" />
</p>

---

## 1.0 – L'instruction 'enum'

Énumération ou **enum** est un type de données défini par l'utilisateur en C.

Il est principalement utilisé pour attribuer des noms à des constantes entières (**int**).

Ces noms **facilitent** la lecture et la maintenance d'un programme.

Le mot-clé '**enum**' est utilisé pour déclarer de nouveaux types d'énumération en C et C++.

Voici des exemples d'utilisation de l'instruction '***enum***':

```c
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
```

**Note**: Si nous n'attribuons pas explicitement de valeurs aux membres du ***enum***, le compilateur affecte par défaut des valeurs à partir de 0. Par exemple, dans l'exemple 02 précédent, dimanche obtient la valeur 0, lundi vaut 1, etc.

---

## 1.1 – Exemple d'utilisation d'une variable de type *enum*

```c


enum Menu {
  option1,   // vaut 0
  option2,   // vaut 1
  option3    // vaut 2
};


void setup(){
  Serial.begin(9600);

  Menu unMenu = option2;

  switch (unMenu) {

    case option2: Serial << "Option 2\n"; break;

    default: Serial << "Choix invalide!\n";
  } // switch

} // setup()

void loop(){}
```

---

## 1.2 – Affecter une valeur aux membres d'un 'enum'.

```c
#include "Streaming.h"

enum Menu {
  option1 = 1, 
  option2 = 2, 
  option3 = 0 
};


void setup(){
  Serial.begin(9600);

  Menu unMenu = option3;

  switch (unMenu) {

    case option1: Serial << "Option 1\n"; break;
    case option2: Serial << "Option 2\n"; break;
    case option3: Serial << "Option 3\n"; break;

    default: Serial << "Choix invalide!\n";
  } // switch

} // setup()


void loop(){}
```

---

## 1.3 – Un autre exemple : une liste de fruits???

```c
// Exemple d'utilisation de l'instruction 'enum'
#include <Streaming.h>

enum desFruits {
  pomme,
  cerise,
  kiwi,
  banane,
  fraise = 99
};

void setup() {
  Serial.begin(115200);

  desFruits unFruit = kiwi;

  switch (unFruit) {

    case kiwi: Serial << "Je suis un kiwi ;-)"; break;

    default: Serial << "Je suis un fruit non traité";
  } // switch

  Serial << " et j'ai la valeur: " << unFruit << endl; 
} // setup()

void loop() {
  // put your main code here, to run repeatedly:

}
```

---

## 1.4 – Gestion d'un menu avec enum – sous Wokwi

<img src="../images/Capture-décran-2022-10-23-à-14.31.35.png" alt="" width="500" />

```c
/*
    Projet: Enum+Menu
    Auteur: Alain Boudreault
    Date:   2022.10.23
    ------------------------------------
    Description:  Exemple d'utilisation de l'instruction 'enum' pour la gestion
                  d'un menu affiché sur un LCD. 

*/

#define DEBUG
#define WOKWI
#include <Streaming.h>
#include "projet.h"       // Les 'define's du projet sont dans un fichier à part.

#ifdef WOKWI
#include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C ecranLCD(LCD_ADRESSE_I2C,LCD_NB_COLONNE,LCD_NB_LIGNE);   
#else
#include "rgb_lcd.h"  
  rgb_lcd ecranLCD;    
#endif


void setup() {
#ifdef DEBUG  
  Serial.begin(UART_VITESSE);
  Serial << "Début du projet enum+menu\n";
#endif
  pinMode(BOUTON, INPUT);
  ecranLCD.begin(LCD_NB_COLONNE, LCD_NB_LIGNE);
  ecranLCD.cursor_on();
  ecranLCD << "Ex d'un Menu";
  ecranLCD.setCursor(LCD_PREMIERE_COLONNE, LCD_LIGNE2);  
  ecranLCD << "Version 1.00";
  delay(DELAI_MSG_DEBUT);
  ecranLCD.clear();  // Effacer l'écran
  ecranLCD << "Menu1 Menu2 Menu3";
  ecranLCD.setCursor(LCD_PREMIERE_COLONNE, LCD_LIGNE1);
  ecranLCD.blink_on(); 
} // setup()

void loop() {
  static optionMenu choixMenu = menu1;
  static unsigned long compteurBouton = 0;
  
  int etatBouton = digitalRead(BOUTON);
  if ( etatBouton == HIGH) {
    delay(BOUTON_DELAI_REBOND);
    while (digitalRead(BOUTON)) ;
    delay(BOUTON_DELAI_REBOND);

    compteurBouton++;

    // Calculer le choix menu en fonction du reste d'une division par trois (3)
    // Note: Il y a trois options au Menu.
    choixMenu = compteurBouton % 3;

#ifdef DEBUG
    Serial << "\nChoix menu = " << choixMenu;
#endif
    // Afficher le choix courant sur le LCD
    ecranLCD.setCursor(LCD_PREMIERE_COLONNE, LCD_LIGNE3);                  
    ecranLCD << MSG_CHOIX_MENU_SELECTIONNE << choixMenu+1;


    // Déplacer le curseur du LCD en fonction de la sélection menu
    switch (choixMenu) {

      case menu1: ecranLCD.setCursor(MENU_POS_OPTION_1, LCD_POS_LIG_MENU);
                  break;
      case menu2: ecranLCD.setCursor(MENU_POS_OPTION_2, LCD_POS_LIG_MENU);
                  break;
      case menu3: ecranLCD.setCursor(MENU_POS_OPTION_3, LCD_POS_LIG_MENU);      
                  break;

      default: break;  // ERREUR!!!

    } // switch (choixMenu)
  } // if

} // loop()
```

Le fichier projet.h:

```c
/*****************************************/
#define   UART_VITESSE          115200
#define   BOUTON                2
#define   BOUTON_DELAI_REBOND   5
#define   DELAI_MSG_DEBUT       1000
#define   LCD_DELAI             50
#define   LCD_NB_LIGNE          2
#define   LCD_NB_COLONNE        16
#define   LCD_LIGNE1            0
#define   LCD_LIGNE2            1
#define   LCD_LIGNE3            2
#define   LCD_PREMIERE_COLONNE  0
#define   LCD_POSITION_COMPTEUR 10
#define   LCD_ADRESSE_I2C       0x27
#define   LCD_POS_COL_MENU      0
#define   LCD_POS_LIG_MENU      0

#define   MENU_POS_OPTION_1     LCD_POS_COL_MENU + 0
#define   MENU_POS_OPTION_2     LCD_POS_COL_MENU + 6
#define   MENU_POS_OPTION_3     LCD_POS_COL_MENU + 12

#define   MSG_CHOIX_MENU_SELECTIONNE "Choix --> Menu"

/*****************************************/

enum  optionMenu {
  menu1,
  menu2,
  menu3
};
```

Le projet Wokwi est disponible [ici](https://wokwi.com/projects/346330484426408531)