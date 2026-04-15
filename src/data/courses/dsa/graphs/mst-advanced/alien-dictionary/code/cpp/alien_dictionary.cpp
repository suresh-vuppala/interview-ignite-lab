#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
// ============================================================
// Solution 1: DFS topological sort on character graph — O(C)
// ============================================================
class Solution1 {
    unordered_map<char,unordered_set<char>>adj;
    unordered_map<char,int>color;string result;bool hasCycle=false;
    void dfs(char u){color[u]=1;for(char v:adj[u]){if(color[v]==1){hasCycle=true;return;}if(color[v]==0)dfs(v);if(hasCycle)return;}
        color[u]=2;result+=u;}
public:
    string alienOrder(vector<string>&words){
        for(auto&w:words)for(char c:w){adj[c];color[c]=0;}
        for(int i=0;i<(int)words.size()-1;i++){
            string&a=words[i],&b=words[i+1];
            if(a.size()>b.size()&&a.substr(0,b.size())==b)return"";
            for(int j=0;j<min(a.size(),b.size());j++)if(a[j]!=b[j]){adj[a[j]].insert(b[j]);break;}
        }
        for(auto&[c,_]:adj)if(color[c]==0)dfs(c);
        if(hasCycle)return"";
        reverse(result.begin(),result.end());return result;
    }
};

// ============================================================
// Solution 2: Kahn's BFS — O(C) where C = total chars
// ============================================================
class Solution2 {
public:
    string alienOrder(vector<string>&words){
        unordered_map<char,int>inDeg;unordered_map<char,unordered_set<char>>adj;
        for(auto&w:words)for(char c:w){inDeg[c];adj[c];}
        for(int i=0;i<(int)words.size()-1;i++){
            string&a=words[i],&b=words[i+1];
            if(a.size()>b.size()&&a.substr(0,b.size())==b)return"";
            for(int j=0;j<min(a.size(),b.size());j++)if(a[j]!=b[j]){if(!adj[a[j]].count(b[j])){adj[a[j]].insert(b[j]);inDeg[b[j]]++;}break;}
        }
        queue<char>q;for(auto&[c,d]:inDeg)if(d==0)q.push(c);
        string result;while(!q.empty()){char c=q.front();q.pop();result+=c;for(char v:adj[c])if(--inDeg[v]==0)q.push(v);}
        return result.size()==inDeg.size()?result:"";
    }
};
