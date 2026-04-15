#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — iterate from min downward — O(min(a,b))
// ============================================================
class Solution1 {
public:
    int gcd(int a, int b) {
        int res = 1;
        for (int i = min(a, b); i >= 1; i--)
            if (a % i == 0 && b % i == 0) return i;
        return 1;
    }
    long long lcm(int a, int b) { return (long long)a / gcd(a, b) * b; }
};

// ============================================================
// Solution 2: Euclidean Algorithm — O(log(min(a,b)))
// ============================================================
class Solution2 {
public:
    int gcd(int a, int b) {
        while (b) { int t = b; b = a % b; a = t; }
        return a;
    }
    long long lcm(int a, int b) { return (long long)a / gcd(a, b) * b; } // Divide first to avoid overflow
};
