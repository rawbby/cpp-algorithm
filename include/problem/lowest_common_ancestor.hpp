#pragma once

#include <iostream> // std::cout
#include <vector>   // std::vector

namespace problem {
namespace impl {
/// represents a binary tree node with a value and indices to left/right children
struct lca_node
{
  int         value;
  std::size_t left;
  std::size_t right;
};

static constexpr auto lca_npos = static_cast<std::size_t>(-1);

// adapts the subtree recursion pattern: LCA is either the root (if p or q match)
// or the node where p and q are found in different subtrees
inline auto
find_lca(
  std::vector<lca_node> const& tree,
  std::size_t                  root,
  std::size_t                  p,
  std::size_t                  q) -> std::size_t
{
  if (root == lca_npos || root == p || root == q) return root;

  auto const left  = find_lca(tree, tree[root].left, p, q);
  auto const right = find_lca(tree, tree[root].right, p, q);

  if (left != lca_npos && right != lca_npos) return root;
  return left != lca_npos ? left : right;
}
} // namespace impl

inline void
lowest_common_ancestor()
{
  using impl::lca_node;
  using impl::lca_npos;

  // tree: 3 -> (5, 1), 5 -> (6, 2)
  auto const tree = std::vector<lca_node>{ { 3, 1, 2 }, { 5, 3, 4 }, { 1, lca_npos, lca_npos }, { 6, lca_npos, lca_npos }, { 2, lca_npos, lca_npos } };
  auto const root = std::size_t{ 0 };
  auto const p    = std::size_t{ 3 }; // node 6
  auto const q    = std::size_t{ 4 }; // node 2

  std::cout << "Lowest Common Ancestor problem (subtree recursion pattern)\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(H) auxiliary (stack)\n";

  auto const lca = impl::find_lca(tree, root, p, q);

  std::cout << "Nodes:      " << tree[p].value << ", " << tree[q].value << '\n';
  std::cout << "LCA:        " << (lca != lca_npos ? tree[lca].value : -1) << '\n';
}
} // namespace problem
