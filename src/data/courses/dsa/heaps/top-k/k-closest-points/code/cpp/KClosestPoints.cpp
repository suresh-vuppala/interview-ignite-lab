#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Sort by distance — O(N log N)
// ============================================================
class Solution1 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](auto& a, auto& b){
            return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
        });
        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
};

// ============================================================
// Solution 2: Max-heap of size K — O(N log K)
// ============================================================
class Solution2 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto dist = [](vector<int>& p){ return p[0]*p[0]+p[1]*p[1]; };
        priority_queue<pair<int,int>> maxH; // {dist, index}
        for (int i = 0; i < (int)points.size(); i++) {
            maxH.push({dist(points[i]), i});
            if ((int)maxH.size() > k) maxH.pop();
        }
        vector<vector<int>> res;
        while (!maxH.empty()) { res.push_back(points[maxH.top().second]); maxH.pop(); }
        return res;
    }
};
