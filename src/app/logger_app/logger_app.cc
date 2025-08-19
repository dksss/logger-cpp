#include "logger_app.h"

namespace app {

App::App(const std::string& logfile, lib::LogType type)
    : queue_(), logger_(logfile, type) {}

App::~App() {
  queue_.Stop();
  if (writer_thread_.joinable()) {
    writer_thread_.join();
  }
}

void App::Run() {
  writer_thread_ = std::thread(&App::WriterLoop, this);
  InputLoop();
}

void App::WriterLoop() {
  LogMessage msg;
  while (queue_.Pop(msg)) {
    try {
      logger_.MakeLog(msg.text, msg.type);
    } catch (const std::runtime_error& er) {
      std::cerr << "Logger error: " << er.what() << std::endl;
    } catch (const std::invalid_argument& ex) {
      std::cerr << "Log err: " << ex.what() << std::endl;
    }
  }
}

void App::InputLoop() {
  std::cout
      << "Enter message (or '" << kExitCmd << "' to exit).\n"
      << "After entering message, enter Log Level: INFO | WARNING | ERROR.\n"
      << "Empty Log Level = use default Log Level ("
      << lib::utils::FromLogTypeToStr(logger_.get_min_log_type()) << ").\n";

  while (true) {
    std::string message = ScanMessage();
    if (message == kExitCmd) break;

    if (message.empty()) {
      std::cerr << "Empty message skipped.\n";
      continue;
    }

    lib::LogType type = ScanType();
    queue_.Push({message, type});
  }

  queue_.Stop();
}

std::string App::ScanMessage() {
  std::string message;
  std::cout << "\n> Message: " << std::flush;
  std::getline(std::cin, message);

  return (std::cin ? message : kExitCmd);
}

lib::LogType App::ScanType() {
  std::string level;
  std::cout << "> Log Level [INFO|WARNING|ERROR] (default = "
            << lib::utils::FromLogTypeToStr(logger_.get_min_log_type())
            << "): " << std::flush;

  if (!std::getline(std::cin, level)) {
    return logger_.get_min_log_type();
  }

  lib::LogType type = logger_.get_min_log_type();
  if (!level.empty()) {
    try {
      type = lib::utils::FromStrToLogType(level);
    } catch (const std::invalid_argument& ex) {
      std::cerr << "Error: " << ex.what() << "\nUsing default type: "
                << lib::utils::FromLogTypeToStr(type) << std::endl;
    }
  }

  return type;
}

}  // namespace app
