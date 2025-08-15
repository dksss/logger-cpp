#include "log.h"

namespace lib {

Log::Log(const std::string& msg, LogType type)
    : msg_(msg), type_(type), timestamp_(std::chrono::system_clock::now()) {
  BuildInfoStr();
}

void Log::BuildInfoStr() {
  std::string time = ConvertTimeToStr();
  std::string type = utils::FromLogTypeToStr(type_);

  info_ = "[" + time + "] " + "[" + type + "] " + msg_;
}

const std::string Log::ConvertTimeToStr() {
  std::time_t time_point = std::chrono::system_clock::to_time_t(timestamp_);
  std::tm* local_time = std::localtime(&time_point);

  char time_str[20];
  strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", local_time);

  return time_str;
}

}  // namespace lib