#include "main_tests.h"

namespace lib {
namespace {

TEST(LogTests, ValidInfoLogTest) {
  std::string msg = "Test message";
  LogType type = LogType::kInfo;
  int log_size = 6 + 19 + (utils::FromLogTypeToStr(type)).size() + msg.size();

  Log log(msg, type);
  std::string info = log.get_info();

  ASSERT_FALSE(info.empty());
  ASSERT_EQ(info.size(), log_size);
  ASSERT_EQ(info[0], '[');
  ASSERT_EQ(info[5], '-');
  ASSERT_EQ(info[8], '-');
  ASSERT_EQ(info[11], ' ');
  ASSERT_EQ(info[14], ':');
  ASSERT_EQ(info[17], ':');
  ASSERT_EQ(info[20], ']');
  ASSERT_EQ(info[21], ' ');
  ASSERT_EQ(info[22], '[');
}

TEST(LogTests, InvalidMsgLogTest) {
  std::string msg = "";
  LogType type = LogType::kInfo;

  EXPECT_NO_THROW(Log log(msg, type));
}

TEST(LogTests, InvalidTypeLogTest) {
  std::string msg = "Test message";
  LogType type = (LogType)5;

  EXPECT_ANY_THROW(Log log(msg, type));
}

}  // namespace
}  // namespace lib