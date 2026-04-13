Find the K closest points to the origin (0,0).

<br>

> points=[[1,3],[-2,2],[5,8],[0,1]], K=2 → [[-2,2],[0,1]]
>
> **Key insight:** Max-heap of size K tracking closest points. Or QuickSelect for O(N) average. Distance = x²+y² (no need for sqrt).

<br>

---

## Constraints
- Typical problem constraints apply

<br>

---

## All Possible Edge Cases
1. **Empty input:** Handle gracefully
2. **Single element:** Base case
3. **Large input:** Verify time complexity holds

<br>

---

## Solution 1: Sort all by distance

### Time Complexity: O(N log N)

> **Drawback:**
> Sorting all N points when we only need K is wasteful for K << N.

> **Key Insight for Improvement:**
> Max-heap of size K: push each point. If heap size > K, remove the farthest (max distance). After processing all, heap contains K closest.

<br>

---

## Solution 2: Max-Heap Size K (Optimal)

**Intuition:** Max-heap of size K tracking closest points. Or QuickSelect for O(N) average. Distance = x²+y² (no need for sqrt).

**Algorithm:**
1. For each point: compute distance² = x²+y²
2. Push to max-heap (by distance)
3. If heap size > K: pop max (farthest point)
4. Remaining K points = K closest

### Time Complexity: O(N log K)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
K=2: push (1,3)→d=10, push (-2,2)→d=8, push (5,8)→d=89→pop 89
push (0,1)→d=1→pop 10. Heap: [(-2,2,d=8),(0,1,d=1)] ✓
```

### Space Complexity: O(K)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort all by distance | O(N log N) | Varies | Baseline |
| Max-Heap Size K | O(N log K) | O(K) | Max-heap of size K: push each point. If heap size > K, remov |

**Recommended Solution:** Max-Heap Size K — O(N log K) time, O(K) space.

**Key Insights:**
1. **No sqrt needed:** Comparing x²+y² preserves distance ordering
2. **Max-heap for K-smallest:** Pop the largest to keep only K smallest
3. **QuickSelect alternative:** O(N) average but O(N²) worst case

<br>
<br>

---

```code```
