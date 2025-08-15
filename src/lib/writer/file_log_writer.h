#ifndef LOGGER_SRC_LIB_WRITER_FILE_LOG_WRITER_H_
#define LOGGER_SRC_LIB_WRITER_FILE_LOG_WRITER_H_

#include <fstream>

#include "log_writer_interface.h"

namespace lib {

class FileLogWriter : public LogWriterInterface {
 public:
  explicit FileLogWriter(const std::string& filename);
  ~FileLogWriter() override;

  void Write(const std::string& log) override;

 private:
  std::ofstream file_;
};

} // namespace lib

#endif // LOGGER_SRC_LIB_WRITER_FILE_LOG_WRITER_H_