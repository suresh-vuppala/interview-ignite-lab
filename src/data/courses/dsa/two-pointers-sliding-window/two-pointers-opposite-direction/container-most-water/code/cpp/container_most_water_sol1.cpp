class Solution {
public:
    // Brute Force: O(n²) — Check all pairs
    int maxArea(vector<int>& height) {
        int maxA = 0;
        for (int i = 0; i < height.size(); i++)
            for (int j = i+1; j < height.size(); j++)
                maxA = max(maxA, min(height[i], height[j]) * (j - i));
        return maxA;
    }
};