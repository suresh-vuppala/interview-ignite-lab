Check if kth bit is set, set it, unset it, or toggle it.

<br>

> n=5(101), k=1: check→0, set→7(111), toggle→7(111)
>
> **Key insight:** Use bitmask (1<<k). Check: n&mask. Set: n|mask. Unset: n&~mask. Toggle: n^mask.

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

## Solution 1: N/A — direct operations

### Time Complexity: O(1)

> **Drawback:**
> N/A — these are O(1) bit tricks.

> **Key Insight for Improvement:**
> Bitmask (1<<k) isolates the kth bit for any operation.

<br>

---

## Solution 2: Bitmask Operations (Optimal)

**Intuition:** Use bitmask (1<<k). Check: n&mask. Set: n|mask. Unset: n&~mask. Toggle: n^mask.

**Algorithm:**
Check: (n >> k) & 1, or n & (1<<k)
Set: n | (1<<k)
Unset: n & ~(1<<k)
Toggle: n ^ (1<<k)

### Time Complexity: O(1)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
n=5(101): check bit 1: (101>>1)&1=10&1=0 (not set)
Set bit 1: 101|010=111=7
Toggle bit 1: 101^010=111=7
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A — direct operations | O(1) | Varies | Baseline |
| Bitmask Operations | O(1) | O(1) | Optimal approach |

**Recommended Solution:** Bitmask Operations — O(1) time.

**Key Insights:**
1. **1<<k creates mask:** Single bit at position k
2. **~mask inverts:** For unsetting
3. **Essential toolkit:** Used in generate subsets, DP bitmask, etc.

<br><br>

---

```code```
