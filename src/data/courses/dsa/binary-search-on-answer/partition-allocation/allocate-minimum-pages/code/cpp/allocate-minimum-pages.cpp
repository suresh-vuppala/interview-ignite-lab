// Time: O(N * log(sum - max))
// Space: O(1)

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int allocateBooks(vector<int>& arr, int m) {
        if (m > arr.size()) return -1;
        
        int left = *max_element(arr.begin(), arr.end());
        int right = accumulate(arr.begin(), arr.end(), 0);
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAllocate(arr, m, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
    
private:
    bool canAllocate(vector<int>& arr, int m, int maxPages) {
        int students = 1, currentPages = 0;
        
        for (int pages : arr) {
            if (currentPages + pages > maxPages) {
                students++;
                currentPages = pages;
            } else {
                currentPages += pages;
            }
        }
        
        return students <= m;
    }
};
