#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Basic operations — linear approaches
// ============================================================
class Solution1 {
public:
    // Find element — linear scan O(N)
    int find(vector<int>& arr, int target) {
        for (int i = 0; i < (int)arr.size(); i++)
            if (arr[i] == target) return i;
        return -1;
    }
    // Find max — linear scan O(N)
    int findMax(vector<int>& arr) {
        int mx = arr[0];
        for (int x : arr) mx = max(mx, x);
        return mx;
    }
    // Reverse — two pointer O(N)
    void reverse(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        while (l < r) swap(arr[l++], arr[r--]);
    }
};

// ============================================================
// Solution 2: STL-powered approaches — same complexity, cleaner code
// ============================================================
class Solution2 {
public:
    int find(vector<int>& arr, int target) {
        auto it = std::find(arr.begin(), arr.end(), target);
        return it != arr.end() ? it - arr.begin() : -1;
    }
    int findMax(vector<int>& arr) { return *max_element(arr.begin(), arr.end()); }
    void reverse(vector<int>& arr) { std::reverse(arr.begin(), arr.end()); }
    // Sort — O(N log N)
    void sort(vector<int>& arr) { std::sort(arr.begin(), arr.end()); }
    // Binary search on sorted array — O(log N)
    bool binarySearch(vector<int>& arr, int target) {
        return std::binary_search(arr.begin(), arr.end(), target);
    }
};
