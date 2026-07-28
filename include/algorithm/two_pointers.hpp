#pragma once

#include <cstddef>  // std::size_t
#include <iostream> // std::cout
#include <utility>  // std::pair
#include <vector>   // std::vector

namespace algorithm {
namespace impl {
/// Finds a pair of indices in a sorted vector whose values sum to the target.
inline auto
find_pair_with_target_sum(
  std::vector<int> const& v,
  int                     target) -> std::pair<std::size_t,
                           std::size_t>
{
  auto left  = std::size_t{ 0 };
  auto right = v.size() - 1;

  while (left < right) {
    auto const current_sum = v[left] + v[right];
    if (current_sum == target) return { left, right };
    if (current_sum < target) ++left;
    else --right;
  }
  return { 0, 0 };
}
} // namespace impl

inline void
two_pointers()
{
  constexpr auto target = int{ 9 };
  auto const     v_in   = std::vector{ 2, 3, 4, 5, 8, 11, 15 };

  std::cout << "Two Pointers algorithm for pair with target sum (Two Sum II)\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(1)\n";

  std::cout << "In:         ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << '\n';

  auto const [i, j] = impl::find_pair_with_target_sum(v_in, target);
  std::cout << "Result(target=" << target << "): indices " << i << " and " << j << " (values " << v_in[i] << ", " << v_in[j] << ")\n";
}
} // namespace algorithm
