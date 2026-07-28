#pragma once

#include <iostream> // std::cout
#include <queue>    // std::queue
#include <vector>   // std::vector

namespace problem {
namespace impl {
/// Represents a binary tree node with left/right child indices.
struct level_node
{
  int         value;
  std::size_t left;
  std::size_t right;
};

static constexpr auto level_npos = static_cast<std::size_t>(-1);

// adapts the BFS pattern: use a queue to visit nodes layer by layer,
// keeping track of the current level size to process one level at a time
/// Prints the tree's nodes level by level using a BFS queue.
inline void
print_level_order(
  std::vector<level_node> const& tree,
  std::size_t                    root)
{
  if (root == level_npos) return;

  auto q = std::queue<std::size_t>{};
  q.push(root);

  while (!q.empty()) {
    auto const size = q.size();
    for (auto i = std::size_t{ 0 }; i < size; ++i) {
      auto const curr = q.front();
      q.pop();

      std::cout << ' ' << tree[curr].value;
      if (tree[curr].left != level_npos) q.push(tree[curr].left);
      if (tree[curr].right != level_npos) q.push(tree[curr].right);
    }
    std::cout << " |";
  }
}
} // namespace impl

inline void
binary_tree_level_order()
{
  using impl::level_node;
  using impl::level_npos;

  // tree: 1 -> (2, 3), 2 -> (4, 5)
  auto const tree = std::vector<level_node>{ { 1, 1, 2 }, { 2, 3, 4 }, { 3, level_npos, level_npos }, { 4, level_npos, level_npos }, { 5, level_npos, level_npos } };
  auto const root = std::size_t{ 0 };

  std::cout << "Binary Tree Level Order problem (BFS pattern)\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(N) auxiliary (queue)\n";

  std::cout << "Levels:     ";
  impl::print_level_order(tree, root);
  std::cout << '\n';
}
} // namespace problem
