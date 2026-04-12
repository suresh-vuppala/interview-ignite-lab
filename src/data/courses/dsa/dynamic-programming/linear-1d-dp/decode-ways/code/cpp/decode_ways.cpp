class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int prev2 = 1, prev1 = 1; // dp[-1]=1, dp[0]=1
        for (int i = 1; i < s.size(); i++) {
            int curr = 0;
            if (s[i] != '0') curr += prev1; // Single digit valid
            int two = stoi(s.substr(i-1, 2));
            if (two >= 10 && two <= 26) curr += prev2; // Two digits valid
            prev2 = prev1; prev1 = curr;
        }
        return prev1;
    }
};
