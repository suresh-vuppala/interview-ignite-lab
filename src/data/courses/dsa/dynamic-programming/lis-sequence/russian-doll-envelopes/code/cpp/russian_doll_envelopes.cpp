#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — O(N²) LIS on sorted envelopes
// ============================================================
class Solution1 {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),[](auto& a, auto& b){ return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]); });
        int n=env.size();
        vector<int> dp(n,1);
        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)
                if(env[j][1]<env[i][1]) dp[i]=max(dp[i],dp[j]+1);
        return *max_element(dp.begin(),dp.end());
    }
};

// ============================================================
// Solution 2: Sort + patience sort on height — O(N log N)
// ============================================================
class Solution2 {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),[](auto& a, auto& b){ return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]); });
        vector<int> tails;
        for(auto& e:env) {
            auto it=lower_bound(tails.begin(),tails.end(),e[1]);
            if(it==tails.end()) tails.push_back(e[1]);
            else *it=e[1];
        }
        return tails.size();
    }
};
