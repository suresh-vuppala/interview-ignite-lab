Find maximum XOR of any two numbers in an array.

<br>

> nums=[3,10,5,25,2,8] → 28 (5^25=28)
>
> **Key insight:** Build binary trie of all numbers. For each number, greedily find the number giving maximum XOR.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Check all pairs

### Time Complexity: O(N²)

> **Drawback:**
> Quadratic pair checking.

> **Key Insight for Improvement:**
> Binary trie: insert all numbers. For each number, query trie choosing opposite bits greedily.

<br>

---

## Solution 2: Binary Trie + Greedy (Optimal)

**Intuition:** Build binary trie of all numbers. For each number, greedily find the number giving maximum XOR.

**Algorithm:**
1. Insert all numbers into binary trie
2. For each number: query max XOR by choosing opposite bit at each level
3. Track global maximum

### Time Complexity: O(N×32)=O(N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Insert [3,10,5,25,2,8]. Query 5(00101): at each bit, choose opposite → finds 25(11001)
XOR: 00101^11001=11100=28 ✓
```

### Space Complexity: O(N×32)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check all pairs | O(N²) | Varies | Baseline |
| Binary Trie + Greedy | O(N×32)=O(N) | O(N×32) | Optimal |

**Recommended Solution:** Binary Trie + Greedy

**Key Insights:**
1. **Greedy: opposite bit maximizes XOR at each position**
2. **MSB to LSB:** Higher bits have more value
3. **O(N) total:** 32 is constant

<br><br>

---

```code```
