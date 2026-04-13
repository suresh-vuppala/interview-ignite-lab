Place M balls maximizing minimum magnetic force (distance). Same as aggressive cows.

<br>

> positions=[1,2,3,4,7], m=3 → 3
>
> **Key insight:** Identical to aggressive cows. Binary search on minimum distance, greedy placement.

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

## Solution 1: Same as aggressive cows

### Time Complexity: O(C(N,M))

> **Drawback:**
> Same combinatorial explosion.

> **Key Insight for Improvement:**
> Same BS + greedy pattern.

<br>

---

## Solution 2: BS on Min Distance (Optimal)

**Intuition:** Identical to aggressive cows. Binary search on minimum distance, greedy placement.

**Algorithm:**
Same algorithm as aggressive cows

### Time Complexity: O(N log D)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
Same as aggressive cows with different variable names
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Same as aggressive cows | O(C(N,M)) | Varies | Baseline |
| BS on Min Distance | O(N log D) | O(1) | Optimal approach |

**Recommended Solution:** BS on Min Distance — O(N log D) time.

**Key Insights:**
1. **Identical to aggressive cows:** Same algorithm, LeetCode 1552
2. **Sort + BS + greedy:** The universal maximize-minimum pattern

<br><br>

---

```code```
