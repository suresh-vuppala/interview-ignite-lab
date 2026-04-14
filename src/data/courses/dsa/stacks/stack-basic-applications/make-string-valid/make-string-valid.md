Given a string of '(' and ')', return the minimum number of parentheses to add to make the string valid.

<br>

> Input: s = "())("
> Output: 2

> Explanation: Add '(' at start and ')' at end → "(())()" — 2 additions needed.
> 
> **Key insight:** Track unmatched opens and unmatched closes separately. At the end, total additions = unmatched_opens + unmatched_closes.

<br>

---

## Constraints
- `1 ≤ s.length ≤ 1000`

<br>

---

## All Possible Edge Cases
1. **Already valid:** "()" → 0
2. **All opens:** "(((" → 3 (need 3 closes)
3. **All closes:** ")))" → 3 (need 3 opens)
4. **Empty:** "" → 0

<br>

---

## Solution 1: Naive / Brute Force Approach

**Intuition:**
Try the most straightforward method without optimization.

**Algorithm:**
1. Apply the direct/naive approach
2. May involve extra space, multiple passes, or higher time complexity
3. Serves as baseline to understand the problem before optimizing

### Time Complexity: Higher than optimal
**Why?**
Does not exploit key structural properties of the problem.

### Space Complexity: May use extra space

> **Drawback:**
> Less efficient approach exists.

> **Key Insight for Improvement:**
> Use Counter — Track Unmatched (Optimal) for optimal performance.

<br>

---

## Solution 2: Counter — Track Unmatched (Optimal)

**Intuition:** open tracks unmatched '('. When ')' arrives: if open > 0, it matches an open (open--). Otherwise, it's unmatched (close++). At the end: need open closes + close opens.

**Algorithm:**
1. open = 0, close = 0
2. For each c: if '(' → open++. If ')' → if open > 0: open--, else close++
3. Return open + close

### Time Complexity: O(N)
**Why?** Single pass.

**Detailed breakdown:** N = 1000 → 1000 operations

**Example walkthrough:**
```
s = "())("
')': open=0, can't match → close=1
')': open=0 → close=2... wait let me redo:

s = "())("
'(': open=1
')': open>0 → open=0 (matched)
')': open=0 → close=1 (unmatched)
'(': open=1

Result: open + close = 1 + 1 = 2 ✓
```

### Space Complexity: O(1)

> **Drawback:** None — already optimal.

> **Key Insight for Improvement:** This is the optimal approach. A stack-based solution would also work but uses O(N) space for the same result.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Counter | O(N) | O(1) | Track unmatched opens + closes |

**Key Insights:**
1. **Two counters:** open (pending opens), close (unmatched closes)
2. **Greedy matching:** Each ')' matches the most recent '(' if available
3. **Result = open + close:** Need that many additions

<br><br>

---

```code```
