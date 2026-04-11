class Solution {
public:
    // O(n log 10^7) — Binary search on speed
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lo = 1, hi = 1e7;
        if (dist.size() - 1 >= hour) return -1; // Impossible
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            double time = 0;
            for (int i = 0; i < dist.size() - 1; i++)
                time += (dist[i] + mid - 1) / mid; // ceil for intermediate stops
            time += (double)dist.back() / mid; // Last segment: exact
            if (time <= hour) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};