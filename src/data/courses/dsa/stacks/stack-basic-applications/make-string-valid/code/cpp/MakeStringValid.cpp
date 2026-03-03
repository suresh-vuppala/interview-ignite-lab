int minRemove(string s) {
    stack<char> st;
    int remove = 0;
    for (char c : s) {
        if (c == '(') st.push(c);
        else if (c == ')') {
            if (!st.empty()) st.pop();
            else remove++;
        }
    }
    return remove + st.size();
}