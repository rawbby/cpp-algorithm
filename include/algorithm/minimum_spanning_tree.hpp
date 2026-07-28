#pragma once

#include <algorithm> // std::sort
#include <iostream>  // std::cout
#include <numeric>   // std::iota
#include <utility>   // std::swap
#include <vector>    // std::vector

namespace algorithm {
namespace impl {
/// Represents a weighted undirected edge between two vertices.
struct edge
{
  std::size_t u, v;
  int         weight;

  inline auto operator<(
    edge const& other) const -> bool
  {
    return weight < other.weight;
  }
};

/// Builds a minimum spanning tree using Kruskal's algorithm with a disjoint-set union.
inline auto
kruskal_mst(
  std::size_t       n,
  std::vector<edge> edges) -> std::vector<edge>
{
  std::sort(edges.begin(), edges.end());

  auto parent = std::vector<std::size_t>(n);
  std::iota(parent.begin(), parent.end(), std::size_t{ 0 });
  auto size = std::vector<std::size_t>(n, 1);

  auto find = [&](std::size_t x) -> std::size_t {
    while (parent[x] != x)
      x = parent[x] = parent[parent[x]];
    return x;
  };

  auto mst = std::vector<edge>{};
  for (auto const& e : edges) {
    auto root_u = find(e.u);
    auto root_v = find(e.v);
    if (root_u != root_v) {
      if (size[root_u] < size[root_v]) std::swap(root_u, root_v);
      parent[root_v] = root_u;
      size[root_u] += size[root_v];
      mst.push_back(e);
    }
  }
  return mst;
}
} // namespace impl

inline void
minimum_spanning_tree()
{
  constexpr auto n     = std::size_t{ 4 };
  auto const     edges = std::vector<impl::edge>{ { 0, 1, 10 }, { 0, 2, 6 }, { 0, 3, 5 }, { 1, 3, 15 }, { 2, 3, 4 } };

  std::cout << "Minimum Spanning Tree algorithm (Kruskal's with DSU)\n";
  std::cout << "time-complexity:  O(E log E)\n";
  std::cout << "space-complexity: O(V + E) auxiliary\n";

  std::cout << "In (edges): ";
  for (auto const& e : edges)
    std::cout << " (" << e.u << ',' << e.v << ',' << e.weight << ')';
  std::cout << '\n';

  auto const mst = impl::kruskal_mst(n, edges);

  auto total_weight = 0;
  std::cout << "MST edges:  ";
  for (auto const& e : mst) {
    std::cout << " (" << e.u << ',' << e.v << ')';
    total_weight += e.weight;
  }
  std::cout << "\nTotal weight: " << total_weight << '\n';
}
} // namespace algorithm
