// ============================================================
// Next Smaller Element
// ============================================================

#include <vector>
#include <stack>
using namespace std;

class Solution1 {
public:
    vector<int> nextSmaller(vector<int>& nums) {
        int n = nums.size(); vector<int> result(n, -1);
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (nums[j] < nums[i]) { result[i] = nums[j]; break; }
        return result;
    }
};

class Solution2 {
public:
    vector<int> nextSmaller(vector<int>& nums) {
        int n = nums.size(); vector<int> result(n, -1);
        stack<int> st; // Increasing stack

        for (int i = 0; i < n; i++) {
            // Pop elements LARGER than incoming — incoming is their NSE
            while (!st.empty() && nums[i] < nums[st.top()]) {
                result[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
