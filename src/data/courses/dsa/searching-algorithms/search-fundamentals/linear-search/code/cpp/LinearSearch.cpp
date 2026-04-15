#include <vector>
using namespace std;
// ============================================================
// Solution 1: Linear scan left to right — O(N) Time, O(1) Space
// ============================================================
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < (int)nums.size(); i++)
            if (nums[i] == target) return i;
        return -1;
    }
};

// ============================================================
// Solution 2: Sentinel search — place target at end, avoid bound check — O(N)
// ============================================================
class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        int last = nums[n-1];
        nums[n-1] = target; // Sentinel
        int i = 0;
        while (nums[i] != target) i++; // No bounds check needed!
        nums[n-1] = last; // Restore
        if (i < n-1 || last == target) return i;
        return -1;
    }
};
