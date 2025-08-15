#include "log_type.h"

namespace lib {
namespace utils {

std::string FromLogTypeToStr(LogType type) {
  if (type == LogType::kInfo) {
    return Constants::kInfoLabel;
  } else if (type == LogType::kWarning) {
    return Constants::kWarningLabel;
  } else if (type == LogType::kError) {
    return Constants::kErrorLabel;
  } else {
    throw std::invalid_argument("Unknown type of LogType.");
  }
}

LogType FromStrToLogType(const std::string& type_str) {
  std::string type_upper = MakeUppercaseStr(type_str);
  if (type_upper == Constants::kInfoLabel) {
    return LogType::kInfo;
  } else if (type_upper == Constants::kWarningLabel) {
    return LogType::kWarning;
  } else if (type_upper == Constants::kErrorLabel) {
    return LogType::kError;
  } else {
    throw std::invalid_argument("Unknown LogType string: " + type_upper + ".");
  }
}

std::string MakeUppercaseStr(const std::string& other) {
  std::string upper = other;
  std::transform(upper.begin(), upper.end(), upper.begin(),
                 [](char c) { return std::toupper(c); });

  return upper;
}

}  // namespace utils
}  // namespace lib