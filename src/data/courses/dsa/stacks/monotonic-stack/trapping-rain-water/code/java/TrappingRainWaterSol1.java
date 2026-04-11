class Solution {
    public int trap(int[] h) {
        int water = 0;
        for (int i = 1; i < h.length-1; i++) {
            int maxL = 0, maxR = 0;
            for (int j = 0; j <= i; j++) maxL = Math.max(maxL, h[j]);
            for (int j = i; j < h.length; j++) maxR = Math.max(maxR, h[j]);
            water += Math.min(maxL, maxR) - h[i];
        }
        return water;
    }
}