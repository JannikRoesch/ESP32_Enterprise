#pragma once
#include <Arduino.h>

namespace JRDev {
class OTAManager {
public:
  static void setup(const String& version);
  static bool checkForUpdate();
  static void handleAutoUpdate();
private:
  static String currentVersion;
  static unsigned long lastCheck;
};
}
