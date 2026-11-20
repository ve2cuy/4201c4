/*
    Cours:    Objets connectés
    Module:   L'instruction 'while( condition )'
    Auteur:   Alain Boudreault
    Date:     2022.09.12
    ------------------------------------------------------
    Description:  Présenter des exemples d'utilisation
                  de l'instruction while() du langage C

    Note:         Lorsqu'une condition est évaluée,
                  le langage C considère que vrai = 1 et
                                             faux = 0.

                  Donc, si nous écrivons if(1){}, le 'if'
                  sera toujours vrai.                                         
    ------------------------------------------------------
*/

void setup() {
  Serial.begin(9600);
  Serial.println("Démonstration de l'instruction while(condition)");

  // Exemple 01 - une boucle sans fin

  while ( 1 == 1 ) {
    Serial.println("Objet connecté");
    delay(250);
  } // while ( 1 == 1 )
  // Note:  1 == 1 sera toujours VRAI.  Vrai est égal à 1.
  // Il est alors possible d'écrire: while ( 1 ) et obtenir 
  // le même résultat.  Faire la modification et tester.
  // C propose aussi les mots clé 'true' pour 1 et 'false' pour zéro. 

  // Exemple 02 - une boucle tant que i < 5:
  int i = 0;
  while ( i < 5 ) {
    Serial.print(i);
    Serial.println(" est plus petit que 5");
    i++;
    delay(250);
  } // while ( 1 == 1 )
  // Note: Est-il possible de raccourcir le code précédent?

} //setup()

void loop() {
} // loop()
