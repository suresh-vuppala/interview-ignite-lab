Given an array, find the next smaller element for each element. The next smaller element of x is the first element to its right that is smaller than x. If none exists, output -1.

<br>

> Input: nums = [4, 8, 5, 2, 25]
> Output: [2, 5, 2, -1, -1]

> Explanation: 4→2, 8→5, 5→2, 2→-1, 25→-1.
> 
> **Key insight:** Same as NGE but use a monotonic INCREASING stack. Pop when the incoming element is SMALLER than the top.

<br>

---

## Constraints
- `1 ≤ nums.length ≤ 10⁵`

<br>

---

## All Possible Edge Cases
1. **Sorted ascending: each element's NSE is next
2. **Sorted descending: no NSE for any (-1)
3. **All same elements: no NSE
4. **Single element**

<br>

---

## Solution 1: Brute Force — O(N²)

**Intuition:**
The most straightforward approach — try all possibilities and check each one.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N²)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

<br>

---

## Solution 2: Monotonic Increasing Stack (Optimal)

**Algorithm:**
1. result = [-1] * N, stack = []
2. For i = 0 to N-1:
   - While stack and nums[i] < nums[stack.top()]: result[stack.pop()] = nums[i]
   - push i

### Time Complexity: O(N)
**Why?** Each element pushed/popped at most once.

**Detailed breakdown:** N = 100,000 → at most 200,000 operations

**Example walkthrough:**
```
nums = [4, 8, 5, 2, 25]

i=0(4): push → stack=[0]
i=1(8): 8>4 → push → stack=[0,1]
i=2(5): 5<8 → pop 1, result[1]=5. 5>4 → push → stack=[0,2]
i=3(2): 2<5 → pop 2, result[2]=2. 2<4 → pop 0, result[0]=2. push → stack=[3]
i=4(25): 25>2 → push → stack=[3,4]

Remaining: result[3]=-1, result[4]=-1
Result: [2, 5, 2, -1, -1] ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | Scan right per element |
| Monotonic Stack | O(N) | O(N) | Increasing stack, pop larger |

**Key Insights:**
1. **Mirror of NGE:** NGE uses decreasing stack, NSE uses increasing stack
2. **Pop condition flipped:** Pop when incoming < top (instead of >)
3. **Pattern family:** NGE/NSE/PGE/PSE — four variants, same stack technique

<br><br>

---

```code```
