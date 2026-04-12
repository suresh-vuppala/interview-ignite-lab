// ============================================================
// Word Ladder II
// ============================================================
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return {};

        // BFS to build parent map
        unordered_map<string, vector<string>> parents;
        unordered_set<string> currentLevel, nextLevel;
        currentLevel.insert(beginWord);
        bool found = false;

        while (!currentLevel.empty() && !found) {
            // Remove current level words from set to prevent revisiting
            for (auto& w : currentLevel) wordSet.erase(w);
            nextLevel.clear();

            for (auto& word : currentLevel) {
                string temp = word;
                for (int j = 0; j < temp.size(); j++) {
                    char orig = temp[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[j] = c;
                        if (temp == endWord) found = true;
                        if (wordSet.count(temp) || temp == endWord) {
                            nextLevel.insert(temp);
                            parents[temp].push_back(word);
                        }
                    }
                    temp[j] = orig;
                }
            }
            currentLevel = nextLevel;
        }

        // DFS backtrack from endWord
        vector<vector<string>> result;
        vector<string> path = {endWord};
        dfs(endWord, beginWord, parents, path, result);
        return result;
    }

    void dfs(string& word, string& begin, unordered_map<string, vector<string>>& parents,
             vector<string>& path, vector<vector<string>>& result) {
        if (word == begin) {
            result.push_back(vector<string>(path.rbegin(), path.rend()));
            return;
        }
        for (auto& p : parents[word]) {
            path.push_back(p);
            dfs(p, begin, parents, path, result);
            path.pop_back();
        }
    }
};
