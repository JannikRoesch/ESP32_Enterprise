#pragma once
namespace JRDev {
class Logger {
public:
  static void info(const char* fmt, ...);
  static void error(const char* fmt, ...);
};
}
