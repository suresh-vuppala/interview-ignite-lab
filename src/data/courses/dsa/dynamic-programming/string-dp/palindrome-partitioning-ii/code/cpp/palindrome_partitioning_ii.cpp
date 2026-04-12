#include <string>
#include <vector>
using namespace std;
class Solution{public:int minCut(string s){int n=s.size();vector<vector<bool>>pal(n,vector<bool>(n,false));for(int i=n-1;i>=0;i--)for(int j=i;j<n;j++)pal[i][j]=(s[i]==s[j])&&(j-i<3||pal[i+1][j-1]);vector<int>dp(n,n);for(int i=0;i<n;i++){if(pal[0][i])dp[i]=0;else for(int j=1;j<=i;j++)if(pal[j][i])dp[i]=min(dp[i],dp[j-1]+1);}return dp[n-1];}};