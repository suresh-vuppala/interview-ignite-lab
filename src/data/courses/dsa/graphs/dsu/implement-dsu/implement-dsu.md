Implement Disjoint Set Union (Union-Find) with path compression and union by rank.

<br>

---

## Solution 1: Naive (Array Parent)

find(): follow parent chain. union(): set parent.

### Time: O(n) per operation worst case

<br>

---

## Solution 2: Path Compression + Union by Rank (Optimal)

**Path Compression:** During find, make every node point directly to root.
**Union by Rank:** Attach shorter tree under taller tree.

### Time: O(α(n)) ≈ O(1) amortized per operation
### Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time per op | Space | Key Improvement |
|----------|------------|-------|----------------|
| Naive | O(n) | O(n) | Linear chain |
| Compression + Rank | O(α(n)) ≈ O(1) | O(n) | Near-constant via optimizations |

<br>
<br>

---

```code```
