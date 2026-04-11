Understanding constraints is crucial for choosing the right approach and avoiding Time Limit Exceeded (TLE) or Memory Limit Exceeded (MLE) errors.

<br>

## Typical Constraint Format

```
Constraints:
- 1 ≤ n ≤ 10^5
- 1 ≤ arr[i] ≤ 10^9
- Memory limit: 256 MB
- Time limit: 1 second
```

<br>

---

## Time Constraints

### Standard Time Limits

**Online Judges:**
- Competitive Programming: 1-2 seconds
- LeetCode/HackerRank: 2-3 seconds
- Interviews: Usually not explicitly stated

**Rule of Thumb:** Modern computers execute ~10^8 to 10^9 simple operations per second.

### Operations Per Second by System

| System Architecture | Operations/Second |
|---------------------|-------------------|
| 32-bit system | ~10^8 operations |
| 64-bit system | ~10^9 operations |

**Safe Estimate:** Assume **10^8 operations per second** for calculations.

<br>

### Time Complexity vs Input Size

Given **Time Limit = 1 second** (10^8 operations):

| Input Size (n) | Max Complexity | Algorithm Examples |
|----------------|----------------|-------------------|
| n ≤ 10 | O(n!) | Permutations, Brute force |
| n ≤ 20 | O(2^n) | Subset generation, Backtracking |
| n ≤ 500 | O(n^3) | Floyd-Warshall, DP with 3 loops |
| n ≤ 5,000 | O(n^2) | Bubble sort, Nested loops |
| n ≤ 10^5 | O(n log n) | Merge sort, Binary search tree |
| n ≤ 10^6 | O(n) | Linear scan, Hash map |
| n ≤ 10^9 | O(log n) | Binary search |
| n ≤ 10^18 | O(1) | Math formula |

<br>

### Example Calculations

**Example 1:** n = 10^5, Time limit = 1 second

```
O(n²) = (10^5)² = 10^10 operations
Time needed = 10^10 / 10^8 = 100 seconds ❌ TLE

O(n log n) = 10^5 × log₂(10^5) ≈ 10^5 × 17 = 1.7 × 10^6 operations
Time needed = 1.7 × 10^6 / 10^8 = 0.017 seconds ✓ Safe
```

**Example 2:** n = 10^6, Time limit = 2 seconds

```
O(n) = 10^6 operations
Time needed = 10^6 / 10^8 = 0.01 seconds ✓ Safe

O(n log n) = 10^6 × log₂(10^6) ≈ 10^6 × 20 = 2 × 10^7 operations
Time needed = 2 × 10^7 / 10^8 = 0.2 seconds ✓ Safe

O(n²) = (10^6)² = 10^12 operations
Time needed = 10^12 / 10^8 = 10,000 seconds ❌ TLE
```

<br>

---

## Memory Constraints

### Standard Memory Limits

**Online Judges:**
- Competitive Programming: 256 MB - 512 MB
- LeetCode: 256 MB - 1 GB
- Interviews: Usually 256 MB - 512 MB

<br>

### Data Type Sizes

#### Primitive Data Types

| Data Type | 32-bit System | 64-bit System | Range |
|-----------|---------------|---------------|-------|
| `char` | 1 byte | 1 byte | -128 to 127 |
| `unsigned char` | 1 byte | 1 byte | 0 to 255 |
| `short` | 2 bytes | 2 bytes | -32,768 to 32,767 |
| `int` | 4 bytes | 4 bytes | -2^31 to 2^31-1 (~±2×10^9) |
| `unsigned int` | 4 bytes | 4 bytes | 0 to 2^32-1 (~4×10^9) |
| `long` | 4 bytes | 8 bytes | System dependent |
| `long long` | 8 bytes | 8 bytes | -2^63 to 2^63-1 (~±9×10^18) |
| `float` | 4 bytes | 4 bytes | ~7 decimal digits |
| `double` | 8 bytes | 8 bytes | ~15 decimal digits |
| `bool` | 1 byte | 1 byte | true/false |
| `pointer` | 4 bytes | 8 bytes | Memory address |

<br>

### Array Memory Calculations

#### 1D Array

```cpp
int arr[n];
```

**Memory:** `n × sizeof(int) = n × 4 bytes`

**Examples:**
```
n = 10^5 → 10^5 × 4 = 400,000 bytes = 400 KB ✓
n = 10^6 → 10^6 × 4 = 4,000,000 bytes = 4 MB ✓
n = 10^7 → 10^7 × 4 = 40,000,000 bytes = 40 MB ✓
n = 10^8 → 10^8 × 4 = 400,000,000 bytes = 400 MB ⚠️ (close to limit)
```

<br>

#### 2D Array

```cpp
int arr[n][m];
```

**Memory:** `n × m × sizeof(int) = n × m × 4 bytes`

**Examples:**
```
n = 1000, m = 1000 → 10^6 × 4 = 4 MB ✓
n = 5000, m = 5000 → 25 × 10^6 × 4 = 100 MB ✓
n = 10^4, m = 10^4 → 10^8 × 4 = 400 MB ⚠️ (close to limit)
n = 10^5, m = 10^5 → 10^10 × 4 = 40 GB ❌ MLE
```

<br>

#### 3D Array

```cpp
int arr[n][m][k];
```

**Memory:** `n × m × k × sizeof(int) = n × m × k × 4 bytes`

**Examples:**
```
n = 100, m = 100, k = 100 → 10^6 × 4 = 4 MB ✓
n = 500, m = 500, k = 500 → 125 × 10^6 × 4 = 500 MB ❌ MLE (if limit is 256 MB)
```

<br>

### Memory Limit Calculations

**Given:** Memory limit = 256 MB

**Convert to bytes:** 256 MB = 256 × 1024 × 1024 = 268,435,456 bytes ≈ 2.68 × 10^8 bytes

**Maximum array sizes:**

```
int array (4 bytes):
Max elements = 2.68 × 10^8 / 4 = 6.7 × 10^7 elements

long long array (8 bytes):
Max elements = 2.68 × 10^8 / 8 = 3.35 × 10^7 elements

char array (1 byte):
Max elements = 2.68 × 10^8 / 1 = 2.68 × 10^8 elements

2D int array (n × n):
Max n = √(6.7 × 10^7) ≈ 8,185 × 8,185
```

<br>

### Memory Limit Examples

**Example 1:** Memory limit = 256 MB, Need 2D array

```cpp
int dp[5000][5000];
Memory = 5000 × 5000 × 4 = 100,000,000 bytes = 100 MB ✓ Safe
```

**Example 2:** Memory limit = 512 MB, Need 2D array

```cpp
long long dp[10000][10000];
Memory = 10^4 × 10^4 × 8 = 800,000,000 bytes = 800 MB ❌ MLE
```

**Solution:** Use `int` instead or optimize space.

```cpp
int dp[10000][10000];
Memory = 10^4 × 10^4 × 4 = 400,000,000 bytes = 400 MB ✓ Safe
```

<br>

---

## Choosing the Right Data Type

### Based on Value Range

| Value Range | Data Type | Size |
|-------------|-----------|------|
| 0 to 255 | `unsigned char` | 1 byte |
| -128 to 127 | `char` | 1 byte |
| -32,768 to 32,767 | `short` | 2 bytes |
| -2×10^9 to 2×10^9 | `int` | 4 bytes |
| 0 to 4×10^9 | `unsigned int` | 4 bytes |
| -9×10^18 to 9×10^18 | `long long` | 8 bytes |

<br>

### Example: Choosing Data Type

**Problem:** Array elements can be up to 10^9

```cpp
// ❌ Wrong: char can only hold -128 to 127
char arr[n];

// ❌ Wrong: short can only hold -32,768 to 32,767
short arr[n];

// ✓ Correct: int can hold -2×10^9 to 2×10^9
int arr[n];
```

**Problem:** Need to store sum of 10^5 elements, each up to 10^9

```cpp
// ❌ Wrong: int max = 2×10^9, sum can be 10^5 × 10^9 = 10^14
int sum = 0;

// ✓ Correct: long long max = 9×10^18
long long sum = 0;
```

<br>

---

## Clarifying Questions to Ask

### 1. Input Size Constraints

**Questions:**
- "What is the maximum value of n?"
- "Can n be 0 or negative?"
- "What is the range of array elements?"
- "Can the array contain duplicates?"
- "Is the array sorted?"

**Example:**
```
Problem: Find two numbers that sum to target

Clarifying Questions:
Q: What is the maximum size of the array?
A: n ≤ 10^5

Q: What is the range of array elements?
A: -10^9 ≤ arr[i] ≤ 10^9

Q: Can the array contain duplicates?
A: Yes

Decision: Use HashMap (O(n)) instead of nested loops (O(n²))
```

<br>

### 2. Output Constraints

**Questions:**
- "What should I return if no solution exists?"
- "Should I return indices or values?"
- "Can there be multiple valid answers?"
- "What order should the output be in?"

**Example:**
```
Problem: Find all pairs with sum = k

Clarifying Questions:
Q: Should I return pairs or just count?
A: Return all pairs

Q: Can I use the same element twice?
A: No, each element can be used once

Q: What if there are duplicates?
A: Return all unique pairs

Decision: Use set to avoid duplicate pairs
```

<br>

### 3. Edge Cases

**Questions:**
- "What if the input is empty?"
- "What if all elements are the same?"
- "What if there's only one element?"
- "Can the input contain negative numbers?"
- "What about integer overflow?"

**Example:**
```
Problem: Find maximum subarray sum

Clarifying Questions:
Q: What if all numbers are negative?
A: Return the least negative number

Q: Can the array be empty?
A: No, n ≥ 1

Q: What is the range of elements?
A: -10^4 ≤ arr[i] ≤ 10^4

Decision: Use Kadane's algorithm, handle all negatives case
```

<br>

### 4. Time and Space Constraints

**Questions:**
- "What is the time limit?"
- "What is the memory limit?"
- "Is there a preference for time vs space optimization?"

**Example:**
```
Problem: Check if array has duplicates

Given: n ≤ 10^5, Memory limit = 256 MB

Clarifying Questions:
Q: Can I use extra space?
A: Yes, within memory limits

Decision: Use HashSet O(n) time, O(n) space
Alternative: Sort O(n log n) time, O(1) space
```

<br>

### 5. Data Type Constraints

**Questions:**
- "What is the maximum value of the result?"
- "Can intermediate calculations overflow?"
- "Should I use 32-bit or 64-bit integers?"

**Example:**
```
Problem: Calculate factorial of n

Clarifying Questions:
Q: What is the maximum value of n?
A: n ≤ 20

Q: Should I return the exact value or modulo?
A: Exact value

Calculation: 20! ≈ 2.4 × 10^18
Decision: Use long long (max 9×10^18) ✓
```

<br>

---

## Common Pitfalls

### 1. Integer Overflow

```cpp
// ❌ Wrong: Overflow when n = 10^5, arr[i] = 10^9
int sum = 0;
for (int i = 0; i < n; i++) {
    sum += arr[i];  // Can exceed 2×10^9
}

// ✓ Correct: Use long long
long long sum = 0;
for (int i = 0; i < n; i++) {
    sum += arr[i];
}
```

<br>

### 2. Memory Limit Exceeded

```cpp
// ❌ Wrong: 10^5 × 10^5 × 4 = 40 GB
int dp[100000][100000];

// ✓ Correct: Optimize space or use smaller dimensions
int dp[5000][5000];  // 100 MB
```

<br>

### 3. Wrong Data Type

```cpp
// ❌ Wrong: int can't hold 10^18
int result = pow(10, 18);

// ✓ Correct: Use long long
long long result = pow(10, 18);
```

<br>

### 4. Pointer Size Confusion

```cpp
// 32-bit system: pointer = 4 bytes
// 64-bit system: pointer = 8 bytes

int* ptr[1000000];  // 1M pointers

// 32-bit: 1M × 4 = 4 MB
// 64-bit: 1M × 8 = 8 MB
```

<br>

---

## Quick Reference Table

### Time Complexity Decision

| n | Use | Avoid |
|---|-----|-------|
| ≤ 10 | O(n!), O(2^n) | - |
| ≤ 20 | O(2^n), O(n^3) | O(n!) |
| ≤ 500 | O(n^3) | O(2^n) |
| ≤ 5,000 | O(n^2) | O(n^3) |
| ≤ 10^5 | O(n log n) | O(n^2) |
| ≤ 10^6 | O(n) | O(n log n) |
| ≤ 10^9 | O(log n) | O(n) |

<br>

### Memory Limit Decision (256 MB)

| Data Structure | Max Size |
|----------------|----------|
| `int` array | ~6.7 × 10^7 elements |
| `long long` array | ~3.35 × 10^7 elements |
| `int` 2D array (n×n) | ~8,000 × 8,000 |
| `long long` 2D array (n×n) | ~5,700 × 5,700 |

<br>
<br>

---

```code```
