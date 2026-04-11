// Same pattern as Aggressive Cows / Magnetic Force
int placeKElements(vector<int>& positions, int k) {
    sort(positions.begin(), positions.end());
    int lo = 1, hi = positions.back() - positions[0];
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        int count = 1, last = positions[0];
        for (int i = 1; i < positions.size(); i++)
            if (positions[i] - last >= mid) { count++; last = positions[i]; }
        if (count >= k) lo = mid; else hi = mid - 1;
    }
    return lo;
}