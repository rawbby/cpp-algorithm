#pragma once

#include <iostream> // std::cout
#include <stack>    // std::stack
#include <vector>   // std::vector

namespace problem {
namespace impl {
/// Represents a binary tree node with left/right child indices.
struct traversal_node
{
  int         value;
  std::size_t left;
  std::size_t right;
};

static constexpr auto traversal_npos = static_cast<std::size_t>(-1);

// adapts the DFS pattern (recursive): traverse left subtree, visit node,
// then traverse right subtree
/// Prints the tree's values in inorder using recursion.
inline void
inorder_recursive(
  std::vector<traversal_node> const& tree,
  std::size_t                        root)
{
  if (root == traversal_npos) return;
  inorder_recursive(tree, tree[root].left);
  std::cout << ' ' << tree[root].value;
  inorder_recursive(tree, tree[root].right);
}

// adapts the DFS pattern (iterative): use an explicit stack to simulate
// the call stack, pushing nodes as we go left, then popping to go right
/// Prints the tree's values in inorder using an explicit stack.
inline void
inorder_iterative(
  std::vector<traversal_node> const& tree,
  std::size_t                        root)
{
  auto s    = std::stack<std::size_t>{};
  auto curr = root;

  while (curr != traversal_npos || !s.empty()) {
    while (curr != traversal_npos) {
      s.push(curr);
      curr = tree[curr].left;
    }
    curr = s.top();
    s.pop();
    std::cout << ' ' << tree[curr].value;
    curr = tree[curr].right;
  }
}
} // namespace impl

inline void
binary_tree_traversals()
{
  using impl::traversal_node;
  using impl::traversal_npos;

  // tree: 1 -> (2, 3), 2 -> (4, 5)
  auto const tree =
    std::vector<traversal_node>{ { 1, 1, 2 }, { 2, 3, 4 }, { 3, traversal_npos, traversal_npos }, { 4, traversal_npos, traversal_npos }, { 5, traversal_npos, traversal_npos } };
  auto const root = std::size_t{ 0 };

  std::cout << "Binary Tree Traversals problem (DFS pattern)\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(H) auxiliary (stack)\n";

  std::cout << "Recursive:  ";
  impl::inorder_recursive(tree, root);
  std::cout << '\n';

  std::cout << "Iterative:  ";
  impl::inorder_iterative(tree, root);
  std::cout << '\n';
}
} // namespace problem
