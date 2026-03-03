#include <vector>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int xorAll = 0;
    for (int num : nums) xorAll ^= num;
    
    int rightmost = xorAll & -xorAll;
    int a = 0, b = 0;
    for (int num : nums) {
        if (num & rightmost)
            a ^= num;
        else
            b ^= num;
    }
    return {a, b};
}