#pragma once

#include <algorithm>  // std::make_heap, std::pop_heap, std::push_heap
#include <functional> // std::greater
#include <iostream>   // std::cout
#include <vector>     // std::vector

namespace algorithm {
namespace impl {
/// Represents an element from a specific list, used as a min-heap entry.
struct node
{
  int         val;
  std::size_t list_idx;
  std::size_t element_idx;

  inline auto operator>(
    node const& other) const -> bool
  {
    return val > other.val;
  }
};

/// Merges K sorted vectors into a single sorted vector using a min-heap.
inline auto
k_way_merge_impl(
  std::vector<std::vector<int>> const& lists) -> std::vector<int>
{
  auto result = std::vector<int>{};
  auto heap   = std::vector<node>{}; // min-heap via std::greater

  for (auto i = std::size_t{ 0 }; i < lists.size(); ++i) {
    if (!lists[i].empty()) heap.push_back({ lists[i][0], i, 0 });
  }
  std::make_heap(heap.begin(), heap.end(), std::greater<>{});

  while (!heap.empty()) {
    std::pop_heap(heap.begin(), heap.end(), std::greater<>{});
    auto const [val, l_idx, e_idx] = heap.back();
    heap.pop_back();
    result.push_back(val);

    if (e_idx + 1 < lists[l_idx].size()) {
      heap.push_back({ lists[l_idx][e_idx + 1], l_idx, e_idx + 1 });
      std::push_heap(heap.begin(), heap.end(), std::greater<>{});
    }
  }
  return result;
}
} // namespace impl

inline void
k_way_merge()
{
  auto const lists = std::vector<std::vector<int>>{ { 1, 4, 7 }, { 2, 5, 8 }, { 3, 6, 9 } };

  std::cout << "K-Way Merge algorithm for merging K sorted vectors\n";
  std::cout << "time-complexity:  O(N log K)\n";
  std::cout << "space-complexity: O(N) result, O(K) heap\n";

  std::cout << "In:\n";
  for (auto const& list : lists) {
    std::cout << "  ";
    for (auto const v : list)
      std::cout << ' ' << v;
    std::cout << '\n';
  }

  auto const result = impl::k_way_merge_impl(lists);

  std::cout << "Merged:     ";
  for (auto const v : result)
    std::cout << ' ' << v;
  std::cout << '\n';
}
} // namespace algorithm
