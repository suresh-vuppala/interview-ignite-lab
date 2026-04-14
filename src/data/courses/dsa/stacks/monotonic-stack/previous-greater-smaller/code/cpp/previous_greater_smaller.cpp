#include <vector>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Brute Force — scan left for each — O(N²)
// ============================================================
class Solution1 {
public:
    vector<int> prevGreater(vector<int>& nums) {
        int n=nums.size(); vector<int> res(n,-1);
        for(int i=0;i<n;i++)for(int j=i-1;j>=0;j--)if(nums[j]>nums[i]){res[i]=nums[j];break;}
        return res;
    }
    vector<int> prevSmaller(vector<int>& nums) {
        int n=nums.size(); vector<int> res(n,-1);
        for(int i=0;i<n;i++)for(int j=i-1;j>=0;j--)if(nums[j]<nums[i]){res[i]=nums[j];break;}
        return res;
    }
};

// ============================================================
// Solution 2: Monotonic stack — traverse left to right — O(N)
// ============================================================
class Solution2 {
public:
    vector<int> prevGreater(vector<int>& nums) {
        int n=nums.size(); vector<int> res(n,-1); stack<int> st;
        for(int i=0;i<n;i++){while(!st.empty()&&nums[st.top()]<=nums[i])st.pop();if(!st.empty())res[i]=nums[st.top()];st.push(i);}
        return res;
    }
    vector<int> prevSmaller(vector<int>& nums) {
        int n=nums.size(); vector<int> res(n,-1); stack<int> st;
        for(int i=0;i<n;i++){while(!st.empty()&&nums[st.top()]>=nums[i])st.pop();if(!st.empty())res[i]=nums[st.top()];st.push(i);}
        return res;
    }
};
