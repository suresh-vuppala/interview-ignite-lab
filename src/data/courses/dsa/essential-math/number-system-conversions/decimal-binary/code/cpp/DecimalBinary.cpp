#include <string>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Repeated division — build string — O(log N)
// ============================================================
class Solution1 {
public:
    string decimalToBinary(int n) {
        if (n == 0) return "0";
        string result;
        while (n > 0) { result += (n % 2) + '0'; n /= 2; }
        reverse(result.begin(), result.end());
        return result;
    }
    int binaryToDecimal(string s) {
        int result = 0;
        for (char c : s) result = result * 2 + (c - '0');
        return result;
    }
};

// ============================================================
// Solution 2: Bitwise operations — O(log N)
// ============================================================
class Solution2 {
public:
    string decimalToBinary(int n) {
        if (n == 0) return "0";
        string result;
        while (n > 0) { result += (n & 1) + '0'; n >>= 1; } // Bit shift
        reverse(result.begin(), result.end());
        return result;
    }
    int binaryToDecimal(string s) {
        int result = 0;
        for (char c : s) result = (result << 1) | (c - '0'); // Shift + OR
        return result;
    }
};
