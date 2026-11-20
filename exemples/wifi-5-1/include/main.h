#include <Arduino.h>
#include "WiFiEsp.h"
#include <UrlEncode.h>
#include "secrets.h"

#define SERIAL_BAUD_RATE        115200
#define WIFI_BAUD_RATE          115200
#define DELAI_ENTRE_REQUETES    5000

void sendInfoTOWebAPI();
void printWifiStatus();
