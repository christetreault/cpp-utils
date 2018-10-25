#pragma once

#include "utility/Assert.hpp"

#include <chrono>
#include <cstdint>

namespace dmp
{
namespace utility
{
using Clock = std::chrono::high_resolution_clock;
using TimePoint = Clock::time_point;

class Duration
{
public:
  Duration() noexcept = default;
  Duration(const Duration& rhs) = default;
  Duration& operator=(const Duration& rhs) = default;
  Duration(Duration&& rhs) = default;
  Duration& operator=(Duration&& rhs) = default;

  Duration(const Clock::duration& d) noexcept
    : m_duration(d)
  {}

  template<typename T>
  T as() const noexcept
  {
    return std::chrono::duration_cast<T>(m_duration);
  }

  template<typename T>
  uint64_t countAs() const noexcept
  {
    // durations range from [0, INT_MAX], so we can convert to unsigned
    const auto count = as<T>().count();

    dmpExpect("duration non-negative", count >= 0);

    return static_cast<uint64_t>(count);
  }

  const Clock::duration& getDuration() const
  {
    return m_duration;
  }

private:
  Clock::duration m_duration;
};

class Timer
{
public:
  Timer() noexcept;
  ~Timer() = default;
  Timer(const Timer &) = delete;
  Timer & operator=(const Timer &) = delete;
  Timer(Timer &&) = default;
  Timer & operator=(Timer &&) = default;

  Duration getElapsedTime() const noexcept;

  Duration getDeltaTime() const noexcept
  {
    return m_deltaTime;
  };

  Duration getPausedDuration() const noexcept;

  void reset() noexcept;
  void unpause() noexcept;
  void pause() noexcept;
  void tick() noexcept;

  bool isPaused() noexcept
  {
    return m_paused;
  }

private:
  TimePoint m_pausedTime;
  TimePoint m_stoppedTime;
  TimePoint m_prevTime;
  TimePoint m_currTime;

  Duration m_deltaTime;

  bool m_paused;
};
}
}
