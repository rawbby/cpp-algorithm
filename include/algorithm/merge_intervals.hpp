#pragma once

#include <algorithm> // std::sort, std::max
#include <iostream>  // std::cout
#include <utility>   // std::pair
#include <vector>    // std::vector

namespace algorithm {
namespace impl {
/// Sorts intervals by start and merges any that overlap.
inline auto
merge_overlapping(
  std::vector<std::pair<int,
                        int>> intervals) -> std::vector<std::pair<int,
                                                                  int>>
{
  if (intervals.empty()) return {};

  std::sort(intervals.begin(), intervals.end(), [](auto const& a, auto const& b) { return a.first < b.first; });

  auto merged = std::vector<std::pair<int, int>>{ intervals[0] };
  for (auto i = std::size_t{ 1 }; i < intervals.size(); ++i) {
    if (intervals[i].first <= merged.back().second) merged.back().second = std::max(merged.back().second, intervals[i].second);
    else merged.push_back(intervals[i]);
  }
  return merged;
}
} // namespace impl

inline void
merge_intervals()
{
  auto const v_in = std::vector<std::pair<int, int>>{ { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } };

  std::cout << "Merge Intervals algorithm for overlapping ranges\n";
  std::cout << "time-complexity:  O(N log N)\n";
  std::cout << "space-complexity: O(N) for result\n";

  std::cout << "In:         ";
  for (auto const& p : v_in)
    std::cout << " [" << p.first << "," << p.second << "]";
  std::cout << '\n';

  auto const result = impl::merge_overlapping(v_in);

  std::cout << "Merged:     ";
  for (auto const& p : result)
    std::cout << " [" << p.first << "," << p.second << "]";
  std::cout << '\n';
}
} // namespace algorithm
