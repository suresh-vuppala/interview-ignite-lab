Master the fundamentals of recursion - a powerful problem-solving technique.

<br>

> **Recursion Definition:**
> A function that calls itself to solve smaller instances of the same problem.

> **Key Components:**
> 1. Base Case: Stopping condition
> 2. Recursive Case: Function calls itself with smaller input
> 3. Progress: Each call moves toward base case
> 
> **Key insight:** Break complex problems into simpler subproblems of the same type.

<br>

---

## What is Recursion?

**Intuition:**
Recursion solves a problem by breaking it into smaller instances of the same problem.
Like Russian nesting dolls - each doll contains a smaller version of itself.

**Three Essential Components:**

1. **Base Case:** Simplest form that can be solved directly (no recursion needed)
2. **Recursive Case:** Problem broken into smaller subproblems
3. **Progress Toward Base:** Each recursive call must move closer to base case

**Example - Factorial:**
```cpp
factorial(5) = 5 × factorial(4)
             = 5 × 4 × factorial(3)
             = 5 × 4 × 3 × factorial(2)
             = 5 × 4 × 3 × 2 × factorial(1)
             = 5 × 4 × 3 × 2 × 1  [Base case: factorial(1) = 1]
             = 120
```

<br>


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

## How Recursion Works: The Call Stack

**Call Stack Visualization:**
```cpp
factorial(3):
  Call Stack:
  [factorial(3)]           // Push factorial(3)
  [factorial(3), factorial(2)]  // Push factorial(2)
  [factorial(3), factorial(2), factorial(1)]  // Push factorial(1)
  [factorial(3), factorial(2)]  // Pop: factorial(1) returns 1
  [factorial(3)]           // Pop: factorial(2) returns 2
  []                       // Pop: factorial(3) returns 6
```

**Memory Usage:**
- Each function call uses stack space
- Maximum stack depth = recursion depth
- Stack overflow if recursion too deep

<br>

---

## Recursion vs Iteration

| Aspect | Recursion | Iteration |
|--------|-----------|----------|
| Readability | Often clearer for tree/graph problems | Better for simple loops |
| Memory | O(depth) stack space | O(1) typically |
| Performance | Function call overhead | Faster (no overhead) |
| Use Case | Tree traversal, divide & conquer | Simple counting, accumulation |

**When to Use Recursion:**
- Problem has recursive structure (trees, graphs)
- Divide and conquer approach
- Backtracking problems
- Mathematical definitions (factorial, Fibonacci)

**When to Use Iteration:**
- Simple loops
- Memory constraints
- Performance critical code

<br>

---

## Types of Recursion

### 1. Direct Recursion
Function calls itself directly.
```cpp
int factorial(int n) {
    if (n <= 1) return 1;  // Base case
    return n * factorial(n - 1);  // Direct recursive call
}
```

### 2. Indirect Recursion
Function A calls function B, which calls function A.
```cpp
void functionA(int n) {
    if (n > 0) {
        functionB(n - 1);
    }
}

void functionB(int n) {
    if (n > 0) {
        functionA(n - 1);
    }
}
```

### 3. Tail Recursion
Recursive call is the last operation.
```cpp
int factorial(int n, int acc = 1) {
    if (n <= 1) return acc;
    return factorial(n - 1, n * acc);  // Tail call
}
```
**Advantage:** Can be optimized to iteration by compiler.

### 4. Head Recursion
Recursive call is the first operation.
```cpp
void print(int n) {
    if (n > 0) {
        print(n - 1);  // Recursive call first
        cout << n << " ";
    }
}
```

<br>

---

## Common Recursion Patterns

### Pattern 1: Linear Recursion
Single recursive call per function.
```cpp
int sum(int n) {
    if (n == 0) return 0;
    return n + sum(n - 1);
}
```

### Pattern 2: Binary Recursion
Two recursive calls per function.
```cpp
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

### Pattern 3: Multiple Recursion
More than two recursive calls.
```cpp
void printCombinations(string prefix, string remaining) {
    if (remaining.empty()) {
        cout << prefix << endl;
        return;
    }
    for (int i = 0; i < remaining.length(); i++) {
        printCombinations(prefix + remaining[i], 
                         remaining.substr(0, i) + remaining.substr(i + 1));
    }
}
```

<br>

---

## Designing Recursive Solutions

**Step-by-Step Approach:**

1. **Identify Base Case(s)**
   - Simplest input that can be solved directly
   - Usually: empty, size 1, or boundary condition

2. **Define Recursive Relation**
   - How to break problem into smaller subproblems
   - Express solution in terms of smaller inputs

3. **Ensure Progress**
   - Each call must move toward base case
   - Input size must decrease

4. **Combine Results**
   - How to build solution from subproblem results

**Example - Power Function:**
```cpp
// Calculate x^n
Base case: n = 0 → return 1
Recursive: x^n = x × x^(n-1)
Progress: n decreases by 1 each call
```

<br>

---

## Common Pitfalls

### 1. Missing Base Case
```cpp
// WRONG - infinite recursion
int factorial(int n) {
    return n * factorial(n - 1);  // No base case!
}
```

### 2. No Progress Toward Base
```cpp
// WRONG - infinite recursion
int bad(int n) {
    if (n == 0) return 0;
    return bad(n);  // n doesn't change!
}
```

### 3. Multiple Base Cases Needed
```cpp
// WRONG - negative input causes infinite recursion
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

// CORRECT
int factorial(int n) {
    if (n <= 1) return 1;  // Handles 0, 1, and negative
    return n * factorial(n - 1);
}
```

### 4. Stack Overflow
```cpp
// Deep recursion can cause stack overflow
factorial(100000);  // May crash!
```

<br>

---

## Time & Space Complexity

### Time Complexity
- Count total number of recursive calls
- Multiply by work done per call

**Example - Factorial:**
```cpp
factorial(n): n calls × O(1) work = O(n)
```

**Example - Fibonacci (naive):**
```cpp
fib(n): 2^n calls × O(1) work = O(2^n)
```

### Space Complexity
- Maximum recursion depth
- Space used by each call

**Example - Factorial:**
```cpp
Depth: n
Space per call: O(1)
Total: O(n) stack space
```

<br>

---

## Applications

1. **Tree/Graph Traversal:** DFS, tree operations
2. **Divide & Conquer:** Merge sort, quick sort, binary search
3. **Backtracking:** N-Queens, Sudoku, permutations
4. **Dynamic Programming:** Fibonacci, knapsack (with memoization)
5. **Mathematical:** Factorial, GCD, power
6. **String Processing:** Palindrome check, string reversal

<br>
<br>

---

```code```
