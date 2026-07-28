#pragma once

#include <algorithm>  // std::pop_heap, std::push_heap
#include <functional> // std::greater
#include <iostream>   // std::cout
#include <limits>     // std::numeric_limits
#include <vector>     // std::vector

namespace algorithm {
namespace impl {
/// Computes shortest distances from a start vertex using Dijkstra's algorithm with a binary heap.
inline auto
dijkstra_impl(
  std::size_t                                     n,
  std::vector<std::vector<std::pair<std::size_t,
                                    int>>> const& adj,
  std::size_t                                     start) -> std::vector<int>
{
  auto dist = std::vector<int>(n, std::numeric_limits<int>::max());
  auto heap = std::vector<std::pair<int, std::size_t>>{}; // min-heap via std::greater

  dist[start] = 0;
  heap.push_back({ 0, start });

  while (!heap.empty()) {
    std::pop_heap(heap.begin(), heap.end(), std::greater<>{});
    auto const [d, u] = heap.back();
    heap.pop_back();

    if (d > dist[u]) continue;

    for (auto const& [v, weight] : adj[u]) {
      if (dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        heap.push_back({ dist[v], v });
        std::push_heap(heap.begin(), heap.end(), std::greater<>{});
      }
    }
  }
  return dist;
}
} // namespace impl

inline void
dijkstra()
{
  constexpr auto n   = std::size_t{ 5 };
  auto const     adj = std::vector<std::vector<std::pair<std::size_t, int>>>{
    { { 1, 10 }, { 4, 5 } }, { { 2, 1 }, { 4, 2 } }, { { 3, 4 } }, { { 0, 7 }, { 2, 6 } }, { { 1, 3 }, { 2, 9 }, { 3, 2 } }
  };

  std::cout << "Dijkstra's Shortest Path algorithm\n";
  std::cout << "time-complexity:  O(E log V)\n";
  std::cout << "space-complexity: O(V + E) auxiliary\n";

  auto const dists = impl::dijkstra_impl(n, adj, 0);

  std::cout << "In (adj list with weights):\n";
  for (auto i = std::size_t{ 0 }; i < n; ++i) {
    std::cout << "  " << i << ":";
    for (auto const& [v, w] : adj[i])
      std::cout << " (" << v << ',' << w << ')';
    std::cout << '\n';
  }

  std::cout << "Shortest distances from 0:\n";
  for (auto i = std::size_t{ 0 }; i < n; ++i) {
    std::cout << "  0 -> " << i << ": " << dists[i] << '\n';
  }
}
} // namespace algorithm
