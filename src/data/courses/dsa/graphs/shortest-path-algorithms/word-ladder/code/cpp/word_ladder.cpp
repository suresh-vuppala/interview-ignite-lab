// ============================================================
// Word Ladder
// ============================================================
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        int steps = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string word = q.front(); q.pop();

                // Try all one-letter variants
                for (int j = 0; j < word.size(); j++) {
                    char original = word[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;
                        if (word == endWord) return steps + 1;
                        if (wordSet.count(word)) {
                            wordSet.erase(word); // Mark visited
                            q.push(word);
                        }
                    }
                    word[j] = original; // Restore
                }
            }
            steps++;
        }

        return 0; // No transformation possible
    }
};
