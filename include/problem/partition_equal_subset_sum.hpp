#pragma once

#include <iostream> // std::cout
#include <numeric>  // std::accumulate
#include <vector>   // std::vector

namespace problem {
namespace impl {
// adapts the 0/1 knapsack pattern: determines if a subset exists with sum
// equal to half the total sum using a boolean-vector DP; dp[i] is true
// if sum i is achievable using a subset of elements seen so far
inline auto
can_partition(
  std::vector<int> const& v) -> bool
{
  auto const total = std::accumulate(v.begin(), v.end(), 0);
  if (total % 2 != 0) return false;

  auto const target = total / 2;
  auto       dp     = std::vector<bool>(static_cast<std::size_t>(target) + 1, false);
  dp[0]             = true;

  for (auto const x : v) {
    for (auto i = target; i >= x; --i) {
      if (dp[static_cast<std::size_t>(i - x)]) dp[static_cast<std::size_t>(i)] = true;
    }
  }
  return dp[static_cast<std::size_t>(target)];
}
} // namespace impl

inline void
partition_equal_subset_sum()
{
  auto const v_in = std::vector{ 1, 5, 11, 5 };

  std::cout << "Partition Equal Subset Sum problem (0/1 knapsack pattern)\n";
  std::cout << "time-complexity:  O(N * sum)\n";
  std::cout << "space-complexity: O(sum) auxiliary\n";

  std::cout << "In:         ";
  for (auto const x : v_in)
    std::cout << ' ' << x;
  std::cout << '\n';

  std::cout << "Possible:   " << (impl::can_partition(v_in) ? "true" : "false") << '\n';
}
} // namespace problem
