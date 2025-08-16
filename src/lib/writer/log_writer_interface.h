/**
 * @file log_writer_interface.h
 * @brief В этом файле описан интерфейс для записи логов.
 */

#ifndef LOGGER_SRC_LIB_WRITER_LOG_WRITER_INTERFACE_H_
#define LOGGER_SRC_LIB_WRITER_LOG_WRITER_INTERFACE_H_

#include <string>

namespace lib {

/**
 * @class LogWriterInterface
 * @brief Интерфейс для классов, реализующих запись логов.
 *
 * Определяет обязательный метод для записи логов.
 */
class LogWriterInterface {
 public:
  /**
   * @brief Виртуальный деструктор по умолчанию.
   */
  virtual ~LogWriterInterface() = default;

  /**
   * @brief Метод записи строки лога.
   * @param log Лог для записи
   */
  virtual void Write(const std::string& log) = 0;
};

}  // namespace lib

#endif  // LOGGER_SRC_LIB_WRITER_LOG_WRITER_INTERFACE_H_