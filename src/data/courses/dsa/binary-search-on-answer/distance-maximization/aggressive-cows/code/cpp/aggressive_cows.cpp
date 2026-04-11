// O(n log(max-min)) — Binary search on minimum distance
int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int lo = 1, hi = stalls.back() - stalls[0];
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2; // Upper binary search
        int count = 1, lastPos = stalls[0];
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= mid) { count++; lastPos = stalls[i]; }
        }
        if (count >= k) lo = mid;   // Can spread further apart
        else hi = mid - 1;          // Too far apart
    }
    return lo;
}