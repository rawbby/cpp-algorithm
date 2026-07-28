#pragma once

#include <algorithm> // std::max
#include <cstddef>   // std::size_t
#include <iostream>  // std::cout
#include <vector>    // std::vector

namespace problem {
namespace impl {
/// Returns a function that maps 2D (row, col) coordinates to a flat buffer index.
auto
balloon_view2d(
  auto&       buffer,
  std::size_t cols)
{
  return [&buffer, cols](std::size_t r, std::size_t c) -> decltype(auto) { return buffer[r * cols + c]; };
}

// adapts the interval DP pattern: dp(i, j) is the max coins obtained by
// bursting all balloons between i and j; we iterate through all possible
// last balloons k in the interval to maximize the total coins
/// Computes the maximum coins obtainable by bursting all balloons optimally.
inline auto
max_coins(
  std::vector<int> const& v) -> int
{
  auto const n    = v.size();
  auto       nums = std::vector<int>(n + 2, 1);
  for (auto i = std::size_t{ 0 }; i < n; ++i)
    nums[i + 1] = v[i];

  auto const size   = n + 2;
  auto       buffer = std::vector(size * size, 0);
  auto const dp     = balloon_view2d(buffer, size);

  for (auto len = std::size_t{ 1 }; len <= n; ++len) {
    for (auto i = std::size_t{ 1 }; i <= n - len + 1; ++i) {
      auto const j = i + len - 1;
      for (auto k = i; k <= j; ++k) {
        dp(i, j) = std::max(dp(i, j), dp(i, k - 1) + dp(k + 1, j) + nums[i - 1] * nums[k] * nums[j + 1]);
      }
    }
  }
  return dp(1, n);
}
} // namespace impl

inline void
burst_balloons()
{
  auto const v_in = std::vector{ 3, 1, 5, 8 };

  std::cout << "Burst Balloons problem (interval DP pattern)\n";
  std::cout << "time-complexity:  O(N^3)\n";
  std::cout << "space-complexity: O(N^2) auxiliary\n";

  std::cout << "In:         ";
  for (auto const x : v_in)
    std::cout << ' ' << x;
  std::cout << '\n';

  std::cout << "Max coins:  " << impl::max_coins(v_in) << '\n';
}
} // namespace problem
