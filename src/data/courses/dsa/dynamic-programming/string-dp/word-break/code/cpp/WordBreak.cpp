#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
// ============================================================
// Solution 1: Recursion — try all splits — O(2^N)
// ============================================================
class Solution1 {
public:
    bool solve(string& s, unordered_set<string>& dict, int start) {
        if(start==(int)s.size()) return true;
        for(int end=start+1;end<=(int)s.size();end++)
            if(dict.count(s.substr(start,end-start)) && solve(s,dict,end)) return true;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        return solve(s,dict,0);
    }
};

// ============================================================
// Solution 2: DP — Bottom-up — O(N² * L) Time, O(N) Space
// ============================================================
class Solution2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<bool> dp(n+1,false); dp[0]=true;
        for(int i=1;i<=n;i++)
            for(int j=0;j<i;j++)
                if(dp[j]&&dict.count(s.substr(j,i-j))) { dp[i]=true; break; }
        return dp[n];
    }
};
