class Solution {
    public int maxArea(int[] h) {
        int max = 0;
        for (int i = 0; i < h.length; i++)
            for (int j = i+1; j < h.length; j++)
                max = Math.max(max, Math.min(h[i],h[j])*(j-i));
        return max;
    }
}