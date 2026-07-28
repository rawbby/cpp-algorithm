#pragma once

#include <algorithm>     // std::max
#include <iostream>      // std::cout
#include <unordered_set> // std::unordered_set
#include <vector>        // std::vector

namespace problem {
namespace impl {
/// Finds the length of the longest consecutive integer sequence in the vector.
inline auto
find_longest_consecutive(
  std::vector<int> const& v) -> int
{
  auto const s       = std::unordered_set<int>(v.begin(), v.end());
  auto       max_len = 0;

  for (auto const x : s) {
    if (s.find(x - 1) == s.end()) {
      auto curr_x   = x;
      auto curr_len = 1;
      while (s.find(curr_x + 1) != s.end()) {
        curr_x++;
        curr_len++;
      }
      max_len = std::max(max_len, curr_len);
    }
  }
  return max_len;
}
} // namespace impl

inline void
longest_consecutive_sequence()
{
  auto const v_in = std::vector{ 100, 4, 200, 1, 3, 2 };

  std::cout << "Longest Consecutive Sequence problem (hash set start-of-run pattern)\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(N) auxiliary\n";

  std::cout << "In:         ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << '\n';

  std::cout << "Result:     " << impl::find_longest_consecutive(v_in) << '\n';
}
} // namespace problem
