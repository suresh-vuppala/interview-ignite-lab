#include <vector>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Brute Force — scan right for warmer day — O(N²)
// ============================================================
class Solution1 {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n=temps.size(); vector<int> res(n,0);
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(temps[j]>temps[i]){res[i]=j-i;break;}
        return res;
    }
};

// ============================================================
// Solution 2: Monotonic decreasing stack — O(N) Time
// ============================================================
class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n=temps.size(); vector<int> res(n,0); stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&temps[st.top()]<temps[i]){res[st.top()]=i-st.top();st.pop();}
            st.push(i);
        }
        return res;
    }
};
