#include "AutomationManager.h"
#include <LittleFS.h>
#include <ArduinoJson.h>

using namespace JRDev;
static std::vector<AutomationRule> rules;

void AutomationManager::load() {
  File file = LittleFS.open("/automation.json", "r");
  if (!file) return;

  DynamicJsonDocument doc(2048);
  deserializeJson(doc, file);
  rules.clear();

  for (JsonObject r : doc.as<JsonArray>()) {
    AutomationRule rule;
    rule.name = r["name"] | "";
    rule.triggerType = r["triggerType"] | "";
    rule.triggerPin = r["triggerPin"] | -1;
    rule.condition = r["condition"] | "";
    rule.time = r["time"] | "";
    rule.actionType = r["actionType"] | "";
    rule.actionPin = r["actionPin"] | -1;
    rule.actionValue = r["actionValue"] | 0;
    rule.mqttTopic = r["mqttTopic"] | "";
    rule.mqttPayload = r["mqttPayload"] | "";
    rule.nextTriggerName = r["nextTriggerName"] | "";
    rules.push_back(rule);
  }

  file.close();
}

std::vector<AutomationRule>& AutomationManager::get() { return rules; }
void AutomationManager::save() {}  // Placeholder
void AutomationManager::loop() {}  // Placeholder
void AutomationManager::trigger(String, int) {}  // Placeholder
