C++ unordered_map/unordered_set hashing internals.

<br>

> **Key insight:** Default hash, bucket system, load factor, rehashing.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Hash table: buckets + chaining/probing

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Hash table: buckets + chaining/probing`

### Time Complexity: O(1) average
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(1) average | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
