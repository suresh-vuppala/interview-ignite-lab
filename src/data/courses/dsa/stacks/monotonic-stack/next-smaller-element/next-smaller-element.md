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

## Solution 1: Brute Force — O(N²)

> **Drawback:** Same as NGE brute force.

> **Key Insight for Improvement:** Monotonic INCREASING stack. Pop elements LARGER than incoming — the incoming element is their next smaller.

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
