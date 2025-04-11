#include "WebDashboard.h"
#include <ArduinoJson.h>
#include <LittleFS.h>
#include <WiFi.h>

using namespace JRDev;

void WebDashboard::begin() {
  server.on("/", HTTP_GET, []() {
    server.serveStatic("/", LittleFS, "/index.html");
  });

  server.on("/status", HTTP_GET, []() {
    DynamicJsonDocument doc(256);
    doc["ip"] = WiFi.localIP().toString();
    doc["uptime"] = millis();
    String json;
    serializeJson(doc, json);
    server.send(200, "application/json", json);
  });

  server.begin();
}

void WebDashboard::handle() {
  server.handleClient();
}
