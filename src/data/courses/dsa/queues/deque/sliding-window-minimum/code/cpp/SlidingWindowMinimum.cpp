#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — scan each window for min — O(N*K)
// ============================================================
class Solution1 {
public:
    vector<int> minSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size(); vector<int> result;
        for(int i=0;i<=n-k;i++){
            int mn=nums[i]; for(int j=i+1;j<i+k;j++) mn=min(mn,nums[j]);
            result.push_back(mn);
        }
        return result;
    }
};

// ============================================================
// Solution 2: Monotonic Increasing Deque — O(N) Time
// ============================================================
class Solution2 {
public:
    vector<int> minSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size(); deque<int> dq; vector<int> result;
        for(int i=0;i<n;i++){
            while(!dq.empty()&&dq.front()<=i-k) dq.pop_front();
            while(!dq.empty()&&nums[dq.back()]>=nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) result.push_back(nums[dq.front()]);
        }
        return result;
    }
};
