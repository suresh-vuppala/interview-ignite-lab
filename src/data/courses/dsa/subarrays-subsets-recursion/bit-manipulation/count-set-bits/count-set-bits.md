Count the number of 1s in binary representation of a number.

<br>

> Input:
> n = 13 (binary: 1101)

> Output:
> 3

> Explanation:
> Binary 1101 has three 1s at positions 0, 2, and 3
> 
> **Key insight:** Brian Kernighan's algorithm: n & (n-1) clears the rightmost set bit, count iterations until n becomes 0.

<br>

---

## Problem: Count Set Bits (Hamming Weight)

Given an integer N, count how many bits are set to 1 in its binary representation.

**Example:**
```cpp
N = 11 (binary: 1011)
Set bits at positions: 0, 1, 3
Count = 3

N = 15 (binary: 1111)
All 4 bits are set
Count = 4
```

<br>

---

## Solution 1: Check Each Bit

**Intuition:**
Iterate through all bit positions, check if each bit is set.
Count the set bits.

**Algorithm:**
```cpp
count = 0
for i = 0 to 31:  // For 32-bit integer
    if (n & (1 << i)) != 0:
        count++
return count
```

**Example:**
```cpp
n = 13 (1101)

Check bit 0: 1101 & 0001 = 0001 ✓ count = 1
Check bit 1: 1101 & 0010 = 0000 ✗
Check bit 2: 1101 & 0100 = 0100 ✓ count = 2
Check bit 3: 1101 & 1000 = 1000 ✓ count = 3
Bits 4-31: all 0

Result: 3
```

### Time Complexity: O(log N)
**Why?**
- Check all bit positions: O(number of bits)
- For N-bit number: O(log N) bits
- For 32-bit int: O(32) = O(1)

### Space Complexity: O(1)
**Why?**
- Only counter variable
- No additional data structures

<br>

---

## Solution 2: Brian Kernighan's Algorithm (Optimal)

**Intuition:**
Instead of checking all bits, only iterate through set bits.
Key trick: `n & (n-1)` clears the rightmost set bit.
Count how many times we can clear a bit before n becomes 0.

**Algorithm:**
```cpp
count = 0
while n > 0:
    n = n & (n - 1)  // Clear rightmost set bit
    count++
return count
```

**How n & (n-1) works:**
```cpp
n = 12 (1100)
n-1 = 11 (1011)
n & (n-1) = 1100 & 1011 = 1000 (8)

Rightmost 1 in 1100 is at position 2
Subtracting 1 flips all bits from rightmost 1 to right
AND operation clears the rightmost 1
```

**Example:**
```cpp
n = 13 (1101)

Iteration 1:
n & (n-1) = 1101 & 1100 = 1100 (12)
count = 1

Iteration 2:
n & (n-1) = 1100 & 1011 = 1000 (8)
count = 2

Iteration 3:
n & (n-1) = 1000 & 0111 = 0000 (0)
count = 3

n = 0, stop
Result: 3
```

### Time Complexity: O(K) where K = number of set bits
**Why?**
- Loop runs exactly K times (once per set bit)
- Best case: O(1) when n = 0 or n = power of 2
- Worst case: O(log N) when all bits are set
- Better than Solution 1 for sparse bit patterns

**Comparison:**
- Solution 1: Always O(log N) iterations
- Solution 2: O(K) iterations where K ≤ log N
- Example: n = 2^30 has 1 set bit
  - Solution 1: 31 iterations
  - Solution 2: 1 iteration

### Space Complexity: O(1)
**Why?**
- Only counter variable
- In-place bit manipulation

<br>

---

## Complexity Comparison

| Solution | Time | Iterations for n=13 | Best For |
|----------|------|---------------------|----------|
| Check Each Bit | O(log N) | 32 (all bits) | Dense bit patterns |
| Brian Kernighan | O(K) | 3 (set bits only) | Sparse bit patterns |

**When to use each:**
- **Check Each Bit:** Simple, predictable performance
- **Brian Kernighan:** Optimal for numbers with few set bits

> **Final Complexity:** O(K) time where K = set bits, O(1) space

<br>

---

## Applications

1. **Hamming Distance:** Count differing bits between two numbers
2. **Network Protocols:** Count active flags in packet headers
3. **Error Detection:** Parity checking in data transmission
4. **Population Count:** CPU instruction (POPCNT) uses similar logic
5. **Sparse Data Structures:** Analyze bit density in bitmasks

<br>
<br>

---

```code```