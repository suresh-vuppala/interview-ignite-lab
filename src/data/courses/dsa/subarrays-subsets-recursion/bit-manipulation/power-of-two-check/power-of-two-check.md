Check if a number is a power of 2 using bit manipulation.

<br>

> Input:
> n = 8 (binary: 1000)

> Output:
> True

> Explanation:
> 8 = 2^3, has exactly one set bit
> Powers of 2: 1, 2, 4, 8, 16, 32...
> 
> **Key insight:** Powers of 2 have exactly one set bit. Use n & (n-1) == 0 to check.

<br>

---

## Problem: Is Power of Two

Given a positive integer N, determine if it's a power of 2.

**Examples:**
```cpp
Powers of 2:
1 = 2^0 (0001) ✓
2 = 2^1 (0010) ✓
4 = 2^2 (0100) ✓
8 = 2^3 (1000) ✓

Not powers of 2:
3 (0011) - two set bits ✗
6 (0110) - two set bits ✗
7 (0111) - three set bits ✗
```

**Pattern:** Powers of 2 have exactly ONE set bit.

<br>

---

## Solution: n & (n-1) Trick

**Intuition:**
For powers of 2, subtracting 1 flips all bits after the single set bit.
AND operation with original gives 0.

**Algorithm:**
```cpp
return (n > 0) && ((n & (n - 1)) == 0);
```

**Why it works:**
```cpp
Power of 2:
n = 8:    1000
n-1 = 7:  0111
n & (n-1): 1000 & 0111 = 0000 ✓

n = 16:   10000
n-1 = 15: 01111
n & (n-1): 10000 & 01111 = 00000 ✓

Not power of 2:
n = 6:    0110
n-1 = 5:  0101
n & (n-1): 0110 & 0101 = 0100 (non-zero) ✗

n = 7:    0111
n-1 = 6:  0110
n & (n-1): 0111 & 0110 = 0110 (non-zero) ✗
```

**Edge Cases:**
```cpp
n = 0: Not power of 2 (need n > 0 check)
n = 1: 2^0 = 1 ✓
Negative: Not power of 2
```

### Time Complexity: O(1)
**Why?**
- Single AND operation
- Single comparison
- Constant time regardless of N

### Space Complexity: O(1)
**Why?**
- No additional storage
- Only boolean result

<br>

---

## Alternative: Count Set Bits

**Algorithm:**
```cpp
return (n > 0) && (countSetBits(n) == 1);
```

**Comparison:**
- n & (n-1): O(1) - optimal
- Count set bits: O(log N) - slower but more intuitive

<br>

---

## Applications

1. **Memory Allocation:** Check if size is power of 2 for alignment
2. **Hash Tables:** Optimize modulo with bitwise AND when size is power of 2
3. **Binary Trees:** Validate complete binary tree node counts
4. **Bit Manipulation:** Validate single-bit flags
5. **Performance:** Powers of 2 enable efficient bit shifts for multiply/divide

<br>
<br>

---

```code```