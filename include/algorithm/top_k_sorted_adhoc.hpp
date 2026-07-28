#pragma once

#include <algorithm>  // std::ranges::partial_sort
#include <functional> // std::less, std::greater
#include <iostream>   // std::cout
#include <vector>     // std::vector

namespace algorithm {
namespace impl {
/// Partially sorts the vector in-place to place the K smallest elements first.
inline void
top_k_smallest_sorted_adhoc_inplace(
  std::vector<int>& v,
  int               k)
{
  std::ranges::partial_sort(v, v.begin() + k, std::less<int>{});
}

/// Partially sorts the vector in-place to place the K greatest elements first.
inline void
top_k_greatest_sorted_adhoc_inplace(
  std::vector<int>& v,
  int               k)
{
  std::ranges::partial_sort(v, v.begin() + k, std::greater<int>{});
}
}

inline void
top_k_sorted_adhoc()
{
  constexpr auto k    = int{ 3 };
  auto const     v_in = std::vector{ 3, 1, 2, 5, 6, 1, 1, 9 };

  std::cout << "Top-K (sorted-adhoc) algorithm for static input\n";
  std::cout << "time-complexity:  O(N log K)\n";
  std::cout << "space-complexity: O(1) - inplace\n";

  std::cout << "In:                  ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << '\n';
  {
    auto v_out = v_in;
    impl::top_k_smallest_sorted_adhoc_inplace(v_out, k);
    std::cout << "Auxiliary (smallest):";
    for (auto const v : v_out)
      std::cout << ' ' << v;
    std::cout << '\n';
  }
  {
    auto v_out = v_in;
    impl::top_k_greatest_sorted_adhoc_inplace(v_out, k);
    std::cout << "Auxiliary (greatest):";
    for (auto const v : v_out)
      std::cout << ' ' << v;
    std::cout << '\n';
  }
}
}
