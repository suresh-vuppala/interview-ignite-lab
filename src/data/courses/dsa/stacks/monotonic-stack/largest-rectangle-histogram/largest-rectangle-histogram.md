Given an array of non-negative integers representing bar heights in a histogram, find the area of the largest rectangle that can be formed.

<br>

> Input:
> heights = [2, 1, 5, 6, 2, 3]

> Output:
> 10

> Explanation:
> Rectangle spanning bars at indices 2 and 3 (heights 5, 6): width=2, height=min(5,6)=5, area=10.
> 
> **Key insight:** For each bar, find how far LEFT and RIGHT it can extend (i.e., nearest smaller bars on both sides). Area = height × (rightSmaller - leftSmaller - 1). Monotonic increasing stack finds both boundaries in O(N).

<br>



---

## Constraints

- `1 ≤ heights.length ≤ 10⁵`
- `0 ≤ heights[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **All same height:** Area = height × n
2. **Ascending:** Largest uses last two (or more) bars
3. **Descending:** Each bar's rectangle is just itself × remaining width
4. **Single bar:** Area = heights[0]
5. **Contains zeros:** Zeros break continuity

<br>

---

## Solution 1: Brute Force — Check All Pairs

**Intuition:**
For every pair (i, j), the rectangle height = min(heights[i..j]) and width = j-i+1.

### Time Complexity: O(N²)
**Why?**
- O(N²) pairs, maintaining running min: O(1) per extension

**Detailed breakdown:**
- N = 100,000 → ~5 billion operations — TLE

### Space Complexity: O(1)

> **Drawback:**
> Checking all pairs. For each bar, the maximum rectangle using that bar as the shortest has a deterministic left and right boundary — we can compute these boundaries for ALL bars in one pass using a monotonic stack.

> **Key Insight for Improvement:**
> For each bar i, its rectangle extends left until it hits a shorter bar, and right until it hits a shorter bar. These are the "Previous Smaller" and "Next Smaller" elements. A monotonic increasing stack computes both in O(N). Area[i] = heights[i] × (nextSmaller[i] - prevSmaller[i] - 1).

<br>

---

## Solution 2: Monotonic Increasing Stack (Optimal)

**Intuition:**
Maintain a stack of bar indices in increasing height order. When a shorter bar arrives, pop taller bars — the popped bar's rectangle extends from the new stack top to the current position. This simultaneously finds left and right boundaries.

**Algorithm:**
1. Push -1 as sentinel (left boundary for bars touching the left edge)
2. For i = 0 to n:
   - h = heights[i] (or 0 for i=n, forcing all remaining bars to pop)
   - While stack.top() ≠ -1 and h ≤ heights[stack.top()]:
     - height = heights[stack.pop()]
     - width = i - stack.top() - 1 (distance between left and right boundaries)
     - maxArea = max(maxArea, height × width)
   - Push i
3. Return maxArea

### Time Complexity: O(N)
**Why?**
- Each bar pushed once, popped once
- Total: 2N operations

**Detailed breakdown:**
- N = 100,000 → at most 200,000 stack operations

**Example walkthrough:**
```
heights = [2, 1, 5, 6, 2, 3]
stack = [-1]

i=0(h=2): push → stack=[-1, 0]
i=1(h=1): 1 < 2 → pop 0: height=2, width=1-(-1)-1=1, area=2
           push → stack=[-1, 1]
i=2(h=5): push → stack=[-1, 1, 2]
i=3(h=6): push → stack=[-1, 1, 2, 3]
i=4(h=2): 2 < 6 → pop 3: height=6, width=4-2-1=1, area=6
           2 < 5 → pop 2: height=5, width=4-1-1=2, area=10 ★
           push → stack=[-1, 1, 4]
i=5(h=3): push → stack=[-1, 1, 4, 5]
i=6(h=0): 0 < 3 → pop 5: height=3, width=6-4-1=1, area=3
           0 < 2 → pop 4: height=2, width=6-1-1=4, area=8
           0 < 1 → pop 1: height=1, width=6-(-1)-1=6, area=6
           push → stack=[-1, 6]

maxArea = 10 ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | All pairs with running min |
| Monotonic Stack | O(N) | O(N) | Left/right boundaries via stack |

**Recommended Solution:** Monotonic Increasing Stack (Solution 2) — O(N) time.

**Key Insights:**
1. **Each bar's max rectangle:** height × (nextSmaller - prevSmaller - 1)
2. **Stack finds both boundaries:** Pop gives right boundary (current i), stack top gives left boundary
3. **Sentinel trick:** Push -1 initially to handle bars extending to the left edge
4. **Sentinel at end:** Use height=0 at i=n to force all remaining bars to pop
5. **Foundation for Maximal Rectangle in Matrix:** Apply this algorithm per row


<br>
<br>

---

```code```
