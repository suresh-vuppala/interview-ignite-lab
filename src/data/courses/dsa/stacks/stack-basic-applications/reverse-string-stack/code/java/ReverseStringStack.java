String reverse(String s) {
    Stack<Character> st = new Stack<>();
    for (char c : s.toCharArray()) st.push(c);
    StringBuilder res = new StringBuilder();
    while (!st.isEmpty()) res.append(st.pop());
    return res.toString();
}