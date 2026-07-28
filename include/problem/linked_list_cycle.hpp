#pragma once

#include <iostream> // std::cout
#include <vector>   // std::vector

namespace problem {
namespace impl {
/// Represents a singly linked list node with a next-index pointer.
struct cycle_node
{
  int         value;
  std::size_t next;
};

static constexpr auto cycle_npos = static_cast<std::size_t>(-1);

// adapts the fast/slow pointers pattern (Floyd's cycle-finding algorithm):
// if a cycle exists, the fast pointer will eventually catch up to the slow one
/// Determines whether the linked list contains a cycle using fast/slow pointers.
inline auto
has_cycle(
  std::vector<cycle_node> const& list,
  std::size_t                    head) -> bool
{
  if (head == cycle_npos) return false;

  auto slow = head;
  auto fast = head;

  while (fast != cycle_npos && list[fast].next != cycle_npos) {
    slow = list[slow].next;
    fast = list[list[fast].next].next;
    if (slow == fast) return true;
  }
  return false;
}
} // namespace impl

inline void
linked_list_cycle()
{
  using impl::cycle_node;
  using impl::cycle_npos;

  auto const list = std::vector<cycle_node>{
    { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 1 } // 4 -> 2 (index 1)
  };
  auto const head = std::size_t{ 0 };

  std::cout << "Linked List Cycle problem (fast/slow pointers pattern)\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(1) auxiliary\n";

  std::cout << "In (8):     ";
  for (auto i = head, count = std::size_t{ 0 }; i != cycle_npos && count < std::size_t{ 8 }; i = list[i].next, ++count)
    std::cout << ' ' << list[i].value;
  std::cout << '\n';

  std::cout << "Has cycle:  " << (impl::has_cycle(list, head) ? "true" : "false") << '\n';
}
} // namespace problem
