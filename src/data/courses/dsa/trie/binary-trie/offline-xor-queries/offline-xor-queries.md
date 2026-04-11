Answer Q queries where query[i] = [xi, mi]: find maximum XOR of xi with any element nums[j] where j ≤ mi.

<br>

> Input:
> nums = [0, 1, 2, 3, 4]
> queries = [[3, 1], [1, 3], [5, 6]]

> Output:
> [3, 3, 7]

> Explanation:
> - Query [3, 1]: max XOR of 3 with nums[0..1] = max(3^0, 3^1) = 3
> - Query [1, 3]: max XOR of 1 with nums[0..3] = max(1^0, 1^1, 1^2, 1^3) = 3
> - Query [5, 6]: max XOR of 5 with nums[0..4] = max(5^0, 5^1, 5^2, 5^3, 5^4) = 7
> 
> **Key insight:** Sort queries by index, build trie incrementally to answer offline.

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

## Solution: Offline Query Processing with Binary Trie

**Algorithm:**
1. Sort queries by index mi (offline processing)
2. Maintain pointer in nums array
3. For each query in sorted order:
   - Insert nums elements up to index mi into trie
   - Query trie for maximum XOR with xi
   - Store result at original query position
4. Return results in original query order

**Key insight:** Process queries offline to build trie incrementally, avoiding rebuilds.



<br>

### Time Complexity Analysis

**Overall: O((N+Q)×32 + Q log Q)**

**Sort Queries: O(Q log Q)**
- Sort Q queries by index: O(Q log Q)

**Build Trie Incrementally: O(N×32)**
- Insert each of N numbers once: O(N)
- Each insertion: O(32) bits
- Total: O(N×32)

**Answer Queries: O(Q×32)**
- Process Q queries: O(Q)
- Each query: O(32) bits traversal
- Total: O(Q×32)

**Why offline processing is efficient?**
- Online: O(Q×N×32) - rebuild trie for each query
- Offline: O((N+Q)×32) - build trie once incrementally
- Sorting overhead: O(Q log Q) is negligible

**Space Complexity: O(N×32 + Q)**
- Trie storage: O(N×32)
- Query storage with indices: O(Q)
- Result array: O(Q)

**Applications:**
- Range query optimization
> Batch processing systems
- Historical data analysis

> **Time Complexity:** O((N+Q) + Q log Q) where N is array length, Q is queries
> **Space Complexity:** O(N + Q) for trie and query storage

<br>
<br>

---

---

```code```
