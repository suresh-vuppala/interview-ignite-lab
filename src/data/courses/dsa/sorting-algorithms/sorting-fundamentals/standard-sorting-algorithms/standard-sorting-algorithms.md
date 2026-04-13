Overview and comparison of all standard sorting algorithms.

<br>

> Comparison of bubble, selection, insertion, merge, quick, heap, counting, radix
>
> **Key insight:** Different algorithms excel in different scenarios. No single best algorithm for all cases.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## All Possible Edge Cases
1. **Empty/single element input**
2. **Boundary values** (min/max of range)
3. **All elements same / sorted / reverse sorted**

<br>

---

## Solution 1: N/A — reference

### Time Complexity: Varies

> **Drawback:**
> Each has tradeoffs in time, space, stability, and best/worst case.

> **Key Insight for Improvement:**
> Choose based on constraints: nearly sorted → insertion. Guaranteed O(N log N) → merge/heap. Fastest average → quick. Integer range → counting/radix.

<br>

---

## Solution 2: Algorithm Selection (Optimal)

**Intuition:** Different algorithms excel in different scenarios. No single best algorithm for all cases.

**Algorithm:**
| Algorithm | Best | Average | Worst | Space | Stable |
|-----------|------|---------|-------|-------|--------|
| Bubble | O(N) | O(N²) | O(N²) | O(1) | Yes |
| Selection | O(N²) | O(N²) | O(N²) | O(1) | No |
| Insertion | O(N) | O(N²) | O(N²) | O(1) | Yes |
| Merge | O(NlogN) | O(NlogN) | O(NlogN) | O(N) | Yes |
| Quick | O(NlogN) | O(NlogN) | O(N²) | O(logN) | No |
| Heap | O(NlogN) | O(NlogN) | O(NlogN) | O(1) | No |

### Time Complexity: Varies
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
See table above
```

### Space Complexity: Varies

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A — reference | Varies | Varies | Baseline |
| Algorithm Selection | Varies | Varies | Optimal approach |

**Recommended Solution:** Algorithm Selection — Varies time.

**Key Insights:**
1. **Comparison sort lower bound:** Ω(N log N) — can't do better
2. **Non-comparison (counting/radix):** O(N+K) for integer ranges
3. **Stability matters:** When preserving relative order of equal elements

<br><br>

---

```code```
