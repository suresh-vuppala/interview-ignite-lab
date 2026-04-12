#include <vector>
#include <algorithm>
using namespace std;
class Solution{public:int maxProfit(vector<int>&p,int fee){int cash=0,hold=-p[0];for(int i=1;i<p.size();i++){cash=max(cash,hold+p[i]-fee);hold=max(hold,cash-p[i]);}return cash;}};