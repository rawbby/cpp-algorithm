#pragma once

#include <algorithm> // std::max
#include <cstddef>   // std::size_t
#include <iostream>  // std::cout
#include <string>    // std::string
#include <vector>    // std::vector

namespace algorithm {
namespace impl {
/// Finds the length of the longest substring without repeating characters.
inline auto
longest_substring_without_repeating(
  std::string const& s) -> int
{
  auto last_seen = std::vector<int>(128, -1);
  auto max_len   = 0;
  auto left      = 0;

  for (auto right = std::size_t{ 0 }; right < s.size(); ++right) {
    auto const c = static_cast<unsigned char>(s[right]);
    auto const r = static_cast<int>(right);
    if (last_seen[c] >= left) left = last_seen[c] + 1;
    last_seen[c] = r;
    max_len      = std::max(max_len, r - left + 1);
  }
  return max_len;
}
} // namespace impl

inline void
sliding_window()
{
  auto const s_in = std::string{ "abcabcbb" };

  std::cout << "Sliding Window algorithm for longest substring without repeating characters\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(M) where M is charset size\n";

  std::cout << "In:         " << s_in << '\n';

  std::cout << "Result:     " << impl::longest_substring_without_repeating(s_in) << '\n';
}
} // namespace algorithm
