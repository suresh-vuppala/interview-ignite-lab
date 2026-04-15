#include <vector>
using namespace std;
// ============================================================
// Solution 1: Naive Fibonacci — overlapping subproblems — O(2^N)
// ============================================================
class Solution1 {
public:
    int fib(int n) {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
        // Recursion tree: exponential nodes, many repeated calls
        // fib(5) calls fib(3) twice, fib(2) three times, etc.
    }
};

// ============================================================
// Solution 2: Memoized Fibonacci — prune repeated branches — O(N)
// ============================================================
class Solution2 {
    vector<int> memo;
    int solve(int n) {
        if (n <= 1) return n;
        if (memo[n] != -1) return memo[n];
        return memo[n] = solve(n - 1) + solve(n - 2);
        // Same tree structure but each node computed only once
    }
public:
    int fib(int n) { memo.assign(n + 1, -1); return solve(n); }
};
