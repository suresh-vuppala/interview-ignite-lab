Design simplified Twitter: postTweet, getNewsFeed, follow, unfollow.

<br>

> postTweet(1,'hello'), follow(1,2), getNewsFeed(1)→[tweets from 1 and 2]
>
> **Key insight:** HashMap for follows (user→set of followees) and tweets (user→list of (timestamp,tweet)). News feed = merge-k-sorted of followee tweet lists using heap.

<br>

---

## Constraints
- 1 ≤ userId, tweetId ≤ 500
- Up to 3 × 10⁴ calls

<br>

---

## All Possible Edge Cases
1. **User with no tweets
2. **User with no followees: only own tweets
3. **Follow/unfollow self
4. **More than 10 tweets: show 10 most recent**

<br>

---

## Solution 1: Scan all tweets

**Intuition:**
The most straightforward approach. Scanning all tweets for every feed request.

**Algorithm:**
1. Scan through each element from left to right
2. For each element, check the required condition
3. Track and return the best result

### Time Complexity: O(all tweets)
**Why?**
The approach processes each state/element with the work described by the complexity.
Total operations scale accordingly with input size.

**Detailed breakdown:**
Verify against constraint limits to ensure it passes within time.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Scanning all tweets for every feed request.

> **Key Insight for Improvement:**
> Per-user tweet list + follows set. Feed: collect latest tweets from each followee, merge with min-heap (top 10).

<br>

---

## Solution 2: HashMap + Heap Merge (Optimal)

**Intuition:** HashMap for follows (user→set of followees) and tweets (user→list of (timestamp,tweet)). News feed = merge-k-sorted of followee tweet lists using heap.

**Algorithm:**
1. follow: followMap[user].add(followee)
2. postTweet: tweetMap[user].append((timestamp, tweet))
3. getNewsFeed: collect latest tweet from each followee → min-heap → top 10

### Time Complexity: O(N log K) for feed
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
User 1 follows [2,3]. Feed: merge latest from user 1,2,3's tweets. Top 10 by timestamp.
```

### Space Complexity: O(U + T)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Scan all tweets | O(all tweets) | Varies | Baseline |
| HashMap + Heap Merge | O(N log K) for feed | O(U + T) | Optimal |

**Recommended Solution:** HashMap + Heap Merge

**Key Insights:**
1. **Merge-k-sorted pattern:** Heap of latest tweets per followee
2. **Timestamp ordering:** Global counter for tweet ordering
3. **LeetCode 355:** OOP design problem

<br><br>

---

```code```
