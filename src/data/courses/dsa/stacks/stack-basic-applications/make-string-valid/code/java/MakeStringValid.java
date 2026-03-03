int minRemove(String s) {
    Stack<Integer> st = new Stack<>();
    int remove = 0;
    for (char c : s.toCharArray()) {
        if (c == '(') st.push(c);
        else if (c == ')') {
            if (!st.isEmpty()) st.pop();
            else remove++;
        }
    }
    return remove + st.size();
}