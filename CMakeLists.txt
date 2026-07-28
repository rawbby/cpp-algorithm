cmake_minimum_required(VERSION 3.21)
project(cpp-algorithm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cpp-algorithm src/main.cpp)

target_include_directories(cpp-algorithm PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_sources(cpp-algorithm PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/backtracking.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/binary_search.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/count_inversions.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/cyclic_sort.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/difference_array.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/dijkstra.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/fast_pow.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/k_way_merge.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/kadane.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/merge_intervals.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/minimum_spanning_tree.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/monotonic_deque.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/monotonic_stack.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/prefix_sums.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/sieve_of_eratosthenes.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/sliding_window.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/top_k_heap_streaming.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/top_k_sorted_adhoc.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/top_k_unsorted.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/topological_sort.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm/two_pointers.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/datastructure/fenwick_tree.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/datastructure/iterative_segmentation_tree.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/datastructure/median_two_heaps.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/datastructure/sparse_table.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/datastructure/trie.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/datastructure/union_find.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/binary_tree_level_order.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/binary_tree_traversals.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/burst_balloons.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/coin_change.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/diameter_of_binary_tree.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/linked_list_cycle.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/longest_consecutive_sequence.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/longest_increasing_subsequence.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/lowest_common_ancestor.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/n_queens.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/number_of_islands.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/partition_equal_subset_sum.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/reverse_linked_list.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/single_number.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/subarray_sum_equals_k.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/two_sum.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/unique_paths.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/problem/valid_parentheses.hpp)

target_compile_options(cpp-algorithm PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall;-Wextra;-Wpedantic;-Wshadow;-Wnon-virtual-dtor;-Wold-style-cast;-Wcast-align;-Wunused;-Woverloaded-virtual;-Wconversion;-Wsign-conversion;-Wdouble-promotion;-Wformat=2>
        $<$<CXX_COMPILER_ID:GNU>:-Wlogical-op;-Wduplicated-cond;-Wduplicated-branches>
        $<$<CXX_COMPILER_ID:Clang,AppleClang>:-Wnull-dereference>)

find_program(CLANG_FORMAT_20_EXECUTABLE clang-format-20)
if (CLANG_FORMAT_20_EXECUTABLE)
    file(GLOB_RECURSE FORMAT_SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
    add_custom_target(clang-format
            COMMAND ${CLANG_FORMAT_20_EXECUTABLE} -i ${FORMAT_SOURCES}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif ()
