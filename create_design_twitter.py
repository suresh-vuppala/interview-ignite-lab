import os
import json

base_path = "src/data/courses/dsa/miscellaneous/design-problems/design-twitter"
code_path = os.path.join(base_path, "code")

os.makedirs(os.path.join(code_path, "java"), exist_ok=True)
os.makedirs(os.path.join(code_path, "cpp"), exist_ok=True)
os.makedirs(os.path.join(code_path, "python"), exist_ok=True)

# Markdown
md_content = """## Problem Statement

Design a simplified Twitter with:
- postTweet(userId, tweetId)
- getNewsFeed(userId) - 10 most recent tweets from user and followees
- follow(followerId, followeeId)
- unfollow(followerId, followeeId)

## Approach

1. Use HashMap for user tweets and followees
2. Use max heap to merge k sorted lists for news feed
3. Each user maintains list of tweets with timestamp

## Complexity

- postTweet: O(1)
- getNewsFeed: O(n log k) where k = number of followees
- follow/unfollow: O(1)

## Code

```code```"""

with open(os.path.join(base_path, "design-twitter.md"), "w", encoding="utf-8") as f:
    f.write(md_content)

# JSON
json_content = {
    "title": "Design Twitter",
    "description": "Design a simplified Twitter system",
    "difficulty": "medium",
    "isPremium": False,
    "isPosted": True
}

with open(os.path.join(base_path, "design-twitter.json"), "w", encoding="utf-8") as f:
    json.dump(json_content, f, indent=4)

# Java
java_code = """class Twitter {
    private int timestamp = 0;
    private Map<Integer, List<int[]>> tweets;
    private Map<Integer, Set<Integer>> following;
    
    public Twitter() {
        tweets = new HashMap<>();
        following = new HashMap<>();
    }
    
    public void postTweet(int userId, int tweetId) {
        tweets.putIfAbsent(userId, new ArrayList<>());
        tweets.get(userId).add(new int[]{timestamp++, tweetId});
    }
    
    public List<Integer> getNewsFeed(int userId) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        
        if (tweets.containsKey(userId)) {
            List<int[]> userTweets = tweets.get(userId);
            int idx = userTweets.size() - 1;
            if (idx >= 0) pq.offer(new int[]{userTweets.get(idx)[0], userTweets.get(idx)[1], userId, idx});
        }
        
        if (following.containsKey(userId)) {
            for (int followeeId : following.get(userId)) {
                if (tweets.containsKey(followeeId)) {
                    List<int[]> followeeTweets = tweets.get(followeeId);
                    int idx = followeeTweets.size() - 1;
                    if (idx >= 0) pq.offer(new int[]{followeeTweets.get(idx)[0], followeeTweets.get(idx)[1], followeeId, idx});
                }
            }
        }
        
        List<Integer> result = new ArrayList<>();
        while (!pq.isEmpty() && result.size() < 10) {
            int[] curr = pq.poll();
            result.add(curr[1]);
            int nextIdx = curr[3] - 1;
            if (nextIdx >= 0) {
                List<int[]> userTweets = tweets.get(curr[2]);
                pq.offer(new int[]{userTweets.get(nextIdx)[0], userTweets.get(nextIdx)[1], curr[2], nextIdx});
            }
        }
        return result;
    }
    
    public void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following.putIfAbsent(followerId, new HashSet<>());
        following.get(followerId).add(followeeId);
    }
    
    public void unfollow(int followerId, int followeeId) {
        if (following.containsKey(followerId)) {
            following.get(followerId).remove(followeeId);
        }
    }
}"""

with open(os.path.join(code_path, "java", "Twitter.java"), "w") as f:
    f.write(java_code)

# C++
cpp_code = """class Twitter {
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    
public:
    Twitter() : timestamp(0) {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        auto cmp = [](const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {
            return get<0>(a) < get<0>(b);
        };
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, decltype(cmp)> pq(cmp);
        
        if (tweets.count(userId)) {
            auto& userTweets = tweets[userId];
            int idx = userTweets.size() - 1;
            if (idx >= 0) pq.push({userTweets[idx].first, userTweets[idx].second, userId, idx});
        }
        
        if (following.count(userId)) {
            for (int followeeId : following[userId]) {
                if (tweets.count(followeeId)) {
                    auto& followeeTweets = tweets[followeeId];
                    int idx = followeeTweets.size() - 1;
                    if (idx >= 0) pq.push({followeeTweets[idx].first, followeeTweets[idx].second, followeeId, idx});
                }
            }
        }
        
        vector<int> result;
        while (!pq.empty() && result.size() < 10) {
            auto [ts, tweetId, uid, idx] = pq.top();
            pq.pop();
            result.push_back(tweetId);
            int nextIdx = idx - 1;
            if (nextIdx >= 0) {
                auto& userTweets = tweets[uid];
                pq.push({userTweets[nextIdx].first, userTweets[nextIdx].second, uid, nextIdx});
            }
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (following.count(followerId)) {
            following[followerId].erase(followeeId);
        }
    }
};"""

with open(os.path.join(code_path, "cpp", "Twitter.cpp"), "w") as f:
    f.write(cpp_code)

# Python
python_code = """import heapq
from collections import defaultdict

class Twitter:
    def __init__(self):
        self.timestamp = 0
        self.tweets = defaultdict(list)
        self.following = defaultdict(set)
    
    def postTweet(self, userId, tweetId):
        self.tweets[userId].append((self.timestamp, tweetId))
        self.timestamp += 1
    
    def getNewsFeed(self, userId):
        heap = []
        
        if userId in self.tweets:
            idx = len(self.tweets[userId]) - 1
            ts, tid = self.tweets[userId][idx]
            heapq.heappush(heap, (-ts, tid, userId, idx))
        
        for followeeId in self.following[userId]:
            if followeeId in self.tweets:
                idx = len(self.tweets[followeeId]) - 1
                ts, tid = self.tweets[followeeId][idx]
                heapq.heappush(heap, (-ts, tid, followeeId, idx))
        
        result = []
        while heap and len(result) < 10:
            ts, tid, uid, idx = heapq.heappop(heap)
            result.append(tid)
            next_idx = idx - 1
            if next_idx >= 0:
                ts, tid = self.tweets[uid][next_idx]
                heapq.heappush(heap, (-ts, tid, uid, next_idx))
        return result
    
    def follow(self, followerId, followeeId):
        if followerId != followeeId:
            self.following[followerId].add(followeeId)
    
    def unfollow(self, followerId, followeeId):
        self.following[followerId].discard(followeeId)"""

with open(os.path.join(code_path, "python", "design-twitter.py"), "w") as f:
    f.write(python_code)

print("Design Twitter lesson created")
