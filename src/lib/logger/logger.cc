#include "logger.h"

namespace lib {

Logger::Logger(std::unique_ptr<LogWriterInterface> writer,
               const std::string& filename, LogType type)
    : writer_(std::move(writer)),
      log_file_(filename),
      min_type_(type),
      mutex_() {
  if (!IsValidType(type)) {
    throw std::invalid_argument("Invalid type.");
  };
}

Logger::Logger(const std::string& filename, LogType type)
    : Logger(std::make_unique<FileLogWriter>(filename), filename, type) {}

void Logger::MakeLog(const std::string& msg, LogType type) {
  std::lock_guard<std::mutex> lock(mutex_);

  if (!IsValidType(type)) {
    throw std::invalid_argument("Invalid type of log.");
  }

  if (type >= min_type_) {
    Log log{msg, type};
    writer_->Write(log.get_info());
  }
}

void Logger::MakeLog(const std::string& msg) {
  LogType type = min_type_;
  MakeLog(msg, type);
}

void Logger::set_min_log_type(LogType type) {
  std::lock_guard<std::mutex> lock(mutex_);
  if (IsValidType(type)) {
    min_type_ = type;
  }
}

LogType Logger::get_min_log_type() const { return min_type_; }

bool Logger::IsValidType(LogType type) {
  switch (type) {
    case LogType::kInfo:
    case LogType::kWarning:
    case LogType::kError:
      return true;
    default:
      return false;
  }
}

}  // namespace lib
