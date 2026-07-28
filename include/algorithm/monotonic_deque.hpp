#pragma once

#include <cstddef>  // std::size_t
#include <deque>    // std::deque
#include <iostream> // std::cout
#include <vector>   // std::vector

namespace algorithm {
namespace impl {
/// Computes the maximum of every sliding window of size k using a monotonic deque.
inline auto
sliding_window_maximum(
  std::vector<int> const& v,
  std::size_t             k) -> std::vector<int>
{
  auto res = std::vector<int>{};
  auto dq  = std::deque<std::size_t>{};

  for (auto i = std::size_t{ 0 }; i < v.size(); ++i) {
    if (!dq.empty() && dq.front() + k == i) dq.pop_front();
    while (!dq.empty() && v[dq.back()] < v[i])
      dq.pop_back();
    dq.push_back(i);
    if (i + 1 >= k) res.push_back(v[dq.front()]);
  }
  return res;
}
} // namespace impl

inline void
monotonic_deque()
{
  auto const v_in = std::vector{ 1, 3, -1, -3, 5, 3, 6, 7 };
  auto const k    = std::size_t{ 3 };

  std::cout << "Monotonic Deque (Sliding Window Maximum)\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(K) auxiliary\n";

  std::cout << "In:         ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << '\n';

  auto const res = impl::sliding_window_maximum(v_in, k);

  std::cout << "Max (k=" << k << "):  ";
  for (auto const r : res)
    std::cout << ' ' << r;
  std::cout << '\n';
}
} // namespace algorithm
