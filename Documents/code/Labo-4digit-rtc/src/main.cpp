/*
    Solution du laboratoire: Afficher l'heure sur 
     4-Digit, Terminal série et LCD en temps réel.

    Auteur: Alain Boudreault, aka VE2CUY 
    Date:   2025.02.26

    Description:  Afficher l'heure en temps réel en
                  utilisant le format HH:MM.SS

                  Le séparateur ':' clignote à la fréquence de 500 ms.

                  L'heure est affichée sur le moniteur série
                  et sur un écran LCD 16x2.

                  L'heure est aussi affichée sur un écran 4-Digit
                  en format 24 heures.

                  Les affichages ne doivent pas être bloquants.

                  Un bouton poussoir D3 est utilisée pour allumer une LED D2 en temps réel.  
                  Cette opération ne doit pas être bloquante ni bloquée par les affichages.
*/
#include "main.h"
//#define SET_TIME
DS1307    horloge; // Définir un objet de type DS1307
rgb_lcd   lcd;     // Définir un objet de type rgb_lcd
TM1637V2  affichage(CLK, DIO);

char tamponMoniteur[40];
char tamponLCD[50];
ANSI ansi(&Serial);
bool scroll = false;

// ======================== setup ========================
void setup()
{
  Serial.begin(VITESSE_MONITEUR);
  Serial << "Debut du programme ...\n";
  pinMode(LED, OUTPUT);
  pinMode(BP, INPUT);

  lcd.begin(16, 2); 
  horloge.begin();
  affichage.init();
  affichage.clearDisplay();
  affichage.set(ECRAN_FORT);
  ansi.clearScreen();
  Serial << CURSEUR_OFF << ANSI_BLANC;

  #ifdef SET_TIME
    horloge.fillByYMD(2025,2,27);
    horloge.fillByHMS(9,19,00);
    horloge.fillDayOfWeek(THU);
    horloge.setTime();
  #endif
} // setup

// ======================== loop ========================
void loop() {
  static bool firstTime = true;
  digitalWrite(LED, digitalRead(BP));
  // Gestion non bloquante de l'affichage de l'heure sur le 4-Digit
  static unsigned long previous4DigitMillis = 0;
    // Nous utilisons une variable ici pour ne pas appeler la fonction millis() plusieurs fois
  unsigned long current4DigitMillis = millis(); 
  if (current4DigitMillis - previous4DigitMillis >= SECONDE / 2) {
    previous4DigitMillis = current4DigitMillis;
    traiter4Digit();
  } // if

  // Gestion non bloquante de l'affichage de l'heure sur le moniteur
  static unsigned long previousMonitorMillis = 0;
  unsigned long currentMonitorMillis = millis();
  if (currentMonitorMillis - previousMonitorMillis >= SECONDE) {
    previousMonitorMillis = currentMonitorMillis;
    traiterMoniteur();
  } // if

  // Obtenir l'heure et l'afficher sur le LCD au 5 secondes
  bool readTime = (millis() / 1000) % 10 ? false : true;
  if (readTime || firstTime) {
    getPrintTimeLCD();
    firstTime = false;
    // Serial << millis() / 1000 % 5 << endl;
  } // if

  // Gestion non bloquante du scroll sur le LCD
  static unsigned long previousLCDMillis = 0;
  unsigned long currentLCDMillis = millis();
  if ( ((currentLCDMillis - previousLCDMillis) >= DELAI_SCROLL) ) {
    previousLCDMillis = currentLCDMillis;
    lcd.scrollDisplayLeft();
  } // if
} // loop

// ======================== traiterLCD ========================
void getPrintTimeLCD(){
  horloge.getTime();
  snprintf(tamponLCD, sizeof(tamponLCD), "Nous sommes le %d %s, %02d:%02d:%02d", horloge.dayOfMonth, mois[horloge.month], horloge.hour, horloge.minute, horloge.second);
  lcd.home();
  lcd.print(tamponLCD);
} // traiterLCD

// ======================== traiter4Digit ========================
void traiter4Digit() {
    static bool tick = false;
    horloge.getTime();
    float heureDecimale = horloge.hour + float(horloge.minute) / 100 ;  // Pour affichage avec ':'
    int   heureInt      = horloge.hour * 100 + horloge.minute;          // Pour affichage sans ':'
    // En fonction de la valeur de 'tick' afficher l'heure int ou float à 2 dec.
    affichage.displayNum(tick ? heureInt : heureDecimale, tick ? 0 : 2);
    tick ^= true;  // Inverser la valeur de la variable boolean
} // traiter4Digit


// ======================== traiterMoniteur ========================
void traiterMoniteur() {
  snprintf(tamponMoniteur, sizeof(tamponMoniteur), "%02d\033[31m:\033[0m%02d\033[31m:\033[0m%02d", horloge.hour, horloge.minute, horloge.second);
  // Afficher une trace de l'heure
  //ansi.color(GREEN).bgColor(BLACK);
  ansi.gotoXY(0, 0);
  Serial << "Nous sommes " 
  << ANSI_BLEU << jour[horloge.dayOfWeek] << ANSI_BLANC
  << ", le " << ANSI_BLEU << horloge.dayOfMonth << ANSI_BLANC
  << " " << mois[horloge.month] << ANSI_BLEU << " 20" <<  horloge.year << ANSI_BLANC
  << " et il est "
  << tamponMoniteur 
  << endl;
} // traiterMoniteur