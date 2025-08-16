/**
 * @file constants.h
 * @brief Константы, используемые в классе логера.
 */

#ifndef LOGGER_SRC_LIB_COMMON_CONSTANTS_H_
#define LOGGER_SRC_LIB_COMMON_CONSTANTS_H_

namespace lib {

/**
 * @class Constants
 * @brief Класс, содержащий строковые константы для уровней логов.
 */
class Constants {
 public:
  /// Строковое представление типа информационных сообщений
  static constexpr const char* kInfoLabel = "INFO";
  /// Строковое представление типа предупреждений
  static constexpr const char* kWarningLabel = "WARNING";
  /// Строковое представление типа ошибок
  static constexpr const char* kErrorLabel = "ERROR";
};

}  // namespace lib

#endif  // LOGGER_SRC_LIB_COMMON_CONSTANTS_H_