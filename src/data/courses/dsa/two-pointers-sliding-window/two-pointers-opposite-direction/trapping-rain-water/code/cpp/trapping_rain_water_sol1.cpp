class Solution {
public:
    // Brute Force: O(n²) — Scan left/right max for each position
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;
        for (int i = 1; i < n - 1; i++) {
            int maxLeft = *max_element(height.begin(), height.begin() + i + 1);
            int maxRight = *max_element(height.begin() + i, height.end());
            water += min(maxLeft, maxRight) - height[i];
        }
        return water;
    }
};