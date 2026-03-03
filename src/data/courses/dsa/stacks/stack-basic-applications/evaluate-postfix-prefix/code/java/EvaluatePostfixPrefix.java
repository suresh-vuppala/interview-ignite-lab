int evalPostfix(String s) {
    Stack<Integer> st = new Stack<>();
    for (String token : s.split(" ")) {
        if (token.matches("-?\\d+")) st.push(Integer.parseInt(token));
        else {
            int b = st.pop(), a = st.pop();
            if (token.equals("+")) st.push(a + b);
            else if (token.equals("-")) st.push(a - b);
            else if (token.equals("*")) st.push(a * b);
            else st.push(a / b);
        }
    }
    return st.pop();
}