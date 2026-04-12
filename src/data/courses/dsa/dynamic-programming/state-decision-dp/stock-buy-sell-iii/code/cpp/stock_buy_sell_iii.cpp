#include <vector>
#include <algorithm>
using namespace std;
class Solution{public:int maxProfit(vector<int>&p){int buy1=INT_MAX,buy2=INT_MAX,profit1=0,profit2=0;for(int x:p){buy1=min(buy1,x);profit1=max(profit1,x-buy1);buy2=min(buy2,x-profit1);profit2=max(profit2,x-buy2);}return profit2;}};