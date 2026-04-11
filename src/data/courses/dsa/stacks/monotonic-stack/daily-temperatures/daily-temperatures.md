Given daily temperatures, return array where each element is the number of days until a warmer temperature. If no warmer day exists, return 0.

<br>

> Input:
> temperatures = [73, 74, 75, 71, 69, 72, 76, 73]

> Output:
> [1, 1, 4, 2, 1, 1, 0, 0]

> Explanation:
> - Day 0 (73°): Next warmer is day 1 (74°) → wait 1 day
> - Day 1 (74°): Next warmer is day 2 (75°) → wait 1 day
> - Day 2 (75°): Next warmer is day 6 (76°) → wait 4 days
> - Day 3 (71°): Next warmer is day 5 (72°) → wait 2 days
> - Day 4 (69°): Next warmer is day 5 (72°) → wait 1 day
> - Day 5 (72°): Next warmer is day 6 (76°) → wait 1 day
> - Day 6 (76°): No warmer day → 0
> - Day 7 (73°): No warmer day → 0

<br>


---

## Constraints

- `1 ≤ temperatures.length ≤ 10⁵`
- `30 ≤ temperatures[i] ≤ 100`

<br>

---

## All Possible Edge Cases

1. **Strictly increasing:** [30,31,32,33] → [1,1,1,0] — each waits just 1 day
2. **Strictly decreasing:** [100,99,98] → [0,0,0] — no warmer day for any
3. **All same temperature:** [70,70,70] → [0,0,0]
4. **Single element:** [50] → [0]
5. **Warmer only at the end:** [30,30,30,100] → [3,2,1,0]
6. **Two elements:** [30,31] → [1,0]

<br>

---

## Solution: Monotonic Stack

Use stack to store indices of days waiting for warmer temperature:
1. Traverse temperatures left to right
2. While current temp > stack top temp: pop and calculate days
3. Push current index to stack
4. Stack maintains decreasing temperatures

**Key insight:** Stack stores indices of days still waiting for warmer temperature.

```code```

<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Traverse array once: n iterations
- Each index:
  - Pushed to stack exactly once: O(1)
  - Popped from stack at most once: O(1)
- Total operations: 2n = O(n)

**Amortized O(1) per element:**
- While loop may process multiple pops
- But each element popped at most once total
- Amortized constant time per element

**Space Complexity: O(n)**
- Stack can hold all indices in worst case
- Example: decreasing temperatures [80,70,60,50]
- All indices pushed, none popped until end

**Comparison with brute force:**
- Brute force: O(n²) - for each day, scan forward
- Monotonic stack: O(n) - single pass

> **Time Complexity:** O(n) - each element processed once
> **Space Complexity:** O(n) - stack holds indices

<br>
<br>

---
