#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Basic Bubble Sort — O(N²) always
// ============================================================
class Solution1 {
public:
    void bubbleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n-1; i++)
            for (int j = 0; j < n-i-1; j++)
                if (nums[j] > nums[j+1]) swap(nums[j], nums[j+1]);
    }
};

// ============================================================
// Solution 2: Optimized — early termination if no swaps — O(N) best case
// ============================================================
class Solution2 {
public:
    void bubbleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            bool swapped = false;
            for (int j = 0; j < n-i-1; j++)
                if (nums[j] > nums[j+1]) { swap(nums[j], nums[j+1]); swapped = true; }
            if (!swapped) break; // Already sorted!
        }
    }
};
