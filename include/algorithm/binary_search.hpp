#pragma once

#include <algorithm> // std::max_element
#include <cstddef>   // std::size_t
#include <iostream>  // std::cout
#include <vector>    // std::vector

namespace algorithm {
namespace impl {
/// Finds the index of the first element not less than target using binary search.
inline auto
lower_bound(
  std::vector<int> const& v,
  int                     target) -> std::size_t
{
  auto beg = std::size_t{ 0 };
  auto end = v.size();
  while (beg < end) {
    auto const mid = beg + (end - beg) / 2;
    if (v[mid] < target) beg = mid + 1;
    else end = mid;
  }
  return beg;
}

/// Finds the minimum eating speed allowing all piles to be consumed within h hours via binary search on the answer.
inline auto
min_eating_speed(
  std::vector<int> const& piles,
  int                     h) -> int
{
  auto low  = 1;
  auto high = *std::ranges::max_element(piles);
  while (low < high) {
    auto const mid = low + (high - low) / 2;
    auto       hrs = 0;
    for (auto const p : piles)
      hrs += (p + mid - 1) / mid;
    if (hrs <= h) high = mid;
    else low = mid + 1;
  }
  return low;
}
} // namespace impl

inline void
binary_search()
{
  auto const v_in  = std::vector{ 1, 3, 3, 5, 7 };
  auto const piles = std::vector{ 3, 6, 7, 11 };
  auto const h     = 8;

  std::cout << "Binary Search (Lower Bound & Search on Answer Space)\n";
  std::cout << "time-complexity:  O(log N) search, O(N log M) answer space\n";
  std::cout << "space-complexity: O(1) auxiliary\n";

  std::cout << "In:         ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << "\nLowerBound(3): " << impl::lower_bound(v_in, 3) << " (index)\n";

  std::cout << "Piles:      ";
  for (auto const p : piles)
    std::cout << ' ' << p;
  std::cout << "\nMin Speed:     " << impl::min_eating_speed(piles, h) << " (for h=" << h << ")\n";
}
} // namespace algorithm
