#include "main_tests.h"

namespace lib {
namespace {

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