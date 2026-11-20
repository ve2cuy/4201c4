void setup() {
  Serial.begin(9600);
  Serial.println("Debut du programme\n");

  // Boucle 1
  Serial.println("BOUCLE DE 0 A 9");
  for (int i = 0; i < 10; i++) {
    Serial.print(i);
    Serial.println(" - Yo!");
  }

  // Boucle 2
  Serial.println("\n\nBOUCLE DE 10 A 1");
  for (int i = 10; i > 0; i--) {
    Serial.print(i);
    Serial.println(" - Yo!");
  }
}

void loop() {
}
