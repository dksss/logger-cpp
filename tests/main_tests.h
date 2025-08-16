#ifndef LOGGER_TESTS_MAIN_TESTS_H_
#define LOGGER_TESTS_MAIN_TESTS_H_

#include <gtest/gtest.h>

#include "../src/lib/common/log_type.h"
#include "../src/lib/log/log.h"

class LogTest : public testing::Test {
 protected:
  std::string valid_msg_ = "test";
  std::string valid_msg2_ = "valid message";
  std::string invalid_msg_ = "";
};

#endif  // LOGGER_TESTS_MAIN_TESTS_H_