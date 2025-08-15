#ifndef LOGGER_SRC_LIB_LOGGER_H_
#define LOGGER_SRC_LIB_LOGGER_H_

#include <string>

#include "../log/log.h"

namespace lib {

class Logger {
 public:
  Logger();
  ~Logger();

 private:
  std::string log_file_;
  LogType min_type_;
};

}  // namespace lib

#endif  // LOGGER_SRC_LIB_LOGGER_H_