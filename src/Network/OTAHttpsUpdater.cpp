#include "OTAHttpsUpdater.h"
#include <HTTPClient.h>
#include <Update.h>

void JRDev::OTAHttpsUpdater::update(const char* url) {
  HTTPClient http;
  http.begin(url);
  int code = http.GET();
  if (code == 200) {
    int len = http.getSize();
    WiFiClient* stream = http.getStreamPtr();
    if (Update.begin(len)) {
      Update.writeStream(*stream);
      if (Update.end() && Update.isFinished()) {
        ESP.restart();
      }
    }
  }
  http.end();
}
