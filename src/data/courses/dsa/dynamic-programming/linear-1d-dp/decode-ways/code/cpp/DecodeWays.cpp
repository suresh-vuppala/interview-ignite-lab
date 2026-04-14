#include <string>
#include <vector>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^N) Time
// ============================================================
class Solution1 {
public:
    int solve(string& s, int i) {
        if(i==(int)s.size()) return 1;
        if(s[i]=='0') return 0;
        int res = solve(s,i+1);
        if(i+1<(int)s.size() && (s[i]=='1' || (s[i]=='2'&&s[i+1]<='6')))
            res += solve(s,i+2);
        return res;
    }
    int numDecodings(string s) { return solve(s,0); }
};

// ============================================================
// Solution 2: DP — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int numDecodings(string s) {
        int n=s.size();
        int prev2=1, prev1=s[0]!='0';
        for(int i=2;i<=n;i++) {
            int curr=0;
            if(s[i-1]!='0') curr=prev1;
            int two=(s[i-2]-'0')*10+(s[i-1]-'0');
            if(two>=10&&two<=26) curr+=prev2;
            prev2=prev1; prev1=curr;
        }
        return prev1;
    }
};
