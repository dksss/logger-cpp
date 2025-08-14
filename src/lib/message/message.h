#ifndef LOGGER_SRC_LIB_MESSAGE_H_
#define LOGGER_SRC_LIB_MESSAGE_H_

#include <string>
#include <chrono>
#include <stdexcept>
#include <algorithm>
#include <cctype>

namespace lib {

enum class ImportanceLvl {
  kInfo = 0,
  kWarning,
  kError
};

class Message {
  using created_at = std::chrono::system_clock::time_point;

  public:
    explicit Message(const std::string& msg,
        ImportanceLvl lvl = ImportanceLvl::kInfo,
        created_at time = std::chrono::system_clock::now());
    explicit Message(const std::string&);
    Message() = delete;
    Message(const Message&) = delete;
    Message(Message&&) = delete;
    Message& operator=(const Message&) = delete;
    Message& operator=(Message&&) = delete;
    ~Message() = default;

    const std::string& get_info() const { return info_; };

  private:
    static constexpr const char* kInfoLabel = "INFO";
    static constexpr const char* kWarningLabel = "WARNING";
    static constexpr const char* kErrorLabel = "ERROR";
    
    std::string msg_;
    ImportanceLvl lvl_;
    created_at timestamp_;
    std::string info_;

    static std::string FromImportanceLvlToStr(ImportanceLvl);
    static ImportanceLvl FromStrToImportanceLvl(const std::string&);
    static const std::string MakeUppercaseStr(const std::string&);

    void BuildInfoStr();
    const std::string ConvertTimeToStr();
};

} // namespace lib


#endif // LOGGER_SRC_LIB_MESSAGE_H_