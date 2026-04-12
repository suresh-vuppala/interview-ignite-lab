#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),[](auto&a,auto&b){return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];});
        vector<int> tails;
        for(auto&e:env){
            auto it=lower_bound(tails.begin(),tails.end(),e[1]);
            if(it==tails.end()) tails.push_back(e[1]);
            else *it=e[1];
        }
        return tails.size();
    }
};
