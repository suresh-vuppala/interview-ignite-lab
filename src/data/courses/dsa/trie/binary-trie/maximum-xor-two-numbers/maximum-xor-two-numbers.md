Find the maximum XOR of any two numbers in an array.

<br>

> Input:
> nums = [3, 10, 5, 25, 2, 8]

> Output:
> 28

> Explanation:
> - Maximum XOR is 5 XOR 25 = 28
> - Binary: 00101 XOR 11001 = 11100 = 28
> - For each bit position, we get opposite bits
> 
> **Key insight:** Use binary trie to greedily choose opposite bits from MSB to LSB.

<br>


---

## Constraints

- `1 ≤ number of words ≤ 3 × 10⁴`
- `1 ≤ word length ≤ 2000`
- `Words consist of lowercase English letters (unless stated otherwise)`

<br>

---

## All Possible Edge Cases

1. **Empty trie:** Search returns false, prefix returns false
2. **Single character words:** Trie depth = 1
3. **All same word inserted:** Count or flag must handle duplicates
4. **Prefix is also a complete word:** isEnd flag must be separate from having children
5. **Very long word:** Deep trie path
6. **No matching prefix:** Return false or empty list

<br>

---

## Solution: Binary Trie with Greedy Bit Selection

**Algorithm:**
1. Insert all numbers into binary trie (bit by bit from MSB)
2. For each number, find maximum XOR:
   - Traverse trie choosing opposite bit when possible
   - If opposite bit exists, take it (maximizes XOR)
   - Otherwise, take available bit
3. Track maximum XOR found

**Key insight:** Greedy choice of opposite bit at each level maximizes XOR.

```code```

<br>

### Time Complexity Analysis

**Overall: O(N×32) = O(N)**

**Build Trie: O(N×32)**
- Insert N numbers: O(N)
- Each number has 32 bits: O(32) per insert
- Total: O(N×32)

**Find Max XOR: O(N×32)**
- Query N numbers: O(N)
- Each query traverses 32 bits: O(32)
- Total: O(N×32)

**Why Binary Trie is efficient?**
- Brute force: O(N²) to check all pairs
- Binary Trie: O(N×32) = O(N) with constant factor
- Greedy bit selection guarantees maximum XOR

**Space Complexity: O(N×32)**
- Store N numbers in trie
- Each number uses up to 32 nodes
- Shared prefixes reduce actual space

**Applications:**
- Network optimization
- Data compression
- Cryptography

> **Time Complexity:** O(N) where N is array length
> **Space Complexity:** O(N) for binary trie storage

<br>
<br>

---
