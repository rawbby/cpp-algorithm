#pragma once

#include <iostream> // std::cout
#include <utility>  // std::swap
#include <vector>   // std::vector

namespace algorithm {
namespace impl {
/// Recursively generates all subsets of a vector via include/exclude backtracking.
inline void
generate_subsets(
  std::vector<int>&              curr,
  std::vector<int> const&        v,
  std::size_t                    idx,
  std::vector<std::vector<int>>& res)
{
  if (idx == v.size()) {
    res.push_back(curr);
    return;
  }
  generate_subsets(curr, v, idx + 1, res);
  curr.push_back(v[idx]);
  generate_subsets(curr, v, idx + 1, res);
  curr.pop_back();
}

/// Recursively generates all permutations of a vector via swap-based backtracking.
inline void
generate_permutations(
  std::vector<int>&              v,
  std::size_t                    start,
  std::vector<std::vector<int>>& res)
{
  if (start == v.size()) {
    res.push_back(v);
    return;
  }
  for (auto i = start; i < v.size(); ++i) {
    std::swap(v[start], v[i]);
    generate_permutations(v, start + 1, res);
    std::swap(v[start], v[i]);
  }
}
} // namespace impl

inline void
backtracking()
{
  auto v_in    = std::vector{ 1, 2, 3 };
  auto subsets = std::vector<std::vector<int>>{};
  auto perms   = std::vector<std::vector<int>>{};
  auto current = std::vector<int>{};

  std::cout << "Backtracking algorithm for subsets and permutations\n";
  std::cout << "time-complexity:  O(2^N) subsets, O(N!) permutations\n";
  std::cout << "space-complexity: O(N) recursion depth\n";

  std::cout << "In:         ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << '\n';

  impl::generate_subsets(current, v_in, 0, subsets);
  impl::generate_permutations(v_in, 0, perms);

  std::cout << "Subsets:    " << subsets.size() << " generated\n";
  std::cout << "Perms:      " << perms.size() << " generated\n";
}
} // namespace algorithm
