class Solution {
public:
    // O(n log(max-min)) — Same pattern as Aggressive Cows
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lo = 1, hi = position.back() - position[0];
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            int count = 1, last = position[0];
            for (int i = 1; i < position.size(); i++)
                if (position[i] - last >= mid) { count++; last = position[i]; }
            if (count >= m) lo = mid; else hi = mid - 1;
        }
        return lo;
    }
};