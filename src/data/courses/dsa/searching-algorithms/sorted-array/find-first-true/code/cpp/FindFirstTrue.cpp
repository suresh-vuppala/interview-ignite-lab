#include <iostream>
#include <vector>
using namespace std;

/**
 * Find first true in sorted boolean array
 * Time: O(log n), Space: O(1)
 */
int findFirstTrue(vector<bool>& arr) {
    int left = 0, right = arr.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid]) {
            result = mid;   // Record this as potential answer
            right = mid - 1; // Continue searching left
        } else {
            left = mid + 1;  // Search right
        }
    }
    
    return result;
}

int main() {
    vector<bool> arr = {false, false, false, true, true, true};
    
    int result = findFirstTrue(arr);
    cout << "Index: " << result << endl; // Output: 3
    
    return 0;
}
