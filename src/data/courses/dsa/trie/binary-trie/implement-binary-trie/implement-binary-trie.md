Implement a trie for binary representation of numbers to support XOR operations efficiently.

**Binary Trie:** Each node has two children (0 and 1), stores numbers bit by bit from MSB to LSB.

<br>

> Input:
> Operations: ["insert", 5], ["insert", 3], ["getMaxXor", 2]
> (Binary: 5=101, 3=011, 2=010)

> Output:
> [null, null, 7]

> Explanation:
> - insert(5): Add 101 to trie
> - insert(3): Add 011 to trie
> - getMaxXor(2): Find max XOR with 010
>   - 2 XOR 5 = 010 XOR 101 = 111 = 7 (maximum)
>   - 2 XOR 3 = 010 XOR 011 = 001 = 1
> 
> **Key insight:** Choose opposite bit at each level to maximize XOR.

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

## Solution: Binary Trie with Bit Traversal

**Binary Trie Structure:**
- Each node has two children: 0 and 1
- Store numbers bit by bit (31 bits for integers)
- Traverse from MSB to LSB

**Operations:**
1. **Insert**: Add number bit by bit (31 to 0)
2. **getMaxXor**: For each bit, choose opposite bit if exists

**Key insight:** Greedy choice of opposite bit maximizes XOR.



<br>

### Time Complexity Analysis

**All Operations: O(32) = O(1)**

**Insert: O(32)**
- Process 32 bits: O(32)
- Create nodes if needed: O(1) per bit
- Total: O(32) = O(1)

**getMaxXor: O(32)**
- Traverse 32 bits: O(32)
- Choose opposite bit: O(1) per bit
- Total: O(32) = O(1)

**Why Binary Trie is efficient?**
- Brute force: O(N) to check all numbers
- Binary Trie: O(32) = O(1) regardless of N
- Greedy bit selection guarantees maximum XOR

**Space Complexity: O(N×32)**
- N numbers, each 32 bits
- Shared prefixes reduce actual space
- Worst case: All numbers different = O(N×32)

**Applications:**
- Maximum XOR problems
- Network routing (IP addresses)
- Compression algorithms

> **Time Complexity:** O(1) for all operations (32 bits constant)
> **Space Complexity:** O(N×32) for N numbers

<br>
<br>

---

---

```code```
