#include "logger.h"

namespace lib {

Logger::Logger(const std::string& filename, const std::string& type_str)
    : writer_(std::make_unique<FileLogWriter>(filename)),
      log_file_(filename),
      min_type_(utils::FromStrToLogType(type_str)),
      mutex_() {
  if (filename.empty()) {
    throw std::invalid_argument("Log file must not be empty.");
  }
}

void Logger::MakeLog(const std::string& msg, LogType type) {
  std::lock_guard<std::mutex> lock(mutex_);

  if (type < min_type_) {
    return;
  }

  Log log{msg, type};
  writer_->Write(log.get_info());
}

void Logger::MakeLog(const std::string& msg) {
  std::lock_guard<std::mutex> lock(mutex_);
  LogType type = min_type_;
  MakeLog(msg, type);
}

void Logger::set_min_log_type(LogType type) {
  std::lock_guard<std::mutex> lock(mutex_);
  min_type_ = type;
}

LogType Logger::get_min_log_type() const { return min_type_; }

}  // namespace lib
