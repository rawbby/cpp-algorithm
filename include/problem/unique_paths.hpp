#pragma once

#include <iostream> // std::cout
#include <vector>   // std::vector

namespace problem {
namespace impl {
// adapts the 2D grid DP pattern: compressed to a single row since each
// cell only depends on the current row's previous cell and the same
// cell from the previous row
inline auto
count_unique_paths(
  int m,
  int n) -> int
{
  if (m <= 0 || n <= 0) return 0;
  auto dp = std::vector<int>(static_cast<std::size_t>(n), 1);
  for (auto i = 1; i < m; ++i) {
    for (auto j = 1; j < n; ++j) {
      dp[static_cast<std::size_t>(j)] += dp[static_cast<std::size_t>(j - 1)];
    }
  }
  return dp[static_cast<std::size_t>(n - 1)];
}
} // namespace impl

inline void
unique_paths()
{
  constexpr auto m = int{ 3 };
  constexpr auto n = int{ 7 };

  std::cout << "Unique Paths problem (2D grid DP compressed pattern)\n";
  std::cout << "time-complexity:  O(M*N)\n";
  std::cout << "space-complexity: O(N) auxiliary\n";

  std::cout << "In:         m=" << m << " n=" << n << '\n';
  std::cout << "Paths:      " << impl::count_unique_paths(m, n) << '\n';
}
} // namespace problem
