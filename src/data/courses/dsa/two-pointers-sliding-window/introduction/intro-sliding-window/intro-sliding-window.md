## Sliding Window — Efficient Subarray/Substring Processing

The sliding window technique processes contiguous subarrays or substrings by maintaining a "window" that slides across the data, avoiding redundant computation.

<br>

## Why Sliding Window?

- Transforms O(n²) or O(n×k) brute force into **O(n)**
- Essential for **substring** and **subarray** problems
- One of the **top 5 most-asked patterns** at FAANG companies

<br>

## Four Variations

| Type | Question Pattern | Example |
|------|-----------------|---------|
| **Fixed Size** | "Window of size K" | Max Sum Subarray of Size K |
| **Variable — Longest** | "Longest subarray/substring where..." | Longest Substring Without Repeating |
| **Variable — Shortest** | "Shortest subarray where..." | Minimum Window Substring |
| **Variable — Counting** | "Count subarrays where..." | Subarrays with Product < K |

<br>

## Template (Variable Window)

```
left = 0
for right in range(n):
    // expand: add nums[right] to window

    while window_condition_violated:
        // shrink: remove nums[left] from window
        left++

    // update answer (longest: max, shortest: min, count: accumulate)
```

<br>

## Key Decision: When to Shrink?

- **Longest:** Shrink only when constraint is **violated**
- **Shortest:** Shrink while constraint is **satisfied**
- **Counting:** Use `atMost(k) - atMost(k-1)` trick for "exactly K" problems

<br>


## All Possible Edge Cases
1. **N/A — introductory overview**
