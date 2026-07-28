#pragma once

#include <cstddef>  // std::size_t
#include <iostream> // std::cout
#include <numeric>  // std::inclusive_scan
#include <vector>   // std::vector

namespace algorithm {
namespace impl {
/// Creates a zero-initialized difference array of the given size.
inline auto
build_difference_array(
  std::size_t n) -> std::vector<int>
{
  return std::vector(n + 1, 0);
}

/// Applies a delta to a range [l, r] in the difference array in O(1).
inline void
update_difference_array(
  std::vector<int>& diff,
  std::size_t       l,
  std::size_t       r,
  int               delta)
{
  diff[l] += delta;
  diff[r + 1] -= delta;
}

/// Reconstructs the original array from the difference array via prefix sum.
inline auto
materialize_difference_array(
  std::vector<int> const& diff) -> std::vector<int>
{
  auto v = std::vector(diff.size() - 1, 0);
  std::inclusive_scan(diff.begin(), diff.end() - 1, v.begin());
  return v;
}
}

inline void
difference_array()
{
  constexpr auto n = std::size_t{ 8 };

  std::cout << "Difference Array algorithm for offline range updates\n";
  std::cout << "time-complexity:  O(1) range update, O(N) materialize\n";
  std::cout << "space-complexity: O(N) auxiliary\n";

  auto diff = impl::build_difference_array(n);

  std::cout << "Update(1..4, +2)\n";
  impl::update_difference_array(diff, 1, 4, 2);
  std::cout << "Update(3..6, +5)\n";
  impl::update_difference_array(diff, 3, 6, 5);
  std::cout << "Update(0..2, -1)\n";
  impl::update_difference_array(diff, 0, 2, -1);

  std::cout << "Auxiliary:  ";
  for (auto const v : diff)
    std::cout << ' ' << v;
  std::cout << '\n';

  std::cout << "Out:        ";
  for (auto const v : impl::materialize_difference_array(diff))
    std::cout << ' ' << v;
  std::cout << '\n';
}
}
