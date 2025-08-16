/**
 * @file log.h
 * @brief В этом файле описан класс логов
 */

#ifndef LOGGER_SRC_LIB_LOG_H_
#define LOGGER_SRC_LIB_LOG_H_

#include <cctype>
#include <chrono>

#include "../common/constants.h"
#include "../common/log_type.h"

namespace lib {

/**
 * @class Log
 * @brief Модель логов
 */
class Log {
  using created_at = std::chrono::system_clock::time_point;

 public:
  explicit Log(const std::string& msg, LogType type);
  Log() = delete;
  Log(const Log&) = delete;
  Log(Log&&) = delete;
  Log& operator=(const Log&) = delete;
  Log& operator=(Log&&) = delete;
  ~Log() = default;

  /**
   * @brief Геттер информации о логе
   * @return Текстовое представление лога вида: [DATE] [TIME] MSG
   */
  const std::string& get_info() const { return info_; };

 private:
  std::string msg_;       ///< Сообщение лога
  LogType type_;          ///< Тип лога
  created_at timestamp_;  ///< Время создания лога
  std::string info_;  ///< Полный лог в текстовом виде

  /**
   * @brief Метод для создания текстового представления лога
   * @throw std::invalid_argument если задан неподдерживаемый тип лога
   */
  void BuildInfoStr();

  /**
   * @brief Метод для конвертации времени в строку
   */
  const std::string ConvertTimeToStr();
};

}  // namespace lib

#endif  // LOGGER_SRC_LIB_LOG_H_