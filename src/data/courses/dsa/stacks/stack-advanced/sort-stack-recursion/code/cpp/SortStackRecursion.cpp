#include <stack>
using namespace std;

class SortStackRecursion {
public:
    void sortStack(stack<int>& st) {
        if (st.empty()) return;
        
        int top = st.top();
        st.pop();
        sortStack(st); // Sort remaining
        insertSorted(st, top); // Insert in sorted position
    }
    
private:
    void insertSorted(stack<int>& st, int element) {
        if (st.empty() || st.top() < element) {
            st.push(element);
            return;
        }
        
        int top = st.top();
        st.pop();
        insertSorted(st, element);
        st.push(top);
    }
};
