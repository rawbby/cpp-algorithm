#pragma once

#include <cstddef>  // std::size_t
#include <iostream> // std::cout
#include <vector>   // std::vector

namespace problem {
namespace impl {
/// returns a callable that maps 2D row/column coordinates to a flat buffer index
auto
island_view2d(
  auto&       buffer,
  std::size_t cols)
{
  return [&buffer, cols](std::size_t r, std::size_t c) -> decltype(auto) { return buffer[r * cols + c]; };
}

// adapts the graph BFS/DFS pattern to a grid-based flood fill
inline void
flood_fill(
  std::vector<int>& grid,
  std::size_t       rows,
  std::size_t       cols,
  std::size_t       r,
  std::size_t       c)
{
  auto const cell = island_view2d(grid, cols);
  if (r >= rows || c >= cols || cell(r, c) == 0) return;
  cell(r, c) = 0;
  if (r > 0) flood_fill(grid, rows, cols, r - 1, c);
  flood_fill(grid, rows, cols, r + 1, c);
  if (c > 0) flood_fill(grid, rows, cols, r, c - 1);
  flood_fill(grid, rows, cols, r, c + 1);
}

/// counts the number of connected land islands in a grid using flood fill
inline auto
count_islands(
  std::vector<int> grid,
  std::size_t      rows,
  std::size_t      cols) -> int
{
  if (grid.empty()) return 0;
  auto const cell  = island_view2d(grid, cols);
  auto       count = 0;
  for (auto r = std::size_t{ 0 }; r < rows; ++r) {
    for (auto c = std::size_t{ 0 }; c < cols; ++c) {
      if (cell(r, c) == 1) {
        ++count;
        flood_fill(grid, rows, cols, r, c);
      }
    }
  }
  return count;
}
} // namespace impl

inline void
number_of_islands()
{
  constexpr auto rows = std::size_t{ 4 };
  constexpr auto cols = std::size_t{ 5 };
  // clang-format off
  auto const grid = std::vector<int>{ 1, 1, 0, 0, 0,
                                      1, 1, 0, 0, 0,
                                      0, 0, 1, 0, 0,
                                      0, 0, 0, 1, 1 };
  // clang-format on

  std::cout << "Number of Islands problem (grid flood fill pattern)\n";
  std::cout << "time-complexity:  O(R * C)\n";
  std::cout << "space-complexity: O(R * C) recursion stack\n";

  std::cout << "In (grid):\n";
  auto const cell = impl::island_view2d(grid, cols);
  for (auto r = std::size_t{ 0 }; r < rows; ++r) {
    std::cout << "  ";
    for (auto c = std::size_t{ 0 }; c < cols; ++c)
      std::cout << ' ' << cell(r, c);
    std::cout << '\n';
  }

  std::cout << "Result:     " << impl::count_islands(grid, rows, cols) << " islands\n";
}
} // namespace problem
