#include <vector>
#include <stack>
using namespace std;

class NextGreaterElementII {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;
        
        // Traverse twice for circular array
        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;
            while (!st.empty() && nums[st.top()] < nums[idx]) {
                result[st.top()] = nums[idx];
                st.pop();
            }
            if (i < n) st.push(idx); // Push only in first pass
        }
        
        return result;
    }
};
