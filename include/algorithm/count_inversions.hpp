#pragma once

#include <cstddef>  // std::size_t
#include <iostream> // std::cout
#include <vector>   // std::vector

namespace algorithm {
namespace impl {
/// Merges two sorted halves of a vector while counting split inversions.
inline auto
merge(
  std::vector<int>& v,
  std::vector<int>& tmp,
  std::size_t       l,
  std::size_t       m,
  std::size_t       r) -> long long
{
  auto i     = l;
  auto j     = m + 1;
  auto k     = l;
  auto count = 0LL;

  while (i <= m && j <= r) {
    if (v[i] <= v[j]) {
      tmp[k++] = v[i++];
    } else {
      tmp[k++] = v[j++];
      count += static_cast<long long>(m - i + 1);
    }
  }
  while (i <= m)
    tmp[k++] = v[i++];
  while (j <= r)
    tmp[k++] = v[j++];
  for (i = l; i <= r; ++i)
    v[i] = tmp[i];
  return count;
}

/// Recursively counts inversions in a vector using merge sort.
inline auto
count_rec(
  std::vector<int>& v,
  std::vector<int>& tmp,
  std::size_t       l,
  std::size_t       r) -> long long
{
  auto count = 0LL;
  if (l < r) {
    auto const m = l + (r - l) / 2;
    count += count_rec(v, tmp, l, m);
    count += count_rec(v, tmp, m + 1, r);
    count += merge(v, tmp, l, m, r);
  }
  return count;
}
} // namespace impl

inline void
count_inversions()
{
  auto v_in = std::vector{ 8, 4, 2, 1 };

  std::cout << "Count Inversions (Merge Sort pattern)\n";
  std::cout << "time-complexity:  O(N log N)\n";
  std::cout << "space-complexity: O(N) auxiliary\n";

  std::cout << "In:         ";
  for (auto const v : v_in)
    std::cout << ' ' << v;
  std::cout << '\n';

  auto tmp   = std::vector<int>(v_in.size());
  auto count = impl::count_rec(v_in, tmp, 0, v_in.size() - 1);

  std::cout << "Inversions: " << count << '\n';
}
} // namespace algorithm
