/*
URLEncode: https://github.com/plageoj/urlencode
WiFiEsp by bportaluri
lib_deps = 
	bportaluri/WiFiEsp@^2.2.2
	plageoj/UrlEncode@^1.0.1
*/

#include "main.h"

char ssid[] = SID;      
char pass[] = PWS;     
int status = WL_IDLE_STATUS;     // the Wifi radio's status
char buffer[200];
char server[] = "esh25.ve2cuy.com";

const char* messages[] = {  "Je suis celui qui est...", // 0
                            "Rien à ajouter"        // 1
                      };          

// Initialize the Ethernet client object
WiFiEspClient client;

void setup()
{
 
  Serial.begin(SERIAL_BAUD_RATE);        // initialize serial for debugging
  Serial1.begin(WIFI_BAUD_RATE);         // initialize serial for ESP module
  WiFi.init(&Serial1);                   // initialize ESP module  // initialize ESP module

  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("Module WiFi non détecté!");
    // Ne pas continuer
    while (true);
  } 

  while ( status != WL_CONNECTED) {
    Serial.print("Tentative de connexion au WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  Serial.println("Système connecté au réseau!");
  printWifiStatus();
  Serial.println();
  Serial.println("Connexion au serveur...");
 
} // setup()

void loop()
{
  // ---------------------------------------------------
  // Au besoin, afficher la réponse à la requête GET:
  // Utile lors d'une transmission en boucle vers l'API
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  } // while
  // ---------------------------------------------------

  if (!client.connected()) {
    Serial.println();
    Serial.println("Déconnexion du serveur...");
    client.stop();

  }

  sendInfoTOWebAPI();
  delay(DELAI_ENTRE_REQUETES);

  while(true);  // Ne plus rien faire ...

} // loop()

void sendInfoTOWebAPI(){
  // Si la connexion au serveur est établie, envoyer la requête GET
  // avec les paramètres nomSys, ipAdr, note et statut
  // La requête GET doit avoir la forme suivante:
  // http://esh25.ve2cuy.com/apijesuis.php?jesuis=UN_TEXTE

  if (client.connect(server, 80)) { // Ouvrir un socket de connexion
    Serial.println("Connecté au serveur, envoi de la requête GET...");
  

    snprintf(buffer, sizeof(buffer), 
      "GET /apijesuis.php?jesuis=%s HTTP/1.1", 
      urlEncode(messages[0]).c_str());              // NOTE: urlEncode retourne une STRING, conversion avec c_str().

    Serial.println(buffer);                         // Afficher la requête sur le terminal
    client.println(buffer);                         // Transmettre la requête,
    client.println("Host: esh25.ve2cuy.com");       // vers le serveur web
    client.println();

    // Au besoin, afficher la réponse à la requête GET:
    //while (client.available()) {
    //  char c = client.read();
    //  Serial.write(c);
    //}        
  
    client.stop();                                 // IMPORTANT: Fermer le socket de connexion
  }

} // sendInfoTOWebAPI()

void printWifiStatus()
{
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("Adresse IP:");
  Serial.println(ip);

  long rssi = WiFi.RSSI();
  Serial.print("Force du signal Wifi (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
