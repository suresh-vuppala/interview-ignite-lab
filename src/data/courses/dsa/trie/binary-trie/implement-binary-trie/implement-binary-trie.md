Binary trie storing integers bit by bit for XOR operations.

<br>

> Insert 5(101), 7(111). Max XOR with 2(010) → 7 (010^111=101=5)
>
> **Key insight:** Store each integer as 32-bit path (MSB to LSB). Each node has children[0] and children[1].

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: N/A — data structure

**Intuition:**
The most straightforward approach. N/A — this is the implementation.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(32) per op
**Why?**
The approach processes each state/element with the work described by the complexity.
Total operations scale accordingly with input size.

**Detailed breakdown:**
Verify against constraint limits to ensure it passes within time.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> N/A — this is the implementation.

> **Key Insight for Improvement:**
> Binary trie: 32 levels, each level = one bit. Insert/query in O(32) = O(1).

<br>

---

## Solution 2: Binary Trie (Optimal)

**Intuition:** Store each integer as 32-bit path (MSB to LSB). Each node has children[0] and children[1].

**Algorithm:**
1. Insert: for bit from 31 to 0 → follow/create child[bit]
2. Max XOR query: for each bit, greedily choose OPPOSITE bit if possible
3. This maximizes XOR at each bit position (greedy from MSB)

### Time Complexity: O(32)=O(1) per op
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Insert 5(00101): root→0→0→1→0→1
Query max XOR with 2(00010): want opposite bits → try 1,1,0,0,1 → find closest match
```

### Space Complexity: O(N×32)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A — data structure | O(32) per op | Varies | Baseline |
| Binary Trie | O(32)=O(1) per op | O(N×32) | Optimal |

**Recommended Solution:** Binary Trie

**Key Insights:**
1. **MSB first:** Higher bits matter more for maximizing XOR
2. **Greedy opposite bit:** At each level, choose the bit that gives 1 in XOR
3. **Foundation:** Maximum XOR problems

<br><br>

---

```code```
