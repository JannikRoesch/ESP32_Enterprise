#include <Arduino.h>
#include "Core/ChipInfo.h"
#include "System/SleepManager.h"
#include "Network/WiFiManager.h"
#include "Network/OTAHttpsUpdater.h"
#include "Web/WebDashboard.h"
#include "Utilities/Logger.h"
#include "Automation/AutomationManager.h"

void setup() {
  Serial.begin(115200);
  delay(1000);

  JRDev::Logger::info("ESP32 Enterprise Demo v1.9.0 startet...");
  JRDev::ChipInfo::printChipInfo();

  JRDev::WiFiManager::connect("MyWiFi", "password123");

  JRDev::AutomationManager::load();
  JRDev::WebDashboard::begin();

  JRDev::Logger::info("System bereit.");
}

void loop() {
  JRDev::WebDashboard::handle();
  JRDev::AutomationManager::loop();
  delay(50);
}
