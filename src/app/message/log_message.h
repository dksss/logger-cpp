#ifndef LOGGER_SRC_APP_LOG_MESSAGE_H_
#define LOGGER_SRC_APP_LOG_MESSAGE_H_

#include <string>

#include "../../lib/common/log_type.h"

namespace app {

struct LogMessage {
  std::string text;
  lib::LogType type;
};

}  // namespace app

#endif  // LOGGER_SRC_APP_LOG_MESSAGE_H_