Express recursive algorithms mathematically to analyze complexity.

<br>

> **Recurrence Relation:**
> Mathematical equation expressing function in terms of itself with smaller inputs.

> **General Form:**
> T(n) = aT(n/b) + f(n)
> - a: number of recursive calls
> - n/b: size of each subproblem  
> - f(n): work done outside recursion
> 
> **Key insight:** Recurrence relations enable precise complexity analysis of recursive algorithms.

<br>

---

## What is a Recurrence Relation?

**Intuition:**
A recurrence relation defines a sequence where each term is expressed using previous terms.
For algorithms, it describes time/space complexity recursively.

**Components:**
1. **Base Case:** T(1) = O(1) or T(0) = O(1)
2. **Recursive Case:** T(n) expressed using T(smaller values)
3. **Non-recursive Work:** Operations done at current level

**Example - Factorial:**
```cpp
int factorial(int n) {
    if (n <= 1) return 1;        // Base: O(1)
    return n * factorial(n-1);    // Recursive + O(1) work
}

Recurrence: T(n) = T(n-1) + O(1)
Base: T(1) = O(1)
```

<br>

---

## Common Recurrence Patterns

### Pattern 1: Linear Decrement
**Form:** T(n) = T(n-1) + O(1)

**Examples:**
```cpp
// Factorial
T(n) = T(n-1) + O(1)
Solution: T(n) = O(n)

// Sum of array
T(n) = T(n-1) + O(1)
Solution: T(n) = O(n)
```

**Intuition:** n calls, constant work each → O(n)

### Pattern 2: Linear Decrement with Linear Work
**Form:** T(n) = T(n-1) + O(n)

**Example:**
```cpp
// Selection sort (recursive)
T(n) = T(n-1) + O(n)  // Find min takes O(n)
Solution: T(n) = O(n²)
```

**Intuition:** n + (n-1) + (n-2) + ... + 1 = n(n+1)/2 = O(n²)

### Pattern 3: Binary Recursion
**Form:** T(n) = 2T(n-1) + O(1)

**Example:**
```cpp
// Fibonacci (naive)
T(n) = T(n-1) + T(n-2) + O(1)
Approx: T(n) ≈ 2T(n-1) + O(1)
Solution: T(n) = O(2ⁿ)
```

**Intuition:** Each call spawns 2 more → exponential growth

### Pattern 4: Divide by Half
**Form:** T(n) = T(n/2) + O(1)

**Example:**
```cpp
// Binary search
T(n) = T(n/2) + O(1)
Solution: T(n) = O(log n)
```

**Intuition:** Problem size halves each time → logarithmic

### Pattern 5: Divide & Conquer
**Form:** T(n) = 2T(n/2) + O(n)

**Example:**
```cpp
// Merge sort
T(n) = 2T(n/2) + O(n)  // Merge takes O(n)
Solution: T(n) = O(n log n)
```

**Intuition:** log(n) levels, O(n) work per level

<br>

---

## Solving Recurrence Relations

### Method 1: Substitution Method

**Steps:**
1. Guess the solution
2. Prove by induction

**Example:** T(n) = T(n-1) + O(1)

```
Guess: T(n) = O(n)

Expand:
T(n) = T(n-1) + c
     = T(n-2) + c + c
     = T(n-3) + c + c + c
     = ...
     = T(1) + c(n-1)
     = O(1) + O(n)
     = O(n) ✓
```

### Method 2: Recursion Tree Method

**Steps:**
1. Draw recursion tree
2. Calculate work at each level
3. Sum across all levels

**Example:** T(n) = 2T(n/2) + n

```
Level 0: n                    (1 node, n work)
Level 1: n/2 + n/2 = n        (2 nodes, n total work)
Level 2: n/4+n/4+n/4+n/4 = n  (4 nodes, n total work)
...
Level log(n): n × 1 = n      (n nodes, n total work)

Total: n × log(n) = O(n log n)
```

### Method 3: Master Theorem

**For:** T(n) = aT(n/b) + f(n) where a ≥ 1, b > 1

**Three Cases:**

**Case 1:** f(n) = O(n^c) where c < log_b(a)
- **Solution:** T(n) = Θ(n^(log_b(a)))
- **Intuition:** Recursive calls dominate

**Case 2:** f(n) = Θ(n^c log^k(n)) where c = log_b(a)
- **Solution:** T(n) = Θ(n^c log^(k+1)(n))
- **Intuition:** Balanced between recursion and work

**Case 3:** f(n) = Ω(n^c) where c > log_b(a)
- **Solution:** T(n) = Θ(f(n))
- **Intuition:** Non-recursive work dominates

<br>

---

## Master Theorem Examples

### Example 1: Binary Search
```
T(n) = T(n/2) + O(1)
a = 1, b = 2, f(n) = O(1) = O(n⁰)
log_b(a) = log_2(1) = 0

Case 2: c = 0 = log_b(a)
Solution: T(n) = O(n⁰ log n) = O(log n)
```

### Example 2: Merge Sort
```
T(n) = 2T(n/2) + O(n)
a = 2, b = 2, f(n) = O(n) = O(n¹)
log_b(a) = log_2(2) = 1

Case 2: c = 1 = log_b(a)
Solution: T(n) = O(n log n)
```

### Example 3: Binary Tree Traversal
```
T(n) = 2T(n/2) + O(1)
a = 2, b = 2, f(n) = O(1) = O(n⁰)
log_b(a) = log_2(2) = 1

Case 1: c = 0 < 1
Solution: T(n) = O(n¹) = O(n)
```

### Example 4: Strassen's Matrix Multiplication
```
T(n) = 7T(n/2) + O(n²)
a = 7, b = 2, f(n) = O(n²)
log_b(a) = log_2(7) ≈ 2.81

Case 1: c = 2 < 2.81
Solution: T(n) = O(n^2.81)
```

<br>

---

## Common Recurrence Relations

| Recurrence | Solution | Example Algorithm |
|------------|----------|------------------|
| T(n) = T(n-1) + O(1) | O(n) | Factorial, Linear Search |
| T(n) = T(n-1) + O(n) | O(n²) | Selection Sort |
| T(n) = 2T(n-1) + O(1) | O(2ⁿ) | Fibonacci (naive) |
| T(n) = T(n/2) + O(1) | O(log n) | Binary Search |
| T(n) = T(n/2) + O(n) | O(n) | Find median |
| T(n) = 2T(n/2) + O(1) | O(n) | Tree traversal |
| T(n) = 2T(n/2) + O(n) | O(n log n) | Merge Sort, Quick Sort |
| T(n) = T(n-1) + T(n-2) + O(1) | O(2ⁿ) | Fibonacci |

<br>

---

## Space Complexity Recurrences

**Space = Maximum Recursion Depth × Space per Call**

**Examples:**

```cpp
// Factorial
S(n) = S(n-1) + O(1)
Solution: S(n) = O(n)

// Binary Search
S(n) = S(n/2) + O(1)
Solution: S(n) = O(log n)

// Merge Sort
S(n) = S(n/2) + O(n)  // Temp array
Solution: S(n) = O(n)
```

<br>

---

## Optimizing Based on Recurrence

### Problem: Fibonacci O(2ⁿ)
```
T(n) = T(n-1) + T(n-2) + O(1)
```

**Optimization 1: Memoization**
```
Store computed values
T(n) = O(n) with O(n) space
```

**Optimization 2: Iteration**
```
Bottom-up approach
T(n) = O(n) with O(1) space
```

**Optimization 3: Matrix Exponentiation**
```
T(n) = O(log n) with O(1) space
```

<br>

---

## Applications

1. **Algorithm Analysis:** Determine time/space complexity
2. **Optimization:** Identify bottlenecks
3. **Comparison:** Choose between algorithms
4. **Prediction:** Estimate runtime for large inputs
5. **Interview Prep:** Explain complexity rigorously

<br>
<br>

---



---

## Constraints

- `0 ≤ n ≤ 20 (for exponential solutions)`
- `n ≤ 10⁵ for polynomial solutions`
- `Values may include duplicates`

<br>

---

## All Possible Edge Cases

1. **Empty input:** Return [] or [[]]
2. **Single element:** One subset or one subarray
3. **All duplicates:** Must skip to avoid duplicate results
4. **n at maximum:** Verify 2ⁿ doesn't exceed time/memory limits
5. **Negative numbers:** Affects sum-based problems

<br>

---

```code```
