#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// ============================================================
// Solution 1: Backtracking — assign each job to a worker — O(K^N)
// ============================================================
class Solution1 {
    int res = INT_MAX;
    void dfs(vector<int>& jobs, vector<int>& workers, int i) {
        if (i == (int)jobs.size()) {
            res = min(res, *max_element(workers.begin(), workers.end()));
            return;
        }
        for (int j = 0; j < (int)workers.size(); j++) {
            if (workers[j] + jobs[i] >= res) continue; // Prune
            workers[j] += jobs[i];
            dfs(jobs, workers, i + 1);
            workers[j] -= jobs[i];
            if (workers[j] == 0) break; // Symmetry breaking
        }
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend()); // Largest first for better pruning
        vector<int> workers(k, 0);
        res = accumulate(jobs.begin(), jobs.end(), 0);
        dfs(jobs, workers, 0);
        return res;
    }
};

// ============================================================
// Solution 2: Binary Search + backtracking feasibility check — O(N log S * K^N)
// ============================================================
class Solution2 {
    bool canFinish(vector<int>& jobs, vector<int>& workers, int i, int limit) {
        if (i == (int)jobs.size()) return true;
        for (int j = 0; j < (int)workers.size(); j++) {
            if (workers[j] + jobs[i] > limit) continue;
            workers[j] += jobs[i];
            if (canFinish(jobs, workers, i + 1, limit)) return true;
            workers[j] -= jobs[i];
            if (workers[j] == 0) break;
        }
        return false;
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend());
        int lo = *max_element(jobs.begin(), jobs.end());
        int hi = accumulate(jobs.begin(), jobs.end(), 0);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            vector<int> workers(k, 0);
            if (canFinish(jobs, workers, 0, mid)) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};
