class Solution {
public:
    // O(n * α(n)) — Union-Find: merge accounts sharing emails
    vector<int> parent, rank_;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (rank_[a] < rank_[b]) swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b]) rank_[a]++;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n); rank_.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
        
        unordered_map<string, int> emailToId; // email -> first account id
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (emailToId.count(accounts[i][j]))
                    unite(i, emailToId[accounts[i][j]]);
                else
                    emailToId[accounts[i][j]] = i;
            }
        }
        
        // Group emails by root account
        unordered_map<int, set<string>> groups;
        for (auto& [email, id] : emailToId)
            groups[find(id)].insert(email);
        
        vector<vector<string>> result;
        for (auto& [id, emails] : groups) {
            vector<string> merged = {accounts[id][0]}; // Name
            merged.insert(merged.end(), emails.begin(), emails.end());
            result.push_back(merged);
        }
        return result;
    }
};