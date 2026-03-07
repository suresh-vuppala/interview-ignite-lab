#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class WordLadder {
public:
    
    // ==================== SOLUTION 1: BFS WITH NEIGHBOR GENERATION ====================
    // Time: O(N×L²×26) | Space: O(N×L)
    
    static int ladderLengthBFS(string beginWord, string endWord, vector<string>& wordList) {
        /*
         * Generate all possible one-letter changes for each word.
         * Try all 26 letters at each position.
         */
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({beginWord, 1});
        visited.insert(beginWord);
        
        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();
            
            if (word == endWord) return level;
            
            string nextWord = word;
            for (int i = 0; i < word.length(); i++) {
                char old = nextWord[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    nextWord[i] = c;
                    if (wordSet.find(nextWord) != wordSet.end() && 
                        visited.find(nextWord) == visited.end()) {
                        visited.insert(nextWord);
                        q.push({nextWord, level + 1});
                    }
                }
                nextWord[i] = old;
            }
        }
        return 0;
    }
    
    
    // ==================== SOLUTION 2: BFS WITH PATTERN MATCHING ====================
    // Time: O(N×L²) | Space: O(N×L²)
    
    static int ladderLengthPattern(string beginWord, string endWord, vector<string>& wordList) {
        /*
         * Preprocess words into patterns (e.g., "hot" -> "*ot", "h*t", "ho*").
         * Words sharing a pattern are neighbors.
         */
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        
        unordered_map<string, vector<string>> patternMap;
        for (const string& word : wordList) {
            for (int i = 0; i < word.length(); i++) {
                string pattern = word.substr(0, i) + "*" + word.substr(i + 1);
                patternMap[pattern].push_back(word);
            }
        }
        
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({beginWord, 1});
        visited.insert(beginWord);
        
        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();
            
            if (word == endWord) return level;
            
            for (int i = 0; i < word.length(); i++) {
                string pattern = word.substr(0, i) + "*" + word.substr(i + 1);
                if (patternMap.find(pattern) != patternMap.end()) {
                    for (const string& neighbor : patternMap[pattern]) {
                        if (visited.find(neighbor) == visited.end()) {
                            visited.insert(neighbor);
                            q.push({neighbor, level + 1});
                        }
                    }
                }
            }
        }
        return 0;
    }
    
    
    // ==================== SOLUTION 3: BIDIRECTIONAL BFS (OPTIMAL) ====================
    // Time: O(N×L²) | Space: O(N×L)
    
    static int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*
         * Search from both beginWord and endWord simultaneously.
         * When searches meet, we found the shortest path.
         * Explores exponentially fewer nodes.
         */
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        
        unordered_set<string> beginSet, endSet, visited;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        int level = 1;
        
        while (!beginSet.empty() && !endSet.empty()) {
            // Always expand smaller set
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }
            
            unordered_set<string> nextSet;
            for (const string& word : beginSet) {
                string nextWord = word;
                
                for (int i = 0; i < word.length(); i++) {
                    char old = nextWord[i];
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        nextWord[i] = c;
                        
                        if (endSet.find(nextWord) != endSet.end()) {
                            return level + 1;
                        }
                        
                        if (wordSet.find(nextWord) != wordSet.end() && 
                            visited.find(nextWord) == visited.end()) {
                            visited.insert(nextWord);
                            nextSet.insert(nextWord);
                        }
                    }
                    
                    nextWord[i] = old;
                }
            }
            
            beginSet = nextSet;
            level++;
        }
        
        return 0;
    }
};
