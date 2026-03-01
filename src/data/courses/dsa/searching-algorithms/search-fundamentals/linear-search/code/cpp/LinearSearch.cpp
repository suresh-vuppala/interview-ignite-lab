#include <iostream>
#include <vector>
using namespace std;

/**
 * Linear search - scan elements sequentially until target found
 * Time: O(n), Space: O(1)
 */
int linearSearch(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};
    int target = 5;
    
    int result = linearSearch(nums, target);
    cout << "Index: " << result << endl; // Output: 4
    
    return 0;
}
