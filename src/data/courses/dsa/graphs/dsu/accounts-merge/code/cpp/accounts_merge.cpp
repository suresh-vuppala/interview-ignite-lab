// ============================================================
// Accounts Merge
// ============================================================
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
    unordered_map<int,int> p, r;
    int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
    void unite(int x,int y){int a=find(x),b=find(y);if(a==b)return;if(r[a]<r[b])swap(a,b);p[b]=a;if(r[a]==r[b])r[a]++;}
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> emailId;
        unordered_map<string,string> emailName;
        int id = 0;
        for (auto& acc : accounts) {
            for (int i = 1; i < acc.size(); i++) {
                if (!emailId.count(acc[i])) { emailId[acc[i]] = id; p[id] = id; r[id] = 0; id++; }
                emailName[acc[i]] = acc[0];
                if (i > 1) unite(emailId[acc[1]], emailId[acc[i]]);
            }
        }
        map<int, vector<string>> groups;
        for (auto& [email, eid] : emailId)
            groups[find(eid)].push_back(email);
        vector<vector<string>> result;
        for (auto& [root, emails] : groups) {
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), emailName[emails[0]]);
            result.push_back(emails);
        }
        return result;
    }
};
