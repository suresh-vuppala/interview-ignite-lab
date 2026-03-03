String infixToPostfix(String s) {
    Stack<Character> st = new Stack<>();
    StringBuilder res = new StringBuilder();
    for (char c : s.toCharArray()) {
        if (Character.isLetterOrDigit(c)) res.append(c);
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') res.append(st.pop());
            st.pop();
        } else {
            while (!st.isEmpty() && prec(st.peek()) >= prec(c)) res.append(st.pop());
            st.push(c);
        }
    }
    while (!st.isEmpty()) res.append(st.pop());
    return res.toString();
}
int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}