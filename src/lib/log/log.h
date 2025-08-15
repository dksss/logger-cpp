#ifndef LOGGER_SRC_LIB_LOG_H_
#define LOGGER_SRC_LIB_LOG_H_

#include <algorithm>
#include <cctype>
#include <chrono>
#include <stdexcept>
#include <string>

#include "../common/constants.h"
#include "../common/log_type.h"

namespace lib {

class Log {
  using created_at = std::chrono::system_clock::time_point;

 public:
  explicit Log(const std::string& msg,
               const std::string& type = Constants::kInfoLabel);
  Log() = delete;
  Log(const Log&) = delete;
  Log(Log&&) = delete;
  Log& operator=(const Log&) = delete;
  Log& operator=(Log&&) = delete;
  ~Log() = default;

  const std::string& get_info() const { return info_; };
  void set_lvl(const std::string&);

 private:
  std::string msg_;
  LogType type_;
  created_at timestamp_;
  std::string info_;

  static std::string FromLogTypeToStr(LogType);
  static LogType FromStrToLogType(const std::string&);
  static std::string MakeUppercaseStr(const std::string&);

  void BuildInfoStr();
  const std::string ConvertTimeToStr();
};

}  // namespace lib

#endif  // LOGGER_SRC_LIB_LOG_H_