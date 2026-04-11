class Solution {
public:
    // O(n log sum) — Binary search on maximum time per worker
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int lo = *max_element(jobs.begin(), jobs.end());
        int hi = accumulate(jobs.begin(), jobs.end(), 0);
        sort(jobs.rbegin(), jobs.rend()); // Sort descending for better pruning
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            vector<int> workers(k, 0);
            if (canFinish(jobs, workers, 0, mid)) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
    bool canFinish(vector<int>& jobs, vector<int>& workers, int idx, int limit) {
        if (idx == jobs.size()) return true;
        for (int i = 0; i < workers.size(); i++) {
            if (workers[i] + jobs[idx] <= limit) {
                workers[i] += jobs[idx];
                if (canFinish(jobs, workers, idx+1, limit)) return true;
                workers[i] -= jobs[idx];
            }
            if (workers[i] == 0) break; // Prune: empty workers are equivalent
        }
        return false;
    }
};