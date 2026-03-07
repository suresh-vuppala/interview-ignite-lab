Find two elements appearing once when all others appear twice.

<br>

> Input:
> arr = [2, 4, 7, 9, 2, 4]

> Output:
> [7, 9]

> Explanation:
> 2 and 4 appear twice, 7 and 9 appear once
> XOR all → get 7^9, find rightmost set bit, partition array
> 
> **Key insight:** Use rightmost set bit of (a ^ b) to partition array into two groups.

<br>

---

## Problem: Two Non-Repeating Numbers

Given an array where every element appears twice except two, find both single elements.

**Constraint:** Linear time O(N), constant space O(1).

**Example:**
```cpp
arr = [1, 2, 3, 2, 1, 4]
Duplicates: 1, 2 (appear twice)
Singles: 3, 4 (appear once)
Output: [3, 4]
```

<br>

---

## Solution: Partition by Rightmost Set Bit

**Intuition:**
1. XOR all elements → get `xor_result = a ^ b` (two singles)
2. Find any set bit in xor_result (where a and b differ)
3. Partition array by this bit → a in one group, b in other
4. XOR each group separately → get a and b

**Algorithm:**
```cpp
// Step 1: XOR all to get a ^ b
xor_all = 0
for num in arr:
    xor_all ^= num

// Step 2: Find rightmost set bit
rightmost_bit = xor_all & -xor_all

// Step 3: Partition and XOR each group
a = 0, b = 0
for num in arr:
    if (num & rightmost_bit):
        a ^= num
    else:
        b ^= num

return [a, b]
```

**Detailed Example:**
```cpp
arr = [2, 4, 7, 9, 2, 4]

Step 1: XOR all
xor_all = 2 ^ 4 ^ 7 ^ 9 ^ 2 ^ 4
        = (2 ^ 2) ^ (4 ^ 4) ^ 7 ^ 9
        = 0 ^ 0 ^ 7 ^ 9
        = 7 ^ 9
        = 0111 ^ 1001 = 1110 (14)

Step 2: Find rightmost set bit
xor_all = 1110
-xor_all = 0010 (two's complement)
rightmost_bit = 1110 & 0010 = 0010 (bit 1)

Step 3: Partition by bit 1
Group 1 (bit 1 set): 2 (0010), 7 (0111)
  XOR: 2 ^ 7 = 0010 ^ 0111 = 0101 (5)... wait
  Actually: 2 ^ 2 ^ 7 = 7

Group 2 (bit 1 not set): 4 (0100), 9 (1001)
  XOR: 4 ^ 4 ^ 9 = 9

Result: [7, 9]
```

**Why Rightmost Set Bit?**
```cpp
xor_all = a ^ b
If bit i is set in xor_all:
  → bit i differs in a and b
  → one has 0, other has 1
  → partitioning by bit i separates a and b
```

**Binary Visualization:**
```cpp
a = 7:  0111
b = 9:  1001
a^b=14: 1110

Rightmost set bit at position 1:
- 7 has bit 1 set (0111)
- 9 has bit 1 not set (1001)
- Perfect separation!
```

### Time Complexity: O(N)
**Why?**
- First pass: XOR all elements - O(N)
- Find rightmost bit: O(1)
- Second pass: Partition and XOR - O(N)
- Total: O(N) + O(1) + O(N) = O(N)

### Space Complexity: O(1)
**Why?**
- Only few variables (xor_all, rightmost_bit, a, b)
- No additional data structures
- In-place operations

<br>

---

## Key Insights

1. **XOR All:** Duplicates cancel, get a ^ b
2. **Set Bit:** Any set bit in (a ^ b) indicates difference
3. **Partition:** Separate array by this bit
4. **XOR Groups:** Each group has one single number

**Why Any Set Bit Works:**
- Rightmost is convenient (easy to find)
- Any set bit separates a and b
- Duplicates stay together in same group

<br>

---

## Applications

1. **Data Recovery:** Find two corrupted elements
2. **Network Analysis:** Detect two missing packets
3. **Quality Control:** Identify two defective items
4. **Cryptography:** Find two different keys
5. **Debugging:** Locate two unpaired resources

<br>
<br>

---

```code```