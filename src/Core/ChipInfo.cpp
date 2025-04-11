#include "ChipInfo.h"
#include <Arduino.h>

void JRDev::ChipInfo::printChipInfo() {
  Serial.println("=== ESP32 Chip Info ===");
  Serial.printf("Cores: %d\n", ESP.getChipCores());
  Serial.printf("Flash Size: %dMB\n", ESP.getFlashChipSize() / (1024 * 1024));
  Serial.printf("SDK Version: %s\n", ESP.getSdkVersion());
}
