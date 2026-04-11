Find the maximum element in each sliding window of size k as it moves from left to right through an array.

<br>

> Input:
> nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3

> Output:
> [3, 3, 5, 5, 6, 7]

> Explanation:
> Window positions and maximums:
> - [1, 3, -1] -3  5  3  6  7  → max = 3
> -  1 [3, -1, -3] 5  3  6  7  → max = 3
> -  1  3 [-1, -3, 5] 3  6  7  → max = 5
> -  1  3  -1 [-3, 5, 3] 6  7  → max = 5
> -  1  3  -1  -3 [5, 3, 6] 7  → max = 6
> -  1  3  -1  -3  5 [3, 6, 7] → max = 7
> 
> Deque process for window [1,3,-1]:
> - Add 1: deque = [1]
> - Add 3: 3 > 1, remove 1, deque = [3]
> - Add -1: -1 < 3, keep both, deque = [3, -1]
> - Max = front of deque = 3

<br>


---

## Constraints

- `At most 10⁴ operations`
- `-10⁹ ≤ val ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **Dequeue from empty queue:** Handle gracefully — return -1 or error
2. **Peek on empty queue:** Handle gracefully
3. **Single enqueue then dequeue:** Returns the enqueued value
4. **Queue full (if bounded):** Handle overflow
5. **Multiple enqueues then size check:** Size equals enqueue count minus dequeue count

<br>

---

## Solution: Monotonic Deque

Use deque (double-ended queue) to maintain potential maximums:
1. Store indices in deque (not values)
2. Maintain decreasing order in deque
3. Remove indices outside current window
4. Remove smaller elements from back (they can't be max)
5. Front of deque is always maximum

**Key insight:** Keep only elements that could be maximum in current or future windows.

```code```

<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Traverse array once: n elements
- Each element:
  - Added to deque exactly once: n additions
  - Removed from deque at most once: n removals
- Total operations: 2n = O(n)

**Amortized Analysis:**
- While loop for removing smaller elements seems nested
- But each element processed at most twice (add + remove)
- Amortized O(1) per element

**Why not O(n × k)?**
- Brute force: For each window, find max in O(k) = O(n × k)
- Deque: Each element added/removed once = O(n)
- Huge improvement when k is large

**Space Complexity: O(k)**
- Deque holds at most k elements
- Only stores indices of potential maximums
- Elements outside window removed
- Smaller elements removed (can't be max)

**Why deque (not stack or queue)?**
- Need to remove from both ends:
  - Front: Remove elements outside window
  - Back: Remove smaller elements
- Deque supports O(1) operations at both ends
- Stack/Queue can't efficiently remove from both ends

**Monotonic deque property:**
- Maintains decreasing order
- Front = largest element in window
- Back = smallest element that could be future max
- All elements between are potential maximums

> **Time Complexity:** O(n) - each element added and removed once
> **Space Complexity:** O(k) - deque holds at most k indices

<br>
<br>

---
