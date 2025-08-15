#include "message.h"

namespace lib {

Message::Message(const std::string& msg, const std::string& lvl) {
  if (msg.empty()) {
    throw std::invalid_argument("Log with empty message is not valid.");
  }

  msg_ = msg;
  lvl_ = FromStrToImportanceLvl(lvl);
  timestamp_ = std::chrono::system_clock::now();

  BuildInfoStr();
}

void Message::set_lvl(const std::string& lvl) {
  lvl_ = FromStrToImportanceLvl(lvl);
}

std::string Message::FromImportanceLvlToStr(ImportanceLvl lvl) {
  if (lvl == ImportanceLvl::kInfo) {
    return Constants::kInfoLabel;
  } else if (lvl == ImportanceLvl::kWarning) {
    return Constants::kWarningLabel;
  } else if (lvl == ImportanceLvl::kError) {
    return Constants::kErrorLabel;
  } else {
    throw std::invalid_argument("Unknown type of ImportanceLvl.");
  }
}

ImportanceLvl Message::FromStrToImportanceLvl(const std::string& lvl_str) {
  std::string lvl_upper = MakeUppercaseStr(lvl_str);
  if (lvl_upper == Constants::kInfoLabel) {
    return ImportanceLvl::kInfo;
  } else if (lvl_upper == Constants::kWarningLabel) {
    return ImportanceLvl::kWarning;
  } else if (lvl_upper == Constants::kErrorLabel) {
    return ImportanceLvl::kError;
  } else {
    throw std::invalid_argument("Unknown ImportanceLvl string: " + lvl_upper +
                                ".");
  }
}

std::string Message::MakeUppercaseStr(const std::string& other) {
  std::string upper = other;
  std::transform(upper.begin(), upper.end(), upper.begin(),
                 [](char c) { return std::toupper(c); });

  return upper;
}

void Message::BuildInfoStr() {
  std::string time = ConvertTimeToStr();
  std::string type = FromImportanceLvlToStr(lvl_);

  info_ = "[" + time + "] " + "[" + type + "] " + msg_;
}

const std::string Message::ConvertTimeToStr() {
  std::time_t time_point = std::chrono::system_clock::to_time_t(timestamp_);
  std::tm* local_time = std::localtime(&time_point);

  char time_str[20];
  strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", local_time);

  return time_str;
}

}  // namespace lib