Find the largest rectangle area in a histogram where bars have width 1 and varying heights.

<br>

> Input:
> heights = [2, 1, 5, 6, 2, 3]

> Output:
> 10

> Explanation:
> Largest rectangle: height=5, width=2 (bars at index 2 and 3)
> Area = 5 × 2 = 10
> 
> Visualization:
>       6
>     5 █
>     █ █
>     █ █   3
> 2   █ █ 2 █
> █ 1 █ █ █ █
> 
> Stack process (find next smaller on both sides):
> - For bar at index 2 (height=5): next smaller left=1, next smaller right=4
> - Width = 4 - 1 - 1 = 2
> - Area = 5 × 2 = 10

<br>

---

## Solution: Monotonic Stack

Use monotonic increasing stack to find next smaller elements:
1. For each bar, find:
   - Next smaller bar on left (NSL)
   - Next smaller bar on right (NSR)
2. Width for bar i = NSR - NSL - 1
3. Area for bar i = height[i] × width
4. Track maximum area

**Key insight:** For each bar as height, find maximum width where all bars ≥ current height.

```code```

<br>

### Time Complexity Analysis

**Single Pass with Stack: O(n)**
- Traverse array once: n iterations
- Each bar:
  - Pushed to stack exactly once: n pushes
  - Popped from stack at most once: n pops
- Total operations: 2n = O(n)

**Amortized Analysis:**
- While loop may seem nested
- But each element pushed and popped at most once
- Amortized O(1) per element

**Why monotonic stack?**
- Need to find next smaller element efficiently
- Monotonic increasing stack maintains potential NSL/NSR
- Avoids O(n²) brute force (checking all pairs)

**Space Complexity: O(n)**
- Stack can hold all bars in worst case
- Worst case: strictly increasing heights [1,2,3,4,5]
- All bars pushed before any popped

**Comparison with brute force:**
- Brute force: For each bar, expand left and right O(n²)
- Monotonic stack: Single pass O(n)
- Huge improvement for large inputs

**Algorithm steps:**
1. Maintain increasing stack (indices)
2. When current bar < stack top:
   - Pop and calculate area using popped bar as height
   - Width = current index - stack top after pop - 1
3. Push current bar
4. Process remaining stack at end

> **Time Complexity:** O(n) - each bar pushed and popped once
> **Space Complexity:** O(n) - stack holds indices

<br>
<br>

---