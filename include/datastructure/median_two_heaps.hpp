#pragma once

#include <algorithm>  // std::pop_heap, std::push_heap
#include <functional> // std::greater, std::less
#include <iostream>   // std::cout
#include <vector>     // std::vector

namespace datastructure {
namespace impl {

inline auto
build_median_of_two_heaps() -> std::pair<std::vector<int>,
                                         std::vector<int>>
{
  std::vector<int> max_heap; // lower half, max-heap via std::less
  std::vector<int> min_heap; // upper half, min-heap via std::greater
  return { std::move(max_heap), std::move(min_heap) };
}

/// Adds a number to the two-heap structure, keeping heaps balanced.
inline auto
push_median_of_two_heaps(
  std::vector<int>& max_heap,
  std::vector<int>& min_heap,
  int               num)
{
  // push to the right heap
  if (max_heap.empty() || num <= max_heap.front()) {
    max_heap.push_back(num);
    std::ranges::push_heap(max_heap, std::less<int>{});
  } else {
    min_heap.push_back(num);
    std::ranges::push_heap(min_heap, std::greater<int>{});
  }

  // ensure balance
  if (max_heap.size() > min_heap.size() + 1) {
    // move max_heap top to min_heap
    std::ranges::pop_heap(max_heap, std::less<int>{});
    min_heap.push_back(max_heap.back());
    max_heap.pop_back();
    std::ranges::push_heap(min_heap, std::greater<int>{});
  } else if (min_heap.size() > max_heap.size()) {
    // move min_heap top to max_heap
    std::ranges::pop_heap(min_heap, std::greater<int>{});
    max_heap.push_back(min_heap.back());
    min_heap.pop_back();
    std::ranges::push_heap(max_heap, std::less<int>{});
  }
}

/// Returns the current median of all numbers added so far.
inline auto
find_median_of_two_heaps(
  std::vector<int> const& max_heap,
  std::vector<int> const& min_heap) -> double
{
  if (max_heap.size() > min_heap.size()) return static_cast<double>(max_heap.front());
  return (static_cast<double>(max_heap.front()) + static_cast<double>(min_heap.front())) / 2.0;
}
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

  auto [max_heap, min_heap] = impl::build_median_of_two_heaps();
  for (auto const v : v_in) {
    impl::push_median_of_two_heaps(max_heap, min_heap, v);
    std::cout << "After " << v << ": median = " << impl::find_median_of_two_heaps(max_heap, min_heap) << '\n';
  }
}
} // namespace datastructure
