Design a simplified version of Twitter with the following operations:
- postTweet(userId, tweetId): Post a new tweet
- getNewsFeed(userId): Retrieve 10 most recent tweet IDs in user's news feed (from user and followees)
- follow(followerId, followeeId): Follower follows a followee
- unfollow(followerId, followeeId): Follower unfollows a followee

<br>

> Input:
> ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
> [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]

> Output:
> [null, null, [5], null, null, [6, 5], null, [5]]

> Explanation:
> - Twitter(): Initialize
> - postTweet(1, 5): User 1 posts tweet 5
> - getNewsFeed(1): Returns [5] (user 1's own tweet)
> - follow(1, 2): User 1 follows user 2
> - postTweet(2, 6): User 2 posts tweet 6
> - getNewsFeed(1): Returns [6, 5] (user 2's tweet 6 is newer, then user 1's tweet 5)
> - unfollow(1, 2): User 1 unfollows user 2
> - getNewsFeed(1): Returns [5] (only user 1's own tweet)

<br>


---

## Constraints

- `Constraints vary by specific problem`
- `Check individual problem for exact bounds`

<br>

---

## All Possible Edge Cases

1. **Minimum input size:** Base case
2. **Maximum input size:** Performance boundary
3. **Edge values (0, INT_MAX, INT_MIN):** Boundary testing
4. **Empty or null input:** Handle gracefully

<br>

---

## Solution: HashMap + Max Heap

Data structures:
1. HashMap<userId, List<Tweet>>: Store each user's tweets with timestamp
2. HashMap<userId, Set<followeeId>>: Store follow relationships
3. Max Heap: Merge k sorted lists (tweets from user + followees)

Approach for getNewsFeed:
1. Get user's tweets and all followees' tweets
2. Use max heap to merge these sorted lists
3. Extract top 10 most recent tweets

```code```

<br>

### Time Complexity Analysis

**postTweet: O(1)**
- Add tweet to user's list: O(1)
- Increment timestamp: O(1)

**follow: O(1)**
- Add followee to follower's set: O(1)
- HashSet add operation is O(1) average

**unfollow: O(1)**
- Remove followee from follower's set: O(1)
- HashSet remove operation is O(1) average

**getNewsFeed: O(k log k + 10 log k)**
- k = number of users to consider (user + followees)
- Build initial heap with k tweets: O(k log k)
- Extract 10 tweets, each extraction: O(log k)
- Total: O(k log k + 10 log k) = O(k log k)
- In practice, k is small (number of followees)

**Space Complexity:**
- Tweets storage: O(n × m) where n = users, m = avg tweets per user
- Follow relationships: O(n × f) where f = avg followees per user
- Heap for getNewsFeed: O(k) where k = followees count

**Why max heap?**
- Each user's tweets are already sorted by timestamp
- Need to merge k sorted lists efficiently
- Max heap gives us the most recent tweet in O(log k) time
- Alternative: Sort all tweets O(n log n) - less efficient

> **Time Complexity:** 
> - postTweet: O(1)
> - follow/unfollow: O(1)
> - getNewsFeed: O(k log k) where k = number of followees
> 
> **Space Complexity:** O(n × m + n × f) for storing tweets and relationships

<br>
<br>

---
