/**
 * @file file_log_writer.h
 * @brief В этом файле описан класс для записи логов в файл
 */

#ifndef LOGGER_SRC_LIB_WRITER_FILE_LOG_WRITER_H_
#define LOGGER_SRC_LIB_WRITER_FILE_LOG_WRITER_H_

#include <fstream>

#include "log_writer_interface.h"

namespace lib {

/**
 * @class FileLogWriter
 * @brief Класс, реализующий интерфейс LogWriterInterface
 * для записи логов в файл
 *
 * Открывает файл для дозаписи и записывает логи построчно
 */
class FileLogWriter : public LogWriterInterface {
 public:
  /**
   * @brief Конструктор, открывающий файл для дозаписи логов
   * @param  filename Имя файла для записи логов
   * @throws std::runtime_error если файл не удалось открыть
   */
  explicit FileLogWriter(const std::string& filename);
  ~FileLogWriter() override;

  /**
   * @brief Метод записи лога в файл
   * @param log Лог для записи
   * @throws std::runtime_error если файл не открыт для записи
   */
  void Write(const std::string& log) override;

 private:
  /// Поток файлового вывода для записи логов
  std::ofstream file_;
};

}  // namespace lib

#endif  // LOGGER_SRC_LIB_WRITER_FILE_LOG_WRITER_H_