#include <vector>
using namespace std;
// ============================================================
// Solution 1: HashMap frequency count — O(N) Time+Space
// ============================================================
#include <unordered_map>
class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;
        for (auto& [k,v] : freq) if (v == 1) return k;
        return -1;
    }
};

// ============================================================
// Solution 2: XOR all elements — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int x : nums) result ^= x; // a^a=0, a^0=a
        return result; // All pairs cancel, leaving the single number
    }
};
