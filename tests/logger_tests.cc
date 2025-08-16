#include <vector>

#include "main_tests.h"

namespace lib {
namespace {

class MockLogWriter : public LogWriterInterface {
 public:
  std::vector<std::string> logs_;

  void Write(const std::string& log) override { logs_.push_back(log); }
};

class LoggerTest : public ::testing::Test {};

}  // namespace
}  // namespace lib