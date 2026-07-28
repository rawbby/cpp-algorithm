#pragma once

#include <algorithm>  // std::ranges::nth_element
#include <functional> // std::less, std::greater
#include <iostream>   // std::cout
#include <vector>     // std::vector

namespace algorithm {
namespace impl {
/// Partitions the vector in-place so the K smallest elements come first, unsorted.
inline void
top_k_smallest_unsorted_inplace(
  std::vector<int>& v,
  int               k)
{
  std::ranges::nth_element(v, v.begin() + k, std::less<int>{});
}

/// Partitions the vector in-place so the K greatest elements come first, unsorted.
inline void
top_k_greatest_unsorted_inplace(
  std::vector<int>& v,
  int               k)
{
  std::ranges::nth_element(v, v.begin() + k, std::greater<int>{});
}
}

inline void
top_k_unsorted()
{
  constexpr auto k    = int{ 3 };
  auto const     v_in = std::vector{ 3, 1, 2, 5, 6, 1, 1, 9 };

  std::cout << "Top-K (unsorted) algorithm for static input\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(1) - inplace\n";

  std::cout << "In:                  ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << '\n';
  {
    auto v_out = v_in;
    impl::top_k_smallest_unsorted_inplace(v_out, k);
    std::cout << "Auxiliary (smallest):";
    for (auto const v : v_out)
      std::cout << ' ' << v;
    std::cout << '\n';
  }
  {
    auto v_out = v_in;
    impl::top_k_greatest_unsorted_inplace(v_out, k);
    std::cout << "Auxiliary (greatest):";
    for (auto const v : v_out)
      std::cout << ' ' << v;
    std::cout << '\n';
  }
}
}
