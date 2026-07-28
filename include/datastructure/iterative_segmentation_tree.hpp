#pragma once

#include <algorithm> // std::ranges::copy, std::min
#include <cstddef>   // std::size_t
#include <iostream>  // std::cout
#include <limits>    // std::numeric_limits
#include <vector>    // std::vector

namespace datastructure {
namespace impl {
/// Builds an iterative segment tree for range minimum queries.
inline auto
build_segmentation_tree(
  std::vector<int> const& v) -> std::vector<int>
{
  using diff_t = std::vector<int>::difference_type;

  auto const n    = v.size();
  auto       tree = std::vector(2 * n, 0);

  std::ranges::copy(v, tree.begin() + static_cast<diff_t>(n));
  for (std::size_t i = n - 1; i > 0; --i)
    tree[i] = std::min(tree[i << 1], tree[i << 1 | 1]);

  return tree;
}

/// Updates the value at position p in the segment tree.
inline void
update_segmentation_tree(
  std::vector<int>& tree,
  std::size_t       p,
  int               value)
{
  auto const n = tree.size() / 2;
  for (tree[p += n] = value; p > 1; p >>= 1)
    tree[p >> 1] = std::min(tree[p], tree[p ^ 1]);
}

/// Queries the minimum value in the range [l, r] of the segment tree.
inline auto
query_segmentation_tree(
  std::vector<int> const& tree,
  std::size_t             l,
  std::size_t             r) -> int
{
  auto const n = tree.size() / 2;

  auto min = std::numeric_limits<int>::max();
  for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) min = std::min(min, tree[l++]);
    if (r & 1) min = std::min(min, tree[--r]);
  }
  return min;
}
}

inline void
iterative_segmentation_tree()
{
  auto const v_in = std::vector{ 9, 2, 7, 3, 1, 8, 4 };

  std::cout << "Iterative Seg Tree algorithm for dynamic range min\n";
  std::cout << "time-complexity:  O(N) build, O(log N) query/update\n";
  std::cout << "space-complexity: O(N) auxiliary\n";

  std::cout << "In:         ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << '\n';

  auto tree = impl::build_segmentation_tree(v_in);

  std::cout << "Auxiliary:  ";
  for (auto const v : tree)
    std::cout << ' ' << v;
  std::cout << '\n';

  std::cout << "Query(1..4): " << impl::query_segmentation_tree(tree, 1, 4) << '\n';
  std::cout << "Query(2..6): " << impl::query_segmentation_tree(tree, 2, 6) << '\n';
  std::cout << "Query(3..3): " << impl::query_segmentation_tree(tree, 3, 3) << '\n';

  std::cout << "Update(4, -5)\n";
  impl::update_segmentation_tree(tree, 4, -5);

  std::cout << "Auxiliary:  ";
  for (auto const v : tree)
    std::cout << ' ' << v;
  std::cout << '\n';

  std::cout << "Query(1..4): " << impl::query_segmentation_tree(tree, 1, 4) << '\n';
  std::cout << "Query(2..6): " << impl::query_segmentation_tree(tree, 2, 6) << '\n';
  std::cout << "Query(3..3): " << impl::query_segmentation_tree(tree, 3, 3) << '\n';
}
}
