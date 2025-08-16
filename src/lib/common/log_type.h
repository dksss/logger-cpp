/**
 * @file log_type.h
 * @brief Определение типов логов
 * и утилит для преобразования типов в строку и обратно
 */

#ifndef LOGGER_SRC_LIB_COMMON_LOG_TYPE_H_
#define LOGGER_SRC_LIB_COMMON_LOG_TYPE_H_

#include <algorithm>
#include <stdexcept>
#include <string>

#include "constants.h"

namespace lib {

/**
 * @enum LogType
 * @brief Перечисление уровней логов
 */
enum class LogType {
  kInfo = 0,  ///< Информационные сообщения
  kWarning,   ///< Предупреждения
  kError      ///< Ошибки
};

namespace utils {

/**
 * @brief Преобразование значения LogType в строковое представление
 * @param type Уровень лога
 * @return Строковое имя уровня лога
 * @throws std::invalid_argument если передан неизвестный LogType
 */
std::string FromLogTypeToStr(LogType);
/**
 * @brief Преобразование строки в значение LogType
 * @param type_str Строковое представление уровня лога (регистр не важен)
 * @return Соответствующий LogType
 * @throws std::invalid_argument при неизвестной строке
 */
LogType FromStrToLogType(const std::string&);
/**
 * @brief Преобразование строки к верхнему регистру
 * @param other Входная строка
 * @return Копия строки, преобразованная в верхний регистр
 */
std::string MakeUppercaseStr(const std::string&);

}  // namespace utils
}  // namespace lib

#endif  // LOGGER_SRC_LIB_COMMON_LOG_TYPE_H_