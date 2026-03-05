#include <vector>
#include <stack>
using namespace std;

class PreviousGreaterSmaller {
public:
    vector<int> previousGreater(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        
        return result;
    }
    
    vector<int> previousSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() >= nums[i]) {
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        
        return result;
    }
};
