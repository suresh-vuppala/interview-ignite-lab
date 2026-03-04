class Twitter {
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
};