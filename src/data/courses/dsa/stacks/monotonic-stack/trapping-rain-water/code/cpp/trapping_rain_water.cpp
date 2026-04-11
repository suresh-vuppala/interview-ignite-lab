// ============================================================
// Trapping Rain Water
// ============================================================

#include <vector>
#include <algorithm>
using namespace std;

// ============================================================
// Solution 1: Brute Force — Per-Position Scan
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;

        for (int i = 1; i < n - 1; i++) {
            // Find max height to the left
            int maxLeft = *max_element(height.begin(), height.begin() + i + 1);
            // Find max height to the right
            int maxRight = *max_element(height.begin() + i, height.end());

            // Water at this position
            water += min(maxLeft, maxRight) - height[i];
        }

        return water;
    }
};

// ============================================================
// Solution 2: Prefix Max Arrays
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);

        // Build left max array
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i - 1], height[i]);

        // Build right max array
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i + 1], height[i]);

        // Calculate trapped water
        int water = 0;
        for (int i = 0; i < n; i++)
            water += min(leftMax[i], rightMax[i]) - height[i];

        return water;
    }
};

// ============================================================
// Solution 3: Two Pointers (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution3 {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                // Left side is shorter — process left
                if (height[left] >= maxLeft)
                    maxLeft = height[left];  // New max — no water here
                else
                    water += maxLeft - height[left]; // Trap water

                left++;
            } else {
                // Right side is shorter — process right
                if (height[right] >= maxRight)
                    maxRight = height[right];
                else
                    water += maxRight - height[right];

                right--;
            }
        }

        return water;
    }
};
