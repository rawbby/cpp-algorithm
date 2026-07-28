#pragma once

#include <algorithm> // std::max
#include <iostream>  // std::cout
#include <vector>    // std::vector

namespace algorithm {
namespace impl {
/// Computes the maximum subarray sum using Kadane's algorithm.
inline auto
max_subarray_sum(
  std::vector<int> const& v) -> int
{
  if (v.empty()) return 0;

  auto max_so_far      = v[0];
  auto max_ending_here = v[0];

  for (auto i = std::size_t{ 1 }; i < v.size(); ++i) {
    max_ending_here = std::max(v[i], max_ending_here + v[i]);
    max_so_far      = std::max(max_so_far, max_ending_here);
  }
  return max_so_far;
}
} // namespace impl

inline void
kadane()
{
  auto const v_in = std::vector{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };

  std::cout << "Kadane's algorithm for maximum subarray sum\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(1)\n";

  std::cout << "In:         ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << '\n';

  std::cout << "Max Sum:    " << impl::max_subarray_sum(v_in) << '\n';
}
} // namespace algorithm
