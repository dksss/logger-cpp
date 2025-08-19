#include "log_queue.h"

namespace app {

void LogQueue::Push(const LogMessage& msg) {
  {
    std::lock_guard<std::mutex> lock(mutex_);
    queue_.push(msg);
  }
  cond_.notify_one();
}

bool LogQueue::Pop(LogMessage& msg) {
  std::unique_lock<std::mutex> lock(mutex_);
  cond_.wait(lock, [&] { return !queue_.empty() || is_stop_; });

  if (is_stop_ && queue_.empty()) {
    return false;
  }

  msg = queue_.front();
  queue_.pop();
  return true;
}

void LogQueue::Stop() {
  {
    std::lock_guard<std::mutex> lock(mutex_);
    is_stop_ = true;
  }
  cond_.notify_all();
}

}  // namespace app