#include "OTAManager.h"
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <Update.h>
#include <FS.h>
#include <LittleFS.h>

using namespace JRDev;

String OTAManager::currentVersion = "2.0.0";
unsigned long OTAManager::lastCheck = 0;

void OTAManager::setup(const String& version) {
  currentVersion = version;
}

bool OTAManager::checkForUpdate() {
  HTTPClient http;
  http.begin("https://example.com/firmware/version.json");
  int code = http.GET();
  if (code != 200) return false;

  DynamicJsonDocument doc(1024);
  deserializeJson(doc, http.getStream());

  String latest = doc["version"];
  String url = doc["url"];

  if (latest != currentVersion) {
    Serial.printf("[OTA] Update verfügbar: %s → %s\\n", currentVersion.c_str(), latest.c_str());
    HTTPClient dl;
    dl.begin(url);
    int size = dl.GET();
    if (size > 0) {
      WiFiClient* stream = dl.getStreamPtr();
      if (Update.begin(size)) {
        Update.writeStream(*stream);
        if (Update.end() && Update.isFinished()) {
          Serial.println("[OTA] Update abgeschlossen – Neustart.");
          ESP.restart();
        }
      }
    }
    dl.end();
    return true;
  }

  http.end();
  return false;
}

void OTAManager::handleAutoUpdate() {
  if ((millis() - lastCheck) < 3600000) return;
  lastCheck = millis();

  bool enabled = false;
  File cfg = LittleFS.open("/config.json", "r");
  if (cfg) {
    DynamicJsonDocument doc(512);
    deserializeJson(doc, cfg);
    enabled = doc["auto_update_check"] | false;
    cfg.close();
  }

  if (enabled) checkForUpdate();
}
