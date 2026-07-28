#pragma once

#include <array>       // std::array
#include <cstddef>     // std::size_t
#include <iostream>    // std::cout
#include <string_view> // std::string_view
#include <vector>      // std::vector

namespace datastructure {
namespace impl {
/// Represents a single node in the trie, with child links and a terminal flag.
struct trie_node
{
  std::array<std::size_t, 26> next{}; // 0 == no child (root is index 0)
  bool                        terminal{};
};

/// Inserts a word into the trie, creating nodes as needed.
inline void
insert_trie(
  std::vector<trie_node>& nodes,
  std::string_view        word)
{
  std::size_t cur = 0;
  for (auto const c : word) {
    auto const i = static_cast<std::size_t>(c - 'a');
    if (nodes[cur].next[i] == 0) {
      nodes[cur].next[i] = nodes.size();
      nodes.emplace_back();
    }
    cur = nodes[cur].next[i];
  }
  nodes[cur].terminal = true;
}

/// Walks the trie along the given prefix, returning the resulting node index or 0 if not found.
inline auto
walk_trie(
  std::vector<trie_node> const& nodes,
  std::string_view              prefix) -> std::size_t
{
  std::size_t cur = 0;
  for (auto const c : prefix) {
    cur = nodes[cur].next[static_cast<std::size_t>(c - 'a')];
    if (cur == 0) return 0; // not found
  }
  return cur;
}

/// Checks whether the trie contains the exact given word.
inline auto
contains_trie(
  std::vector<trie_node> const& nodes,
  std::string_view              word) -> bool
{
  auto const cur = walk_trie(nodes, word);
  return cur != 0 && nodes[cur].terminal;
}

/// Checks whether the trie contains any word with the given prefix.
inline auto
starts_with_trie(
  std::vector<trie_node> const& nodes,
  std::string_view              prefix) -> bool
{
  return walk_trie(nodes, prefix) != 0;
}
}

inline void
trie()
{
  auto const words = std::vector<std::string_view>{ "apple", "app", "ape", "banana" };

  std::cout << "Trie (prefix tree) datastructure for word/prefix lookup\n";
  std::cout << "time-complexity:  O(L) insert/contains/starts_with (L = word length)\n";
  std::cout << "space-complexity: O(total characters * alphabet)\n";

  auto nodes = std::vector<impl::trie_node>(1); // root

  std::cout << "In:         ";
  for (auto const w : words)
    std::cout << ' ' << w;
  std::cout << '\n';

  for (auto const w : words)
    impl::insert_trie(nodes, w);

  std::cout << "Nodes:       " << nodes.size() << '\n';

  std::cout << "Contains(app):     " << impl::contains_trie(nodes, "app") << '\n';
  std::cout << "Contains(appl):    " << impl::contains_trie(nodes, "appl") << '\n';
  std::cout << "StartsWith(appl):  " << impl::starts_with_trie(nodes, "appl") << '\n';
  std::cout << "StartsWith(ban):   " << impl::starts_with_trie(nodes, "ban") << '\n';
  std::cout << "StartsWith(cat):   " << impl::starts_with_trie(nodes, "cat") << '\n';
}
}
