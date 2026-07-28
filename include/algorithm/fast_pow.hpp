#pragma once

#include <iostream> // std::cout
#include <utility>  // std::swap

namespace algorithm {
namespace impl {
/// Computes base raised to exp using binary exponentiation.
inline auto
power(
  long long base,
  long long exp) -> long long
{
  auto res = 1LL;
  while (exp > 0) {
    if (exp % 2 == 1) res *= base;
    base *= base;
    exp /= 2;
  }
  return res;
}

/// Computes the greatest common divisor of two integers using the Euclidean algorithm.
inline auto
gcd(
  int a,
  int b) -> int
{
  while (b != 0) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}
} // namespace impl

inline void
fast_pow()
{
  constexpr auto b_in = 2LL;
  constexpr auto e_in = 10LL;

  std::cout << "Binary Exponentiation and Euclidean GCD\n";
  std::cout << "time-complexity:  O(log N)\n";
  std::cout << "space-complexity: O(1)\n";

  std::cout << "Pow(" << b_in << ", " << e_in << "):  " << impl::power(b_in, e_in) << '\n';

  constexpr auto a = 48;
  constexpr auto b = 18;
  std::cout << "GCD(" << a << ", " << b << "):   " << impl::gcd(a, b) << '\n';
}
} // namespace algorithm
