#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class WordLadderII {
public:
    // ==================== SOLUTION 1: BFS + DFS (TWO-PASS) ====================
    // Time: O(N×L² + P×L) | Space: O(N×L + P×L)
    
    static vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        /*
         * Phase 1: BFS to build parent relationships.
         * Phase 2: DFS to backtrack and construct all paths.
         */
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        
        if (wordSet.find(endWord) == wordSet.end()) return result;
        
        // BFS Phase: Build parent relationships
        unordered_map<string, vector<string>> parents;
        unordered_map<string, int> level;
        queue<string> q;
        
        q.push(beginWord);
        level[beginWord] = 0;
        bool found = false;
        int currentLevel = 0;
        
        while (!q.empty() && !found) {
            int size = q.size();
            currentLevel++;
            unordered_set<string> visitedThisLevel;
            
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();
                
                for (int j = 0; j < word.length(); j++) {
                    char old = word[j];
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;
                        
                        if (wordSet.find(word) != wordSet.end()) {
                            if (level.find(word) == level.end()) {
                                visitedThisLevel.insert(word);
                                parents[word].push_back(q.front());
                                
                                if (word == endWord) {
                                    found = true;
                                }
                            } else if (level[word] == currentLevel) {
                                parents[word].push_back(q.front());
                            }
                        }
                    }
                    
                    word[j] = old;
                }
            }
            
            for (const string& word : visitedThisLevel) {
                level[word] = currentLevel;
                q.push(word);
            }
        }
        
        // DFS Phase: Construct paths
        if (found) {
            vector<string> path = {endWord};
            dfs(endWord, beginWord, parents, path, result);
        }
        
        return result;
    }
    
private:
    static void dfs(const string& word, const string& beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path, vector<vector<string>>& result) {
        if (word == beginWord) {
            vector<string> newPath = path;
            reverse(newPath.begin(), newPath.end());
            result.push_back(newPath);
            return;
        }
        
        if (parents.find(word) != parents.end()) {
            for (const string& parent : parents[word]) {
                path.push_back(parent);
                dfs(parent, beginWord, parents, path, result);
                path.pop_back();
            }
        }
    }
};
