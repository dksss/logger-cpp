#include "main_tests.h"

namespace lib {
namespace {

class FileLogWriterTest : public testing::Test {
 protected:
  const std::string filename_ = "test_log.txt";

  void SetUp() override { std::remove(filename_.c_str()); }
  void TearDown() override { std::remove(filename_.c_str()); }
};

TEST_F(FileLogWriterTest, WritesLogToFileSuccessfullyTest) {
  FileLogWriter writer(filename_);

  EXPECT_NO_THROW(writer.Write("First test log"));
  EXPECT_NO_THROW(writer.Write("Second test log"));
}

TEST_F(FileLogWriterTest, ThrowsOnOpenningFileTest) {
  std::string invalid_filename = "./invalid_path/log.txt";

  EXPECT_THROW(FileLogWriter writer(invalid_filename), std::runtime_error);
}

}  // namespace
}  // namespace lib