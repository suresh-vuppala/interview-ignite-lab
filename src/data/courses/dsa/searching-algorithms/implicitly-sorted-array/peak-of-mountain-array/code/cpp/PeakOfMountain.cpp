#include <vector>
using namespace std;
// ============================================================
// Solution 1: Linear scan — O(N) Time
// ============================================================
class Solution1 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        for (int i = 1; i < (int)arr.size() - 1; i++)
            if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) return i;
        return -1;
    }
};

// ============================================================
// Solution 2: Binary search — O(log N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo = 1, hi = arr.size() - 2;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            if (arr[mid] < arr[mid+1]) lo = mid + 1; // Peak is to the right
            else hi = mid - 1; // Peak is to the left
        }
        return lo;
    }
};
