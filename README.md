# CPP Algorithm

LeetCode and HackerRank preparation.

A collection of C++ solution tools.

This repository is not about max total performance but tries to provide resonable simple and compact datastructures to
achive expected time and space complexity. For real-world applications more spcial implementations might be required.

## Structure

The includes are split into three groups:

- `include/datastructure/` — stateful data structures with build/query/update operations (Fenwick tree, segment tree,
  sparse table, trie, union-find).
- `include/algorithm/` — general algorithmic patterns applied to plain containers (prefix sums, difference array, top-k
  variants).
- `include/problem/` — solutions to specific problems. As datastructures and algorithms are only templates, problems do
  not include them; instead each solution adapts the pattern to the concrete use case (e.g. *Subarray Sum Equals K*
  turns the prefix-sum array into a running sum + hash map).

## Implemented

All current implementations hit the optimal (or expected-optimal) complexity class while staying short and simple:

| Group         | Algorithm / Data Structure                                                    | Build      | Query / Op      | Space      | Notes                                      |
|---------------|-------------------------------------------------------------------------------|------------|-----------------|------------|--------------------------------------------|
| Datastructure | Fenwick tree (`datastructure/fenwick_tree.hpp`)                               | O(N)       | O(log N)        | O(N)       | Dynamic range sum, point update            |
| Datastructure | Segment tree (`datastructure/iterative_segmentation_tree.hpp`)                | O(N)       | O(log N)        | O(N)       | Iterative, dynamic range min, point update |
| Datastructure | Median two heaps (`datastructure/median_two_heaps.hpp`)                       | –          | O(log N) insert | O(N)       | Streaming median, max-heap + min-heap      |
| Datastructure | Sparse table (`datastructure/sparse_table.hpp`)                               | O(N log N) | O(1)            | O(N log N) | Static range min (idempotent ops)          |
| Datastructure | Trie (`datastructure/trie.hpp`)                                               | –          | O(L)            | O(chars)   | Prefix tree, flat vector nodes             |
| Datastructure | Union-Find (`datastructure/union_find.hpp`)                                   | O(N)       | ~O(1)           | O(N)       | DSU, path halving + union by size          |
| Algorithm     | Backtracking (`algorithm/backtracking.hpp`)                                   | –          | O(2^N) / O(N!)  | O(N)       | Subsets + permutations, choose/undo        |
| Algorithm     | Binary search (`algorithm/binary_search.hpp`)                                 | –          | O(log N)        | O(1)       | Lower bound + search on answer space       |
| Algorithm     | Count inversions (`algorithm/count_inversions.hpp`)                           | –          | O(N log N)      | O(N)       | Merge sort based                           |
| Algorithm     | Cyclic sort (`algorithm/cyclic_sort.hpp`)                                     | –          | O(N)            | O(1)       | First missing positive, in-place           |
| Algorithm     | Difference array (`algorithm/difference_array.hpp`)                           | O(N)       | O(1)            | O(N)       | Offline range updates, O(N) materialize    |
| Algorithm     | Dijkstra (`algorithm/dijkstra.hpp`)                                           | –          | O(E log V)      | O(V + E)   | Shortest path, min-heap + lazy deletion    |
| Algorithm     | Fast pow / GCD (`algorithm/fast_pow.hpp`)                                     | –          | O(log N)        | O(1)       | Binary exponentiation, Euclid              |
| Algorithm     | K-way merge (`algorithm/k_way_merge.hpp`)                                     | –          | O(N log K)      | O(K)       | Min-heap over K sorted lists               |
| Algorithm     | Kadane (`algorithm/kadane.hpp`)                                               | –          | O(N)            | O(1)       | Maximum subarray sum                       |
| Algorithm     | Merge intervals (`algorithm/merge_intervals.hpp`)                             | –          | O(N log N)      | O(N)       | Sort + sweep merge                         |
| Algorithm     | Minimum spanning tree (`algorithm/minimum_spanning_tree.hpp`)                 | –          | O(E log E)      | O(V)       | Kruskal, inline DSU                        |
| Algorithm     | Monotonic deque (`algorithm/monotonic_deque.hpp`)                             | –          | O(N)            | O(K)       | Sliding window maximum                     |
| Algorithm     | Monotonic stack (`algorithm/monotonic_stack.hpp`)                             | –          | O(N)            | O(N)       | Next greater element                       |
| Algorithm     | Prefix sums (`algorithm/prefix_sums.hpp`)                                     | O(N)       | O(1)            | O(N)       | Static range sum                           |
| Algorithm     | Sieve of Eratosthenes (`algorithm/sieve_of_eratosthenes.hpp`)                 | –          | O(N log log N)  | O(N)       | Prime generation                           |
| Algorithm     | Sliding window (`algorithm/sliding_window.hpp`)                               | –          | O(N)            | O(Σ)       | Longest substring without repeats          |
| Algorithm     | Top-K unsorted (`algorithm/top_k_unsorted.hpp`)                               | –          | O(N)            | O(1)       | `nth_element`, in-place                    |
| Algorithm     | Top-K sorted ad hoc (`algorithm/top_k_sorted_adhoc.hpp`)                      | –          | O(N log K)      | O(1)       | `partial_sort`, in-place                   |
| Algorithm     | Top-K heap streaming (`algorithm/top_k_heap_streaming.hpp`)                   | –          | O(N log K)      | O(K)       | Bounded heap for streaming input           |
| Algorithm     | Topological sort (`algorithm/topological_sort.hpp`)                           | –          | O(V + E)        | O(V)       | Kahn's algorithm, in-degrees + queue       |
| Algorithm     | Two pointers (`algorithm/two_pointers.hpp`)                                   | –          | O(N)            | O(1)       | Pair with target sum in sorted array       |
| Problem       | Binary Tree Level Order (`problem/binary_tree_level_order.hpp`)               | –          | O(N)            | O(N)       | BFS queue per level, adapted               |
| Problem       | Binary Tree Traversals (`problem/binary_tree_traversals.hpp`)                 | –          | O(N)            | O(N)       | Recursive + iterative inorder DFS, adapted |
| Problem       | Burst Balloons (`problem/burst_balloons.hpp`)                                 | –          | O(N^3)          | O(N^2)     | Interval DP pattern, adapted               |
| Problem       | Coin Change (`problem/coin_change.hpp`)                                       | –          | O(A·C)          | O(A)       | 1D DP min coins pattern, adapted           |
| Problem       | Diameter of Binary Tree (`problem/diameter_of_binary_tree.hpp`)               | –          | O(N)            | O(H)       | Subtree recursion pattern, adapted         |
| Problem       | Linked List Cycle (`problem/linked_list_cycle.hpp`)                           | –          | O(N)            | O(1)       | Floyd fast/slow pointers, adapted          |
| Problem       | Longest Consecutive Sequence (`problem/longest_consecutive_sequence.hpp`)     | –          | O(N)            | O(N)       | Hash set start-of-run pattern, adapted     |
| Problem       | Longest Increasing Subsequence (`problem/longest_increasing_subsequence.hpp`) | –          | O(N log N)      | O(N)       | Patience sorting tails, adapted            |
| Problem       | Lowest Common Ancestor (`problem/lowest_common_ancestor.hpp`)                 | –          | O(N)            | O(H)       | Subtree recursion pattern, adapted         |
| Problem       | N-Queens (`problem/n_queens.hpp`)                                             | –          | O(N!)           | O(N)       | Backtracking constraint search, adapted    |
| Problem       | Number of Islands (`problem/number_of_islands.hpp`)                           | –          | O(R·C)          | O(R·C)     | Grid flood fill (BFS/DFS), adapted         |
| Problem       | Partition Equal Subset Sum (`problem/partition_equal_subset_sum.hpp`)         | –          | O(N·S)          | O(S)       | 0/1 knapsack pattern, adapted              |
| Problem       | Reverse Linked List (`problem/reverse_linked_list.hpp`)                       | –          | O(N)            | O(1)       | In-place reversal pattern, adapted         |
| Problem       | Single Number / Count Bits (`problem/single_number.hpp`)                      | –          | O(N)            | O(1)       | XOR trick + popcount DP, adapted           |
| Problem       | Subarray Sum Equals K (`problem/subarray_sum_equals_k.hpp`)                   | –          | O(N)            | O(N)       | Prefix-sum + hash map pattern, adapted     |
| Problem       | Two Sum (`problem/two_sum.hpp`)                                               | –          | O(N)            | O(N)       | Hash map single pass, adapted              |
| Problem       | Unique Paths (`problem/unique_paths.hpp`)                                     | –          | O(M·N)          | O(N)       | Row-compressed grid DP, adapted            |
| Problem       | Valid Parentheses (`problem/valid_parentheses.hpp`)                           | –          | O(N)            | O(N)       | Stack simulation pattern, adapted          |

## TODO

Must-have algorithms and data structures for LeetCode / HackerRank, each with example problems that are crucial for
understanding the concept.

### Arrays & Strings

- [x] Two pointers (`algorithm/two_pointers.hpp`) — *Two Sum II*, *Container With Most Water*, *Trapping Rain Water*
- [x] Sliding window (`algorithm/sliding_window.hpp`) — *Longest Substring Without Repeating Characters*, *Minimum
  Window Substring*
- [x] Kadane's algorithm (max subarray) (`algorithm/kadane.hpp`) — *Maximum Subarray*, *Maximum Product Subarray*
- [x] Interval merging / sweeping (`algorithm/merge_intervals.hpp`) — *Merge Intervals*, *Insert Interval*, *Meeting
  Rooms II*
- [x] Cyclic sort / in-place index tricks (`algorithm/cyclic_sort.hpp`) — *Missing Number*, *First Missing Positive*

### Hashing

- [x] Hash map / set patterns (`problem/two_sum.hpp`, `problem/longest_consecutive_sequence.hpp`) — *Two Sum*, *Group
  Anagrams*, *Longest Consecutive Sequence*
- [x] Prefix-sum + hash map (`problem/subarray_sum_equals_k.hpp`) — *Subarray Sum Equals K*

### Sorting & Searching

- [x] Binary search (incl. on answer space) (`algorithm/binary_search.hpp`) — *Search in Rotated Sorted Array*, *Koko
  Eating Bananas*, *Median of Two Sorted Arrays*
- [x] Quickselect — *Kth Largest Element in an Array* (covered by `algorithm/top_k_unsorted.hpp`)
- [x] Merge sort / counting inversions (`algorithm/count_inversions.hpp`) — *Sort an Array*, *Count of Smaller Numbers
  After Self*

### Linked Lists

- [x] Fast/slow pointers (`problem/linked_list_cycle.hpp`) — *Linked List Cycle*, *Middle of the Linked List*
- [x] In-place reversal (`problem/reverse_linked_list.hpp`) — *Reverse Linked List*, *Reverse Nodes in k-Group*

### Stacks & Queues

- [x] Monotonic stack (`algorithm/monotonic_stack.hpp`) — *Daily Temperatures*, *Largest Rectangle in Histogram*, *Next
  Greater Element*
- [x] Monotonic deque (`algorithm/monotonic_deque.hpp`) — *Sliding Window Maximum*
- [x] Stack simulation (`problem/valid_parentheses.hpp`) — *Valid Parentheses*, *Min Stack*

### Trees

- [x] DFS traversals (recursive & iterative) (`problem/binary_tree_traversals.hpp`) — *Binary Tree Inorder Traversal*,
  *Validate Binary Search Tree*
- [x] BFS / level order (`problem/binary_tree_level_order.hpp`) — *Binary Tree Level Order Traversal*, *Binary Tree
  Right Side View*
- [x] Lowest common ancestor (`problem/lowest_common_ancestor.hpp`) — *LCA of a Binary Tree*
- [x] Recursion on subtrees (`problem/diameter_of_binary_tree.hpp`) — *Diameter of Binary Tree*, *Binary Tree Maximum
  Path Sum*
- [x] Trie (prefix tree) (`datastructure/trie.hpp`) — *Implement Trie*, *Word Search II*

### Heaps / Priority Queues

- [x] Top-K via bounded heap (`algorithm/top_k_heap_streaming.hpp`) — *Kth Largest Element in a Stream*, *Top K Frequent
  Elements*
- [x] Two heaps (median maintenance) (`datastructure/median_two_heaps.hpp`) — *Find Median from Data Stream*
- [x] K-way merge (`algorithm/k_way_merge.hpp`) — *Merge k Sorted Lists*

### Graphs

- [x] BFS / DFS on grids and adjacency lists (`problem/number_of_islands.hpp`) — *Number of Islands*, *Clone Graph*,
  *Rotting Oranges*
- [x] Topological sort (Kahn's algorithm) (`algorithm/topological_sort.hpp`) — *Course Schedule*, *Course Schedule II*
- [x] Union-Find (`datastructure/union_find.hpp`, DSU with path halving + union by size) — *Number of Connected
  Components*, *Redundant Connection*, *Accounts Merge*
- [x] Dijkstra's shortest path (`algorithm/dijkstra.hpp`) — *Network Delay Time*, *Cheapest Flights Within K Stops*
- [x] Minimum spanning tree (Kruskal/Prim) (`algorithm/minimum_spanning_tree.hpp`) — *Min Cost to Connect All Points*

### Dynamic Programming

- [x] 1D DP (`problem/coin_change.hpp`) — *Climbing Stairs*, *House Robber*, *Coin Change*
- [x] 2D / grid DP (`problem/unique_paths.hpp`) — *Unique Paths*, *Minimum Path Sum*
- [x] Subsequence DP (`problem/longest_increasing_subsequence.hpp`) — *Longest Increasing Subsequence*, *Longest Common
  Subsequence*, *Edit Distance*
- [x] Knapsack patterns (`problem/partition_equal_subset_sum.hpp`) — *Partition Equal Subset Sum*, *Target Sum*
- [x] Interval DP (`problem/burst_balloons.hpp`) — *Burst Balloons*

### Backtracking

- [x] Subsets / permutations / combinations (`algorithm/backtracking.hpp`) — *Subsets*, *Permutations*, *Combination
  Sum*
- [x] Constraint search (`problem/n_queens.hpp`) — *Word Search*, *N-Queens*

### Range Queries

- [x] Prefix sums (`algorithm/prefix_sums.hpp`) — *Range Sum Query - Immutable*
- [x] Fenwick tree (`datastructure/fenwick_tree.hpp`) — *Range Sum Query - Mutable*, *Count of Smaller Numbers After
  Self*
- [x] Segment tree (`datastructure/iterative_segmentation_tree.hpp`) — *Range Minimum Query*
- [x] Sparse table (`datastructure/sparse_table.hpp`) — static RMQ, useful for *Sliding Window* variants
- [x] Difference array (`algorithm/difference_array.hpp`) — *Corporate Flight Bookings*, *Car Pooling*

### Math & Bit Manipulation

- [x] Bit tricks (XOR, masks, popcount) (`problem/single_number.hpp`) — *Single Number*, *Counting Bits*, *Subsets via
  bitmask*
- [x] GCD / modular arithmetic (`algorithm/fast_pow.hpp`) — *Greatest Common Divisor of Strings*, *Pow (x, n)*
- [x] Sieve of Eratosthenes (`algorithm/sieve_of_eratosthenes.hpp`) — *Count Primes*
