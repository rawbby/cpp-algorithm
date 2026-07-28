#pragma once

#include <cstddef>  // std::size_t
#include <iostream> // std::cout
#include <stack>    // std::stack
#include <vector>   // std::vector

namespace algorithm {
namespace impl {
/// Computes the next greater element for each entry using a monotonic stack.
inline auto
next_greater_elements(
  std::vector<int> const& v) -> std::vector<int>
{
  auto res = std::vector<int>(v.size(), -1);
  auto s   = std::stack<std::size_t>{};

  for (auto i = std::size_t{ 0 }; i < v.size(); ++i) {
    while (!s.empty() && v[s.top()] < v[i]) {
      res[s.top()] = v[i];
      s.pop();
    }
    s.push(i);
  }
  return res;
}
} // namespace impl

inline void
monotonic_stack()
{
  auto const v_in = std::vector{ 2, 1, 2, 4, 3 };

  std::cout << "Monotonic Stack (Next Greater Element)\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(N) auxiliary\n";

  std::cout << "In:         ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << '\n';

  auto const res = impl::next_greater_elements(v_in);

  std::cout << "NextGreater:";
  for (auto const r : res)
    std::cout << ' ' << r;
  std::cout << '\n';
}
} // namespace algorithm
