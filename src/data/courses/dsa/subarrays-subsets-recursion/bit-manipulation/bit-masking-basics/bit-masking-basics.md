Master fundamental bitwise operations and bit manipulation techniques.

<br>

> **Bit Representation:**
> Number 5 in binary: 0101
> Number 3 in binary: 0011

> **Operations:**
> 5 & 3 = 0001 (1) - AND
> 5 | 3 = 0111 (7) - OR
> 5 ^ 3 = 0110 (6) - XOR
> 
> **Key insight:** Bitwise operations work at the binary level, enabling O(1) operations on individual bits for efficient algorithms.

<br>

---

## Fundamental Bitwise Operators

### 1. AND Operator (&)

**Intuition:**
Returns 1 only if BOTH bits are 1.

**Truth Table:**
```cpp
0 & 0 = 0
0 & 1 = 0
1 & 0 = 0
1 & 1 = 1
```

**Example:**
```cpp
  5:  0101
& 3:  0011
-----------
  1:  0001
```

**Common Uses:**
- Check if bit is set: `(n & (1 << k)) != 0`
- Check even/odd: `n & 1`
- Extract lower bits: `n & ((1 << k) - 1)`

<br>

### 2. OR Operator (|)

**Intuition:**
Returns 1 if AT LEAST ONE bit is 1.

**Truth Table:**
```cpp
0 | 0 = 0
0 | 1 = 1
1 | 0 = 1
1 | 1 = 1
```

**Example:**
```cpp
  5:  0101
| 3:  0011
-----------
  7:  0111
```

**Common Uses:**
- Set specific bit: `n | (1 << k)`
- Combine flags: `flag1 | flag2`

<br>

### 3. XOR Operator (^) - Exclusive OR

**Intuition:**
Returns 1 if bits are DIFFERENT.

**Truth Table:**
```cpp
0 ^ 0 = 0
0 ^ 1 = 1
1 ^ 0 = 1
1 ^ 1 = 0
```

**Example:**
```cpp
  5:  0101
^ 3:  0011
-----------
  6:  0110
```

**XOR Properties (Critical!):**
1. **Self-cancellation:** `a ^ a = 0`
2. **Identity:** `a ^ 0 = a`
3. **Commutative:** `a ^ b = b ^ a`
4. **Associative:** `(a ^ b) ^ c = a ^ (b ^ c)`
5. **Reversible:** If `a ^ b = c`, then `c ^ b = a`

**Common Uses:**
- Toggle bit: `n ^ (1 << k)`
- Swap without temp: `a ^= b; b ^= a; a ^= b;`
- Find unique element: XOR all, duplicates cancel

<br>

### 4. NOT Operator (~) - Bitwise Complement

**Intuition:**
Flips all bits: 0 becomes 1, 1 becomes 0.

**Example:**
```cpp
  5:  00000101 (8-bit)
~5:  11111010 = -6 (two's complement)
```

**Important:** In two's complement, `~n = -(n+1)`

**Common Uses:**
- Create bit mask: `~0` gives all 1s
- Clear bits: `n & ~mask`

<br>

### 5. Left Shift (<<)

**Intuition:**
Shifts all bits left by n positions.
Equivalent to multiplying by 2^n.

**Example:**
```cpp
5 << 1:  0101 → 1010 = 10
5 << 2:  0101 → 10100 = 20

Pattern: n << k = n × 2^k
```

**Common Uses:**
- Multiply by power of 2: `n << k`
- Create bit mask: `1 << k`
- Generate powers of 2: `1 << 0 = 1, 1 << 1 = 2, 1 << 2 = 4`

<br>

### 6. Right Shift (>>)

**Intuition:**
Shifts all bits right by n positions.
Equivalent to dividing by 2^n (floor division).

**Example:**
```cpp
5 >> 1:  0101 → 0010 = 2
5 >> 2:  0101 → 0001 = 1

Pattern: n >> k = n ÷ 2^k
```

**Common Uses:**
- Divide by power of 2: `n >> k`
- Extract higher bits: `n >> k`
- Iterate through bits: shift right until n becomes 0

<br>

---

## Operator Precedence (Important!)

```cpp
Highest to Lowest:
1. ~ (NOT)
2. << >> (Shifts)
3. & (AND)
4. ^ (XOR)
5. | (OR)

Example:
a | b & c  →  a | (b & c)  [NOT (a | b) & c]
```

**Best Practice:** Use parentheses for clarity!

<br>

---

## Common Pitfalls

1. **Operator Precedence:** Bitwise operators have lower precedence than comparison
   ```cpp
   if (n & 1 == 0)  // WRONG! Parsed as: n & (1 == 0)
   if ((n & 1) == 0)  // CORRECT
   ```

2. **Overflow:** Left shift can cause overflow
   ```cpp
   1 << 31  // May overflow on 32-bit int
   1LL << 31  // Use long long for safety
   ```

3. **Signed vs Unsigned:** Right shift behavior differs
   - Signed: Arithmetic shift (preserves sign)
   - Unsigned: Logical shift (fills with 0)

<br>

---

## Quick Reference Table

| Operator | Syntax | Result | Use Case |
|----------|--------|--------|----------|
| AND | `5 & 3` | 1 | Check bits, extract patterns |
| OR | `5 \| 3` | 7 | Set bits, combine flags |
| XOR | `5 ^ 3` | 6 | Toggle bits, find differences |
| NOT | `~5` | -6 | Flip bits, create masks |
| Left Shift | `5 << 2` | 20 | Multiply by 2^k |
| Right Shift | `20 >> 2` | 5 | Divide by 2^k |

<br>

---

## Applications

1. **Subset Generation:** Use bitmask to represent subsets
2. **Dynamic Programming:** Bitmask DP for state compression
3. **Optimization:** Replace multiplication/division by 2^n with shifts
4. **Flags/Permissions:** Store multiple boolean flags in single integer
5. **Graphics:** Color manipulation, alpha blending
6. **Cryptography:** XOR cipher, bit-level encryption
7. **Networking:** IP address manipulation, subnet masks

<br>
<br>

---

```code```