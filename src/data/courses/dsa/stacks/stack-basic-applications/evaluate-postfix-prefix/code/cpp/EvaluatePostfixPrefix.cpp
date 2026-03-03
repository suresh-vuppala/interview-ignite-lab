int evalPostfix(string s) {
    stack<int> st;
    stringstream ss(s);
    string token;
    while (ss >> token) {
        if (isdigit(token[0]) || (token.size() > 1)) st.push(stoi(token));
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else st.push(a / b);
        }
    }
    return st.top();
}