#include "message.h"

namespace lib {

Message::Message(const std::string& msg, ImportanceLvl lvl, created_at time)
    : msg_(msg), lvl_(lvl), timestamp_(time) {
  BuildInfoStr();
}

Message::Message(const std::string& info) : info_(info) {

}

std::string Message::FromImportanceLvlToStr(ImportanceLvl lvl) {
  if (lvl == ImportanceLvl::kInfo) {
    return kInfoLabel;
  } else if (lvl == ImportanceLvl::kWarning) {
    return kWarningLabel;
  } else if (lvl == ImportanceLvl::kError) {
    return kErrorLabel;
  } else {
    throw std::invalid_argument("Unknown type of ImportanceLvl.");
  }
}

ImportanceLvl Message::FromStrToImportanceLvl(const std::string& lvl_str) {
  std::string lvl_upper = MakeUppercaseStr(lvl_str);
  if (lvl_upper == kInfoLabel) {
    return ImportanceLvl::kInfo;
  } else if (lvl_upper == kWarningLabel) {
    return ImportanceLvl::kWarning;
  } else if (lvl_upper == kErrorLabel) {
    return ImportanceLvl::kError;
  } else {
    throw std::invalid_argument(
        "Unknown ImportanceLvl string: " + lvl_upper + ".");
  }
}

const std::string Message::MakeUppercaseStr(const std::string& other) {
  std::string upper = other;
  std::transform(upper.begin(), upper.end(), upper.begin(),
      [](char c) { return std::toupper(c); });

  return upper;
}

void Message::BuildInfoStr() {
  if (msg_.empty()) {
    throw std::invalid_argument("Log with empty message is not valid.");
  }

  std::string time = ConvertTimeToStr();
  std::string type = FromImportanceLvlToStr(lvl_);

  info_ = "[" + time + "] " + "[" + type + "] " + msg_;
}

const std::string Message::ConvertTimeToStr() {
  std::time_t time_point = std::chrono::system_clock::to_time_t(timestamp_);
  std::tm* local_time = std::localtime(&time_point);
  
  char time_str[20];
  strftime(time_str, sizeof(local_time), "%D %T", local_time);

  return time_str;
}

} // namespace lib