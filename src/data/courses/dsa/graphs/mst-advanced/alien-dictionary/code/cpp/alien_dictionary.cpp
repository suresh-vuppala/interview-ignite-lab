class Solution {
public:
    // O(C) where C = total chars — Topological sort from word ordering
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        for (auto& w : words) for (char c : w) indegree[c] = 0;
        
        for (int i = 0; i < words.size()-1; i++) {
            string& w1 = words[i], &w2 = words[i+1];
            int len = min(w1.size(), w2.size());
            if (w1.size() > w2.size() && w1.substr(0,len) == w2.substr(0,len)) return "";
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    if (!adj[w1[j]].count(w2[j])) { adj[w1[j]].insert(w2[j]); indegree[w2[j]]++; }
                    break;
                }
            }
        }
        
        queue<char> q;
        for (auto& [c, deg] : indegree) if (deg == 0) q.push(c);
        string result;
        while (!q.empty()) {
            char c = q.front(); q.pop(); result += c;
            for (char nb : adj[c]) if (--indegree[nb] == 0) q.push(nb);
        }
        return result.size() == indegree.size() ? result : "";
    }
};