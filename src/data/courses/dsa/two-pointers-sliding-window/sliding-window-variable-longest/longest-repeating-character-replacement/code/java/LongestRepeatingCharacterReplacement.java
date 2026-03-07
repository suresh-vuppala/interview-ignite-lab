import java.util.*;

// Time: O(N³), Space: O(1)
class LongestRepeatingCharacterReplacement {
    public int characterReplacementBruteForce(String s, int k) {
        int n = s.length(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int[] freq = new int[26];
                int maxFreq = 0;
                for (int p = i; p <= j; p++) {
                    freq[s.charAt(p) - 'A']++;
                    maxFreq = Math.max(maxFreq, freq[s.charAt(p) - 'A']);
                }
                if ((j - i + 1) - maxFreq <= k) maxLen = Math.max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N² × 26), Space: O(26)
    public int characterReplacementBruteOptimized(String s, int k) {
        int n = s.length(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            int[] freq = new int[26];
            int maxFreq = 0;
            for (int j = i; j < n; j++) {
                freq[s.charAt(j) - 'A']++;
                maxFreq = Math.max(maxFreq, freq[s.charAt(j) - 'A']);
                if ((j - i + 1) - maxFreq <= k) maxLen = Math.max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N × 26), Space: O(26)
    public int characterReplacementSlidingWindowRecalc(String s, int k) {
        int left = 0, maxLen = 0;
        int[] freq = new int[26];
        for (int right = 0; right < s.length(); right++) {
            freq[s.charAt(right) - 'A']++;
            int maxFreq = 0;
            for (int f : freq) maxFreq = Math.max(maxFreq, f);
            while ((right - left + 1) - maxFreq > k) {
                freq[s.charAt(left) - 'A']--;
                left++;
                maxFreq = 0;
                for (int f : freq) maxFreq = Math.max(maxFreq, f);
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N), Space: O(26)
    public int characterReplacementSlidingWindow(String s, int k) {
        int left = 0, maxLen = 0, maxFreq = 0;
        int[] freq = new int[26];
        for (int right = 0; right < s.length(); right++) {
            freq[s.charAt(right) - 'A']++;
            maxFreq = Math.max(maxFreq, freq[s.charAt(right) - 'A']);
            while ((right - left + 1) - maxFreq > k) {
                freq[s.charAt(left) - 'A']--;
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N), Space: O(26)
    public int characterReplacementSlidingWindowOptimized(String s, int k) {
        int left = 0, maxLen = 0, maxFreq = 0;
        int[] freq = new int[26];
        for (int right = 0; right < s.length(); right++) {
            maxFreq = Math.max(maxFreq, ++freq[s.charAt(right) - 'A']);
            if ((right - left + 1) - maxFreq > k) freq[s.charAt(left++) - 'A']--;
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }
}
