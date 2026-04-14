#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
// ============================================================
// Solution 1: BFS to find distance + DFS to collect all shortest paths
// ============================================================
class Solution1 {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};
        // BFS to build parent map (all shortest-path parents)
        unordered_map<string, int> dist;
        unordered_map<string, vector<string>> parents;
        queue<string> q; q.push(beginWord); dist[beginWord] = 0;
        while (!q.empty()) {
            string word = q.front(); q.pop();
            for (int i = 0; i < (int)word.size(); i++) {
                string next = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    next[i] = c;
                    if (!dict.count(next)) continue;
                    if (!dist.count(next)) { dist[next] = dist[word] + 1; q.push(next); parents[next].push_back(word); }
                    else if (dist[next] == dist[word] + 1) parents[next].push_back(word);
                }
            }
        }
        if (!dist.count(endWord)) return {};
        // DFS backtrack from endWord to beginWord
        vector<vector<string>> result; vector<string> path = {endWord};
        function<void(string&)> dfs = [&](string& word) {
            if (word == beginWord) { vector<string> p(path.rbegin(), path.rend()); result.push_back(p); return; }
            for (string& par : parents[word]) { path.push_back(par); dfs(par); path.pop_back(); }
        };
        string end = endWord; dfs(end);
        return result;
    }
};

// ============================================================
// Solution 2: BFS level-by-level with path tracking (same complexity)
// ============================================================
class Solution2 {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};
        vector<vector<string>> result;
        queue<vector<string>> q; q.push({beginWord});
        unordered_set<string> visited, levelVisited;
        bool found = false;
        while (!q.empty() && !found) {
            int sz = q.size();
            levelVisited.clear();
            while (sz--) {
                vector<string> path = q.front(); q.pop();
                string word = path.back();
                for (int i = 0; i < (int)word.size(); i++) {
                    char orig = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if (word == endWord) { path.push_back(word); result.push_back(path); path.pop_back(); found = true; }
                        else if (dict.count(word) && !visited.count(word)) { levelVisited.insert(word); path.push_back(word); q.push(path); path.pop_back(); }
                    }
                    word[i] = orig;
                }
            }
            for (auto& w : levelVisited) visited.insert(w);
        }
        return result;
    }
};
