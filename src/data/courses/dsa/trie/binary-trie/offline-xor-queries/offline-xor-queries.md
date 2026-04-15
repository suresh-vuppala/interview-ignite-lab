Answer maximum XOR queries offline by sorting and processing incrementally.

<br>

> queries with value limits — process in sorted order
>
> **Key insight:** Sort queries by limit. Add numbers to binary trie incrementally as limit increases. Answer each query when all valid numbers are in trie.

<br>

---

## Constraints
- 1 ≤ N, Q ≤ 10⁵

<br>

---

## All Possible Edge Cases
1. **All limits are 0: no valid numbers
2. **All limits are MAX: use all numbers
3. **Queries already sorted**

<br>

---

## Solution 1: Online: rebuild trie per query

**Intuition:**
The most straightforward approach. Rebuilding trie for each query is wasteful.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(Q×N×32)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Rebuilding trie for each query is wasteful.

> **Key Insight for Improvement:**
> Sort queries by limit. Sort numbers. Two-pointer: add numbers ≤ current query's limit to trie, then query.

<br>

---

## Solution 2: Offline Sort + Binary Trie (Optimal)

**Intuition:** Sort queries by limit. Add numbers to binary trie incrementally as limit increases. Answer each query when all valid numbers are in trie.

**Algorithm:**
1. Sort queries by limit, sort numbers
2. Pointer j=0 for numbers
3. For each query (val, limit): while nums[j] ≤ limit → insert into trie, j++
4. Query trie for max XOR with val

### Time Complexity: O((N+Q)×32)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Sort both. Process queries in limit order, adding numbers incrementally.
```

### Space Complexity: O(N×32)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Online: rebuild trie per query | O(Q×N×32) | Varies | Baseline |
| Offline Sort + Binary Trie | O((N+Q)×32) | O(N×32) | Optimal |

**Recommended Solution:** Offline Sort + Binary Trie

**Key Insights:**
1. **Offline processing:** Sort enables incremental trie building
2. **Two-pointer:** Numbers added in order, never removed
3. **O((N+Q)×32):** Much better than O(Q×N×32)

<br><br>

---

```code```
