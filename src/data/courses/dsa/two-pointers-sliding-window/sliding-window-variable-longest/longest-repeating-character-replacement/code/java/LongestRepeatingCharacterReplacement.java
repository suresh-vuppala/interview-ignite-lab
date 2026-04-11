// ============================================================
// Longest Repeating Character Replacement
// ============================================================

// ============================================================
// Solution 1: Brute Force
// Time: O(N²×26) | Space: O(1)
// ============================================================
class Solution1 {
    public int characterReplacement(String s, int k) {
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            int[] f = new int[26]; int mf = 0;
            for (int j = i; j < s.length(); j++) {
                f[s.charAt(j)-'A']++;
                mf = Math.max(mf, f[s.charAt(j)-'A']);
                if (j-i+1-mf <= k) max = Math.max(max, j-i+1);
                else break;
            }
        }
        return max;
    }
}

// ============================================================
// Solution 2: Sliding Window + Max Frequency (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public int characterReplacement(String s, int k) {
        int[] freq = new int[26];
        int left = 0, maxFreq = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            freq[s.charAt(right)-'A']++;
            maxFreq = Math.max(maxFreq, freq[s.charAt(right)-'A']);

            if (right - left + 1 - maxFreq > k) {
                freq[s.charAt(left)-'A']--;
                left++;
            }

            maxLen = Math.max(maxLen, right - left + 1);
        }

        return maxLen;
    }
}
