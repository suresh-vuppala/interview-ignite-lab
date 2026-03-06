#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^n) | Space: O(n)
    int tilingRecursive(int n) {
        return solveFull(n);
    }
    
private:
    int solveFull(int i) {
        if (i == 0) return 1;
        if (i == 1) return 1;
        if (i < 0) return 0;
        return solveFull(i-1) + solveFull(i-2) + 2 * solvePartial(i-1);
    }
    
    int solvePartial(int i) {
        if (i == 0) return 0;
        if (i == 1) return 1;
        if (i < 0) return 0;
        return solveFull(i-2) + solvePartial(i-1);
    }
    
public:
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(n) | Space: O(n)
    int tilingMemo(int n) {
        unordered_map<int, int> memoFull, memoPartial;
        return solveFull(n, memoFull, memoPartial);
    }
    
private:
    int solveFull(int i, unordered_map<int, int>& memoFull, unordered_map<int, int>& memoPartial) {
        if (i == 0) return 1;
        if (i == 1) return 1;
        if (i < 0) return 0;
        if (memoFull.count(i)) return memoFull[i];
        memoFull[i] = solveFull(i-1, memoFull, memoPartial) + solveFull(i-2, memoFull, memoPartial) 
                      + 2 * solvePartial(i-1, memoFull, memoPartial);
        return memoFull[i];
    }
    
    int solvePartial(int i, unordered_map<int, int>& memoFull, unordered_map<int, int>& memoPartial) {
        if (i == 0) return 0;
        if (i == 1) return 1;
        if (i < 0) return 0;
        if (memoPartial.count(i)) return memoPartial[i];
        memoPartial[i] = solveFull(i-2, memoFull, memoPartial) + solvePartial(i-1, memoFull, memoPartial);
        return memoPartial[i];
    }
    
public:
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(n) | Space: O(n)
    int tilingTab(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        
        vector<int> full(n + 1), partial(n + 1);
        full[0] = 1; full[1] = 1;
        partial[0] = 0; partial[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            full[i] = full[i-1] + full[i-2] + 2 * partial[i-1];
            partial[i] = full[i-2] + partial[i-1];
        }
        
        return full[n];
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    // Time: O(n) | Space: O(1)
    int numTilings(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        
        int full_prev2 = 1, full_prev1 = 1;
        int partial_prev2 = 0, partial_prev1 = 1;
        
        for (int i = 2; i <= n; i++) {
            int full_curr = full_prev1 + full_prev2 + 2 * partial_prev1;
            int partial_curr = full_prev2 + partial_prev1;
            full_prev2 = full_prev1;
            full_prev1 = full_curr;
            partial_prev2 = partial_prev1;
            partial_prev1 = partial_curr;
        }
        
        return full_prev1;
    }
};
