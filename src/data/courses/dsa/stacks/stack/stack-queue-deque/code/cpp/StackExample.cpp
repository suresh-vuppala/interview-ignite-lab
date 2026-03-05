#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    
    st.push(5);
    st.push(10);
    st.push(15);
    
    cout << "Popped: " << st.top() << endl; // 15
    st.pop();
    cout << "Top: " << st.top() << endl;    // 10
    cout << "Size: " << st.size() << endl;  // 2
    cout << "Empty: " << st.empty() << endl; // 0 (false)
    
    return 0;
}
