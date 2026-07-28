#pragma once

#include <cstddef>  // std::size_t
#include <iostream> // std::cout
#include <vector>   // std::vector

namespace problem {
namespace impl {
// adapts the backtracking pattern (algorithm/backtracking.hpp): uses
// constraint satisfaction to count valid queen placements on an NxN board
inline auto
solve_n_queens(
  int                row,
  int                n,
  std::vector<bool>& cols,
  std::vector<bool>& diag1,
  std::vector<bool>& diag2) -> int
{
  if (row == n) return 1;
  auto count = 0;
  for (auto col = 0; col < n; ++col) {
    auto const d1 = static_cast<std::size_t>(row - col + n - 1);
    auto const d2 = static_cast<std::size_t>(row + col);
    auto const c  = static_cast<std::size_t>(col);
    if (cols[c] || diag1[d1] || diag2[d2]) continue;

    cols[c] = diag1[d1] = diag2[d2] = true;
    count += solve_n_queens(row + 1, n, cols, diag1, diag2);
    cols[c] = diag1[d1] = diag2[d2] = false;
  }
  return count;
}
} // namespace impl

inline void
n_queens()
{
  constexpr auto n = int{ 6 };

  std::cout << "N-Queens problem (backtracking constraint search)\n";
  std::cout << "time-complexity:  O(N!)\n";
  std::cout << "space-complexity: O(N) auxiliary\n";

  auto const sz   = static_cast<std::size_t>(n);
  auto const d_sz = static_cast<std::size_t>(2 * n - 1);
  auto       cols = std::vector<bool>(sz, false);
  auto       d1   = std::vector<bool>(d_sz, false);
  auto       d2   = std::vector<bool>(d_sz, false);

  std::cout << "In (N):     " << n << '\n';
  std::cout << "Solutions:  " << impl::solve_n_queens(0, n, cols, d1, d2) << '\n';
}
} // namespace problem
