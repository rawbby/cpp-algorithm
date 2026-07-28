#pragma once

#include <algorithm> // std::swap
#include <cstddef>   // std::size_t
#include <iostream>  // std::cout
#include <vector>    // std::vector

namespace algorithm {
namespace impl {
/// Finds the smallest missing positive integer using cyclic sort placement.
inline auto
find_first_missing_positive(
  std::vector<int>& nums) -> int
{
  auto const n = nums.size();
  for (auto i = std::size_t{ 0 }; i < n; ++i) {
    while (nums[i] > 0 && static_cast<std::size_t>(nums[i]) <= n && nums[static_cast<std::size_t>(nums[i]) - 1] != nums[i]) {
      std::swap(nums[i], nums[static_cast<std::size_t>(nums[i]) - 1]);
    }
  }

  for (auto i = std::size_t{ 0 }; i < n; ++i) {
    if (nums[i] != static_cast<int>(i) + 1) return static_cast<int>(i) + 1;
  }
  return static_cast<int>(n) + 1;
}
} // namespace impl

inline void
cyclic_sort()
{
  auto const v_in = std::vector{ 3, 4, -1, 1 };

  std::cout << "Cyclic Sort algorithm for first missing positive\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(1) auxiliary\n";

  std::cout << "In:         ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << '\n';

  auto v_work = v_in;
  std::cout << "Result:     " << impl::find_first_missing_positive(v_work) << '\n';
}
} // namespace algorithm
