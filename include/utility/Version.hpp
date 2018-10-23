#pragma once

#include <tuple>

namespace dmp
{
namespace utility
{
struct Version
{
  uint32_t major;
  uint32_t minor;
  uint32_t patch;
};

constexpr bool operator==(const Version& lhs, const Version& rhs)
{
  auto l = std::tie(lhs.major, lhs.minor, lhs.patch);
  auto r = std::tie(rhs.major, rhs.minor, rhs.patch);

  return l == r;
}

constexpr bool operator!=(const Version& lhs, const Version& rhs)
{
  auto l = std::tie(lhs.major, lhs.minor, lhs.patch);
  auto r = std::tie(rhs.major, rhs.minor, rhs.patch);

  return l != r;
}

constexpr bool operator<(const Version& lhs, const Version& rhs)
{
  auto l = std::tie(lhs.major, lhs.minor, lhs.patch);
  auto r = std::tie(rhs.major, rhs.minor, rhs.patch);

  return l < r;
}

constexpr bool operator<=(const Version& lhs, const Version& rhs)
{
  auto l = std::tie(lhs.major, lhs.minor, lhs.patch);
  auto r = std::tie(rhs.major, rhs.minor, rhs.patch);

  return l <= r;
}

constexpr bool operator>=(const Version& lhs, const Version& rhs)
{
  auto l = std::tie(lhs.major, lhs.minor, lhs.patch);
  auto r = std::tie(rhs.major, rhs.minor, rhs.patch);

  return l >= r;
}

constexpr bool operator>(const Version& lhs, const Version& rhs)
{
  auto l = std::tie(lhs.major, lhs.minor, lhs.patch);
  auto r = std::tie(rhs.major, rhs.minor, rhs.patch);

  return l > r;
}

}
}
