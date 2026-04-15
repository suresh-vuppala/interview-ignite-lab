using namespace std;
// ============================================================
// Solution 1: Simulation / Recursion — O(N) or O(2^N) with memoization
// ============================================================
class Solution1 {
public:
    // Recursive game simulation
    bool canWin(int n) {
        if (n <= 0) return false; // Losing position (previous player took last)
        // Try taking 1, 2, or 3 stones — if ANY move leaves opponent in losing position
        for (int take = 1; take <= 3 && take <= n; take++)
            if (!canWin(n - take)) return true; // Opponent loses!
        return false; // All moves leave opponent winning
    }
};

// ============================================================
// Solution 2: Math — O(1)
// ============================================================
class Solution2 {
public:
    bool canWin(int n) {
        return n % 4 != 0; // If divisible by 4, first player ALWAYS loses
        // Why: whatever you take (1-3), opponent takes (3-1) to keep total=4
    }
};
