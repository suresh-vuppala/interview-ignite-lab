Calculate stock span for each day. Span is the number of consecutive days before current day where price was less than or equal to current price.

<br>

> Input:
> prices = [100, 80, 60, 70, 60, 75, 85]

> Output:
> [1, 1, 1, 2, 1, 4, 6]

> Explanation:
> - Day 0 (100): No previous days → span = 1
> - Day 1 (80): 80 < 100 → span = 1
> - Day 2 (60): 60 < 80 → span = 1
> - Day 3 (70): 70 > 60, 70 < 80 → span = 2 (includes day 2)
> - Day 4 (60): 60 < 70 → span = 1
> - Day 5 (75): 75 > 60,70,60,80 but < 100 → span = 4
> - Day 6 (85): 85 > all previous except 100 → span = 6

<br>


---

## Constraints

- `1 ≤ prices.length ≤ 10⁵`
- `1 ≤ prices[i] ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **Strictly increasing:** Span grows: [1, 2, 3, 4, ...]
2. **Strictly decreasing:** Span is always 1
3. **All same price:** Span grows linearly
4. **Single day:** Span = 1
5. **Peak after valley:** Peak absorbs all valley spans

<br>

---

## Solution: Monotonic Stack

Use stack to find previous greater element:
1. Stack stores indices of days
2. Pop elements with price ≤ current price
3. Span = current index - stack top (or current index + 1 if empty)
4. Push current index

**Key insight:** Span = distance to previous greater price.

```code```

<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Process each day once: n iterations
- Each index:
  - Pushed to stack once: n pushes
  - Popped at most once: n pops
- Total: 2n = O(n)

**Amortized O(1) per day:**
- While loop may pop multiple elements
- But each element popped at most once total
- Amortized constant time

**Space Complexity: O(n)**
- Stack holds indices
- Worst case: strictly decreasing prices
- All indices pushed, none popped until end

> **Time Complexity:** O(n) - each day processed once
> **Space Complexity:** O(n) - stack holds indices

<br>
<br>

---
