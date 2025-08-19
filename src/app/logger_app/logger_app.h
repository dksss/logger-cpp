#ifndef LOGGER_SRC_APP_LOGGER_APP_H_
#define LOGGER_SRC_APP_LOGGER_APP_H_

#include <atomic>
#include <iostream>
#include <string>
#include <thread>

#include "../../lib/logger/logger.h"
#include "../log_queue/log_queue.h"

namespace app {

class App {
 public:
  App(const std::string& logfile, lib::LogType type);
  App(const App&) = delete;
  App(App&&) = delete;
  App& operator=(const App&) = delete;
  App& operator=(App&&) = delete;
  ~App();

  int Run();

 private:
  lib::Logger logger_;
  LogQueue queue_;
  std::thread writer_thread_;

  void WriterLoop();
  void InputLoop();

  std::string ScanMessage();
  lib::LogType ScanType();
};

}  // namespace app

#endif  // LOGGER_SRC_APP_LOGGER_APP_H_