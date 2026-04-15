#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Selection sort — find min each pass — O(N²)
// ============================================================
class Solution1 {
public:
    void sort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int minIdx = i;
            for (int j = i+1; j < n; j++) if (nums[j] < nums[minIdx]) minIdx = j;
            swap(nums[i], nums[minIdx]);
        }
    }
};

// ============================================================
// Solution 2: Heap Sort — O(N log N) Time, O(1) Space
// ============================================================
class Solution2 {
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i, l = 2*i+1, r = 2*i+2;
        if (l < n && nums[l] > nums[largest]) largest = l;
        if (r < n && nums[r] > nums[largest]) largest = r;
        if (largest != i) { swap(nums[i], nums[largest]); heapify(nums, n, largest); }
    }
public:
    void sort(vector<int>& nums) {
        int n = nums.size();
        for (int i = n/2-1; i >= 0; i--) heapify(nums, n, i); // Build max-heap
        for (int i = n-1; i > 0; i--) { swap(nums[0], nums[i]); heapify(nums, i, 0); } // Extract max
    }
};
