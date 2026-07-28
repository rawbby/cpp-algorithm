#pragma once

#include <algorithm> // std::min
#include <iostream>  // std::cout
#include <vector>    // std::vector

namespace problem {
namespace impl {
// adapts the 1D DP pattern: let dp[i] be the minimum coins for amount i,
// where dp[i] = min(dp[i], dp[i - coin] + 1) for each coin in coins;
// initializing dp[0] = 0 and others to amount + 1 allows finding the min
/// Computes the minimum number of coins needed to make up the given amount.
inline auto
min_coins_for_amount(
  std::vector<int> const& coins,
  int                     amount) -> int
{
  auto const n  = static_cast<std::size_t>(amount);
  auto       dp = std::vector<int>(n + 1, amount + 1);

  dp[0] = 0;
  for (auto const coin : coins) {
    for (auto i = coin; i <= amount; ++i) {
      auto const idx  = static_cast<std::size_t>(i);
      auto const prev = static_cast<std::size_t>(i - coin);
      if (dp[prev] != amount + 1) dp[idx] = std::min(dp[idx], dp[prev] + 1);
    }
  }

  return dp[n] > amount ? -1 : dp[n];
}
} // namespace impl

inline void
coin_change()
{
  auto const     coins = std::vector{ 1, 2, 5 };
  constexpr auto amt   = int{ 11 };

  std::cout << "Coin Change problem (1D DP min coins pattern)\n";
  std::cout << "time-complexity:  O(amount * coins)\n";
  std::cout << "space-complexity: O(amount) auxiliary\n";

  std::cout << "In:         ";
  for (auto const c : coins)
    std::cout << ' ' << c;
  std::cout << " (amount: " << amt << ")\n";

  std::cout << "Min coins:  " << impl::min_coins_for_amount(coins, amt) << '\n';
}
} // namespace problem
