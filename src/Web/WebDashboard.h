#pragma once
#include <WebServer.h>
namespace JRDev {
class WebDashboard {
public:
  static WebServer server;
  static void begin();
  static void handle();
};
inline WebServer WebDashboard::server(80);
}
