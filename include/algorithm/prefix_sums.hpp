#pragma once

#include <cstddef>  // std::size_t
#include <iostream> // std::cout
#include <numeric>  // std::inclusive_scan
#include <vector>   // std::vector

namespace algorithm {
namespace impl {
/// Builds the prefix sums array from the input vector.
inline auto
build_prefix_sums(
  std::vector<int> const& v) -> std::vector<int>
{
  auto prefix_sums = std::vector(v.size() + 1, 0);
  std::inclusive_scan(v.begin(), v.end(), prefix_sums.begin() + 1);
  return prefix_sums;
}

/// Queries the sum of the range [l, r] using precomputed prefix sums.
inline auto
query_range_sum(
  std::vector<int> const& prefix_sums,
  std::size_t             l,
  std::size_t             r) -> int
{
  return prefix_sums[r + 1] - prefix_sums[l];
}
} // namespace impl

inline void
prefix_sums()
{
  auto const v_in = std::vector{ 1, 2, 3, 4, 5, 6, 7, 8 };

  std::cout << "Prefix Sum algorithm for static range sum\n";
  std::cout << "time-complexity:  O(N) build, O(1) query\n";
  std::cout << "space-complexity: O(N) auxiliary\n";

  std::cout << "In:         ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << '\n';

  auto const prefix_sums = impl::build_prefix_sums(v_in);

  std::cout << "Auxiliary:  ";
  for (auto const v : prefix_sums)
    std::cout << ' ' << v;
  std::cout << '\n';

  std::cout << "Query(1..4): " << impl::query_range_sum(prefix_sums, 1, 4) << '\n';
  std::cout << "Query(0..5): " << impl::query_range_sum(prefix_sums, 0, 5) << '\n';
  std::cout << "Query(2..2): " << impl::query_range_sum(prefix_sums, 2, 2) << '\n';
}
} // namespace algorithm
