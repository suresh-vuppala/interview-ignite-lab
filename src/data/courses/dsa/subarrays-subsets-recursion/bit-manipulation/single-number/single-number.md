Find the single element that appears once when all others appear twice.

<br>

> Input:
> arr = [4, 1, 2, 1, 2]

> Output:
> 4

> Explanation:
> 1 appears twice, 2 appears twice, 4 appears once
> XOR all elements: duplicates cancel out (a ^ a = 0)
> 
> **Key insight:** XOR has self-cancellation property: a ^ a = 0 and a ^ 0 = a.

<br>

---

## Problem: Single Number (LeetCode 136)

Given an array where every element appears twice except one, find the single element.

**Constraint:** Linear time O(N), constant space O(1).

**Example:**
```cpp
arr = [2, 3, 5, 4, 5, 3, 4]
Duplicates: 3, 4, 5 (appear twice)
Single: 2 (appears once)
Output: 2
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

## Solution: XOR All Elements

**Intuition:**
XOR has magical properties for this problem:
- `a ^ a = 0` (any number XOR itself is 0)
- `a ^ 0 = a` (any number XOR 0 is itself)
- XOR is commutative and associative

XOR all elements → duplicates cancel → single number remains.

**Algorithm:**
```cpp
result = 0
for num in arr:
    result ^= num
return result
```

**Step-by-Step Example:**
```cpp
arr = [4, 1, 2, 1, 2]

result = 0
result ^= 4 → 0 ^ 4 = 4
result ^= 1 → 4 ^ 1 = 5
result ^= 2 → 5 ^ 2 = 7
result ^= 1 → 7 ^ 1 = 6
result ^= 2 → 6 ^ 2 = 4

Result: 4
```

**Why it works (rearranged):**
```cpp
result = 4 ^ 1 ^ 2 ^ 1 ^ 2
       = 4 ^ (1 ^ 1) ^ (2 ^ 2)  // Rearrange (commutative)
       = 4 ^ 0 ^ 0              // Self-cancellation
       = 4                       // Identity
```

**Binary Level:**
```cpp
arr = [4, 1, 2, 1, 2]

  0000 (initial)
^ 0100 (4) = 0100
^ 0001 (1) = 0101
^ 0010 (2) = 0111
^ 0001 (1) = 0110
^ 0010 (2) = 0100 (4)
```

### Time Complexity: O(N)
**Why?**
- Single pass through array
- XOR operation: O(1) per element
- Total: N × O(1) = O(N)

### Space Complexity: O(1)
**Why?**
- Only one variable (result)
- No additional data structures
- In-place XOR accumulation

<br>

---

## Why Not Other Approaches?

**Hash Map:**
- Time: O(N), Space: O(N)
- Violates O(1) space constraint

**Sorting:**
- Time: O(N log N), Space: O(1)
- Violates O(N) time constraint

**XOR:**
- Time: O(N), Space: O(1) ✓
- Optimal solution!

<br>

---

## Applications

1. **Data Integrity:** Find corrupted element in duplicate data
2. **Network Protocols:** Detect missing packet in transmission
3. **Memory Management:** Track unpaired allocations
4. **Error Detection:** Find single bit flip in data
5. **Puzzle Solving:** Mathematical brain teasers

<br>
<br>

---

```code```
