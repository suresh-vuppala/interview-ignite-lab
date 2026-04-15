#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: HashMap + sort by frequency — O(N log N)
// ============================================================
class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;
        vector<pair<int,int>> freqVec(freq.begin(), freq.end());
        sort(freqVec.begin(), freqVec.end(), [](auto&a,auto&b){return a.second>b.second;});
        vector<int> res;
        for (int i = 0; i < k; i++) res.push_back(freqVec[i].first);
        return res;
    }
};

// ============================================================
// Solution 2: HashMap + min-heap of size K — O(N log K)
// ============================================================
class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minH;
        for (auto& [num, cnt] : freq) {
            minH.push({cnt, num});
            if ((int)minH.size() > k) minH.pop();
        }
        vector<int> res;
        while (!minH.empty()) { res.push_back(minH.top().second); minH.pop(); }
        return res;
    }
};
