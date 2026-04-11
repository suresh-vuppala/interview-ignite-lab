// ============================================================
// Celebrity Problem
// ============================================================

#include <stack>
#include <vector>
using namespace std;

// Assume knows(a, b) is provided
bool knows(int a, int b);

class Solution1 {
public:
    int findCelebrity(int n) {
        for (int i = 0; i < n; i++) {
            bool isCeleb = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (knows(i, j) || !knows(j, i)) { isCeleb = false; break; }
            }
            if (isCeleb) return i;
        }
        return -1;
    }
};

class Solution2 {
public:
    int findCelebrity(int n) {
        stack<int> st;
        for (int i = 0; i < n; i++) st.push(i);

        // Eliminate: each comparison removes one person
        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            if (knows(a, b)) st.push(b); // A knows B → A not celebrity
            else st.push(a);             // A doesn't know B → B not celebrity
        }

        // Verify the candidate
        int candidate = st.top();
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;
            if (knows(candidate, i) || !knows(i, candidate)) return -1;
        }
        return candidate;
    }
};
