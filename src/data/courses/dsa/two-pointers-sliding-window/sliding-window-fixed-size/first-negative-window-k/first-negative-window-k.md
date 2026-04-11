Find the first negative integer in every window of size k. If no negative exists in a window, output 0.

<br>

> Input:
> nums = [-8, 2, 3, -6, 10], k = 2

> Output:
> [-8, 0, -6, -6]

> Explanation:
> Window [-8,2] → first negative = -8. Window [2,3] → no negative = 0. Window [3,-6] → -6. Window [-6,10] → -6.
> 
> **Key insight:** Use a deque of negative indices. Front of deque = first negative in current window. Expire indices that fall outside the window.

<br>



---

## Constraints

- `1 ≤ k ≤ n ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **No negatives:** All outputs are 0
2. **All negatives:** First element of each window
3. **k = 1:** Each element individually (negative or 0)
4. **k = n:** One window, find first negative

<br>

---

## Solution 1: Brute Force — Scan Each Window

**Intuition:**
For each window, scan left to right to find the first negative number.

### Time Complexity: O(N × K)
**Why?**
- (N-K+1) windows × K scans per window

**Detailed breakdown:**
- N=100,000, K=1,000 → 100,000,000 operations

### Space Complexity: O(1) extra

> **Drawback:**
> Scanning K elements per window to find the first negative. A negative at position i serves as "first negative" for multiple consecutive windows — we're rediscovering it each time.

> **Key Insight for Improvement:**
> Use a deque to track indices of negative numbers. As the window slides, pop expired indices from the front. The front of the deque is always the first negative in the current window — O(1) per slide.

<br>

---

## Solution 2: Deque of Negative Indices (Optimal)

**Intuition:**
Maintain a deque storing indices of negative numbers. For each new element: if negative, add to deque back. Before reading result, pop front if expired (index < window start). Front = first negative.

**Algorithm:**
1. Initialize deque (stores indices of negatives)
2. For each i from 0 to n-1:
   - If nums[i] < 0 → push i to deque back
   - If i ≥ k-1 (window is full):
     - Pop from front while front < i-k+1 (expired)
     - If deque not empty → result.add(nums[deque.front])
     - Else → result.add(0)

### Time Complexity: O(N)
**Why?**
- Each index pushed at most once, popped at most once
- Total operations: ≤ 2N = O(N)

**Detailed breakdown:**
- N = 100,000 → at most 200,000 deque operations
- Compared to brute: 100,000,000 → 200,000 (500× faster!)

**Example walkthrough:**
```
nums = [-8, 2, 3, -6, 10], k = 2
deque = []

i=0: -8 < 0 → deque=[0]
     i=0 < k-1=1 → no output yet
i=1: 2 ≥ 0 → skip
     i=1 ≥ 1 → deque front=0, 0 ≥ 1-2+1=0 ✓ → output nums[0]=-8
i=2: 3 ≥ 0 → skip
     i=2 ≥ 1 → front=0, 0 < 2-2+1=1 → expired! pop → deque=[]
     deque empty → output 0
i=3: -6 < 0 → deque=[3]
     i=3 ≥ 1 → front=3 ≥ 2 ✓ → output nums[3]=-6
i=4: 10 ≥ 0 → skip
     i=4 ≥ 1 → front=3 ≥ 3 ✓ → output nums[3]=-6

Result: [-8, 0, -6, -6] ✓
```

### Space Complexity: O(K)
**Why?**
- Deque stores at most K indices (one window's worth)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N×K) | O(1) | Scan each window for first negative |
| Deque | O(N) | O(K) | Track negative indices, expire old ones |

**Recommended Solution:** Deque (Solution 2) — O(N) time, O(K) space.

**Key Insights:**
1. **Deque tracks candidates:** Only negative numbers are candidates
2. **Expire from front:** Remove indices outside current window
3. **Same pattern as Sliding Window Maximum:** Deque of indices with expiration


<br>
<br>

---

```code```
