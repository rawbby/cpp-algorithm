#pragma once

#include <algorithm> // std::max
#include <iostream>  // std::cout
#include <vector>    // std::vector

namespace problem {
namespace impl {
/// Represents a binary tree node with left/right child indices.
struct diameter_node
{
  int         value;
  std::size_t left;
  std::size_t right;
};

static constexpr auto diameter_npos = static_cast<std::size_t>(-1);

// adapts the subtree recursion pattern: return the height of the subtree
// while updating the diameter (max distance found so far) as a side effect
/// Computes the subtree height while updating the diameter as a side effect.
inline auto
calculate_height_and_diameter(
  std::vector<diameter_node> const& tree,
  std::size_t                       root,
  int&                              diameter) -> int
{
  if (root == diameter_npos) return 0;

  auto const left  = calculate_height_and_diameter(tree, tree[root].left, diameter);
  auto const right = calculate_height_and_diameter(tree, tree[root].right, diameter);

  diameter = std::max(diameter, left + right);
  return 1 + std::max(left, right);
}
} // namespace impl

inline void
diameter_of_binary_tree()
{
  using impl::diameter_node;
  using impl::diameter_npos;

  // tree: 1 -> (2, 3), 2 -> (4, 5)
  auto const tree =
    std::vector<diameter_node>{ { 1, 1, 2 }, { 2, 3, 4 }, { 3, diameter_npos, diameter_npos }, { 4, diameter_npos, diameter_npos }, { 5, diameter_npos, diameter_npos } };
  auto const root = std::size_t{ 0 };

  std::cout << "Diameter of Binary Tree problem (subtree recursion pattern)\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(H) auxiliary (stack)\n";

  auto diameter = 0;
  impl::calculate_height_and_diameter(tree, root, diameter);

  std::cout << "Diameter:   " << diameter << '\n';
}
} // namespace problem
