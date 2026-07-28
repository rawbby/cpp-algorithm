#pragma once

#include <algorithm> // std::ranges::copy, std::min
#include <bit>       // std::bit_width
#include <cstddef>   // std::size_t
#include <iostream>  // std::cout
#include <vector>    // std::vector

namespace datastructure {
namespace impl {
/// Returns a function that maps 2D (row, col) coordinates to a flat buffer index.
auto
transpose2d(
  auto&       buffer,
  std::size_t cols)
{
  return [&buffer, cols](std::size_t c, std::size_t r) -> decltype(auto) { return buffer[r * cols + c]; };
}

/// Builds a sparse table for O(1) range-minimum queries over the input vector.
inline auto
build_sparse_table(
  std::vector<int> const& v) -> std::vector<int>
{
  if (v.empty()) return {};

  constexpr auto one    = std::size_t{ 1 };
  auto const     n      = v.size();
  auto const     k      = static_cast<std::size_t>(std::bit_width(n));
  auto           buffer = std::vector(k * n, 0);
  auto const     st     = transpose2d(buffer, n);

  std::ranges::copy(v, buffer.begin());
  for (std::size_t j = 1; j < k; j++)
    for (std::size_t i = 0; i + (one << j) <= n; i++)
      st(i, j) = std::min(st(i, j - one), st(i + (one << (j - one)), j - one));

  return buffer;
}

/// Queries the minimum value in range [l, r] using the precomputed sparse table.
inline auto
query_sparse_table(
  std::vector<int> const& buffer,
  std::size_t             n,
  std::size_t             l,
  std::size_t             r) -> int
{
  constexpr auto one = std::size_t{ 1 };
  auto const     j   = static_cast<std::size_t>(std::bit_width(r - l + one)) - one;
  auto const     st  = transpose2d(buffer, n);
  return std::min(st(l, j), st(r - (one << j) + one, j));
}
}

inline void
sparse_table()
{
  auto const v_in = std::vector{ 9, 2, 7, 3, 1, 8, 4, 6 };
  auto const n    = v_in.size();
  auto const k    = static_cast<std::size_t>(std::bit_width(n));

  std::cout << "Sparse Table algorithm for static range min\n";
  std::cout << "time-complexity:  O(N log N) build, O(1) query\n";
  std::cout << "space-complexity: O(N log N) auxiliary\n";

  std::cout << "In:         ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << '\n';

  auto const buffer = impl::build_sparse_table(v_in);

  std::cout << "Auxiliary:  ";
  for (std::size_t j = 0; j < k; ++j) {
    for (std::size_t i = 0; i < n; ++i)
      std::cout << ' ' << impl::transpose2d(buffer, n)(i, j);
    if (j < k - 1) std::cout << "\n            ";
  }
  std::cout << '\n';

  std::cout << "Query(1..4): " << impl::query_sparse_table(buffer, n, 1, 4) << '\n';
  std::cout << "Query(2..6): " << impl::query_sparse_table(buffer, n, 2, 6) << '\n';
  std::cout << "Query(3..3): " << impl::query_sparse_table(buffer, n, 3, 3) << '\n';
}
}
