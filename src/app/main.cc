#include "logger_app/logger_app.h"

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " <logfile> <default_level>"
              << std::endl;
    return 1;
  }

  try {
    std::string logfile = argv[1];
    lib::LogType default_type = lib::utils::FromStrToLogType(argv[2]);

    app::App app(logfile, default_type);
    app.Run();
  } catch (const std::exception& ex) {
    std::cerr << ex.what() << std::endl;
  }

  return 0;
}