#include <string>
using namespace std;

class MakeStringValid {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        
        for (char c : s) {
            if (c == '(') {
                open++;
            } else {
                if (open > 0) open--; // Match with opening
                else close++; // Unmatched closing
            }
        }
        
        return open + close; // Total additions needed
    }
};
