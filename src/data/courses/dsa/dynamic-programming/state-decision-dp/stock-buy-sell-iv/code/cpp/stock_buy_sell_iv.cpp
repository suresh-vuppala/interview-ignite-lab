#include <vector>
#include <algorithm>
using namespace std;
class Solution{public:int maxProfit(int k,vector<int>&p){int n=p.size();if(k>=n/2){int s=0;for(int i=1;i<n;i++)s+=max(0,p[i]-p[i-1]);return s;}
vector<int>buy(k+1,INT_MAX),profit(k+1,0);for(int x:p)for(int i=1;i<=k;i++){buy[i]=min(buy[i],x-profit[i-1]);profit[i]=max(profit[i],x-buy[i]);}return profit[k];}};