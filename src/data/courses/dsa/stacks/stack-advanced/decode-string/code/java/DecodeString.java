String decodeString(String s) {
    Stack<Integer> numSt = new Stack<>();
    Stack<String> strSt = new Stack<>();
    String curr = "";
    int num = 0;
    for (char c : s.toCharArray()) {
        if (Character.isDigit(c)) num = num * 10 + (c - '0');
        else if (c == '[') {
            numSt.push(num);
            strSt.push(curr);
            num = 0;
            curr = "";
        } else if (c == ']') {
            int k = numSt.pop();
            String prev = strSt.pop();
            curr = prev + curr.repeat(k);
        } else curr += c;
    }
    return curr;
}