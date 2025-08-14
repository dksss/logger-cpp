#include "message.h"

namespace lib {

Message::Message(const std::string& msg, ImportanceLvl lvl, created_at time)
    : msg_(msg), lvl_(lvl), timestamp_(time) {
  info_ = "";
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
  if (lvl_str == kInfoLabel) {
    return ImportanceLvl::kInfo;
  } else if (lvl_str == kWarningLabel) {
    return ImportanceLvl::kWarning;
  } else if (lvl_str == kErrorLabel) {
    return ImportanceLvl::kError;
  } else {
    throw std::invalid_argument(
        "Unknown ImportanceLvl string: " + lvl_str + ".");
  }
}

void Message::BuildInfo() {

}

} // namespace lib