#pragma once

#include <cstddef>  // std::size_t
#include <iostream> // std::cout
#include <vector>   // std::vector

namespace algorithm {
namespace impl {
/// Computes a boolean sieve of primality for all numbers up to n.
inline auto
sieve(
  int n) -> std::vector<bool>
{
  auto is_prime = std::vector<bool>(static_cast<std::size_t>(n + 1), true);
  if (n >= 0) is_prime[0] = false;
  if (n >= 1) is_prime[1] = false;
  for (auto p = 2; p * p <= n; ++p) {
    if (is_prime[static_cast<std::size_t>(p)]) {
      for (auto i = p * p; i <= n; i += p)
        is_prime[static_cast<std::size_t>(i)] = false;
    }
  }
  return is_prime;
}
} // namespace impl

inline void
sieve_of_eratosthenes()
{
  constexpr auto n = 30;

  std::cout << "Sieve of Eratosthenes for prime generation\n";
  std::cout << "time-complexity:  O(N log log N)\n";
  std::cout << "space-complexity: O(N) auxiliary\n";

  auto const is_prime = impl::sieve(n);

  std::cout << "Primes <=" << n << ":  ";
  for (auto i = 0; i <= n; ++i) {
    if (is_prime[static_cast<std::size_t>(i)]) std::cout << ' ' << i;
  }
  std::cout << '\n';
}
} // namespace algorithm
