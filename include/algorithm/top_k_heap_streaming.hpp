#pragma once

#include <algorithm>  // std::ranges::push_heap, std::ranges::pop_heap
#include <functional> // std::less, std::greater
#include <iostream>   // std::cout
#include <ranges>     // std::views::enumerate
#include <vector>     // std::vector

namespace algorithm {
namespace impl {
/// Maintains the top-K greatest elements seen so far using a min-heap.
inline void
top_k_greatest_heap_streaming(
  std::vector<int>& heap,
  int               k,
  int               v)
{
  if (static_cast<int>(heap.size()) < k) {
    heap.emplace_back(v);
    std::ranges::push_heap(heap, std::greater<int>{});
  } else if (std::greater<int>{}(v, heap.front())) {
    std::ranges::pop_heap(heap, std::greater<int>{});
    heap.back() = v;
    std::ranges::push_heap(heap, std::greater<int>{});
  }
}

/// Maintains the top-K smallest elements seen so far using a max-heap.
inline void
top_k_smallest_heap_streaming(
  std::vector<int>& heap,
  int               k,
  int               v)
{
  if (static_cast<int>(heap.size()) < k) {
    heap.emplace_back(v);
    std::ranges::push_heap(heap, std::less<int>{});
  } else if (std::less<int>{}(v, heap.front())) {
    std::ranges::pop_heap(heap, std::less<int>{});
    heap.back() = v;
    std::ranges::push_heap(heap, std::less<int>{});
  }
}
}

inline void
top_k_heap_streaming()
{
  constexpr auto k        = int{ 3 };
  auto const     v_stream = std::vector{ 3, 1, 2, 5, 6, 1, 1, 9 };

  std::cout << "Top-K (heap-streaming) algorithm for streaming input\n";
  std::cout << "time-complexity:  O(N log K)\n";
  std::cout << "space-complexity: O(K)\n";

  std::cout << "In:                      ";
  for (auto const it : v_stream)
    std::cout << ' ' << it;
  std::cout << '\n';
  {
    std::vector<int> heap;
    for (auto const [i, stream_item] : v_stream | std::views::enumerate) {
      impl::top_k_greatest_heap_streaming(heap, k, stream_item);
      std::cout << "Auxiliary (greatest) (" << i << "):";
      for (auto const heap_item : heap)
        std::cout << ' ' << heap_item;
      std::cout << '\n';
    }
  }
  {
    std::vector<int> heap;
    for (auto const [i, stream_item] : v_stream | std::views::enumerate) {
      impl::top_k_smallest_heap_streaming(heap, k, stream_item);
      std::cout << "Auxiliary (smallest) (" << i << "):";
      for (auto const heap_item : heap)
        std::cout << ' ' << heap_item;
      std::cout << '\n';
    }
  }
}
}
