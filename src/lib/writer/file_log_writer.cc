#include "file_log_writer.h"

namespace lib {

FileLogWriter::FileLogWriter(const std::string& filename)
    : file_(filename, std::ios::app) {
  if (!file_.is_open()) {
    throw std::runtime_error("Failed to open log file: " + filename);
  }
}

FileLogWriter::~FileLogWriter() {}

void FileLogWriter::Write(const std::string& log) {
  if (!file_.is_open()) {
    throw std::runtime_error("Log file is not open");
  }

  file_ << log << std::endl;
}

}  // namespace lib