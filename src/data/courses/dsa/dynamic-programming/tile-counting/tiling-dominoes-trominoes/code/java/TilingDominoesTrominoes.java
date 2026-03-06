import java.util.HashMap;
import java.util.Map;

class Solution {
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^n) | Space: O(n)
    public int tilingRecursive(int n) {
        return solveFull(n);
    }
    
    private int solveFull(int i) {
        if (i == 0) return 1;
        if (i == 1) return 1;
        if (i < 0) return 0;
        return solveFull(i-1) + solveFull(i-2) + 2 * solvePartial(i-1);
    }
    
    private int solvePartial(int i) {
        if (i == 0) return 0;
        if (i == 1) return 1;
        if (i < 0) return 0;
        return solveFull(i-2) + solvePartial(i-1);
    }
    
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(n) | Space: O(n)
    public int tilingMemo(int n) {
        Map<Integer, Integer> memoFull = new HashMap<>();
        Map<Integer, Integer> memoPartial = new HashMap<>();
        return solveFull(n, memoFull, memoPartial);
    }
    
    private int solveFull(int i, Map<Integer, Integer> memoFull, Map<Integer, Integer> memoPartial) {
        if (i == 0) return 1;
        if (i == 1) return 1;
        if (i < 0) return 0;
        if (memoFull.containsKey(i)) return memoFull.get(i);
        int result = solveFull(i-1, memoFull, memoPartial) + solveFull(i-2, memoFull, memoPartial) 
                     + 2 * solvePartial(i-1, memoFull, memoPartial);
        memoFull.put(i, result);
        return result;
    }
    
    private int solvePartial(int i, Map<Integer, Integer> memoFull, Map<Integer, Integer> memoPartial) {
        if (i == 0) return 0;
        if (i == 1) return 1;
        if (i < 0) return 0;
        if (memoPartial.containsKey(i)) return memoPartial.get(i);
        int result = solveFull(i-2, memoFull, memoPartial) + solvePartial(i-1, memoFull, memoPartial);
        memoPartial.put(i, result);
        return result;
    }
    
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(n) | Space: O(n)
    public int tilingTab(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        
        int[] full = new int[n + 1];
        int[] partial = new int[n + 1];
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
    public int numTilings(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        
        int fullPrev2 = 1, fullPrev1 = 1;
        int partialPrev2 = 0, partialPrev1 = 1;
        
        for (int i = 2; i <= n; i++) {
            int fullCurr = fullPrev1 + fullPrev2 + 2 * partialPrev1;
            int partialCurr = fullPrev2 + partialPrev1;
            fullPrev2 = fullPrev1;
            fullPrev1 = fullCurr;
            partialPrev2 = partialPrev1;
            partialPrev1 = partialCurr;
        }
        
        return fullPrev1;
    }
}
