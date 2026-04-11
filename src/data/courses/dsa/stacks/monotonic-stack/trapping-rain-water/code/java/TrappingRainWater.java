// ============================================================
// Trapping Rain Water
// ============================================================

// ============================================================
// Solution 1: Brute Force — Per-Position Scan
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
    public int trap(int[] h) {
        int water = 0;
        for (int i = 1; i < h.length - 1; i++) {
            int maxL = 0, maxR = 0;
            for (int j = 0; j <= i; j++) maxL = Math.max(maxL, h[j]);
            for (int j = i; j < h.length; j++) maxR = Math.max(maxR, h[j]);
            water += Math.min(maxL, maxR) - h[i];
        }
        return water;
    }
}

// ============================================================
// Solution 2: Prefix Max Arrays
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
    public int trap(int[] h) {
        int n = h.length;
        int[] lm = new int[n], rm = new int[n];
        lm[0] = h[0];
        for (int i = 1; i < n; i++) lm[i] = Math.max(lm[i-1], h[i]);
        rm[n-1] = h[n-1];
        for (int i = n-2; i >= 0; i--) rm[i] = Math.max(rm[i+1], h[i]);
        int water = 0;
        for (int i = 0; i < n; i++) water += Math.min(lm[i], rm[i]) - h[i];
        return water;
    }
}

// ============================================================
// Solution 3: Two Pointers (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution3 {
    public int trap(int[] h) {
        int left = 0, right = h.length - 1;
        int maxL = 0, maxR = 0, water = 0;

        while (left < right) {
            if (h[left] < h[right]) {
                if (h[left] >= maxL) maxL = h[left];
                else water += maxL - h[left];
                left++;
            } else {
                if (h[right] >= maxR) maxR = h[right];
                else water += maxR - h[right];
                right--;
            }
        }

        return water;
    }
}
