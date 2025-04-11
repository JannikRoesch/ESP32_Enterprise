#include "Logger.h"
#include <Arduino.h>
#include <stdarg.h>

void JRDev::Logger::info(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  Serial.print("[INFO] ");
  Serial.vprintf(fmt, args);
  Serial.println();
  va_end(args);
}

void JRDev::Logger::error(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  Serial.print("[ERROR] ");
  Serial.vprintf(fmt, args);
  Serial.println();
  va_end(args);
}
