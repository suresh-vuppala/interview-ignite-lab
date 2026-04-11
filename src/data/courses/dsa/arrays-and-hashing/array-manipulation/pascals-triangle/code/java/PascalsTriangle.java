// ============================================================
// Pascal's Triangle
// ============================================================

import java.util.*;

// ============================================================
// Solution: Row-by-Row Construction (Optimal)
// Time: O(N²) | Space: O(1) extra
// ============================================================
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();

        for (int i = 0; i < numRows; i++) {
            List<Integer> row = new ArrayList<>(Collections.nCopies(i + 1, 1));

            // Fill interior elements
            for (int j = 1; j < i; j++) {
                row.set(j, result.get(i - 1).get(j - 1) + result.get(i - 1).get(j));
            }

            result.add(row);
        }

        return result;
    }
}
