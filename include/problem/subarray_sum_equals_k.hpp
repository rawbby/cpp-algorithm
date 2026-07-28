#pragma once

#include <iostream>      // std::cout
#include <unordered_map> // std::unordered_map
#include <vector>        // std::vector

namespace problem {
namespace impl {
// adapts the prefix-sum pattern (algorithm/prefix_sums.hpp): instead of a
// prefix-sum array, keep a running sum and count seen prefix sums in a hash
// map, so `sum - k` lookups count all subarrays ending here that sum to k
inline auto
count_subarrays_with_sum(
  std::vector<int> const& v,
  int                     k) -> int
{
  auto seen = std::unordered_map<int, int>{ { 0, 1 } };
  auto sum  = 0;

  auto count = 0;
  for (auto const x : v) {
    sum += x;
    if (auto const it = seen.find(sum - k); it != seen.end()) count += it->second;
    ++seen[sum];
  }
  return count;
}
} // namespace impl

inline void
subarray_sum_equals_k()
{
  constexpr auto k    = int{ 3 };
  auto const     v_in = std::vector{ 1, 2, 3, -3, 3, 1, 2 };

  std::cout << "Subarray Sum Equals K problem (prefix-sum + hash map pattern)\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(N) auxiliary\n";

  std::cout << "In:         ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << '\n';

  std::cout << "Count(k=" << k << "): " << impl::count_subarrays_with_sum(v_in, k) << '\n';
}
} // namespace problem
