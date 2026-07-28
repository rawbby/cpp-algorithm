#pragma once

#include <cstddef>       // std::size_t
#include <iostream>      // std::cout
#include <unordered_map> // std::unordered_map
#include <utility>       // std::pair
#include <vector>        // std::vector

namespace problem {
namespace impl {
// adapts the hash-map lookup pattern: for each element, check if `target - x`
// has been seen before; if so, a pair is found. This is a common pattern
// for O(N) search problems
inline auto
find_two_sum(
  std::vector<int> const& v,
  int                     target) -> std::pair<int,
                           int>
{
  auto seen = std::unordered_map<int, int>{};
  for (auto i = std::size_t{ 0 }; i < v.size(); ++i) {
    if (auto const it = seen.find(target - v[i]); it != seen.end()) return { it->second, static_cast<int>(i) };
    seen[v[i]] = static_cast<int>(i);
  }
  return { -1, -1 };
}
} // namespace impl

inline void
two_sum()
{
  constexpr auto target = int{ 9 };
  auto const     v_in   = std::vector{ 2, 7, 11, 15 };

  std::cout << "Two Sum problem (hash map pattern)\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(N) auxiliary\n";

  std::cout << "In:         ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << '\n';

  auto const [i, j] = impl::find_two_sum(v_in, target);
  std::cout << "Result(target=" << target << "): indices " << i << " and " << j << '\n';
}
} // namespace problem
