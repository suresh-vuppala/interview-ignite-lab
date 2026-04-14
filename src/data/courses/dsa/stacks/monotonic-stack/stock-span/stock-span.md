Design a class that collects daily price quotes and returns the span of the stock's price for the current day. The span is the number of consecutive days (starting from today, going backward) where the price was ≤ today's price.

<br>

> Input:
> prices: 100, 80, 60, 70, 60, 75, 85

> Output:
> spans: 1, 1, 1, 2, 1, 4, 6

> Explanation:
> Day 5 (price=75): prices 60,70,60 ≤ 75 → span back 4 days (including today). Day 6 (price=85): all 6 previous ≤ 85 → span = 6.
> 
> **Key insight:** This is "Previous Greater Element" in disguise. Use a monotonic decreasing stack of (price, index) pairs. The span = today's index - index of previous greater element.

<br>



---

## Constraints

- At most 10⁴ calls to next
- `1 ≤ price ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **First day:** Always span = 1
2. **Increasing prices:** Spans grow: 1,2,3,4,...
3. **Decreasing prices:** All spans = 1
4. **Spike after decline:** Large span

<br>

---

## Solution 1: Brute Force — Scan Back Each Day

**Intuition:**
The most straightforward approach. Scanning back from each day.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N) per call, O(N²) total
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Scanning back from each day. After processing a large span, the next day may need to go back even further, re-examining elements we already checked.

> **Key Insight for Improvement:**
> Use a monotonic decreasing stack. Each new price pops all smaller/equal prices. The span = distance to the new stack top (previous greater). Each element pushed/popped at most once across all calls → O(1) amortized per call.

<br>

---

## Solution 2: Monotonic Decreasing Stack (Optimal)

**Algorithm:**
1. Maintain stack of (price, index) pairs, monotonically decreasing
2. next(price):
   - While stack top ≤ price → pop (current day spans over them)
   - span = currentIndex - stack.top().index (or currentIndex + 1 if stack empty)
   - Push (price, currentIndex) onto stack
   - Return span

### Time Complexity: O(1) amortized per call
**Why?**
- Each element pushed once, popped at most once
- Over N calls: 2N operations total → O(1) average per call

**Detailed breakdown:**
- 10,000 calls → at most 20,000 stack operations total

**Example walkthrough:**
```
prices: 100, 80, 60, 70, 60, 75, 85

day0(100): stack=[] → span=0+1=1, push (100,0) → stack=[(100,0)]
day1(80):  80<100 → span=1-0=1... actually 1-1+1? Let me use the index approach:
  stack top (100,0), 80<100 → no pop. span = 1-0 = 1. push (80,1)
day2(60):  60<80 → span = 2-1 = 1. push (60,2)
day3(70):  70>60 → pop (60,2). 70<80 → stop. span = 3-1 = 2. push (70,3)
day4(60):  60<70 → span = 4-3 = 1. push (60,4)
day5(75):  75>60 → pop. 75>70 → pop. 75<80 → stop. span = 5-1 = 4. push (75,5)
day6(85):  85>75 → pop. 85>80 → pop. 85<100 → stop. span = 6-0 = 6. push (85,6)

Spans: [1, 1, 1, 2, 1, 4, 6] ✓
```

### Space Complexity: O(N) worst case

<br>

---

## Complexity Progression Summary

| Solution | Time per call | Space | Key Improvement |
|----------|--------------|-------|----------------|
| Brute Force | O(N) | O(N) | Scan back each day |
| Monotonic Stack | O(1) amortized | O(N) | Previous greater via stack |

**Recommended Solution:** Monotonic Stack (Solution 2) — O(1) amortized per call.

**Key Insights:**
1. **Span = Previous Greater distance:** span[i] = i - index of previous greater element
2. **Stack stores only "active" prices:** Smaller prices are consumed and never revisited
3. **Online algorithm:** Processes one price at a time — suitable for streaming data


<br>
<br>

---

```code```
