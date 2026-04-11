// ============================================================
// Container With Most Water
// ============================================================

#include <vector>
#include <algorithm>
using namespace std;

// ============================================================
// Solution 1: Brute Force — All Pairs
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;

        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = i + 1; j < height.size(); j++) {
                // Area = min height × width
                int area = min(height[i], height[j]) * (j - i);
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};

// ============================================================
// Solution 2: Two Pointers — Move Shorter Side (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            // Calculate area with current pair
            int area = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, area);

            // Move the SHORTER line — it limits the area
            if (height[left] < height[right]) {
                left++;   // Shorter side moves inward
            } else {
                right--;  // Shorter (or equal) side moves inward
            }
        }

        return maxArea;
    }
};
