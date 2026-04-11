## Linked Lists — Pointer-Based Linear Structures

A linked list stores elements in nodes connected by pointers. Unlike arrays, elements aren't contiguous in memory, enabling O(1) insertion/deletion at known positions but losing O(1) random access.

<br>

## Why Linked Lists in Interviews?

- **Pointer manipulation mastery** — Tests your ability to reason about references
- **In-place operations** — Reverse, reorder, merge without extra space
- **Classic patterns** — Fast/slow pointers, dummy head, recursive solutions
- **Design problems** — LRU Cache (linked list + hash map) is a FAANG favorite

<br>

## Core Patterns

| Pattern | Problems | Key Idea |
|---------|----------|----------|
| **Fast/Slow Pointer** | Detect cycle, find middle, palindrome check | Two pointers at different speeds |
| **Reversal** | Reverse list, reverse K-group, reverse between | Rewire next pointers |
| **Merge** | Merge two sorted, merge K sorted | Compare heads, build result |
| **Dummy Head** | Any problem that might change the head | Simplifies edge cases |

<br>

## Top FAANG Problems

Reverse Linked List, LRU Cache, Merge K Sorted Lists, Reorder List, Remove Nth from End, and Copy List with Random Pointer.

<br>
