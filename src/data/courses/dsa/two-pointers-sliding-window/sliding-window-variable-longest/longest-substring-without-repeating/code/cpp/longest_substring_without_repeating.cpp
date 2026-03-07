class LongestSubstringWithoutRepeating {
public:
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(N³) | Space: O(min(N, M))
    int lengthOfLongestSubstringBruteForce(string s) {
        int n = s.length();
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (allUnique(s, i, j)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }
    
private:
    bool allUnique(const string& s, int start, int end) {
        unordered_set<char> charSet;
        for (int i = start; i <= end; i++) {
            if (charSet.count(s[i])) {
                return false;
            }
            charSet.insert(s[i]);
        }
        return true;
    }
    
public:
    // ==================== SOLUTION 2: BRUTE FORCE OPTIMIZED ====================
    // Time: O(N²) | Space: O(min(N, M))
    int lengthOfLongestSubstringBruteOptimized(string s) {
        int n = s.length();
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_set<char> charSet;
            for (int j = i; j < n; j++) {
                if (charSet.count(s[j])) {
                    break;
                }
                charSet.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
            }
        }
        
        return maxLen;
    }
    
    // ==================== SOLUTION 3: SLIDING WINDOW (TWO POINTERS) ====================
    // Time: O(2N) = O(N) | Space: O(min(N, M))
    int lengthOfLongestSubstringSlidingWindow(string s) {
        int n = s.length();
        unordered_set<char> charSet;
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < n; right++) {
            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
    
    // ==================== SOLUTION 4: SLIDING WINDOW WITH HASHMAP ====================
    // Time: O(N) | Space: O(min(N, M))
    int lengthOfLongestSubstringHashMap(string s) {
        int n = s.length();
        unordered_map<char, int> charMap;
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < n; right++) {
            if (charMap.count(s[right])) {
                left = max(left, charMap[s[right]] + 1);
            }
            charMap[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
    
    // ==================== SOLUTION 5: OPTIMIZED WITH ARRAY (ASCII) - OPTIMAL ====================
    // Time: O(N) | Space: O(1)
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(128, -1);
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            if (charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1;
            }
            charIndex[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
