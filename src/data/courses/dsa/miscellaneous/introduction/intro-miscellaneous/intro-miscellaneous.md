## Miscellaneous — Design, Matrix Search & Advanced Techniques

This module covers important problems that don't fit neatly into other categories but are still frequently asked in FAANG interviews.

<br>

## What's Covered

1. **Design problems** — Design Twitter (combines heaps, hash maps, OOP)
2. **Meet in the Middle** — Split search space in half for exponential speedup (Subset Sum MITM, Closest Subsequence Sum)
3. **Matrix search** — Efficient search in sorted 2D matrices (binary search on rows/columns)

<br>

## Meet in the Middle

When brute force is O(2ⁿ) and n ≤ 40, split into two halves of size n/2. Enumerate each half in O(2^(n/2)), then combine results. This reduces time from O(2⁴⁰) ≈ 10¹² to O(2²⁰) ≈ 10⁶.

<br>
