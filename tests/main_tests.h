#ifndef LOGGER_TESTS_MAIN_TESTS_H_
#define LOGGER_TESTS_MAIN_TESTS_H_

#include <gtest/gtest.h>

#include <cstdio>

#include "../src/lib/common/log_type.h"
#include "../src/lib/log/log.h"
#include "../src/lib/writer/file_log_writer.h"

namespace lib {
namespace {

class FileLogWriterTest : public testing::Test {
 protected:
  const std::string filename_ = "test_log.txt";

  void SetUp() override { std::remove(filename_.c_str()); }
  void TearDown() override { std::remove(filename_.c_str()); }
};

}  // namespace
}  // namespace lib

#endif  // LOGGER_TESTS_MAIN_TESTS_H_