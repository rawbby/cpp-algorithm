#include <ios>      // std::ios_base::sync_with_stdio
#include <iostream> // std::cin, std::cout

#include <algorithm/backtracking.hpp>
#include <algorithm/binary_search.hpp>
#include <algorithm/count_inversions.hpp>
#include <algorithm/cyclic_sort.hpp>
#include <algorithm/difference_array.hpp>
#include <algorithm/dijkstra.hpp>
#include <algorithm/fast_pow.hpp>
#include <algorithm/k_way_merge.hpp>
#include <algorithm/kadane.hpp>
#include <algorithm/merge_intervals.hpp>
#include <algorithm/minimum_spanning_tree.hpp>
#include <algorithm/monotonic_deque.hpp>
#include <algorithm/monotonic_stack.hpp>
#include <algorithm/prefix_sums.hpp>
#include <algorithm/sieve_of_eratosthenes.hpp>
#include <algorithm/sliding_window.hpp>
#include <algorithm/top_k_heap_streaming.hpp>
#include <algorithm/top_k_sorted_adhoc.hpp>
#include <algorithm/top_k_unsorted.hpp>
#include <algorithm/topological_sort.hpp>
#include <algorithm/two_pointers.hpp>
#include <datastructure/fenwick_tree.hpp>
#include <datastructure/iterative_segmentation_tree.hpp>
#include <datastructure/median_two_heaps.hpp>
#include <datastructure/sparse_table.hpp>
#include <datastructure/trie.hpp>
#include <datastructure/union_find.hpp>
#include <problem/binary_tree_level_order.hpp>
#include <problem/binary_tree_traversals.hpp>
#include <problem/burst_balloons.hpp>
#include <problem/coin_change.hpp>
#include <problem/diameter_of_binary_tree.hpp>
#include <problem/linked_list_cycle.hpp>
#include <problem/longest_consecutive_sequence.hpp>
#include <problem/longest_increasing_subsequence.hpp>
#include <problem/lowest_common_ancestor.hpp>
#include <problem/n_queens.hpp>
#include <problem/number_of_islands.hpp>
#include <problem/partition_equal_subset_sum.hpp>
#include <problem/reverse_linked_list.hpp>
#include <problem/single_number.hpp>
#include <problem/subarray_sum_equals_k.hpp>
#include <problem/two_sum.hpp>
#include <problem/unique_paths.hpp>
#include <problem/valid_parentheses.hpp>

namespace {
void
datastructures()
{
  std::cout << '\n';
  datastructure::fenwick_tree();
  std::cout << '\n';
  datastructure::iterative_segmentation_tree();
  std::cout << '\n';
  datastructure::median_two_heaps();
  std::cout << '\n';
  datastructure::sparse_table();
  std::cout << '\n';
  datastructure::trie();
  std::cout << '\n';
  datastructure::union_find();
}

void
algorithms()
{
  std::cout << '\n';
  algorithm::backtracking();
  std::cout << '\n';
  algorithm::binary_search();
  std::cout << '\n';
  algorithm::count_inversions();
  std::cout << '\n';
  algorithm::cyclic_sort();
  std::cout << '\n';
  algorithm::difference_array();
  std::cout << '\n';
  algorithm::dijkstra();
  std::cout << '\n';
  algorithm::fast_pow();
  std::cout << '\n';
  algorithm::k_way_merge();
  std::cout << '\n';
  algorithm::kadane();
  std::cout << '\n';
  algorithm::merge_intervals();
  std::cout << '\n';
  algorithm::minimum_spanning_tree();
  std::cout << '\n';
  algorithm::monotonic_deque();
  std::cout << '\n';
  algorithm::monotonic_stack();
  std::cout << '\n';
  algorithm::prefix_sums();
  std::cout << '\n';
  algorithm::sieve_of_eratosthenes();
  std::cout << '\n';
  algorithm::sliding_window();
  std::cout << '\n';
  algorithm::top_k_unsorted();
  std::cout << '\n';
  algorithm::top_k_sorted_adhoc();
  std::cout << '\n';
  algorithm::top_k_heap_streaming();
  std::cout << '\n';
  algorithm::topological_sort();
  std::cout << '\n';
  algorithm::two_pointers();
}

void
problems()
{
  std::cout << '\n';
  problem::binary_tree_level_order();
  std::cout << '\n';
  problem::binary_tree_traversals();
  std::cout << '\n';
  problem::burst_balloons();
  std::cout << '\n';
  problem::coin_change();
  std::cout << '\n';
  problem::diameter_of_binary_tree();
  std::cout << '\n';
  problem::linked_list_cycle();
  std::cout << '\n';
  problem::longest_consecutive_sequence();
  std::cout << '\n';
  problem::longest_increasing_subsequence();
  std::cout << '\n';
  problem::lowest_common_ancestor();
  std::cout << '\n';
  problem::n_queens();
  std::cout << '\n';
  problem::number_of_islands();
  std::cout << '\n';
  problem::partition_equal_subset_sum();
  std::cout << '\n';
  problem::reverse_linked_list();
  std::cout << '\n';
  problem::single_number();
  std::cout << '\n';
  problem::subarray_sum_equals_k();
  std::cout << '\n';
  problem::two_sum();
  std::cout << '\n';
  problem::unique_paths();
  std::cout << '\n';
  problem::valid_parentheses();
}
}

int
main(
  int /* argc */,
  char** /* argv */)
{
  // for LeetCode and HackerRank avoid input latenzy:

  // use distinct unsynced buffer for std::fprint and std::cout
  std::ios_base::sync_with_stdio(false);

  // on cin dont fluh cout
  std::cin.tie(nullptr);

  datastructures();
  algorithms();
  problems();

  std::cout.flush();

  // omit return as no error
}
