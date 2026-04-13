Java HashMap internals: hashCode, equals, tree buckets.

<br>

> How java.util.HashMap works
>
> **Key insight:** hashCode() determines bucket. equals() resolves collisions. Treeification: bucket converts to red-black tree at size 8.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: N/A — implementation knowledge

### Time Complexity: O(1) average

> **Drawback:**
> Worst case O(log N) with tree buckets (O(N) without).

> **Key Insight for Improvement:**
> Override both hashCode() and equals() correctly. Java 8+ treeifies long chains.

<br>

---

## Solution 2: HashMap Internals (Optimal)

**Intuition:** hashCode() determines bucket. equals() resolves collisions. Treeification: bucket converts to red-black tree at size 8.

**Algorithm:**
Bucket array + chaining (linked list → tree at threshold 8)
hashCode() → bucket index via (h = hash) ^ (h >>> 16)
Load factor 0.75, double capacity on rehash

### Time Complexity: O(1) avg, O(log N) worst
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
HashMap<String,Integer> m = new HashMap<>();
m.put("key", 42); // hashCode("key") → bucket → store entry
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A — implementation knowledge | O(1) average | Varies | Baseline |
| HashMap Internals | O(1) avg, O(log N) worst | O(N) | Optimal |

**Recommended Solution:** HashMap Internals

**Key Insights:**
1. **hashCode + equals contract:** Equal objects must have equal hashCodes
2. **Treeification at 8:** Long chains become red-black trees
3. **Initial capacity:** Set to expected size / 0.75 for performance

<br><br>

---

```code```
