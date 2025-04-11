#include "WiFiManager.h"
#include <WiFi.h>

void JRDev::WiFiManager::connect(const char* ssid, const char* pass) {
  WiFi.begin(ssid, pass);
  int tries = 0;
  while (WiFi.status() != WL_CONNECTED && tries++ < 20) {
    delay(500);
  }
}
