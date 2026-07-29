#pragma once

#include <cstddef>  // std::size_t
#include <iostream> // std::cout
#include <numeric>  // std::iota
#include <utility>  // std::swap
#include <vector>   // std::vector

namespace datastructure {
namespace impl {
/// Builds a union-find parent array where each element starts as its own set.
inline auto
build_union_find(
  std::size_t n) -> std::pair<std::vector<std::size_t>,
                              std::vector<std::size_t>>
{
  auto size   = std::vector<std::size_t>(n, 1);
  auto parent = std::vector<std::size_t>(n);
  std::ranges::iota(parent, 0);

  return { std::move(parent), std::move(size) };
}

/// Finds the representative (root) of the set containing x, using path halving.
inline auto
find_union_find(
  std::vector<std::size_t>& parent,
  std::size_t               x) -> std::size_t
{
  while (parent[x] != x)
    x = parent[x] = parent[parent[x]]; // path halving
  return x;
}

/// Unites the sets containing a and b using union by size, returning false if already united.
inline auto
unite_union_find(
  std::vector<std::size_t>& parent,
  std::vector<std::size_t>& size,
  std::size_t               a,
  std::size_t               b) -> bool
{
  a = find_union_find(parent, a);
  b = find_union_find(parent, b);
  if (a == b) return false;

  if (size[a] < size[b]) std::swap(a, b); // union by size
  parent[b] = a;
  size[a] += size[b];
  return true;
}
}

inline void
union_find()
{
  constexpr auto n     = std::size_t{ 7 };
  auto const     edges = std::vector<std::pair<std::size_t, std::size_t>>{
    { 0, 1 }, { 1, 2 }, { 3, 4 }, { 5, 6 }, { 4, 5 }, { 2, 0 },
  };

  std::cout << "Union-Find (DSU) algorithm for dynamic connectivity\n";
  std::cout << "time-complexity:  O(N) build, ~O(1) amortized find/unite\n";
  std::cout << "space-complexity: O(N) auxiliary\n";

  auto [parent, size] = impl::build_union_find(n);

  std::cout << "In (edges): ";
  for (auto const [a, b] : edges)
    std::cout << " (" << a << ", " << b << ')';
  std::cout << '\n';

  for (auto const [a, b] : edges)
    std::cout << "Unite(" << a << ", " << b << "): " << (impl::unite_union_find(parent, size, a, b) ? "merged" : "cycle") << '\n';

  std::cout << "Auxiliary:  ";
  for (auto const p : parent)
    std::cout << ' ' << p;
  std::cout << "\n            ";
  for (auto const s : size)
    std::cout << ' ' << s;
  std::cout << '\n';

  std::cout << "Find(0)==Find(2): " << (impl::find_union_find(parent, 0) == impl::find_union_find(parent, 2)) << '\n';
  std::cout << "Find(0)==Find(3): " << (impl::find_union_find(parent, 0) == impl::find_union_find(parent, 3)) << '\n';
}
}
