Given an array and a window size k, find the first negative number in every window of size k. If no negative exists, return 0.

<br>

> Input:
> arr = [12, -1, -7, 8, -15, 30, 16, 28], k = 3

> Output:
> [-1, -1, -7, -15, -15, 0]

> Explanation:
> Windows and first negative:
> - [12,-1,-7] → -1
> - [-1,-7,8] → -1
> - [-7,8,-15] → -7
> - [8,-15,30] → -15
> - [-15,30,16] → -15
> - [30,16,28] → 0 (no negative)
> 
> **Key insight:** Use deque to track negative numbers in current window.

<br>

---

## Solution 1: Brute Force

**Intuition:**
For each window, scan all k elements to find the first negative number.

**Algorithm:**
1. For each starting position i
2. Scan next k elements
3. Return first negative found, or 0

### Time Complexity: O(n×k)
**Why?**
- Outer loop: n-k+1 windows
- Inner loop: up to k elements per window
- Total: O(n×k)

### Space Complexity: O(1)
**Why?**
- No extra data structures
- Only result array (output)

**Problem:** Rescanning entire window is wasteful.

> **Key Insight for Improvement:**
> Use a deque to store indices of negative numbers. When sliding, remove indices outside window and add new negatives.

<br>

---

## Solution 2: Sliding Window with Deque (Optimal)

**Intuition:**
Maintain a deque of indices of negative numbers in current window. Front of deque always has first negative.

**Algorithm:**
1. Process first k elements, store negative indices in deque
2. For each window:
   - Remove indices outside window from front
   - Add new element if negative
   - First negative = arr[deque.front()] or 0

### Time Complexity: O(n)
**Why?**
- Each element added to deque once: O(n)
- Each element removed from deque once: O(n)
- Total: O(n)

**Improvement:**
- Before: O(n×k)
- After: O(n)
- Example: n=1000, k=100 → 100× faster!

### Space Complexity: O(k)
**Why?**
- Deque stores at most k indices
- In worst case, all k elements are negative

<br>

---

## Complexity Summary

| Solution | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n×k) | O(1) | Scans each window |
| Deque | O(n) | O(k) | Optimal time, tracks negatives |

> **Recommended Solution:** Deque - O(n) time, O(k) space

<br>
<br>

---

```code```
