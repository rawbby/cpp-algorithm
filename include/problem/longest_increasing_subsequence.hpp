#pragma once

#include <algorithm> // std::lower_bound
#include <iostream>  // std::cout
#include <vector>    // std::vector

namespace problem {
namespace impl {
// adapts the patience sorting pattern: tails[i] stores the smallest tail of
// all increasing subsequences of length i + 1; using binary search to
// maintain tails makes the algorithm O(N log N)
inline auto
length_of_lis(
  std::vector<int> const& v) -> int
{
  auto tails = std::vector<int>{};
  for (auto const x : v) {
    if (auto const it = std::lower_bound(tails.begin(), tails.end(), x); it == tails.end()) tails.push_back(x);
    else *it = x;
  }
  return static_cast<int>(tails.size());
}
} // namespace impl

inline void
longest_increasing_subsequence()
{
  auto const v_in = std::vector{ 10, 9, 2, 5, 3, 7, 101, 18 };

  std::cout << "Longest Increasing Subsequence problem (patience sorting pattern)\n";
  std::cout << "time-complexity:  O(N log N)\n";
  std::cout << "space-complexity: O(N) auxiliary\n";

  std::cout << "In:         ";
  for (auto const x : v_in)
    std::cout << ' ' << x;
  std::cout << '\n';

  std::cout << "Length:     " << impl::length_of_lis(v_in) << '\n';
}
} // namespace problem
