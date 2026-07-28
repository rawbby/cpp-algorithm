#pragma once

#include <iostream> // std::cout
#include <queue>    // std::queue
#include <vector>   // std::vector

namespace algorithm {
namespace impl {
/// Computes a topological ordering of the graph vertices using Kahn's algorithm.
inline auto
kahn_topological_sort(
  std::size_t                                n,
  std::vector<std::pair<std::size_t,
                        std::size_t>> const& edges) -> std::vector<std::size_t>
{
  auto adj       = std::vector<std::vector<std::size_t>>(n);
  auto in_degree = std::vector<std::size_t>(n, 0);
  for (auto const& [u, v] : edges) {
    adj[u].push_back(v);
    ++in_degree[v];
  }

  auto q = std::queue<std::size_t>{};
  for (auto i = std::size_t{ 0 }; i < n; ++i) {
    if (in_degree[i] == 0) q.push(i);
  }

  auto result = std::vector<std::size_t>{};
  while (!q.empty()) {
    auto const u = q.front();
    q.pop();
    result.push_back(u);

    for (auto const v : adj[u]) {
      if (--in_degree[v] == 0) q.push(v);
    }
  }

  return result.size() == n ? result : std::vector<std::size_t>{};
}
} // namespace impl

inline void
topological_sort()
{
  constexpr auto n     = std::size_t{ 6 };
  auto const     edges = std::vector<std::pair<std::size_t, std::size_t>>{ { 5, 2 }, { 5, 0 }, { 4, 0 }, { 4, 1 }, { 2, 3 }, { 3, 1 } };

  std::cout << "Topological Sort algorithm (Kahn's algorithm)\n";
  std::cout << "time-complexity:  O(V + E)\n";
  std::cout << "space-complexity: O(V + E) auxiliary\n";

  std::cout << "In (edges): ";
  for (auto const& [u, v] : edges)
    std::cout << " (" << u << ',' << v << ')';
  std::cout << '\n';

  auto const result = impl::kahn_topological_sort(n, edges);

  std::cout << "Result:     ";
  if (result.empty()) {
    std::cout << "Cycle detected or no sort possible\n";
  } else {
    for (auto const v : result)
      std::cout << ' ' << v;
    std::cout << '\n';
  }
}
} // namespace algorithm
