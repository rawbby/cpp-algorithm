#pragma once

#include <cstddef>  // std::size_t
#include <iostream> // std::cout
#include <vector>   // std::vector

namespace datastructure {
namespace impl {
/// Applies a delta update to the element at index i in the Fenwick tree.
inline void
fenwick_update(
  std::vector<int>& tree,
  std::size_t       i,
  int               delta)
{
  for (; i < tree.size(); i += i & -i)
    tree[i] += delta;
}

/// Builds a Fenwick tree from the input vector.
inline auto
build_fenwick_tree(
  std::vector<int> const& v) -> std::vector<int>
{
  auto const n    = v.size();
  auto       tree = std::vector(n + 1, 0);
  for (std::size_t i = 0; i < n; ++i)
    tree[i + 1] = v[i];
  for (std::size_t i = 1; i <= n; ++i) {
    auto const p = i + (i & -i);
    if (p <= n) tree[p] += tree[i];
  }
  return tree;
}

/// Queries the prefix sum of the first i elements in the Fenwick tree.
inline auto
fenwick_query(
  std::vector<int> const& tree,
  std::size_t             i) -> int
{
  auto sum = 0;
  for (; i > 0; i -= i & -i)
    sum += tree[i];
  return sum;
}

/// Queries the sum of the range [l, r] using the Fenwick tree.
inline auto
fenwick_query(
  std::vector<int> const& tree,
  std::size_t             l,
  std::size_t             r) -> int
{
  return fenwick_query(tree, r + 1) - fenwick_query(tree, l);
}
}

inline void
fenwick_tree()
{
  auto const v_in = std::vector{ 1, 2, 3, 4, 5, 6, 7, 8 };

  std::cout << "Fenwick Tree algorithm for dynamic range sums\n";
  std::cout << "time-complexity:  O(N) build, O(log N) query/update\n";
  std::cout << "space-complexity: O(N) auxiliary\n";

  std::cout << "In:         ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << '\n';

  auto tree = impl::build_fenwick_tree(v_in);

  std::cout << "Auxiliary:  ";
  for (auto const v : tree)
    std::cout << ' ' << v;
  std::cout << '\n';

  std::cout << "Query(2..5): " << impl::fenwick_query(tree, 2, 5) << '\n';

  std::cout << "Update(4, 10)\n";
  impl::fenwick_update(tree, 4, 10);

  std::cout << "Query(2..5): " << impl::fenwick_query(tree, 2, 5) << '\n';
}
}
