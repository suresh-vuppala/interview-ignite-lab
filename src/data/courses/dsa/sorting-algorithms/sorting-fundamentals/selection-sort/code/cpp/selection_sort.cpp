#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Basic Selection Sort — find min, place at front — O(N²)
// ============================================================
class Solution1 {
public:
    void selectionSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            int minIdx = i;
            for (int j = i+1; j < n; j++)
                if (nums[j] < nums[minIdx]) minIdx = j;
            swap(nums[i], nums[minIdx]); // One swap per pass
        }
    }
};

// ============================================================
// Solution 2: Double-ended — find min AND max each pass — O(N²) but fewer passes
// ============================================================
class Solution2 {
public:
    void selectionSort(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int minIdx = left, maxIdx = left;
            for (int i = left; i <= right; i++) {
                if (nums[i] < nums[minIdx]) minIdx = i;
                if (nums[i] > nums[maxIdx]) maxIdx = i;
            }
            swap(nums[left], nums[minIdx]);
            if (maxIdx == left) maxIdx = minIdx; // Adjust if max was at left
            swap(nums[right], nums[maxIdx]);
            left++; right--;
        }
    }
};
