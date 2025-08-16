#include "main_tests.h"

namespace lib {
namespace {

TEST(UtilsTests, ValidFromTypeToStrTest) {
  auto info_check = utils::FromLogTypeToStr(LogType::kInfo);
  auto warn_check = utils::FromLogTypeToStr(LogType::kWarning);
  auto err_check = utils::FromLogTypeToStr(LogType::kError);

  ASSERT_EQ(info_check, Constants::kInfoLabel);
  ASSERT_EQ(warn_check, Constants::kWarningLabel);
  ASSERT_EQ(err_check, Constants::kErrorLabel);
}

TEST(UtilsTests, ExceptionFromTypeToStrTest) {
  LogType invalid_type = (LogType)4;

  ASSERT_ANY_THROW(utils::FromLogTypeToStr(invalid_type));
}

TEST(UtilsTests, ValidFromStrToLogTypeTest) {
  LogType info_check = utils::FromStrToLogType(Constants::kInfoLabel);
  LogType warn_check = utils::FromStrToLogType(Constants::kWarningLabel);
  LogType err_check = utils::FromStrToLogType(Constants::kErrorLabel);

  ASSERT_EQ(info_check, LogType::kInfo);
  ASSERT_EQ(warn_check, LogType::kWarning);
  ASSERT_EQ(err_check, LogType::kError);
}

TEST(UtilsTests, ExceptionFromStrToLogTypeTest) {
  std::string invalid_type_str = "test";

  ASSERT_ANY_THROW(utils::FromStrToLogType(invalid_type_str));
}

TEST(UtilsTests, MakeUppercaseStrTest) {
  std::string testing_1 = "testing1";
  std::string testing_2 = "some text";
  std::string testing_3 = "4n0th3r 7357";

  std::string expected_1 = "TESTING1";
  std::string expected_2 = "SOME TEXT";
  std::string expected_3 = "4N0TH3R 7357";

  EXPECT_EQ(utils::MakeUppercaseStr(testing_1), expected_1);
  EXPECT_EQ(utils::MakeUppercaseStr(testing_2), expected_2);
  EXPECT_EQ(utils::MakeUppercaseStr(testing_3), expected_3);
}

}  // namespace
}  // namespace lib