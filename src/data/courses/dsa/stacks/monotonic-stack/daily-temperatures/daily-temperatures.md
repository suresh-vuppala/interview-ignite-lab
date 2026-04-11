Given a list of daily temperatures, return how many days you have to wait until a warmer temperature. If no future warmer day, put 0.

<br>

> Input:
> temperatures = [73, 74, 75, 71, 69, 72, 76, 73]

> Output:
> [1, 1, 4, 2, 1, 1, 0, 0]

> Explanation:
> Day 0 (73): next warmer = day 1 (74), wait 1 day. Day 2 (75): next warmer = day 6 (76), wait 4 days.
> 
> **Key insight:** This is "Next Greater Element" but returning the index DISTANCE instead of the value. Monotonic decreasing stack of indices — when a warmer day arrives, compute the distance.

<br>



---

## Constraints

- `1 ≤ temperatures.length ≤ 10⁵`
- `30 ≤ temperatures[i] ≤ 100`

<br>

---

## All Possible Edge Cases

1. **Always increasing:** [1,2,3] → [1,1,0]
2. **Always decreasing:** [3,2,1] → [0,0,0]
3. **All same:** [73,73,73] → [0,0,0]
4. **Single element:** [50] → [0]

<br>

---

## Solution 1: Brute Force — Scan Right for Each

### Time Complexity: O(N²)
**Why?**
- For each day, scan all future days
- N = 100,000 → up to 5 billion operations

### Space Complexity: O(1) extra

> **Drawback:**
> Same as NGE — scanning right from scratch for each position. The monotonic stack resolves all pending positions in one pass.

> **Key Insight for Improvement:**
> Monotonic decreasing stack of indices. When temp[i] > temp[stack.top()], day i is the answer for stack.top(). Distance = i - stack.top(). Pop and assign.

<br>

---

## Solution 2: Monotonic Decreasing Stack (Optimal)

**Intuition:**
Identical to Next Greater Element, but instead of recording the value, record the index distance: result[idx] = i - idx.

**Algorithm:**
1. result = [0] * n, stack = []
2. For i = 0 to n-1:
   - While stack not empty and temps[i] > temps[stack.top()]:
     - idx = stack.pop()
     - result[idx] = i - idx (days to wait)
   - stack.push(i)

### Time Complexity: O(N)
**Why?**
- Each index pushed once, popped at most once
- Total: ≤ 2N operations

**Detailed breakdown:**
- N = 100,000 → at most 200,000 stack operations

**Example walkthrough:**
```
temps = [73, 74, 75, 71, 69, 72, 76, 73]

i=0(73): push 0 → stack=[0]
i=1(74): 74>73 → pop 0, result[0]=1-0=1 → stack=[1]
i=2(75): 75>74 → pop 1, result[1]=2-1=1 → stack=[2]
i=3(71): 71<75 → push → stack=[2,3]
i=4(69): 69<71 → push → stack=[2,3,4]
i=5(72): 72>69 → pop 4, result[4]=5-4=1
         72>71 → pop 3, result[3]=5-3=2
         72<75 → push → stack=[2,5]
i=6(76): 76>72 → pop 5, result[5]=6-5=1
         76>75 → pop 2, result[2]=6-2=4
         push → stack=[6]
i=7(73): 73<76 → push → stack=[6,7]

Remaining: result[6]=0, result[7]=0
Result: [1, 1, 4, 2, 1, 1, 0, 0] ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | Scan right per day |
| Monotonic Stack | O(N) | O(N) | Pop smaller, assign distance |

**Recommended Solution:** Monotonic Stack (Solution 2) — O(N) time.

**Key Insights:**
1. **Same as NGE:** But record distance (i - idx) instead of value
2. **Decreasing stack invariant:** Stack values always decrease from bottom to top
3. **FAANG favorite:** Tests monotonic stack pattern recognition


<br>
<br>

---

```code```
