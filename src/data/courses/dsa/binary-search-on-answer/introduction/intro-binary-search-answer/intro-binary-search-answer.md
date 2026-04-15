## Binary Search on Answer — Search the Solution Space

Instead of searching an array, binary search on the **answer space** itself. If you can frame a problem as "what is the minimum/maximum X such that some condition holds?", you can binary search on X.

<br>

## The Key Insight

If a condition is **monotonic** — once it becomes true/false at some point, it stays that way — you can binary search.

**Pattern:**
1. Define the search range: `lo = minimum possible answer`, `hi = maximum possible answer`
2. Write a `canAchieve(mid)` function that checks if `mid` is a valid answer
3. Binary search to find the optimal `mid`

<br>

## Three Main Categories

| Category | Pattern | Example |
|----------|---------|---------|
| **Minimize Maximum** | "What's the smallest max load?" | Split Array Largest Sum, Allocate Pages |
| **Maximize Minimum** | "What's the largest min distance?" | Aggressive Cows, Magnetic Force |
| **Capacity/Rate** | "What's the min rate to finish in time?" | Koko Bananas, Ship Packages |

<br>

## Template

```
lo, hi = min_possible, max_possible
while lo < hi:
    mid = lo + (hi - lo) / 2
    if canAchieve(mid):
        hi = mid       // minimize answer
    else:
        lo = mid + 1
return lo
```

For "maximize minimum" problems, flip the condition.

<br>

## FAANG Frequency

This pattern appears in **~15% of Google interviews** and is a favorite because it tests both binary search mastery and the ability to write a clean feasibility check function.

<br>


## All Possible Edge Cases
1. **N/A — introductory overview**
