#include <vector>

#include "main_tests.h"

namespace lib {
namespace {

class MockLogWriter : public LogWriterInterface {
 public:
  std::vector<std::string> logs;

  void Write(const std::string& log) override { logs.push_back(log); }

  int get_size() { return logs.size(); }
};

TEST(LoggerTests, ThrowsOnEmptyFilenameCtorTest) {
  std::string filename = "";
  LogType type = LogType::kInfo;

  EXPECT_THROW(Logger logger(filename, type), std::runtime_error);
}

TEST(LoggerTests, ThrowOnInvalidTypeCtorTest) {
  auto mock_writer = std::make_unique<MockLogWriter>();
  std::string filename = "test.txt";
  LogType invalid_type = (LogType)4;

  EXPECT_THROW(Logger logger(std::move(mock_writer), filename, invalid_type),
               std::invalid_argument);
}

TEST(LoggerTests, ValidCtorTest) {
  auto mock_writer = std::make_unique<MockLogWriter>();

  EXPECT_NO_THROW(
      Logger logger(std::move(mock_writer), "test", LogType::kInfo));
}

TEST(LoggerTests, ValidMakeLogTest) {
  auto mock_writer = std::make_unique<MockLogWriter>();
  MockLogWriter* logs = static_cast<MockLogWriter*>(mock_writer.get());
  Logger logger(std::move(mock_writer), "test.txt", LogType::kInfo);

  logger.MakeLog("Test msg", LogType::kInfo);
  logger.MakeLog("Test msg 2");

  ASSERT_EQ(logs->get_size(), 2);
}

TEST(LoggerTests, MakeLogFilterByMinLevelTest) {
  auto mock_writer = std::make_unique<MockLogWriter>();
  MockLogWriter* logs = static_cast<MockLogWriter*>(mock_writer.get());
  Logger logger(std::move(mock_writer), "test.txt", LogType::kWarning);

  logger.MakeLog("Test info", LogType::kInfo);
  ASSERT_EQ(logs->get_size(), 0);

  logger.MakeLog("Test warning", LogType::kWarning);
  ASSERT_EQ(logs->get_size(), 1);

  logger.MakeLog("Test error", LogType::kError);
  ASSERT_EQ(logs->get_size(), 2);

  logger.MakeLog("Test info 2", LogType::kInfo);
  ASSERT_EQ(logs->get_size(), 2);

  logger.MakeLog("Test default");
  ASSERT_EQ(logs->get_size(), 3);
}

TEST(LoggerTests, InvalidTypeMakeLogTest) {
  auto mock_writer = std::make_unique<MockLogWriter>();
  Logger logger(std::move(mock_writer), "test.txt", LogType::kInfo);
  LogType invalid_type = (LogType)4;

  EXPECT_THROW(logger.MakeLog("Test", invalid_type), std::invalid_argument);
}

TEST(LoggerTests, ValidSetMinLogTypeTest) {
  auto mock_writer = std::make_unique<MockLogWriter>();
  MockLogWriter* logs = static_cast<MockLogWriter*>(mock_writer.get());
  Logger logger(std::move(mock_writer), "test.txt", LogType::kInfo);

  logger.MakeLog("Test info", LogType::kInfo);
  ASSERT_EQ(logs->get_size(), 1);

  // WARNING lvl
  logger.set_min_log_type(LogType::kWarning);

  logger.MakeLog("Test info", LogType::kInfo);
  ASSERT_EQ(logs->get_size(), 1);

  logger.MakeLog("Test warning", LogType::kWarning);
  ASSERT_EQ(logs->get_size(), 2);

  // ERROR lvl
  logger.set_min_log_type(LogType::kError);

  logger.MakeLog("Test warning", LogType::kWarning);
  ASSERT_EQ(logs->get_size(), 2);

  logger.MakeLog("Test error", LogType::kError);
  ASSERT_EQ(logs->get_size(), 3);
}

TEST(LoggerTests, InvalidLogTypeOnSetLogTypeTest) {
  auto mock_writer = std::make_unique<MockLogWriter>();
  Logger logger(std::move(mock_writer), "test.txt", LogType::kInfo);
  LogType invalid_type = (LogType)4;

  logger.set_min_log_type(invalid_type);

  ASSERT_EQ(logger.get_min_log_type(), LogType::kInfo);
}

}  // namespace
}  // namespace lib