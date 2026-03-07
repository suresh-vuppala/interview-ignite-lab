// Time: O(N * log(sum - max))
// Space: O(1)

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int paintersPartition(vector<int>& arr, int m) {
        if (m > arr.size()) return -1;
        
        int left = *max_element(arr.begin(), arr.end());
        int right = accumulate(arr.begin(), arr.end(), 0);
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canPaint(arr, m, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
    
private:
    bool canPaint(vector<int>& arr, int m, int maxTime) {
        int painters = 1, currentTime = 0;
        for (int time : arr) {
            if (currentTime + time > maxTime) {
                painters++;
                currentTime = time;
            } else {
                currentTime += time;
            }
        }
        return painters <= m;
    }
};
