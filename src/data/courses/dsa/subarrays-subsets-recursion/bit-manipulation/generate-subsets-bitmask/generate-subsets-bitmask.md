Generate all possible subsets of an array using bitmask representation.

<br>

> Input:
> arr = [1, 2, 3]

> Output:
> [], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]

> Explanation:
> 8 subsets total (2^3)
> Each number 0-7 represents a subset via its binary representation
> 
> **Key insight:** For N elements, iterate 0 to 2^N-1. Each bit position indicates element inclusion.

<br>

---

## Problem: Power Set Using Bitmask

Given an array of N elements, generate all 2^N subsets.

**Example:**
```cpp
arr = [1, 2, 3]

Bitmask representation:
000 (0) → []
001 (1) → [1]
010 (2) → [2]
011 (3) → [1, 2]
100 (4) → [3]
101 (5) → [1, 3]
110 (6) → [2, 3]
111 (7) → [1, 2, 3]
```

**Mapping:** Bit i set → include arr[i]

<br>

---

## Solution: Iterate Through All Bitmasks

**Intuition:**
Each number from 0 to 2^N-1 represents a unique subset.
Bit i in the number indicates whether to include arr[i].

**Algorithm:**
```cpp
result = []
for mask = 0 to (2^N - 1):
    subset = []
    for i = 0 to N-1:
        if (mask & (1 << i)) != 0:
            subset.add(arr[i])
    result.add(subset)
return result
```

**Detailed Example:**
```cpp
arr = [a, b, c], N = 3

mask = 0 (000):
  Check bit 0: 0 & 1 = 0 ✗
  Check bit 1: 0 & 2 = 0 ✗
  Check bit 2: 0 & 4 = 0 ✗
  Subset: []

mask = 5 (101):
  Check bit 0: 5 & 1 = 1 ✓ → include a
  Check bit 1: 5 & 2 = 0 ✗
  Check bit 2: 5 & 4 = 4 ✓ → include c
  Subset: [a, c]

mask = 7 (111):
  Check bit 0: 7 & 1 = 1 ✓ → include a
  Check bit 1: 7 & 2 = 2 ✓ → include b
  Check bit 2: 7 & 4 = 4 ✓ → include c
  Subset: [a, b, c]
```

### Time Complexity: O(N × 2^N)
**Why?**
- Outer loop: 2^N iterations (all possible subsets)
- Inner loop: N iterations (check each bit)
- Total: 2^N × N = O(N × 2^N)

**Detailed breakdown:**
- Generate 2^N subsets
- Each subset requires checking N bits
- Cannot do better - must generate all subsets

### Space Complexity: O(N × 2^N)
**Why?**
- Store all 2^N subsets
- Each subset can have up to N elements
- Total: O(N × 2^N) for output
- Auxiliary space: O(1) (excluding output)

<br>

---

## Why Bitmask Approach?

**Advantages:**
1. **Iterative:** No recursion overhead
2. **Systematic:** Generates subsets in lexicographic order
3. **Space Efficient:** No call stack
4. **Easy to Understand:** Direct mapping between numbers and subsets

**Comparison with Recursion:**
- Recursion: More intuitive, uses call stack
- Bitmask: Iterative, explicit control, better for large N

<br>

---

## Practical Example

```cpp
arr = ["A", "B", "C"]

mask = 0 (000): {}
mask = 1 (001): {A}
mask = 2 (010): {B}
mask = 3 (011): {A, B}
mask = 4 (100): {C}
mask = 5 (101): {A, C}
mask = 6 (110): {B, C}
mask = 7 (111): {A, B, C}
```

<br>

---

## Applications

1. **Combinatorial Problems:** Generate all combinations
2. **Dynamic Programming:** Bitmask DP for state compression
3. **Traveling Salesman:** Track visited cities with bitmask
4. **Subset Sum:** Check all possible subset sums
5. **Feature Selection:** ML model feature combinations

<br>
<br>

---

```code```