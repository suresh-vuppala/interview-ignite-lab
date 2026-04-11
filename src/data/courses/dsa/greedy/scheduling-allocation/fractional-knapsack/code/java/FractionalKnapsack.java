class Solution {
    public double fractionalKnapsack(int W, int[][] items) {
        Arrays.sort(items, (a,b) -> Double.compare((double)b[0]/b[1], (double)a[0]/a[1]));
        double total = 0;
        for (int[] item : items) {
            if (W >= item[1]) { total += item[0]; W -= item[1]; }
            else { total += item[0] * ((double)W / item[1]); break; }
        }
        return total;
    }
}