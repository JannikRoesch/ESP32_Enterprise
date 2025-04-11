#include "SleepManager.h"
#include <esp_sleep.h>

void JRDev::SleepManager::deepSleep(uint64_t us) {
  esp_sleep_enable_timer_wakeup(us);
  esp_deep_sleep_start();
}
