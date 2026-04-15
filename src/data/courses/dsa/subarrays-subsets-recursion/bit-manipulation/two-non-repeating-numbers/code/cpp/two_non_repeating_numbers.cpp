#include <vector>
using namespace std;
// ============================================================
// Solution 1: HashMap — O(N) Time+Space
// ============================================================
#include <unordered_map>
class Solution1 {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;
        vector<int> res;
        for (auto& [k,v] : freq) if (v == 1) res.push_back(k);
        return res;
    }
};

// ============================================================
// Solution 2: XOR + split by differentiating bit — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int xorAll = 0;
        for (int x : nums) xorAll ^= x; // xorAll = a ^ b
        int diffBit = xorAll & (-xorAll); // Isolate rightmost set bit
        int a = 0, b = 0;
        for (int x : nums) {
            if (x & diffBit) a ^= x; // Group 1: bit set
            else b ^= x;             // Group 2: bit not set
        }
        return {a, b};
    }
};
