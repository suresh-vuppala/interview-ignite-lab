#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
// ============================================================
// Solution 1: BFS — try all single-char changes — O(N * L * 26)
// ============================================================
class Solution1 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        dict.erase(beginWord);
        while (!q.empty()) {
            auto [word, steps] = q.front(); q.pop();
            if (word == endWord) return steps;
            for (int i = 0; i < (int)word.size(); i++) {
                char orig = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (dict.count(word)) {
                        dict.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = orig;
            }
        }
        return 0;
    }
};

// ============================================================
// Solution 2: Bidirectional BFS — O(N * L * 26) but ~half the states
// ============================================================
class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        unordered_set<string> front = {beginWord}, back = {endWord};
        dict.erase(beginWord); dict.erase(endWord);
        int steps = 1;
        while (!front.empty() && !back.empty()) {
            if (front.size() > back.size()) swap(front, back);
            unordered_set<string> next;
            for (string word : front) {
                for (int i = 0; i < (int)word.size(); i++) {
                    char orig = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if (back.count(word)) return steps + 1;
                        if (dict.count(word)) { dict.erase(word); next.insert(word); }
                    }
                    word[i] = orig;
                }
            }
            front = next; steps++;
        }
        return 0;
    }
};
