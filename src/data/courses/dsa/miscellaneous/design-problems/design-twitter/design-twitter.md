Design Twitter: post tweet, follow/unfollow, get news feed.

<br>

> **Key insight:** HashMap for follows and tweets. Merge-k-sorted for news feed (heap of latest tweets from followees).

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** HashMap + min-heap merge of followee tweets

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `HashMap + min-heap merge of followee tweets`

### Time Complexity: O(N log K) for feed
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log K) for feed | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
