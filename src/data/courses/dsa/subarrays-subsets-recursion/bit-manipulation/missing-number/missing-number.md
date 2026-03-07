Find the missing number in an array containing n distinct numbers from 0 to n.

<br>

> Input:
> arr = [3, 0, 1], n = 3

> Output:
> 2

> Explanation:
> Array should contain [0, 1, 2, 3], missing number is 2
> XOR all indices (0^1^2^3) with all values (3^0^1) = 2
> 
> **Key insight:** XOR all numbers 0 to n with all array elements - missing number remains.

<br>

---

## Problem: Missing Number (LeetCode 268)

Given an array of n distinct numbers from range [0, n], find the missing number.

**Example:**
```cpp
arr = [9, 6, 4, 2, 3, 5, 7, 0, 1], n = 9
Range: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
Missing: 8
```

<br>

---

## Solution 1: XOR Approach (Optimal)

**Intuition:**
XOR all numbers from 0 to n with all array elements.
Numbers present in array cancel out (a ^ a = 0).
Missing number remains.

**Algorithm:**
```cpp
result = n  // Start with n
for i = 0 to n-1:
    result ^= i      // XOR with index
    result ^= arr[i] // XOR with value
return result
```

**Step-by-Step Example:**
```cpp
arr = [3, 0, 1], n = 3

result = 3

i=0: result ^= 0 ^= 3 → result = 3 ^ 0 ^ 3 = 0
i=1: result ^= 1 ^= 0 → result = 0 ^ 1 ^ 0 = 1
i=2: result ^= 2 ^= 1 → result = 1 ^ 2 ^ 1 = 2

Result: 2 (missing number)
```

**Why it works:**
```cpp
result = n ^ (0 ^ arr[0]) ^ (1 ^ arr[1]) ^ (2 ^ arr[2])
       = 3 ^ (0 ^ 3) ^ (1 ^ 0) ^ (2 ^ 1)
       = 3 ^ 0 ^ 3 ^ 1 ^ 0 ^ 2 ^ 1
       = (0 ^ 0) ^ (1 ^ 1) ^ (3 ^ 3) ^ 2  // Rearrange
       = 0 ^ 0 ^ 0 ^ 2
       = 2
```

### Time Complexity: O(N)
**Why?**
- Single pass through array
- Two XOR operations per element: O(1)
- Total: N × O(1) = O(N)

### Space Complexity: O(1)
**Why?**
- Only one variable (result)
- No additional data structures

<br>

---

## Solution 2: Sum Formula

**Intuition:**
Sum of 0 to n: `sum = n × (n+1) / 2`
Missing = Expected sum - Actual sum

**Algorithm:**
```cpp
expected_sum = n * (n + 1) / 2
actual_sum = sum(arr)
return expected_sum - actual_sum
```

**Example:**
```cpp
arr = [3, 0, 1], n = 3
expected_sum = 3 × 4 / 2 = 6
actual_sum = 3 + 0 + 1 = 4
missing = 6 - 4 = 2
```

### Time Complexity: O(N)
### Space Complexity: O(1)

**Caveat:** Risk of integer overflow for large n.

<br>

---

## Comparison

| Approach | Time | Space | Overflow Risk |
|----------|------|-------|---------------|
| XOR | O(N) | O(1) | No |
| Sum Formula | O(N) | O(1) | Yes (large n) |

**Recommendation:** XOR approach is safer (no overflow).

<br>

---

## Applications

1. **Data Validation:** Detect missing records in sequence
2. **Network Packets:** Find dropped packet in sequence
3. **Database:** Identify missing ID in sequential table
4. **File Systems:** Detect missing block in sequence
5. **Quality Assurance:** Find missing test case number

<br>
<br>

---

```code```