#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: DFS on email graph — O(N*K*log(NK))
// ============================================================
class Solution1 {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<int>> emailToAccts;
        for(int i=0;i<(int)accounts.size();i++)
            for(int j=1;j<(int)accounts[i].size();j++)
                emailToAccts[accounts[i][j]].push_back(i);
        vector<bool> vis(accounts.size(),false);
        vector<vector<string>> result;
        for(int i=0;i<(int)accounts.size();i++){
            if(vis[i])continue;
            set<string> emails;
            // DFS to find all connected accounts
            vector<int> stack={i};
            while(!stack.empty()){
                int idx=stack.back();stack.pop_back();if(vis[idx])continue;vis[idx]=true;
                for(int j=1;j<(int)accounts[idx].size();j++){
                    emails.insert(accounts[idx][j]);
                    for(int k:emailToAccts[accounts[idx][j]])if(!vis[k])stack.push_back(k);
                }
            }
            vector<string> merged={accounts[i][0]};
            merged.insert(merged.end(),emails.begin(),emails.end());
            result.push_back(merged);
        }
        return result;
    }
};

// ============================================================
// Solution 2: Union-Find on emails — O(N*K*α(NK))
// ============================================================
class Solution2 {
    unordered_map<string,string> par;
    string find(string x){return par[x]==x?x:par[x]=find(par[x]);}
    void unite(string a,string b){par[find(a)]=find(b);}
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string> emailToName;
        for(auto&acc:accounts)for(int i=1;i<(int)acc.size();i++){par[acc[i]]=acc[i];emailToName[acc[i]]=acc[0];}
        for(auto&acc:accounts)for(int i=2;i<(int)acc.size();i++)unite(acc[1],acc[i]);
        unordered_map<string,set<string>> groups;
        for(auto&[email,_]:par) groups[find(email)].insert(email);
        vector<vector<string>> result;
        for(auto&[root,emails]:groups){
            vector<string> merged={emailToName[root]};
            merged.insert(merged.end(),emails.begin(),emails.end());
            result.push_back(merged);
        }
        return result;
    }
};
