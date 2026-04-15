#include <vector>
using namespace std;
// ============================================================
// Solution 1: Basic Insertion Sort — shift elements — O(N²)
// ============================================================
class Solution1 {
public:
    void insertionSort(vector<int>& nums) {
        for (int i = 1; i < (int)nums.size(); i++) {
            int key = nums[i], j = i-1;
            while (j >= 0 && nums[j] > key) { nums[j+1] = nums[j]; j--; }
            nums[j+1] = key;
        }
    }
};

// ============================================================
// Solution 2: Binary Insertion Sort — binary search for position — O(N²) shifts, O(N log N) comparisons
// ============================================================
#include <algorithm>
class Solution2 {
public:
    void insertionSort(vector<int>& nums) {
        for (int i = 1; i < (int)nums.size(); i++) {
            int key = nums[i];
            // Binary search for insertion position in [0..i-1]
            int pos = upper_bound(nums.begin(), nums.begin()+i, key) - nums.begin();
            // Shift elements right
            for (int j = i; j > pos; j--) nums[j] = nums[j-1];
            nums[pos] = key;
        }
    }
};
