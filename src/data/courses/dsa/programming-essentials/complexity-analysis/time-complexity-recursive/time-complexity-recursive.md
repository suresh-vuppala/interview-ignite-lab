Understanding time complexity of recursive programs is crucial for analyzing divide-and-conquer algorithms and recursive solutions.

<br>

---

## What Makes Recursive Programs Different?

Recursive programs call themselves, creating a call stack. Time complexity depends on:
- Number of recursive calls
- Work done per call
- Depth of recursion

<br>

---

## Master Theorem for Divide and Conquer

For recurrences of form: T(n) = aT(n/b) + f(n)

Where:
- a = number of subproblems
- n/b = size of each subproblem
- f(n) = work done outside recursive calls

**Three Cases:**

1. **Case 1:** If f(n) = O(n^c) where c < log_b(a)
   - T(n) = Θ(n^log_b(a))

2. **Case 2:** If f(n) = Θ(n^c) where c = log_b(a)
   - T(n) = Θ(n^c log n)

3. **Case 3:** If f(n) = Ω(n^c) where c > log_b(a)
   - T(n) = Θ(f(n))

<br>

---

## Common Recursive Patterns

### Pattern 1: Single Recursive Call

```
function solve(n) {
    if (n <= 1) return 1;
    return solve(n - 1) + O(1);
}
```

**Analysis:** T(n) = T(n-1) + O(1) = O(n)

<br>

### Pattern 2: Two Recursive Calls (Binary Recursion)

```
function fib(n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

**Analysis:** T(n) = T(n-1) + T(n-2) + O(1) = O(2^n)

<br>

### Pattern 3: Divide and Conquer (Halving)

```
function binarySearch(arr, left, right, target) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] > target) 
        return binarySearch(arr, left, mid-1, target);
    return binarySearch(arr, mid+1, right, target);
}
```

**Analysis:** T(n) = T(n/2) + O(1) = O(log n)

<br>

### Pattern 4: Merge Sort Pattern

```
function mergeSort(arr, left, right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right); // O(n)
}
```

**Analysis:** T(n) = 2T(n/2) + O(n) = O(n log n)

<br>

---

## Step-by-Step Analysis Method

### Step 1: Identify Base Case
What's the stopping condition? What's returned?

### Step 2: Count Recursive Calls
How many times does function call itself?

### Step 3: Determine Input Size Reduction
By how much does input size decrease each call?

### Step 4: Calculate Work Per Call
What operations happen outside recursive calls?

### Step 5: Write Recurrence Relation
Combine all factors: T(n) = [recursive calls] + [work per call]

### Step 6: Solve Recurrence
Use Master Theorem, recursion tree, or substitution method

<br>

---

## Examples with Analysis

### Example 1: Factorial

```
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

**Analysis:**
- Recursive calls: 1 per level
- Input reduction: n → n-1
- Work per call: O(1)
- Recurrence: T(n) = T(n-1) + O(1)
- **Time Complexity: O(n)**

<br>

### Example 2: Tower of Hanoi

```
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        move(from, to);
        return;
    }
    hanoi(n-1, from, aux, to);
    move(from, to);
    hanoi(n-1, aux, to, from);
}
```

**Analysis:**
- Recursive calls: 2 per level
- Input reduction: n → n-1
- Work per call: O(1)
- Recurrence: T(n) = 2T(n-1) + O(1)
- **Time Complexity: O(2^n)**

<br>

### Example 3: Binary Search

```
int binarySearch(int arr[], int left, int right, int x) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x)
        return binarySearch(arr, left, mid-1, x);
    return binarySearch(arr, mid+1, right, x);
}
```

**Analysis:**
- Recursive calls: 1 per level
- Input reduction: n → n/2
- Work per call: O(1)
- Recurrence: T(n) = T(n/2) + O(1)
- **Time Complexity: O(log n)**

<br>

### Example 4: Merge Sort

```
void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}
```

**Analysis:**
- Recursive calls: 2 per level
- Input reduction: n → n/2
- Work per call: O(n) for merge
- Recurrence: T(n) = 2T(n/2) + O(n)
- Using Master Theorem: a=2, b=2, f(n)=n
- log_b(a) = log_2(2) = 1, f(n) = Θ(n^1)
- **Time Complexity: O(n log n)**

<br>

---

## Recursion Tree Method

Visualize recursive calls as a tree to calculate total work.

**Example: T(n) = 2T(n/2) + n**

```
Level 0:           n                    → n work
                  / \
Level 1:        n/2  n/2                → n work
               / \   / \
Level 2:     n/4 n/4 n/4 n/4            → n work
             ...
Level log n: 1 1 1 ... 1 (n times)      → n work
```

Total levels: log n
Work per level: n
**Total: O(n log n)**

<br>

---

## Space Complexity of Recursion

Space complexity = Maximum depth of recursion stack

**Examples:**

1. **Linear Recursion:** O(n)
   - factorial(n), sum(n)

2. **Logarithmic Recursion:** O(log n)
   - binarySearch(n)

3. **Binary Tree Recursion:** O(h)
   - Tree traversals, h = height

4. **Exponential Recursion:** O(n)
   - fibonacci(n) - depth is n, not 2^n

<br>

---

## Common Recurrence Relations

| Recurrence | Time Complexity | Example |
|------------|-----------------|---------|
| T(n) = T(n-1) + O(1) | O(n) | Factorial, Linear search |
| T(n) = T(n-1) + O(n) | O(n²) | Selection sort |
| T(n) = 2T(n-1) + O(1) | O(2^n) | Fibonacci, Tower of Hanoi |
| T(n) = T(n/2) + O(1) | O(log n) | Binary search |
| T(n) = T(n/2) + O(n) | O(n) | Randomized select |
| T(n) = 2T(n/2) + O(1) | O(n) | Tree traversal |
| T(n) = 2T(n/2) + O(n) | O(n log n) | Merge sort, Quick sort |
| T(n) = T(n-1) + T(n-2) + O(1) | O(2^n) | Fibonacci |

<br>

---

## Key Takeaways

1. **Identify the pattern** - single call, binary, divide-and-conquer
2. **Write recurrence relation** - T(n) = aT(n/b) + f(n)
3. **Use Master Theorem** when applicable
4. **Draw recursion tree** for visualization
5. **Space complexity** = recursion depth
6. **Memoization** can reduce exponential to polynomial

> **Interview Tip:** Always explain your recurrence relation clearly. Say: "This makes 2 recursive calls on half the input, with O(n) work per call, giving us T(n) = 2T(n/2) + O(n) = O(n log n)."

<br>
<br>

---
