// Time: O(N) | Space: O(1)

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums)
            result ^= num;
        return result;
    }
};