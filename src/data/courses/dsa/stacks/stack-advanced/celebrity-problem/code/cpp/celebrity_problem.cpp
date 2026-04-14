#include <vector>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Brute Force — check each person — O(N²)
// ============================================================
class Solution1 {
public:
    int findCelebrity(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            bool isCeleb=true;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(matrix[i][j]==1||matrix[j][i]==0){isCeleb=false;break;}
            }
            if(isCeleb) return i;
        }
        return -1;
    }
};

// ============================================================
// Solution 2: Stack — eliminate candidates — O(N) Time
// ============================================================
class Solution2 {
public:
    int findCelebrity(vector<vector<int>>& matrix) {
        int n=matrix.size();
        stack<int> st; for(int i=0;i<n;i++)st.push(i);
        // Eliminate: if A knows B → A is not celebrity, else B is not
        while(st.size()>1){int a=st.top();st.pop();int b=st.top();st.pop();
            if(matrix[a][b])st.push(b);else st.push(a);}
        int cand=st.top();
        // Verify candidate
        for(int i=0;i<n;i++){if(i==cand)continue;if(matrix[cand][i]==1||matrix[i][cand]==0)return -1;}
        return cand;
    }
};
