int findCelebrity(vector<vector<int>>& mat, int n) {
    stack<int> st;
    for (int i = 0; i < n; i++) st.push(i);
    while (st.size() > 1) {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();
        if (mat[a][b] == 1) st.push(b);
        else st.push(a);
    }
    int cand = st.top(); st.pop();
    for (int i = 0; i < n; i++) {
        if (i != cand && (mat[cand][i] == 1 || mat[i][cand] == 0)) return -1;
    }
    return cand;
}