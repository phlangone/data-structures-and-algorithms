# Data Structures and Algorithms in C++

A personal study repository containing C++ implementations of fundamental data structures and algorithms. This is an ongoing learning project, focused on understanding how data structures work internally by implementing them from scratch.

## Learning objectives

- Understand pointers, dynamic memory allocation, and object lifetime.
- Implement node-based data structures without relying on standard library containers for their internal storage.
- Practice object-oriented programming, recursion, and iterative algorithms.
- Analyze time and space complexity and understand the trade-offs between different data structures.
- Develop and test solutions to algorithmic problems.

## Implementations

| Topic | Directory | Current scope |
| --- | --- | --- |
| Singly linked list | [01_linked_list](01_linked_list/) | Insertion, removal, indexed access, update, and reversal |
| Doubly linked list | [02_doubly_linked_list](02_doubly_linked_list/) | Insertion, removal, indexed access, and update |
| Stack | [03_stack](03_stack/) | Linked-node LIFO structure, push and pop |
| Queue | [04_queue](04_queue/) | Linked-node FIFO structure, enqueue and dequeue |
| Binary search tree | [05_binary_search_tree](05_binary_search_tree/) | Search, insertion, deletion, and recursive in-order traversal |

Additional introductory and academic exercises are available in [00_misc](00_misc/).

## Development environment

- C++
- GNU C++ compiler (`g++`)
- GNU Make
- GitHub Codespaces (primary study environment)

Each numbered data structure directory contains its own implementation, a `main.cpp` entry point for experiments and tests, and a Makefile. Projects can be built independently.

## Building and running

Open the repository in GitHub Codespaces or a local environment with `g++` and `make` installed.

For example, to build and run the binary search tree:

```bash
cd 05_binary_search_tree
make
./meu_programa
```

To remove the generated executable:

```bash
make clean
```

The same workflow applies to the other data structure directories.

## Complexity reference

The following table summarizes the expected time complexity of common operations for the structures studied here. It is a conceptual reference, not a benchmark of the current implementations.

| Data structure | Access / search | Insertion | Removal |
| --- | --- | --- | --- |
| Singly linked list | O(n) | O(1) at front or back; O(n) by index | O(1) at front; O(n) at back or by index |
| Doubly linked list | O(n) | O(1) at either end; O(n) by index | O(1) at either end; O(n) by index |
| Stack | O(1) top access | O(1) push | O(1) pop |
| Queue | O(1) front access | O(1) enqueue | O(1) dequeue |
| Binary search tree | O(h) | O(h) | O(h) |

For a binary search tree, `h` is the tree height: O(log n) for a balanced tree and O(n) in the worst case for an unbalanced tree. The current implementation does not automatically balance the tree. Linked-list endpoint operations assume the corresponding head or tail pointer is maintained.

## Learning resources

This repository accompanies my independent studies in data structures and algorithms, including Scott Barrett's *C++ Data Structures & Algorithms* course on Udemy, as well as complementary academic exercises.

## Project status

**Work in progress.** New data structures, algorithms, exercises, and refinements will be added as my studies progress. Existing implementations may evolve as I revisit topics and improve their design, correctness, and memory management.

The code is intended for educational exploration rather than production use.
