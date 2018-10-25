#include "utility/Timer.hpp"

#include <algorithm>

namespace dmp
{
namespace utility
{

namespace
{

inline Duration clampDuration(const Duration& dur)
{
  if (dur.getDuration().count() < 0)
    {
      return Duration();
    }
  return dur;
}

}

Timer::Timer() noexcept
  : m_pausedTime(Clock::now())
  , m_stoppedTime(Clock::now())
  , m_prevTime(Clock::now())
  , m_currTime(Clock::now())
  , m_deltaTime()
  , m_paused(true)
{}

Duration Timer::getElapsedTime() const noexcept
{
  auto now = m_currTime;

  if (m_paused)
    {
      now = m_stoppedTime;
    }

  return clampDuration(now - m_pausedTime);
}

Duration Timer::getPausedDuration() const noexcept
{
  if (m_paused)
    {
      return clampDuration(Clock::now() - m_stoppedTime);
    }

  return Duration();
}

void Timer::reset() noexcept
{
  auto now = Clock::now();

  m_pausedTime = now;
  m_stoppedTime = now;
  m_prevTime = now;
  m_currTime = now;
  m_deltaTime = Duration();
  m_paused = true;
}

void Timer::unpause() noexcept
{
  if (m_paused)
    {
      auto now = Clock::now();
      m_pausedTime += now - m_stoppedTime;
      m_prevTime = now;
      m_paused = false;
    }
}

void Timer::pause() noexcept
{
  if (!m_paused)
    {
      m_stoppedTime = Clock::now();
      m_paused = true;
    }
}

void Timer::tick() noexcept
{
  if (m_paused)
    {
      m_deltaTime = Duration();
      return;
    }

  m_prevTime = m_currTime;
  m_currTime = Clock::now();
  m_deltaTime = clampDuration(m_currTime - m_prevTime);
}


}
}
