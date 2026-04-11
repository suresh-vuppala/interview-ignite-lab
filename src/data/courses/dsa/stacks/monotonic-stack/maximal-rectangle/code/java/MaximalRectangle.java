// ============================================================
// Maximal Rectangle
// ============================================================

import java.util.*;

class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0) return 0;
        int C = matrix[0].length, max = 0;
        int[] h = new int[C];
        for (char[] row : matrix) {
            for (int j = 0; j < C; j++) h[j] = row[j]=='1' ? h[j]+1 : 0;
            max = Math.max(max, largestRect(h));
        }
        return max;
    }
    private int largestRect(int[] h) {
        Deque<Integer> st = new ArrayDeque<>(); st.push(-1); int max = 0;
        for (int i = 0; i <= h.length; i++) {
            int cur = i==h.length ? 0 : h[i];
            while (st.peek()!=-1 && cur<=h[st.peek()]) { int ht=h[st.pop()]; max=Math.max(max,ht*(i-st.peek()-1)); }
            st.push(i);
        }
        return max;
    }
}
