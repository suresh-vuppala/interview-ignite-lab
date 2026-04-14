#include <vector>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Brute Force — circular scan — O(N²)
// ============================================================
class Solution1 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size(); vector<int> res(n,-1);
        for(int i=0;i<n;i++)
            for(int j=1;j<n;j++){int idx=(i+j)%n;if(nums[idx]>nums[i]){res[i]=nums[idx];break;}}
        return res;
    }
};

// ============================================================
// Solution 2: Monotonic stack — traverse 2*N (circular trick) — O(N)
// ============================================================
class Solution2 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size(); vector<int> res(n,-1); stack<int> st;
        for(int i=0;i<2*n;i++){  // Traverse twice for circular
            while(!st.empty()&&nums[st.top()]<nums[i%n]){res[st.top()]=nums[i%n];st.pop();}
            if(i<n) st.push(i);
        }
        return res;
    }
};
