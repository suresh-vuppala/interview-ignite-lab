Given an array of cards where each card has a number, find the minimum number of consecutive cards you need to pick to have a pair of matching cards. Return -1 if no pair exists.

<br>

> Input:
> cards = [3,4,2,3,4,7]

> Output:
> 4

> Explanation:
> Pick cards [3,4,2,3] (4 consecutive cards) to get a matching pair of 3's
> Or pick [4,2,3,4] (4 consecutive cards) to get a matching pair of 4's
> Minimum is 4
> 
> **Key insight:** Track last seen position of each card. When we see a duplicate, calculate distance.

<br>



---

## Constraints

- `1 ≤ cards.length ≤ 10⁵`
- `0 ≤ cards[i] ≤ 10⁶`

<br>

---

## All Possible Edge Cases

1. **No matching cards:** All unique → return -1
2. **Adjacent matching cards:** Minimum possible answer is 2
3. **First and last card match:** Window size is n
4. **All same cards:** Return 2 (any adjacent pair)
5. **Single card:** Return -1 — can't form a pair
6. **Two cards, same value:** Return 2
7. **Two cards, different value:** Return -1
8. **Multiple pairs, different distances:** Must find the minimum

<br>

---

## Solution 1: Brute Force

**Intuition:**
Check all possible consecutive subarrays. For each subarray, check if it contains a duplicate.

**Algorithm:**
1. For each starting position i
2. For each ending position j ≥ i
3. Check if subarray [i, j] has duplicates
4. Update minimum length if found

### Time Complexity: O(n³)
**Why?**
- Two nested loops: O(n²) subarrays
- Checking duplicates: O(n) per subarray
- Total: O(n³)

### Space Complexity: O(n)
**Why?**
- Set to track seen cards in current subarray
- Worst case: all cards unique

**Problem:** Checking all subarrays is extremely inefficient.

> **Key Insight for Improvement:**
> We don't need to check all subarrays. For each card, track its last seen position. When we see it again, the distance is a candidate answer.

<br>

---

## Solution 2: HashMap with Last Seen Position

**Intuition:**
Store the last seen index of each card. When we encounter a card we've seen before, calculate the distance and update minimum.

**Algorithm:**
1. Use hashmap to store last seen index of each card
2. For each card:
   - If seen before, calculate distance (current_index - last_index + 1)
   - Update minimum distance
   - Update last seen index
3. Return minimum distance (or -1 if no pair)

### Time Complexity: O(n)
**Why?**
- Single pass through array
- HashMap operations: O(1) average
- Total: O(n)

**Improvement:**
- Before: O(n³)
- After: O(n)
- Example: n=10000
  - Brute: 1,000,000,000,000 operations
  - HashMap: 10,000 operations (100 million× faster!)

### Space Complexity: O(n)
**Why?**
- HashMap stores at most n unique cards
- Worst case: all cards unique

<br>

---

## Solution 3: Sliding Window

**Intuition:**
Use sliding window to maintain a window without duplicates. When we find a duplicate, we have a valid window. Shrink to find minimum.

**Algorithm:**
1. Use hashmap to track cards in current window
2. Expand right pointer
3. If card already in window:
   - Update minimum length
   - Shrink from left until duplicate removed
4. Add card to window

### Time Complexity: O(n)
**Why?**
- Right pointer moves n times: O(n)
- Left pointer moves at most n times: O(n)
- Total: O(n)

### Space Complexity: O(n)
**Why?**
- HashMap for window cards
- Worst case: all unique

<br>

---

## Complexity Summary

| Solution | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n³) | O(n) | Checks all subarrays |
| HashMap | O(n) | O(n) | Optimal - tracks last position |
| Sliding Window | O(n) | O(n) | Alternative optimal approach |

> **Recommended Solution:** HashMap with Last Seen - O(n) time, O(n) space

<br>
<br>

---

```code```
