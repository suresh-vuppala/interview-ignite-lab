#include <vector>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Brute Force — for each element scan right — O(N²)
// ============================================================
class Solution1 {
public:
    vector<int> nextGreaterElement(vector<int>& nums) {
        int n=nums.size(); vector<int> res(n,-1);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(nums[j]>nums[i]){res[i]=nums[j];break;}
        return res;
    }
};

// ============================================================
// Solution 2: Monotonic stack — O(N) Time, O(N) Space
// ============================================================
class Solution2 {
public:
    vector<int> nextGreaterElement(vector<int>& nums) {
        int n=nums.size(); vector<int> res(n,-1); stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]<nums[i]){res[st.top()]=nums[i];st.pop();}
            st.push(i);
        }
        return res;
    }
};
