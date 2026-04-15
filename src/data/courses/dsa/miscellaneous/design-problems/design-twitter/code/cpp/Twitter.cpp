#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: Store all tweets, filter on getNewsFeed — O(T) per feed
// ============================================================
class Solution1 {
    unordered_map<int, vector<pair<int,int>>> tweets; // userId → [(time, tweetId)]
    unordered_map<int, unordered_set<int>> follows;
    int time = 0;
public:
    void postTweet(int userId, int tweetId) { tweets[userId].push_back({time++, tweetId}); }
    void follow(int follower, int followee) { follows[follower].insert(followee); }
    void unfollow(int follower, int followee) { follows[follower].erase(followee); }
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> all;
        for (auto& [t,id] : tweets[userId]) all.push_back({t,id});
        for (int f : follows[userId])
            for (auto& [t,id] : tweets[f]) all.push_back({t,id});
        sort(all.rbegin(), all.rend()); // Sort by time desc — O(T log T)
        vector<int> res;
        for (int i = 0; i < min(10, (int)all.size()); i++) res.push_back(all[i].second);
        return res;
    }
};

// ============================================================
// Solution 2: Min-heap merge of K sorted feeds — O(K log K + 10 log K)
// ============================================================
class Solution2 {
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    int time = 0;
public:
    void postTweet(int userId, int tweetId) { tweets[userId].push_back({time++, tweetId}); }
    void follow(int follower, int followee) { follows[follower].insert(followee); }
    void unfollow(int follower, int followee) { follows[follower].erase(followee); }
    vector<int> getNewsFeed(int userId) {
        // Max-heap: (time, tweetId, userId, index_in_user_tweets)
        priority_queue<tuple<int,int,int,int>> pq;
        auto addLatest = [&](int uid) {
            if (!tweets[uid].empty()) {
                int idx = tweets[uid].size() - 1;
                pq.push({tweets[uid][idx].first, tweets[uid][idx].second, uid, idx});
            }
        };
        addLatest(userId);
        for (int f : follows[userId]) addLatest(f);
        vector<int> res;
        unordered_set<int> seen;
        while (!pq.empty() && (int)res.size() < 10) {
            auto [t, tid, uid, idx] = pq.top(); pq.pop();
            res.push_back(tid);
            if (idx > 0) pq.push({tweets[uid][idx-1].first, tweets[uid][idx-1].second, uid, idx-1});
        }
        return res;
    }
};
