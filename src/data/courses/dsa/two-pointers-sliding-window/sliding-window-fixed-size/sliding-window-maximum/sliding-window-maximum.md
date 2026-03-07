Given an array and a window size k, find the maximum element in each window of size k as it slides from left to right.

<br>

> Input:
> arr = [1, 3, -1, -3, 5, 3, 6, 7], k = 3

> Output:
> [3, 3, 5, 5, 6, 7]

> Explanation:
> Windows and their maximums:
> - [1,3,-1] → 3
> - [3,-1,-3] → 3
> - [-1,-3,5] → 5
> - [-3,5,3] → 5
> - [5,3,6] → 6
> - [3,6,7] → 7
> 
> **Key insight:** Use monotonic deque to efficiently track maximum in sliding window.

<br>

---

## Solution 1: Brute Force

**Intuition:**
For each window, scan all k elements to find the maximum.

**Algorithm:**
1. For each starting position i
2. Find max of k elements starting at i
3. Add to result

### Time Complexity: O(n×k)
**Why?**
- n-k+1 windows
- Each window: scan k elements
- Total: O(n×k)

### Space Complexity: O(1)
**Why?**
- Only tracking current max
- No additional structures

**Problem:** Rescanning entire window is wasteful.

> **Key Insight for Improvement:**
> Use a deque to maintain elements in decreasing order. Front always has maximum for current window.

<br>

---

## Solution 2: Monotonic Deque (Optimal)

**Intuition:**
Maintain a deque of indices in decreasing order of values. Remove indices outside window and smaller elements that can't be maximum.

**Algorithm:**
1. For each element:
   - Remove indices outside current window from front
   - Remove indices with smaller values from back (they can't be max)
   - Add current index to back
   - Front of deque is maximum for current window

### Time Complexity: O(n)
**Why?**
- Each element added to deque once: O(n)
- Each element removed from deque once: O(n)
- Total: O(n)

**Improvement:**
- Before: O(n×k)
- After: O(n)
- Example: n=10000, k=1000
  - Brute: 10,000,000 operations
  - Deque: 10,000 operations (1000× faster!)

### Space Complexity: O(k)
**Why?**
- Deque stores at most k indices
- In worst case (decreasing array), all k elements in deque

<br>

---

## Solution 3: Using Max Heap

**Intuition:**
Use a max heap to track maximum. Remove elements outside window when they appear at top.

**Algorithm:**
1. Add first k elements to max heap with indices
2. For each window:
   - Remove elements outside window from top
   - Add new element
   - Top is maximum

### Time Complexity: O(n log k)
**Why?**
- n insertions: n × log k
- Up to n deletions: n × log k
- Total: O(n log k)

### Space Complexity: O(k)
**Why?**
- Heap stores up to k elements

**Note:** Slower than deque but simpler to implement.

<br>

---

## Complexity Summary

| Solution | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n×k) | O(1) | Scans each window |
| Monotonic Deque | O(n) | O(k) | Optimal - each element processed once |
| Max Heap | O(n log k) | O(k) | Simpler but slower |

> **Recommended Solution:** Monotonic Deque - O(n) time, O(k) space

<br>
<br>

---

```code```
