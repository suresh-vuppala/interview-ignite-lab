class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        int top=0, bot=matrix.length-1, left=0, right=matrix[0].length-1;
        while (top<=bot && left<=right) {
            for (int j=left;j<=right;j++) res.add(matrix[top][j]); top++;
            for (int i=top;i<=bot;i++) res.add(matrix[i][right]); right--;
            if (top<=bot) { for (int j=right;j>=left;j--) res.add(matrix[bot][j]); bot--; }
            if (left<=right) { for (int i=bot;i>=top;i--) res.add(matrix[i][left]); left++; }
        }
        return res;
    }
}