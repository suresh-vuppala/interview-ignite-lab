Perform four essential bit operations at a specific position.

<br>

> Input:
> n = 10 (binary: 1010), position = 1

> Operations:
> Check bit 1: True (bit is set)
> Set bit 1: 10 (already set)
> Unset bit 1: 8 (binary: 1000)
> Toggle bit 1: 8 (binary: 1000)
> 
> **Key insight:** Use bit masks with (1 << position) to target specific bits.

<br>

---

## Problem: Manipulate Bit at Position K

Given a number N and position K (0-indexed from right), perform:
1. **Check** if Kth bit is set (1 or 0)
2. **Set** Kth bit to 1
3. **Unset** (Clear) Kth bit to 0
4. **Toggle** Kth bit (flip 0↔1)

**Example:**
```cpp
N = 5 (binary: 0101)
K = 1

Check bit 1: 0101 → bit 1 is 0 → False
Set bit 1:   0101 → 0111 = 7
Unset bit 1: 0101 → 0101 = 5 (already 0)
Toggle bit 1: 0101 → 0111 = 7
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

## Solution: Bit Mask Operations

**Intuition:**
Create a mask with only Kth bit set: `mask = 1 << K`
Combine mask with N using appropriate operator for each operation.

### Operation 1: Check Kth Bit

**Algorithm:**
```cpp
bool isSet = (N & (1 << K)) != 0;
```

**How it works:**
- `1 << K` creates mask with only Kth bit set
- AND operation isolates Kth bit
- Non-zero result means bit is set

**Example:**
```cpp
N = 5 (0101), K = 2
mask = 1 << 2 = 0100
N & mask = 0101 & 0100 = 0100 (non-zero)
Result: True (bit 2 is set)

N = 5 (0101), K = 1
mask = 1 << 1 = 0010
N & mask = 0101 & 0010 = 0000 (zero)
Result: False (bit 1 is not set)
```

### Operation 2: Set Kth Bit

**Algorithm:**
```cpp
N = N | (1 << K);
```

**How it works:**
- OR operation sets bit to 1 (idempotent: already 1 stays 1)
- Other bits remain unchanged

**Example:**
```cpp
N = 5 (0101), K = 1
mask = 1 << 1 = 0010
N | mask = 0101 | 0010 = 0111 = 7
Result: 7
```

### Operation 3: Unset (Clear) Kth Bit

**Algorithm:**
```cpp
N = N & ~(1 << K);
```

**How it works:**
- `~(1 << K)` creates mask with all bits 1 except Kth bit
- AND operation clears Kth bit
- Other bits remain unchanged

**Example:**
```cpp
N = 7 (0111), K = 1
mask = 1 << 1 = 0010
~mask = 1101
N & ~mask = 0111 & 1101 = 0101 = 5
Result: 5
```

### Operation 4: Toggle Kth Bit

**Algorithm:**
```cpp
N = N ^ (1 << K);
```

**How it works:**
- XOR flips the bit (0→1, 1→0)
- Other bits remain unchanged

**Example:**
```cpp
N = 5 (0101), K = 1
mask = 1 << 1 = 0010
N ^ mask = 0101 ^ 0010 = 0111 = 7

Toggle again:
N = 7 (0111), K = 1
N ^ mask = 0111 ^ 0010 = 0101 = 5
```

<br>

---

## Complexity Analysis

### Time Complexity: O(1)
**Why?**
- Shift operation: O(1)
- Bitwise operation (AND/OR/XOR/NOT): O(1)
- All operations are single CPU instructions

### Space Complexity: O(1)
**Why?**
- Only store mask and result
- No additional data structures

<br>

---

## Quick Reference

| Operation | Formula | Use Case |
|-----------|---------|----------|
| Check | `(N & (1 << K)) != 0` | Test if bit is 1 |
| Set | `N \ (1 << K)` | Force bit to 1 |
| Unset | `N & ~(1 << K)` | Force bit to 0 |
| Toggle | `N ^ (1 << K)` | Flip bit (0↔1) |

<br>

---

## Applications

1. **Permissions/Flags:** Manage user permissions as bit flags
2. **State Management:** Track multiple boolean states in single integer
3. **Graphics:** Manipulate pixel colors, alpha channels
4. **Networking:** Set/check protocol flags in packet headers
5. **Compression:** Bit-level data manipulation

<br>
<br>

---

```code```
