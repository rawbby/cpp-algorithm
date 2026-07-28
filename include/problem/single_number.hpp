#pragma once

#include <cstddef>  // std::size_t
#include <iostream> // std::cout
#include <vector>   // std::vector

namespace problem {
namespace impl {
/// finds the element that appears once in a vector where all others appear twice, using XOR
inline auto
find_single_number(
  std::vector<int> const& v) -> int
{
  auto res = 0;
  for (auto const x : v)
    res ^= x;
  return res;
}

/// computes the number of set bits for every integer from 0 to n using DP
inline auto
count_bits_up_to(
  int n) -> std::vector<int>
{
  auto bits = std::vector(static_cast<std::size_t>(n + 1), 0);
  for (auto i = 1; i <= n; ++i) {
    auto const idx  = static_cast<std::size_t>(i);
    auto const prev = static_cast<std::size_t>(i >> 1);
    bits[idx]       = bits[prev] + (i & 1);
  }
  return bits;
}
} // namespace impl

inline void
single_number()
{
  auto const v_in = std::vector{ 4, 1, 2, 1, 2 };

  std::cout << "Single Number (XOR) and Count Bits (DP)\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(1) for XOR, O(N) for bits\n";

  std::cout << "In (XOR):   ";
  for (auto const x : v_in)
    std::cout << ' ' << x;
  std::cout << '\n';
  std::cout << "Unique:     " << impl::find_single_number(v_in) << '\n';

  constexpr auto n    = 15;
  auto const     bits = impl::count_bits_up_to(n);
  std::cout << "Bits (0..15):";
  for (auto const b : bits)
    std::cout << ' ' << b;
  std::cout << '\n';
}
} // namespace problem
