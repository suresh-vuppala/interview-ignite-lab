string removeKdigits(string num, int k) {
    stack<char> st;
    for (char c : num) {
        while (!st.empty() && k > 0 && st.top() > c) {
            st.pop();
            k--;
        }
        st.push(c);
    }
    while (k-- > 0) st.pop();
    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    int i = 0;
    while (i < res.size() - 1 && res[i] == '0') i++;
    return res.substr(i);
}