class Solution {
public:
    // O(n log max_time) — Binary search on total time
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lo = 1, hi = (long long)*max_element(time.begin(), time.end()) * totalTrips;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long trips = 0;
            for (int t : time) trips += mid / t;
            if (trips >= totalTrips) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};