#include <vector>
#include <algorithm>
using namespace std;
class Solution{public:int maxProfit(vector<int>&p){int n=p.size();if(n<2)return 0;int sold=0,held=INT_MIN,rest=0;for(int x:p){int prevSold=sold;sold=held+x;held=max(held,rest-x);rest=max(rest,prevSold);}return max(sold,rest);}};