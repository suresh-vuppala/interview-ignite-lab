Understanding time complexity of iterative programs is essential for writing efficient code and succeeding in technical interviews.

<br>

---

## What is Time Complexity?

Time complexity measures how the runtime of an algorithm grows as the input size increases. It answers: "If I double the input size, how much longer will my program take?"

**Key Points:**
- Expressed using Big O notation: O(1), O(n), O(n²), etc.
- Focuses on growth rate, not exact time
- Ignores constants and lower-order terms
- Helps compare algorithms objectively

<br>

---

## Why Time Complexity Matters

### In Interviews
- Interviewers expect you to analyze your solution
- Often asked: "What's the time complexity?"
- Shows understanding beyond just coding

### In Real Applications
- Difference between O(n) and O(n²) is huge for large data
- Example: n=1,000,000
  - O(n): 1 million operations
  - O(n²): 1 trillion operations!

<br>

---

## Basic Rules for Iterative Programs

### Rule 1: Single Loop = O(n)

A loop that runs n times has O(n) complexity.

**Example:**
```
for (int i = 0; i < n; i++) {
    // O(1) operation
}
```
**Analysis:** Loop runs n times, each iteration is O(1) → Total: O(n)

<br>

### Rule 2: Nested Loops = Multiply

Nested loops multiply their complexities.

**Example:**
```
for (int i = 0; i < n; i++) {        // O(n)
    for (int j = 0; j < n; j++) {    // O(n)
        // O(1) operation
    }
}
```
**Analysis:** Outer loop O(n) × Inner loop O(n) → Total: O(n²)

<br>

### Rule 3: Sequential Loops = Add

Sequential loops add their complexities.

**Example:**
```
for (int i = 0; i < n; i++) {    // O(n)
    // operation
}
for (int j = 0; j < n; j++) {    // O(n)
    // operation
}
```
**Analysis:** O(n) + O(n) = O(2n) → Simplified: O(n)

<br>

### Rule 4: Drop Constants

Constants don't affect growth rate.

**Example:**
- O(2n) → O(n)
- O(3n + 5) → O(n)
- O(n/2) → O(n)

**Why?** For large n, constants become insignificant.

<br>

### Rule 5: Drop Lower-Order Terms

Keep only the fastest-growing term.

**Example:**
- O(n² + n) → O(n²)
- O(n³ + n² + n) → O(n³)
- O(n log n + n) → O(n log n)

**Why?** For large n, higher-order terms dominate.

<br>

---

## Common Time Complexities

### O(1) - Constant Time
**Description:** Time doesn't depend on input size

**Examples:**
```
// Accessing array element
int x = arr[5];

// Arithmetic operation
int sum = a + b;

// Comparison
if (x > y) { }
```

**Characteristics:**
- Best possible complexity
- Same time for any input size
- No loops or recursion

<br>

### O(log n) - Logarithmic Time
**Description:** Time grows logarithmically with input

**Examples:**
```
// Binary search
while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) left = mid + 1;
    else right = mid - 1;
}

// Dividing problem in half each time
while (n > 1) {
    n = n / 2;
}
```

**Characteristics:**
- Very efficient
- Input halved each iteration
- Common in divide-and-conquer

<br>

### O(n) - Linear Time
**Description:** Time grows linearly with input

**Examples:**
```
// Single loop through array
for (int i = 0; i < n; i++) {
    sum += arr[i];
}

// Finding maximum
int max = arr[0];
for (int i = 1; i < n; i++) {
    if (arr[i] > max) max = arr[i];
}
```

**Characteristics:**
- Most common complexity
- Visit each element once
- Efficient for most problems

<br>

### O(n log n) - Linearithmic Time
**Description:** Combination of linear and logarithmic

**Examples:**
```
// Merge sort, Quick sort (average)
for (int i = 0; i < n; i++) {        // O(n)
    // Binary search: O(log n)
}
```

**Characteristics:**
- Optimal for comparison-based sorting
- Better than O(n²), worse than O(n)
- Common in efficient algorithms

<br>

### O(n²) - Quadratic Time
**Description:** Time grows quadratically with input

**Examples:**
```
// Nested loops
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // operation
    }
}

// Bubble sort, Selection sort
```

**Characteristics:**
- Acceptable for small inputs (n < 1000)
- Slow for large inputs
- Often can be optimized

<br>

### O(2^n) - Exponential Time
**Description:** Time doubles with each input increase

**Examples:**
```
// Generate all subsets
for (int i = 0; i < (1 << n); i++) {
    // process subset
}

// Recursive Fibonacci (naive)
```

**Characteristics:**
- Very slow, impractical for n > 20
- Common in brute force solutions
- Usually needs optimization

<br>

---

## Analyzing Complex Examples

### Example 1: Two Separate Loops

```java
for (int i = 0; i < n; i++) {
    arr[i] = i;
}

for (int i = 0; i < m; i++) {
    brr[i] = i;
}
```

**Analysis:**
- First loop: O(n)
- Second loop: O(m)
- Total: O(n + m)
- **Cannot simplify to O(n)** because n and m are different

<br>

### Example 2: Nested Loop with Different Bounds

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        // O(1) operation
    }
}
```

**Analysis:**
- Outer loop: O(n)
- Inner loop: O(m)
- Total: O(n × m)

<br>

### Example 3: Loop with Increment by 2

```
for (int i = 0; i < n; i += 2) {
    // operation
}
```

**Analysis:**
- Loop runs n/2 times
- O(n/2) → Drop constant → O(n)

<br>

### Example 4: Dependent Nested Loops

```
for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
        // operation
    }
}
```

**Analysis:**
- i=0: inner loop runs n times
- i=1: inner loop runs n-1 times
- i=2: inner loop runs n-2 times
- Total: n + (n-1) + (n-2) + ... + 1 = n(n+1)/2 = O(n²)

<br>

### Example 5: Loop with Multiplication

```
for (int i = 1; i < n; i *= 2) {
    // operation
}
```

**Analysis:**
- i takes values: 1, 2, 4, 8, 16, ..., n
- Number of iterations: log₂(n)
- Total: O(log n)

<br>

---

## Step-by-Step Analysis Method

### Step 1: Identify All Loops
Count how many loops exist and their relationships

### Step 2: Determine Loop Iterations
How many times does each loop run?

### Step 3: Check Loop Dependencies
Are loops nested or sequential?

### Step 4: Calculate Total Operations
- Nested: Multiply
- Sequential: Add

### Step 5: Simplify
- Drop constants
- Drop lower-order terms
- Express in Big O notation

<br>

---

## Common Patterns and Their Complexities

| Pattern | Complexity | Example |
|---------|------------|----------|
| Single loop | O(n) | Linear search |
| Two nested loops | O(n²) | Bubble sort |
| Three nested loops | O(n³) | Matrix multiplication |
| Loop dividing by 2 | O(log n) | Binary search |
| Loop + Binary search | O(n log n) | Sorting |
| Two separate loops | O(n + m) | Process two arrays |
| Loop with i*=2 | O(log n) | Exponential growth |

<br>

---

## Practice Problems

### Problem 1
```
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        sum += arr[i] + arr[j];
    }
}
```
**Answer:** O(n²)
**Explanation:** Inner loop depends on i, total iterations = 0+1+2+...+(n-1) = n(n-1)/2 = O(n²)

<br>

### Problem 2
```
for (int i = 0; i < n; i++) {
    // O(1)
}
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // O(1)
    }
}
```
**Answer:** O(n²)
**Explanation:** O(n) + O(n²) = O(n²) (drop lower-order term)

<br>

### Problem 3
```
int i = n;
while (i > 0) {
    i = i / 2;
}
```
**Answer:** O(log n)
**Explanation:** i is halved each iteration: n, n/2, n/4, ..., 1 → log₂(n) iterations

<br>

---

## Key Takeaways

1. **Count loop iterations** to determine complexity
2. **Nested loops multiply**, sequential loops add
3. **Drop constants and lower-order terms**
4. **Different variables** (n, m) cannot be combined
5. **Logarithmic complexity** comes from halving/doubling
6. **Practice analyzing** code snippets regularly

> **Interview Tip:** Always state your time complexity analysis clearly. Walk through your reasoning: "This loop runs n times, and inside we have another loop running m times, so the total complexity is O(n × m)."

<br>
<br>

---