#include <vector>
using namespace std;
// ============================================================
// Solution 1: Brute Force — check all subarrays — O(N²)
// ============================================================
class Solution1 {
public:
    pair<int,int> countOddEven(vector<int>& nums) {
        int n = nums.size(), odd = 0, even = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum % 2 == 0) even++; else odd++;
            }
        }
        return {odd, even};
    }
};

// ============================================================
// Solution 2: Prefix Sum parity counting — O(N)
// ============================================================
class Solution2 {
public:
    pair<int,int> countOddEven(vector<int>& nums) {
        int oddPrefixes = 0, evenPrefixes = 1; // prefix[0]=0 is even
        int sum = 0, oddSubs = 0, evenSubs = 0;
        for (int x : nums) {
            sum += x;
            if (sum % 2 == 0) { evenSubs += evenPrefixes; oddSubs += oddPrefixes; evenPrefixes++; }
            else { evenSubs += oddPrefixes; oddSubs += evenPrefixes; oddPrefixes++; }
        }
        return {oddSubs, evenSubs};
    }
};
