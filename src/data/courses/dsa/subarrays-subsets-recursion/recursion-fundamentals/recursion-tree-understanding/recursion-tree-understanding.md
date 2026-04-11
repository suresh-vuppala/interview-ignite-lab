Visualize recursion as a tree to understand execution flow and complexity.

<br>

> **Recursion Tree:**
> Visual representation where each node is a function call.

> **Key Components:**
> - Root: Initial function call
> - Nodes: Recursive calls
> - Edges: Call relationships
> - Leaves: Base cases
> 
> **Key insight:** Tree structure reveals time/space complexity and optimization opportunities.

<br>

---

## What is a Recursion Tree?

**Intuition:**
A recursion tree visualizes how recursive calls branch out.
Each node represents a function call, edges show parent-child relationships.

**Tree Properties:**
- **Root:** Original function call
- **Internal Nodes:** Recursive calls that spawn more calls
- **Leaves:** Base cases (no further recursion)
- **Height:** Maximum recursion depth
- **Width:** Maximum calls at any level

<br>

---

## Example 1: Factorial

**Code:**
```cpp
int factorial(int n) {
    if (n <= 1) return 1;  // Base case
    return n * factorial(n - 1);
}
```

**Recursion Tree for factorial(4):**
```
                factorial(4)
                     |
                factorial(3)
                     |
                factorial(2)
                     |
                factorial(1)  [Base case: returns 1]
```

**Analysis:**
- **Height:** 4 (depth of recursion)
- **Total Nodes:** 4 (one per call)
- **Time Complexity:** O(n) - linear chain
- **Space Complexity:** O(n) - call stack depth

**Pattern:** Linear recursion creates a single path (no branching).

<br>

---

## Example 2: Fibonacci (Naive)

**Code:**
```cpp
int fib(int n) {
    if (n <= 1) return n;  // Base case
    return fib(n - 1) + fib(n - 2);
}
```

**Recursion Tree for fib(5):**
```
                    fib(5)
                   /      \
              fib(4)        fib(3)
             /     \       /     \
        fib(3)   fib(2) fib(2)  fib(1)
       /    \    /   \   /   \
   fib(2) fib(1) f(1) f(0) f(1) f(0)
   /   \
fib(1) fib(0)
```

**Analysis:**
- **Height:** 5
- **Total Nodes:** 15 (2^5 - 1 approximately)
- **Time Complexity:** O(2^n) - exponential
- **Space Complexity:** O(n) - maximum depth

**Key Observation:** Many repeated subproblems!
- fib(3) computed 2 times
- fib(2) computed 3 times
- fib(1) computed 5 times

**Optimization:** Memoization can reduce to O(n).

<br>

---

## Example 3: Binary Search

**Code:**
```cpp
int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) return -1;  // Base case
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] > target)
        return binarySearch(arr, left, mid - 1, target);
    return binarySearch(arr, mid + 1, right, target);
}
```

**Recursion Tree for array of size 8:**
```
                [0...7]
                   |
                [0...3]  or  [4...7]
                   |
              [0...1]  or  [2...3]
                   |
              [0] or [1]
```

**Analysis:**
- **Height:** log(n)
- **Total Nodes:** log(n) (only one path taken)
- **Time Complexity:** O(log n)
- **Space Complexity:** O(log n) - call stack

**Pattern:** Each level eliminates half the problem space.

<br>

---

## Analyzing Time Complexity from Tree

**Formula:**
```
Time Complexity = (Number of Nodes) × (Work per Node)
```

**Counting Nodes:**

1. **Linear Recursion:** O(n) nodes
   - Example: factorial, sum of array

2. **Binary Recursion:** O(2^n) nodes (worst case)
   - Example: naive Fibonacci
   - Each node spawns 2 children

3. **Divide & Conquer:** O(n log n) often
   - Example: merge sort
   - Tree height: log(n), work per level: O(n)

**Work Per Node:**
- Count operations excluding recursive calls
- Usually O(1) or O(n)

<br>

---

## Analyzing Space Complexity from Tree

**Formula:**
```
Space Complexity = (Maximum Depth) × (Space per Call)
```

**Maximum Depth = Tree Height**

**Examples:**

1. **Factorial:** Height = n → Space = O(n)
2. **Fibonacci:** Height = n → Space = O(n)
3. **Binary Search:** Height = log(n) → Space = O(log n)
4. **Merge Sort:** Height = log(n), temp arrays → Space = O(n)

**Note:** Space is determined by deepest path, not total nodes.

<br>

---

## Example 4: Merge Sort

**Recursion Tree:**
```
Level 0:        [8 elements]                    Work: O(n)
                /          \
Level 1:    [4 elem]      [4 elem]              Work: O(n)
            /    \        /    \
Level 2: [2]    [2]    [2]    [2]              Work: O(n)
         / \    / \    / \    / \
Level 3:[1][1][1][1][1][1][1][1]              Work: O(n)
```

**Analysis:**
- **Height:** log(n)
- **Nodes per Level:** 2^level
- **Work per Level:** O(n) total
- **Time Complexity:** O(n log n)
- **Space Complexity:** O(n) for temp arrays + O(log n) stack

<br>

---

## Identifying Overlapping Subproblems

**Overlapping Subproblems:** Same subproblem computed multiple times.

**Detection in Tree:**
- Look for duplicate subtrees
- Same function call with same parameters

**Example - Fibonacci:**
```
fib(5) calls fib(3) twice
fib(4) and fib(3) both call fib(2)
```

**Solution:** Memoization or Dynamic Programming
- Store results of subproblems
- Reuse instead of recompute
- Transforms tree into DAG (Directed Acyclic Graph)

<br>

---

## Master Theorem (Quick Reference)

For recurrence: T(n) = aT(n/b) + f(n)

**Tree Interpretation:**
- **a:** Number of subproblems (branching factor)
- **n/b:** Size of each subproblem
- **f(n):** Work done at current level

**Cases:**
1. If f(n) = O(n^c) where c < log_b(a): T(n) = O(n^(log_b(a)))
2. If f(n) = O(n^c) where c = log_b(a): T(n) = O(n^c log n)
3. If f(n) = O(n^c) where c > log_b(a): T(n) = O(f(n))

**Examples:**
- Binary Search: T(n) = T(n/2) + O(1) → O(log n)
- Merge Sort: T(n) = 2T(n/2) + O(n) → O(n log n)
- Binary Tree Traversal: T(n) = 2T(n/2) + O(1) → O(n)

<br>

---

## Practical Tips

1. **Draw Small Examples:** Start with n=3 or n=4
2. **Count Levels:** Determines space complexity
3. **Count Nodes:** Determines time complexity
4. **Look for Patterns:** Repeated subtrees suggest memoization
5. **Check Branching Factor:** Higher branching = exponential growth

<br>

---

## Applications

1. **Complexity Analysis:** Visualize time/space requirements
2. **Optimization:** Identify redundant computations
3. **Debugging:** Trace execution flow
4. **Algorithm Design:** Understand divide & conquer strategies
5. **Interview Prep:** Explain recursive solutions clearly

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
