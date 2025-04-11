#pragma once
#include <vector>
#include <Arduino.h>

namespace JRDev {

struct AutomationRule {
  String name;
  String triggerType;
  int triggerPin;
  String condition;
  String time;
  String actionType;
  String variable;
  int actionPin;
  int actionValue;
  String mqttTopic;
  String mqttPayload;
  String nextTriggerName;
};

class AutomationManager {
public:
  static void load();
  static void save();
  static void loop();
  static void trigger(String type, int value);
  static std::vector<AutomationRule>& get();
};

}
