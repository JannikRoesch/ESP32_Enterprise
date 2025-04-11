#include <Arduino.h>
#include "Core/ChipInfo.h"
#include "System/SleepManager.h"
#include "Network/WiFiManager.h"
#include "Network/OTAManager.h"
#include "Web/WebDashboard.h"
#include "Utilities/Logger.h"
#include "Automation/AutomationManager.h"

void setup() {
  Serial.begin(115200);
  delay(1000);

  JRDev::Logger::info("ESP32 Enterprise Demo v2.0.0 startet...");
  JRDev::ChipInfo::printChipInfo();

  JRDev::WiFiManager::connect("MyWiFi", "password123");

  JRDev::AutomationManager::load();
  JRDev::WebDashboard::begin();
  JRDev::OTAManager::setup("2.0.0");

  JRDev::Logger::info("System vollständig gestartet.");
}

void loop() {
  JRDev::WebDashboard::handle();
  JRDev::AutomationManager::loop();
  JRDev::OTAManager::handleAutoUpdate();
  delay(50);
}
