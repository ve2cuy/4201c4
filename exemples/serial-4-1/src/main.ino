/*
  Programme:  Exemple d'une lecture GPIO avec PullUP
  Auteur:     Alain Boudreault
  Date:       2021.09.13
  Cible:      420-1C4 - objets connectés
  ------------------------------------------------------------
  Note: Ne pas connecter le push button pour tester le projet.

        Il faut l'insérer seulement une fois que l'application roule.
*/


void setup() {
  // Configurer le port série
  Serial.begin(9600);
  Serial.println("Debut du programme\n=========================\n");
  // Configurer la pin BOUTON en entrée et activer la résistance interne de type pull-up.
  pinMode(2, INPUT_PULLUP);
  // Configurer la pin DEL en sortie
  pinMode(3, 1);
}

void loop() {
  // Lire la valeur de l'interrupteur de type poussoir 
  int sensorVal = digitalRead(2);
  // Afficher son état
  Serial.println(sensorVal);

  // Note: Les valeurs des états de l'interrupteur seront inversées.
  // HIGH si ouvert, et LOW lorsqu'appuyé. 
  if (sensorVal == 1) {
    digitalWrite(3, 0);
  } else {
    digitalWrite(3, 1);
  }
  delay(200);
}
