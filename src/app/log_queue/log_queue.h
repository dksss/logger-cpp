#ifndef LOGGER_SRC_APP_LOG_QUEUE_LOG_QUEUE_H_
#define LOGGER_SRC_APP_LOG_QUEUE_LOG_QUEUE_H_

#include <condition_variable>
#include <mutex>
#include <queue>

#include "../message/log_message.h"

namespace app {

class LogQueue {
 public:
  void Push(const LogMessage& msg);
  bool Pop(LogMessage& msg);
  void Stop();

 private:
  std::queue<LogMessage> queue_;
  std::mutex mutex_;
  std::condition_variable cond_;
  bool is_stop_ = false;
};

}  // namespace app

#endif  // LOGGER_SRC_APP_LOG_QUEUE_LOG_QUEUE_H_