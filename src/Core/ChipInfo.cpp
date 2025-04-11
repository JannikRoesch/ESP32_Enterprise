#include "ChipInfo.h"
#include <Arduino.h>

void JRDev::ChipInfo::printChipInfo() {
  Serial.printf("=== ESP32 Chip Info ===\\n");
  Serial.printf("Cores: %d\\n", ESP.getChipCores());
  Serial.printf("Flash: %dMB\\n", ESP.getFlashChipSize() / (1024 * 1024));
  Serial.printf("SDK: %s\\n", ESP.getSdkVersion());
}
