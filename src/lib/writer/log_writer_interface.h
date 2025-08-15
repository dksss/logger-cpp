#ifndef LOGGER_SRC_LIB_WRITER_LOG_WRITER_INTERFACE_H_
#define LOGGER_SRC_LIB_WRITER_LOG_WRITER_INTERFACE_H_

#include <string>

namespace lib {

class LogWriterInterface {
 public:
  virtual ~LogWriterInterface() = default;

  virtual void Write(const std::string& log) = 0;
};

}  // namespace lib

#endif  // LOGGER_SRC_LIB_WRITER_LOG_WRITER_INTERFACE_H_