#ifndef LOGGER_SRC_LIB_LOGGER_H_
#define LOGGER_SRC_LIB_LOGGER_H_

#include <memory>
#include <mutex>
#include <string>

#include "../log/log.h"
#include "../writer/file_log_writer.h"

namespace lib {

class Logger {
 public:
  Logger(const std::string& filename,
         const std::string& type_str = Constants::kInfoLabel);
  Logger() = delete;
  Logger(const Logger&) = delete;
  Logger(Logger&&) = delete;
  Logger& operator=(const Logger&) = delete;
  Logger& operator=(Logger&&) = delete;
  ~Logger() = default;

  void MakeLog(const std::string& msg, LogType type);

  void set_min_log_type(LogType type);
  LogType get_min_log_type() const;

 private:
  std::unique_ptr<LogWriterInterface> writer_;
  std::string log_file_;
  LogType min_type_;
  std::mutex mutex_;
};

}  // namespace lib

#endif  // LOGGER_SRC_LIB_LOGGER_H_