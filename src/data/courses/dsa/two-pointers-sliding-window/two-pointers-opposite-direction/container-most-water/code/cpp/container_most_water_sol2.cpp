class Solution {
public:
    // Optimal: O(n) — Two pointers, move shorter side
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxArea = 0;
        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, area);
            // Move the SHORTER line — it limits area
            if (height[left] < height[right]) left++;
            else right--;
        }
        return maxArea;
    }
};