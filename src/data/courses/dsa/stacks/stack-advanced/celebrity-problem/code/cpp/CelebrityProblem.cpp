#include <vector>
#include <stack>
using namespace std;

class CelebrityProblem {
public:
    int findCelebrity(vector<vector<int>>& M) {
        int n = M.size();
        stack<int> st;
        
        // Push all people
        for (int i = 0; i < n; i++) {
            st.push(i);
        }
        
        // Find candidate
        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            if (M[a][b] == 1) {
                st.push(b); // a knows b, so a is not celebrity
            } else {
                st.push(a); // a doesn't know b, so b is not celebrity
            }
        }
        
        int candidate = st.top();
        
        // Verify candidate
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                if (M[candidate][i] == 1 || M[i][candidate] == 0) {
                    return -1; // Not a celebrity
                }
            }
        }
        
        return candidate;
    }
};
