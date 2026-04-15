#include <vector>
using namespace std;
// ============================================================
// Solution 1: Divide by every number from 2 to N — O(N)
// ============================================================
class Solution1 {
public:
    vector<pair<int,int>> primeFactors(int n) {
        vector<pair<int,int>> factors;
        for (int i = 2; i <= n; i++) {
            int count = 0;
            while (n % i == 0) { count++; n /= i; }
            if (count > 0) factors.push_back({i, count});
        }
        return factors;
    }
};

// ============================================================
// Solution 2: Divide up to √N, handle remaining prime — O(√N)
// ============================================================
class Solution2 {
public:
    vector<pair<int,int>> primeFactors(int n) {
        vector<pair<int,int>> factors;
        for (int i = 2; (long long)i * i <= n; i++) {
            int count = 0;
            while (n % i == 0) { count++; n /= i; }
            if (count > 0) factors.push_back({i, count});
        }
        if (n > 1) factors.push_back({n, 1}); // Remaining large prime
        return factors; // O(√N) — much faster for large primes
    }
};
