#pragma once
namespace JRDev {
class WiFiManager {
public:
  static void connect(const char* ssid = nullptr, const char* pass = nullptr);
};
}
