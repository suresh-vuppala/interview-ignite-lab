Find the maximum element in each sliding window of size k.

<br>

> Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
> Output: [3,3,5,5,6,7]

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`
- `-10⁴ ≤ nums[i] ≤ 10⁴`
- `1 ≤ k ≤ nums.length`

<br>

---

## All Possible Edge Cases

1. **k = 1:** Return original array
2. **k = n:** Return [max of entire array]
3. **Sorted ascending:** Max always at right edge
4. **Sorted descending:** Max always at left edge

<br>

---

## Solution 1: Brute Force

**Intuition:** For each window, scan k elements to find max.

### Time Complexity: O(n × k)
### Space Complexity: O(1)

<br>

---

## Solution 2: Max Heap

**Intuition:** Maintain a max heap. For each window, add new element, remove expired elements.

### Time Complexity: O(n log n) — heap operations
### Space Complexity: O(n)

<br>

---

## Solution 3: Monotonic Deque (Optimal)

**Intuition:**
Maintain a deque of indices in decreasing order of values. The front is always the current window maximum. Remove from front if expired, from back if smaller than incoming element.

**Algorithm:**
1. Deque stores indices, front = max of current window
2. For each i:
   - Remove front if expired (index < i - k + 1)
   - Remove from back while nums[back] ≤ nums[i] (no longer useful)
   - Push i to back
   - If i ≥ k-1 → result.push(nums[deque.front()])

**Why this works:** Elements in deque are potential maximums. Smaller elements behind a larger one will never be the max, so we remove them.

### Time Complexity: O(n) — each element pushed/popped at most once
### Space Complexity: O(k) — deque size

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n×k) | O(1) | Scan each window |
| Max Heap | O(n log n) | O(n) | Heap tracks max, lazy removal |
| Monotonic Deque | O(n) | O(k) | Decreasing deque, amortized O(1) per element |

<br>
<br>

---

```code```
