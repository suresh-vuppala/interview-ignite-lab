Given a 1-indexed sorted array and a target, find two numbers that sum to target. Return their 1-indexed positions.

<br>

> Input:
> numbers = [2, 7, 11, 15], target = 9

> Output:
> [1, 2]

> Explanation:
> numbers[1] + numbers[2] = 2 + 7 = 9. Return 1-indexed: [1, 2].
> 
> **Key insight:** Array is sorted. Start from both ends: sum too small → move left right, sum too large → move right left. Converges in O(N).

<br>



---

## Constraints

- `2 ≤ numbers.length ≤ 3 × 10⁴`
- `-1000 ≤ numbers[i] ≤ 1000`
- `numbers is sorted in non-decreasing order`
- `Exactly one solution exists`

<br>

---

## All Possible Edge Cases

1. **First two elements:** [1,2,3], target=3 → [1,2]
2. **Last two elements:** [1,2,3], target=5 → [2,3]
3. **Negative numbers:** [-3,-1,0,2], target=-4 → [1,2]
4. **Duplicate values:** [1,1,3], target=2 → [1,2]

<br>

---

## Solution 1: Brute Force — Check All Pairs

**Intuition:**
Try every pair (i,j) where i < j. If sum equals target, return.

**Algorithm:**
1. For i = 0 to n-2:
   - For j = i+1 to n-1:
     - If numbers[i] + numbers[j] == target → return [i+1, j+1]

### Time Complexity: O(N²)
**Why?**
- N(N-1)/2 pairs checked
- Each check: O(1)

**Detailed breakdown:**
- Array size 30,000 → ~450,000,000 pair checks — TLE
- Completely ignores the sorted property

### Space Complexity: O(1)
**Why?**
- Only loop variables

> **Drawback:**
> Checking all O(N²) pairs ignores the fact that the array is sorted. The sorted order gives us information about whether we need a larger or smaller sum.

> **Key Insight for Improvement:**
> Start with left at the beginning and right at the end — the widest pair. Their sum tells us which direction to adjust. Sum too small? Move left right (increases sum). Sum too large? Move right left (decreases sum). Converges in O(N).

<br>

---

## Solution 2: Two Pointers — Converge from Ends (Optimal)

**Intuition:**
Left pointer at start, right at end. If sum < target, we need a bigger number → advance left. If sum > target, we need a smaller number → retreat right. Sorted order guarantees this converges to the answer.

**Algorithm:**
1. left = 0, right = n-1
2. While left < right:
   - sum = numbers[left] + numbers[right]
   - If sum == target → return [left+1, right+1]
   - If sum < target → left++ (need bigger)
   - If sum > target → right-- (need smaller)

### Time Complexity: O(N)
**Why?**
- Each iteration either left++ or right--
- Total: at most N iterations before they meet

**Detailed breakdown:**
- Array size 30,000 → at most 30,000 iterations
- Compared to brute force: 450,000,000 → 30,000 (15,000× faster!)

**Example walkthrough:**
```
numbers = [2, 7, 11, 15], target = 9
left=0, right=3

sum = 2+15 = 17 > 9 → right-- → right=2
sum = 2+11 = 13 > 9 → right-- → right=1
sum = 2+7 = 9 == target → return [1, 2] ✓
```

**Why this always finds the answer:**
- If we need both larger numbers, both are to the right of current positions
- Left only moves right, right only moves left
- We never skip over the answer pair because:
  - Moving left past answer-left requires sum was too small (but answer gives exact target)
  - Moving right past answer-right requires sum was too large (same contradiction)

### Space Complexity: O(1)
**Why?**
- Only two pointer variables

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | Check all pairs |
| Two Pointers | O(N) | O(1) | Converge from ends using sorted order |

**Recommended Solution:** Two Pointers (Solution 2) — O(N) time, O(1) space.

**Key Insights:**
1. **Sorted + two pointers:** The classic combination for pair-finding
2. **Direction logic:** Sum too small → advance left; too large → retreat right
3. **vs Hash Map:** Hash map also gives O(N), but two pointers gives O(1) space on sorted input


<br>
<br>

---

```code```
