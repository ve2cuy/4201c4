#define BROCHE_DU_BUZZER 5
#define DELAI            1000
void setup()
{
  pinMode(BROCHE_DU_BUZZER, OUTPUT);
}
 
void loop()
{
  digitalWrite(BROCHE_DU_BUZZER, HIGH);
  delay(DELAI);
  digitalWrite(BROCHE_DU_BUZZER, LOW);
  delay(DELAI);
}
