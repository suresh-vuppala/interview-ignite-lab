import os

base = "src/data/courses/dsa"

# Jump Game
jump_java = """class JumpGame {
    public boolean canJump(int[] nums) {
        int maxReach = 0; // Maximum index we can reach
        for (int i = 0; i < nums.length; i++) {
            if (i > maxReach) return false; // Can't reach this index
            maxReach = Math.max(maxReach, i + nums[i]); // Update max reach
        }
        return true;
    }
}"""

jump_cpp = """class JumpGame {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0; // Maximum index we can reach
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) return false; // Can't reach this index
            maxReach = max(maxReach, i + nums[i]); // Update max reach
        }
        return true;
    }
};"""

jump_python = """def can_jump(nums):
    max_reach = 0  # Maximum index we can reach
    for i in range(len(nums)):
        if i > max_reach:
            return False  # Can't reach this index
        max_reach = max(max_reach, i + nums[i])  # Update max reach
    return True"""

# Jump Game II
jump2_java = """class JumpGameII {
    public int jump(int[] nums) {
        int jumps = 0, currentEnd = 0, farthest = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            farthest = Math.max(farthest, i + nums[i]); // Track farthest reachable
            if (i == currentEnd) { // Reached end of current jump
                jumps++; // Make next jump
                currentEnd = farthest; // Update jump boundary
            }
        }
        return jumps;
    }
}"""

jump2_cpp = """class JumpGameII {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, currentEnd = 0, farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]); // Track farthest reachable
            if (i == currentEnd) { // Reached end of current jump
                jumps++; // Make next jump
                currentEnd = farthest; // Update jump boundary
            }
        }
        return jumps;
    }
};"""

jump2_python = """def jump(nums):
    jumps, current_end, farthest = 0, 0, 0
    for i in range(len(nums) - 1):
        farthest = max(farthest, i + nums[i])  # Track farthest reachable
        if i == current_end:  # Reached end of current jump
            jumps += 1  # Make next jump
            current_end = farthest  # Update jump boundary
    return jumps"""

# Remove K Digits
remove_java = """class RemoveKDigits {
    public String removeKdigits(String num, int k) {
        Stack<Character> stack = new Stack<>();
        for (char c : num.toCharArray()) {
            while (!stack.isEmpty() && k > 0 && stack.peek() > c) {
                stack.pop(); // Remove larger digit
                k--;
            }
            stack.push(c);
        }
        while (k-- > 0) stack.pop(); // Remove remaining k digits
        
        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) sb.append(stack.pop());
        sb.reverse();
        
        while (sb.length() > 1 && sb.charAt(0) == '0') sb.deleteCharAt(0); // Remove leading zeros
        return sb.length() == 0 ? "0" : sb.toString();
    }
}"""

remove_cpp = """class RemoveKDigits {
public:
    string removeKdigits(string num, int k) {
        string stack;
        for (char c : num) {
            while (!stack.empty() && k > 0 && stack.back() > c) {
                stack.pop_back(); // Remove larger digit
                k--;
            }
            stack.push_back(c);
        }
        while (k-- > 0) stack.pop_back(); // Remove remaining k digits
        
        int start = 0;
        while (start < stack.size() && stack[start] == '0') start++; // Remove leading zeros
        string result = stack.substr(start);
        return result.empty() ? "0" : result;
    }
};"""

remove_python = """def remove_k_digits(num, k):
    stack = []
    for c in num:
        while stack and k > 0 and stack[-1] > c:
            stack.pop()  # Remove larger digit
            k -= 1
        stack.append(c)
    while k > 0:
        stack.pop()  # Remove remaining k digits
        k -= 1
    result = ''.join(stack).lstrip('0')  # Remove leading zeros
    return result if result else '0'"""

# Design Twitter
twitter_java = """class Twitter {
    private int timestamp = 0;
    private Map<Integer, List<int[]>> tweets; // userId -> list of [timestamp, tweetId]
    private Map<Integer, Set<Integer>> following; // userId -> set of followeeIds
    
    public Twitter() {
        tweets = new HashMap<>();
        following = new HashMap<>();
    }
    
    public void postTweet(int userId, int tweetId) {
        tweets.putIfAbsent(userId, new ArrayList<>());
        tweets.get(userId).add(new int[]{timestamp++, tweetId});
    }
    
    public List<Integer> getNewsFeed(int userId) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]); // Max heap by timestamp
        
        // Add user's own tweets
        if (tweets.containsKey(userId)) {
            List<int[]> userTweets = tweets.get(userId);
            int idx = userTweets.size() - 1;
            if (idx >= 0) pq.offer(new int[]{userTweets.get(idx)[0], userTweets.get(idx)[1], userId, idx});
        }
        
        // Add followees' tweets
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
            result.add(curr[1]); // Add tweetId
            int nextIdx = curr[3] - 1;
            if (nextIdx >= 0) { // Add next tweet from same user
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

twitter_cpp = """class Twitter {
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> list of {timestamp, tweetId}
    unordered_map<int, unordered_set<int>> following; // userId -> set of followeeIds
    
public:
    Twitter() : timestamp(0) {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        auto cmp = [](const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {
            return get<0>(a) < get<0>(b); // Max heap by timestamp
        };
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, decltype(cmp)> pq(cmp);
        
        // Add user's own tweets
        if (tweets.count(userId)) {
            auto& userTweets = tweets[userId];
            int idx = userTweets.size() - 1;
            if (idx >= 0) pq.push({userTweets[idx].first, userTweets[idx].second, userId, idx});
        }
        
        // Add followees' tweets
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
            if (nextIdx >= 0) { // Add next tweet from same user
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

twitter_python = """import heapq
from collections import defaultdict

class Twitter:
    def __init__(self):
        self.timestamp = 0
        self.tweets = defaultdict(list)  # userId -> list of (timestamp, tweetId)
        self.following = defaultdict(set)  # userId -> set of followeeIds
    
    def postTweet(self, userId, tweetId):
        self.tweets[userId].append((self.timestamp, tweetId))
        self.timestamp += 1
    
    def getNewsFeed(self, userId):
        heap = []
        
        # Add user's own tweets
        if userId in self.tweets:
            idx = len(self.tweets[userId]) - 1
            ts, tid = self.tweets[userId][idx]
            heapq.heappush(heap, (-ts, tid, userId, idx))  # Max heap by timestamp
        
        # Add followees' tweets
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
            if next_idx >= 0:  # Add next tweet from same user
                ts, tid = self.tweets[uid][next_idx]
                heapq.heappush(heap, (-ts, tid, uid, next_idx))
        return result
    
    def follow(self, followerId, followeeId):
        if followerId != followeeId:
            self.following[followerId].add(followeeId)
    
    def unfollow(self, followerId, followeeId):
        self.following[followerId].discard(followeeId)"""

# Write files
with open(f"{base}/greedy/others/jump-game/code/java/JumpGame.java", "w") as f:
    f.write(jump_java)
with open(f"{base}/greedy/others/jump-game/code/cpp/JumpGame.cpp", "w") as f:
    f.write(jump_cpp)
with open(f"{base}/greedy/others/jump-game/code/python/jump-game.py", "w") as f:
    f.write(jump_python)

with open(f"{base}/greedy/others/jump-game-ii/code/java/JumpGameII.java", "w") as f:
    f.write(jump2_java)
with open(f"{base}/greedy/others/jump-game-ii/code/cpp/JumpGameII.cpp", "w") as f:
    f.write(jump2_cpp)
with open(f"{base}/greedy/others/jump-game-ii/code/python/jump-game-ii.py", "w") as f:
    f.write(jump2_python)

with open(f"{base}/greedy/others/remove-k-digits/code/java/RemoveKDigits.java", "w") as f:
    f.write(remove_java)
with open(f"{base}/greedy/others/remove-k-digits/code/cpp/RemoveKDigits.cpp", "w") as f:
    f.write(remove_cpp)
with open(f"{base}/greedy/others/remove-k-digits/code/python/remove-k-digits.py", "w") as f:
    f.write(remove_python)

with open(f"{base}/miscellaneous/design-problems/design-twitter/code/java/Twitter.java", "w") as f:
    f.write(twitter_java)
with open(f"{base}/miscellaneous/design-problems/design-twitter/code/cpp/Twitter.cpp", "w") as f:
    f.write(twitter_cpp)
with open(f"{base}/miscellaneous/design-problems/design-twitter/code/python/design-twitter.py", "w") as f:
    f.write(twitter_python)

print("Remaining Greedy and Miscellaneous lessons updated with comments")
