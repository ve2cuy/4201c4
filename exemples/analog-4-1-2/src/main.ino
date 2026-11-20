int ledPin        = 3;         // LED sur pin 3
int intensiteDEL  = 255;
int delai         = 20;

void setup() {
  pinMode(ledPin, OUTPUT);    // Broche de la DEL en mode OUTPUT
}

void loop() {
    analogWrite(ledPin, --intensiteDEL);
    if (!intensiteDEL) { 
      intensiteDEL = 255;
      delay(500); // Laisser la DEL éteinte pendant 1/2 sec.
    }
    delay(delai); // Ralentir un peu la variation d'intensité de la DEL.
}
