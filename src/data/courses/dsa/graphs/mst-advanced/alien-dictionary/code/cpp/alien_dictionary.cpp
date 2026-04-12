// ============================================================
// Alien Dictionary
// ============================================================
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        // Build adjacency list and in-degree for characters
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDeg;

        // Initialize all characters
        for (auto& w : words) for (char c : w) { adj[c]; inDeg[c]; }

        // Compare adjacent words
        for (int i = 0; i < (int)words.size() - 1; i++) {
            string& w1 = words[i], &w2 = words[i+1];
            int minLen = min(w1.size(), w2.size());

            // Prefix check: "abc" before "ab" is invalid
            if (w1.size() > w2.size() && w1.substr(0, minLen) == w2.substr(0, minLen))
                return "";

            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    if (!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        inDeg[w2[j]]++;
                    }
                    break; // Only first difference matters
                }
            }
        }

        // Kahn's topological sort
        queue<char> q;
        for (auto& [c, d] : inDeg) if (d == 0) q.push(c);
        string result;
        while (!q.empty()) {
            char c = q.front(); q.pop();
            result += c;
            for (char nb : adj[c])
                if (--inDeg[nb] == 0) q.push(nb);
        }

        return result.size() == inDeg.size() ? result : ""; // Cycle check
    }
};
