#include <string>
#include <stack>
using namespace std;

class DecodeString {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string current = "";
        int k = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0'); // Build multi-digit number
            } else if (c == '[') {
                countStack.push(k);
                stringStack.push(current);
                current = "";
                k = 0;
            } else if (c == ']') {
                int count = countStack.top(); countStack.pop();
                string prev = stringStack.top(); stringStack.pop();
                string temp = "";
                for (int i = 0; i < count; i++) temp += current;
                current = prev + temp;
            } else {
                current += c;
            }
        }
        
        return current;
    }
};
