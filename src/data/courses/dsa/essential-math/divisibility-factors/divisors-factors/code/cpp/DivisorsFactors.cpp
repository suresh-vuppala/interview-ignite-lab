#include <vector>
#include <cmath>
using namespace std;
// ============================================================
// Solution 1: Check every number from 1 to N — O(N)
// ============================================================
class Solution1 {
public:
    vector<int> findDivisors(int n) {
        vector<int> divs;
        for (int i = 1; i <= n; i++)
            if (n % i == 0) divs.push_back(i);
        return divs; // O(N) — slow for large N
    }
};

// ============================================================
// Solution 2: Check up to √N, add pairs — O(√N)
// ============================================================
class Solution2 {
public:
    vector<int> findDivisors(int n) {
        vector<int> small, large;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                small.push_back(i);
                if (i != n / i) large.push_back(n / i);
            }
        }
        for (int i = large.size() - 1; i >= 0; i--) small.push_back(large[i]);
        return small; // O(√N) — much faster
    }
    int countDivisors(int n) {
        int count = 0;
        for (int i = 1; i * i <= n; i++)
            if (n % i == 0) count += (i == n / i) ? 1 : 2;
        return count;
    }
};
