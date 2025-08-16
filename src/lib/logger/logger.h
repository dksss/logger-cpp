/**
 * @file logger.h
 * @brief В этом файле описан класс логгера для записи логов в файл
 * с поддержкой разных уровней важности.
 */

#ifndef LOGGER_SRC_LIB_LOGGER_H_
#define LOGGER_SRC_LIB_LOGGER_H_

#include <memory>
#include <mutex>
#include <string>

#include "../log/log.h"
#include "../writer/file_log_writer.h"

namespace lib {

/**
 * @class Logger
 * @brief Класс для работы с логами с потокобезопасной записью в файл.
 *
 * Позволяет создавать логи с различным уровнем важности
 * и поддерживает фильтрацию по уровню.
 *
 * Использует мьютекс для корректной работы в многопоточной среде.
 */
class Logger {
 public:
  /**
   * @brief Конструктор логгера с указанием файла и начального типа лога.
   * @param filename Имя файла для записи логов (не может быть пустым)
   * @param type_str Тип логов по умолчанию
   * (логи с меньшим уровнем не будут записываться)
   * @throw std::invalid_argument если filename пустой
   */
  Logger(const std::string& filename,
         const std::string& type_str = Constants::kInfoLabel);
  Logger() = delete;
  Logger(const Logger&) = delete;
  Logger(Logger&&) = delete;
  Logger& operator=(const Logger&) = delete;
  Logger& operator=(Logger&&) = delete;
  ~Logger() = default;

  /**
   * @brief Метод для создания лога с указанным уровнем важности.
   * @param msg Сообщение лога
   * @param type Уровень важности лога
   *
   * Если уровень важности type ниже минимального
   * установленного, лог не создается.
   */
  void MakeLog(const std::string& msg, LogType type);

  /**
   * @brief Метод для создания лога с уровнем важности по умолчанию.
   * @param msg Сообщение лога
   * @throws std::runtime_error при ошибках записи в файл
   */
  void MakeLog(const std::string& msg);

  /**
   * @brief Сеттер минимального уровня важности логов
   * @param type Минимальный уровень лога, который будет записываться
   * @throws std::runtime_error при ошибках записи в файл
   */
  void set_min_log_type(LogType type);
  /**
   * @brief Геттер минимального уровня важности лога
   * @return Текущий уровень важности лога
   */
  LogType get_min_log_type() const;

 private:
  /// Объект, записывающий логи
  std::unique_ptr<LogWriterInterface> writer_;
  /// Название файла, в котором будут записываться логи
  std::string log_file_;
  /// Тип логов по умолчанию (логи с типом ниже игнорируются)
  LogType min_type_;
  /// Мьютекс для защиты записи логов в многопоточной среде
  std::mutex mutex_;
};

}  // namespace lib

#endif  // LOGGER_SRC_LIB_LOGGER_H_