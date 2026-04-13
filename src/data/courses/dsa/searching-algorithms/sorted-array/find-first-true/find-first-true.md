Find the first element satisfying a boolean condition in a sorted/monotonic array.

<br>

> arr=[F,F,F,T,T,T], find first True → index 3
>
> **Key insight:** Binary search for boundary: if condition(mid) is true → search left for earlier true. If false → search right.

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

## Solution 1: Linear scan from left

### Time Complexity: O(N)

> **Drawback:**
> Checks every element sequentially.

> **Key Insight for Improvement:**
> Binary search: if condition(mid) true → ans=mid, hi=mid-1. If false → lo=mid+1. Finds leftmost True.

<br>

---

## Solution 2: Binary Search for Boundary (Optimal)

**Intuition:** Binary search for boundary: if condition(mid) is true → search left for earlier true. If false → search right.

**Algorithm:**
1. lo=0, hi=N-1, ans=-1
2. While lo ≤ hi:
   - mid = lo + (hi-lo)/2
   - If condition(mid): ans=mid, hi=mid-1 (look for earlier)
   - Else: lo=mid+1
3. Return ans

### Time Complexity: O(log N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[F,F,F,T,T,T]: mid=2(F)→lo=3, mid=4(T)→ans=4,hi=3, mid=3(T)→ans=3,hi=2→done. First True=3
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Linear scan from left | O(N) | Varies | Baseline |
| Binary Search for Boundary | O(log N) | O(1) | Optimal approach |

**Recommended Solution:** Binary Search for Boundary — O(log N) time.

**Key Insights:**
1. **Monotonic property:** Once True, stays True — enables binary search
2. **Template:** Most binary search problems reduce to "find first True"
3. **Applications:** Lower bound, first occurrence, search on answer

<br><br>

---

```code```
