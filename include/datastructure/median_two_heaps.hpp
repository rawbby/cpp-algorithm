#pragma once

#include <algorithm>  // std::pop_heap, std::push_heap
#include <functional> // std::greater, std::less
#include <iostream>   // std::cout
#include <vector>     // std::vector

namespace datastructure {
namespace impl {
/// Pushes a value onto a binary heap using the given comparator.
inline void
heap_push(
  std::vector<int>& heap,
  int               value,
  auto              cmp)
{
  heap.push_back(value);
  std::push_heap(heap.begin(), heap.end(), cmp);
}

/// Pops and returns the top value from a binary heap using the given comparator.
inline auto
heap_pop(
  std::vector<int>& heap,
  auto              cmp) -> int
{
  std::pop_heap(heap.begin(), heap.end(), cmp);
  auto const top = heap.back();
  heap.pop_back();
  return top;
}

/// Maintains a running median of a stream of numbers using two heaps.
struct median_finder
{
  std::vector<int> max_heap; // lower half, max-heap via std::less
  std::vector<int> min_heap; // upper half, min-heap via std::greater

  /// Adds a number to the two-heap structure, keeping heaps balanced.
  inline void add_number(
    int num)
  {
    if (max_heap.empty() || num <= max_heap.front()) {
      heap_push(max_heap, num, std::less<>{});
    } else {
      heap_push(min_heap, num, std::greater<>{});
    }

    if (max_heap.size() > min_heap.size() + 1) {
      heap_push(min_heap, heap_pop(max_heap, std::less<>{}), std::greater<>{});
    } else if (min_heap.size() > max_heap.size()) {
      heap_push(max_heap, heap_pop(min_heap, std::greater<>{}), std::less<>{});
    }
  }

  /// Returns the current median of all numbers added so far.
  inline auto find_median() const -> double
  {
    if (max_heap.size() > min_heap.size()) return static_cast<double>(max_heap.front());
    return (static_cast<double>(max_heap.front()) + static_cast<double>(min_heap.front())) / 2.0;
  }
};
} // namespace impl

inline void
median_two_heaps()
{
  auto const v_in = std::vector{ 5, 2, 10, 1, 7 };

  std::cout << "Median maintenance algorithm using two heaps\n";
  std::cout << "time-complexity:  O(log N) insert, O(1) median\n";
  std::cout << "space-complexity: O(N) auxiliary\n";

  std::cout << "In:         ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << '\n';

  auto finder = impl::median_finder{};
  for (auto const v : v_in) {
    finder.add_number(v);
    std::cout << "After " << v << ": median = " << finder.find_median() << '\n';
  }
}
} // namespace datastructure
