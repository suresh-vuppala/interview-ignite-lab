#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — expand from each bar — O(N²)
// ============================================================
class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(), maxArea=0;
        for(int i=0;i<n;i++){
            int minH=heights[i];
            for(int j=i;j<n;j++){minH=min(minH,heights[j]);maxArea=max(maxArea,minH*(j-i+1));}
        }
        return maxArea;
    }
};

// ============================================================
// Solution 2: Monotonic stack — next/prev smaller — O(N)
// ============================================================
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(), maxArea=0; stack<int> st;
        for(int i=0;i<=n;i++){
            int h = (i==n) ? 0 : heights[i];
            while(!st.empty()&&heights[st.top()]>h){
                int height=heights[st.top()]; st.pop();
                int width=st.empty()?i:i-st.top()-1;
                maxArea=max(maxArea,height*width);
            }
            st.push(i);
        }
        return maxArea;
    }
};
