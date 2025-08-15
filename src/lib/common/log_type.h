#ifndef LOGGER_SRC_LIB_COMMON_LOG_TYPE_H_
#define LOGGER_SRC_LIB_COMMON_LOG_TYPE_H_

#include <algorithm>
#include <stdexcept>
#include <string>

#include "constants.h"

namespace lib {

enum class LogType { kInfo = 0, kWarning, kError };

namespace utils {

std::string FromLogTypeToStr(LogType);
LogType FromStrToLogType(const std::string&);
std::string MakeUppercaseStr(const std::string&);

}  // namespace utils
}  // namespace lib

#endif  // LOGGER_SRC_LIB_COMMON_LOG_TYPE_H_