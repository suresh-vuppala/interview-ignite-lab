Understanding common time complexities and their relationship with input constraints helps you choose the right algorithm approach in interviews.

<br>

---

## Common Time Complexities (Best to Worst)

### O(1) - Constant Time
**Description:** Time doesn't change with input size

**Examples:**
- Array access: arr[i]
- Hash table lookup (average)
- Arithmetic operations
- Variable assignment

**When to use:** Direct access, mathematical formulas

<br>

### O(log n) - Logarithmic Time
**Description:** Time grows logarithmically with input

**Examples:**
- Binary search
- Balanced BST operations
- Heap insert/delete
- Finding power (a^n using exponentiation)

**When to use:** Divide and conquer on sorted data

<br>

### O(√n) - Square Root Time
**Description:** Time proportional to square root of input

**Examples:**
- Check if number is prime
- Find divisors of a number
- Sieve optimizations

**When to use:** Number theory problems, factorization

<br>

### O(n) - Linear Time
**Description:** Time grows linearly with input

**Examples:**
- Single loop through array
- Linear search
- Finding min/max
- Counting elements

**When to use:** Must examine each element once

<br>

### O(n log n) - Linearithmic Time
**Description:** Combination of linear and logarithmic

**Examples:**
- Merge sort
- Quick sort (average)
- Heap sort
- Sorting-based solutions

**When to use:** Optimal comparison-based sorting

<br>

### O(n²) - Quadratic Time
**Description:** Time grows quadratically with input

**Examples:**
- Nested loops (i, j)
- Bubble sort, Selection sort
- Checking all pairs
- Naive string matching

**When to use:** Small inputs (n ≤ 1000), pair comparisons

<br>

### O(n³) - Cubic Time
**Description:** Time grows cubically with input

**Examples:**
- Triple nested loops
- Floyd-Warshall algorithm
- Matrix multiplication (naive)
- All triplets problems

**When to use:** Very small inputs (n ≤ 100)

<br>

### O(2^n) - Exponential Time
**Description:** Time doubles with each input increase

**Examples:**
- Generate all subsets
- Recursive Fibonacci (naive)
- Traveling salesman (brute force)
- All combinations

**When to use:** Small inputs (n ≤ 20), no better solution exists

<br>

### O(n!) - Factorial Time
**Description:** Time grows factorially

**Examples:**
- Generate all permutations
- Traveling salesman (all routes)
- Brute force optimization

**When to use:** Tiny inputs (n ≤ 10), last resort

<br>

---

## Complexity Comparison Chart

For n = 1,000,000:

| Complexity | Operations | Practical? |
|------------|-----------|------------|
| O(1) | 1 | ✅ Instant |
| O(log n) | ~20 | ✅ Instant |
| O(√n) | ~1,000 | ✅ Very fast |
| O(n) | 1,000,000 | ✅ Fast |
| O(n log n) | ~20,000,000 | ✅ Acceptable |
| O(n²) | 1,000,000,000,000 | ❌ Too slow |
| O(2^n) | 2^1000000 | ❌ Impossible |
| O(n!) | 1000000! | ❌ Impossible |

<br>

---

## Input Constraints → Time Complexity Guide

This is the most important table for interviews!

| Input Size (n) | Maximum Complexity | Algorithm Examples |
|----------------|-------------------|-------------------|
| n ≤ 10 | O(n!), O(2^n) | Permutations, Subsets |
| n ≤ 20 | O(2^n) | Bitmask DP, Subsets |
| n ≤ 100 | O(n³) | Floyd-Warshall, Triple loops |
| n ≤ 1,000 | O(n²) | Bubble sort, All pairs |
| n ≤ 10,000 | O(n²) | Optimized O(n²) |
| n ≤ 100,000 | O(n log n) | Merge sort, Binary search |
| n ≤ 1,000,000 | O(n), O(n log n) | Linear scan, Sorting |
| n ≤ 10,000,000 | O(n) | Single pass algorithms |
| n > 10,000,000 | O(log n), O(1) | Binary search, Math |

<br>

---

## How to Choose Algorithm Based on Constraints

### Step 1: Read the Constraint
Look for: "1 ≤ n ≤ 10^5" or similar

### Step 2: Identify Maximum Complexity
Use the table above

### Step 3: Choose Algorithm Pattern
Match complexity to algorithm type

### Step 4: Verify Time Limit
Usually 1-2 seconds = ~10^8 operations

<br>

---

## Practical Examples

### Example 1: n ≤ 20
**Constraint:** Array size ≤ 20
**Allowed:** O(2^n), O(n!)
**Approach:** Generate all subsets, Try all permutations
**Problems:** Subset sum, Traveling salesman

<br>

### Example 2: n ≤ 1,000
**Constraint:** Array size ≤ 1,000
**Allowed:** O(n²)
**Approach:** Nested loops, All pairs
**Problems:** Longest increasing subsequence (DP), All pairs shortest path

<br>

### Example 3: n ≤ 100,000
**Constraint:** Array size ≤ 100,000
**Allowed:** O(n log n)
**Approach:** Sorting, Binary search, Heap
**Problems:** Merge intervals, Kth largest element

<br>

### Example 4: n ≤ 1,000,000
**Constraint:** Array size ≤ 1,000,000
**Allowed:** O(n)
**Approach:** Single pass, Hash map, Two pointers
**Problems:** Two sum, Subarray sum equals k

<br>

---

## Space Complexity Constraints

### Common Space Limits

| Space Complexity | Memory Usage (n=10^6) | Practical? |
|------------------|----------------------|------------|
| O(1) | Few variables | ✅ Always OK |
| O(log n) | ~20 variables | ✅ Always OK |
| O(n) | ~4 MB (int array) | ✅ Usually OK |
| O(n²) | ~4 TB | ❌ Too much |

**Memory Limit:** Usually 256 MB - 512 MB

**Rule of Thumb:**
- int array of size n: 4n bytes
- long array of size n: 8n bytes
- 10^6 integers ≈ 4 MB ✅
- 10^6 × 10^6 integers ≈ 4 TB ❌

<br>

---

## Interview Strategy

### When You See Constraints

1. **n ≤ 10:** Think brute force, try everything
2. **n ≤ 20:** Think exponential, bitmask, backtracking
3. **n ≤ 100:** Think O(n³), dynamic programming
4. **n ≤ 1,000:** Think O(n²), nested loops OK
5. **n ≤ 10^5:** Think O(n log n), sorting, binary search
6. **n ≤ 10^6:** Think O(n), single pass, hash map
7. **n > 10^6:** Think O(log n) or O(1), math, binary search

<br>

---

## Common Pitfalls

### Pitfall 1: Ignoring Constants
O(100n) might be slower than O(n²) for small n

### Pitfall 2: Multiple Operations
If you do O(n) operation n times → O(n²)

### Pitfall 3: Hidden Complexity
String operations, sorting inside loops add complexity

### Pitfall 4: Space vs Time Trade-off
Sometimes O(n) space can reduce O(n²) to O(n)

<br>

---

## Quick Reference: Algorithm Complexities

### Sorting Algorithms
- Bubble Sort: O(n²)
- Selection Sort: O(n²)
- Insertion Sort: O(n²)
- Merge Sort: O(n log n)
- Quick Sort: O(n log n) average, O(n²) worst
- Heap Sort: O(n log n)
- Counting Sort: O(n + k)

### Searching Algorithms
- Linear Search: O(n)
- Binary Search: O(log n)
- Hash Table: O(1) average

### Data Structure Operations
- Array Access: O(1)
- Array Insert/Delete: O(n)
- Linked List Insert/Delete: O(1)
- Stack Push/Pop: O(1)
- Queue Enqueue/Dequeue: O(1)
- Heap Insert/Delete: O(log n)
- BST Insert/Delete/Search: O(log n) average

### Graph Algorithms
- BFS/DFS: O(V + E)
- Dijkstra: O((V + E) log V)
- Bellman-Ford: O(VE)
- Floyd-Warshall: O(V³)

<br>

---

## Practice Problems by Complexity

### O(n) Problems
- Two Sum (with hash map)
- Maximum Subarray
- Valid Parentheses

### O(n log n) Problems
- Merge Intervals
- Kth Largest Element
- Meeting Rooms II

### O(n²) Problems
- Longest Palindromic Substring
- 3Sum
- Container With Most Water

### O(2^n) Problems
- Subsets
- Permutations
- Combination Sum

<br>

---

## Key Takeaways

1. **Always check constraints first** - they tell you the expected complexity
2. **10^8 operations ≈ 1 second** - rough estimate
3. **n ≤ 20 → exponential OK** - try all possibilities
4. **n ≤ 10^5 → O(n log n) max** - sorting, binary search
5. **n > 10^6 → O(n) or better** - single pass, math
6. **Space matters too** - O(n²) space often not feasible

> **Interview Tip:** When you see constraints, immediately think: "What's the maximum complexity I can afford?" This guides your algorithm choice and shows the interviewer you understand complexity analysis.

<br>
<br>

---
