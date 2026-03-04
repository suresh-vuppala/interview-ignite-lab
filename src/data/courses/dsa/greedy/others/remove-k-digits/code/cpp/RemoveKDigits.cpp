class RemoveKDigits {
public:
    string removeKdigits(string num, int k) {
        string stack;
        for (char c : num) {
            while (!stack.empty() && k > 0 && stack.back() > c) {
                stack.pop_back(); // Remove larger digit
                k--;
            }
            stack.push_back(c);
        }
        while (k-- > 0) stack.pop_back(); // Remove remaining k digits
        
        int start = 0;
        while (start < stack.size() && stack[start] == '0') start++; // Remove leading zeros
        string result = stack.substr(start);
        return result.empty() ? "0" : result;
    }
};