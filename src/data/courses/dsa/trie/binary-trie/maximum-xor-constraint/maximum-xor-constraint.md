Find the maximum XOR of two elements where one element must be ≤ K.

<br>

> Input:
> nums = [0, 1, 2, 3, 4], K = 3

> Output:
> 3

> Explanation:
> - We need one element ≤ 3
> - Maximum XOR: 0 XOR 3 = 3
> - Binary: 00 XOR 11 = 11 = 3
> - Other valid pairs: (1,2)=3, but not better
> 
> **Key insight:** Traverse trie while respecting constraint K's bit pattern.

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

## Solution: Binary Trie with Constraint Checking

**Algorithm:**
1. Insert all numbers ≤ K into binary trie
2. For each number in array:
   - Traverse trie choosing opposite bit when possible
   - Check if path stays within constraint K
   - If choosing opposite bit violates K, take other path
3. Track maximum XOR found

**Key insight:** Only insert numbers ≤ K, then find max XOR with any number.



<br>

### Time Complexity Analysis

**Overall: O(N×32) = O(N)**

**Build Trie: O(N×32)**
- Filter and insert numbers ≤ K: O(N)
- Each insertion: O(32) bits
- Total: O(N×32)

**Find Max XOR: O(N×32)**
- Query with each number: O(N)
- Each query: O(32) bits with constraint check
- Total: O(N×32)

**Why constraint checking works?**
- Pre-filter numbers ≤ K during insertion
- Guarantees one element in XOR pair is ≤ K
- No backtracking needed during query

**Space Complexity: O(N×32)**
- Store numbers ≤ K in trie
- Worst case: all numbers ≤ K
- Shared prefixes reduce space

**Applications:**
- Constrained optimization problems
- Range query problems
- Network routing with constraints

> **Time Complexity:** O(N) where N is array length
> **Space Complexity:** O(N) for binary trie storage

<br>
<br>

---

---

```code```
