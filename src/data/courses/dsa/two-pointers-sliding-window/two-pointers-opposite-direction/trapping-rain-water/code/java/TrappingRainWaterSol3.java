class Solution {
    public int trap(int[] h) {
        int l=0, r=h.length-1, ml=0, mr=0, w=0;
        while (l < r) {
            if (h[l] < h[r]) { if (h[l]>=ml) ml=h[l]; else w+=ml-h[l]; l++; }
            else { if (h[r]>=mr) mr=h[r]; else w+=mr-h[r]; r--; }
        }
        return w;
    }
}