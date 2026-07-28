#pragma once

#include <iostream> // std::cout
#include <vector>   // std::vector

namespace problem {
namespace impl {
/// represents a singly linked list node with a value and an index to the next node
struct reverse_node
{
  int         value;
  std::size_t next;
};

static constexpr auto reverse_npos = static_cast<std::size_t>(-1);

// adapts the in-place reversal pattern: iterate through the list while
// maintaining a pointer to the previous node to flip each `next` pointer
inline auto
reverse_list(
  std::vector<reverse_node>& list,
  std::size_t                head) -> std::size_t
{
  auto prev = reverse_npos;
  auto curr = head;

  while (curr != reverse_npos) {
    auto const next = list[curr].next;
    list[curr].next = prev;
    prev            = curr;
    curr            = next;
  }
  return prev;
}
} // namespace impl

inline void
reverse_linked_list()
{
  using impl::reverse_node;
  using impl::reverse_npos;

  auto       list = std::vector<reverse_node>{ { 1, 1 }, { 2, 2 }, { 3, reverse_npos } };
  auto const head = std::size_t{ 0 };

  std::cout << "Reverse Linked List problem (in-place reversal pattern)\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(1) auxiliary\n";

  std::cout << "In:         ";
  for (auto i = head; i != reverse_npos; i = list[i].next)
    std::cout << ' ' << list[i].value;
  std::cout << '\n';

  auto const new_head = impl::reverse_list(list, head);

  std::cout << "Out:        ";
  for (auto i = new_head; i != reverse_npos; i = list[i].next)
    std::cout << ' ' << list[i].value;
  std::cout << '\n';
}
} // namespace problem
