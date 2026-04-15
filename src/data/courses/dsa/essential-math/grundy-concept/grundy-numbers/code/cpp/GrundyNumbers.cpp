#include <vector>
#include <unordered_set>
using namespace std;
// ============================================================
// Solution 1: Recursive Grundy with memoization — O(N * moves)
// ============================================================
class Solution1 {
    vector<int> memo;
    int grundy(int n, vector<int>& moves) {
        if (n == 0) return 0;
        if (memo[n] != -1) return memo[n];
        unordered_set<int> reachable;
        for (int m : moves)
            if (n >= m) reachable.insert(grundy(n - m, moves));
        int mex = 0;
        while (reachable.count(mex)) mex++; // Minimum excludant
        return memo[n] = mex;
    }
public:
    int computeGrundy(int n, vector<int>& moves) {
        memo.assign(n + 1, -1);
        return grundy(n, moves);
    }
};

// ============================================================
// Solution 2: Bottom-up Grundy table — O(N * moves)
// ============================================================
class Solution2 {
public:
    int computeGrundy(int n, vector<int>& moves) {
        vector<int> grundy(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            unordered_set<int> reachable;
            for (int m : moves)
                if (i >= m) reachable.insert(grundy[i - m]);
            int mex = 0;
            while (reachable.count(mex)) mex++;
            grundy[i] = mex;
        }
        return grundy[n];
    }
    // For combined games: XOR all Grundy values
    bool firstPlayerWins(vector<int>& piles, vector<int>& moves) {
        int xorSum = 0;
        for (int pile : piles) xorSum ^= computeGrundy(pile, moves);
        return xorSum != 0; // Non-zero XOR → first player wins
    }
};
