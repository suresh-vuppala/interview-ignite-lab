#include <vector>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Brute Force — scan left for each day — O(N²)
// ============================================================
class Solution1 {
public:
    vector<int> stockSpan(vector<int>& prices) {
        int n=prices.size(); vector<int> span(n);
        for(int i=0;i<n;i++){span[i]=1;for(int j=i-1;j>=0&&prices[j]<=prices[i];j--)span[i]++;}
        return span;
    }
};

// ============================================================
// Solution 2: Stack — previous greater element — O(N)
// ============================================================
class Solution2 {
public:
    vector<int> stockSpan(vector<int>& prices) {
        int n=prices.size(); vector<int> span(n); stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&prices[st.top()]<=prices[i])st.pop();
            span[i]=st.empty()?i+1:i-st.top();
            st.push(i);
        }
        return span;
    }
};
