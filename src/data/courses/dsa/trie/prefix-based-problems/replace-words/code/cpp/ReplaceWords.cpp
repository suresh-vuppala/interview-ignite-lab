// ============================================================
// Solution 1: HashSet — Check all prefixes of each word
// Time: O(W × L²) | Space: O(D × L)
// ============================================================
#include <vector>
#include <string>
#include <unordered_set>
#include <sstream>
using namespace std;

class Solution1 {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_set<string> roots(dict.begin(), dict.end());
        istringstream iss(sentence);
        string word, result;
        while (iss >> word) {
            string replacement = word;
            for (int i = 1; i <= (int)word.size(); i++) {
                if (roots.count(word.substr(0, i))) { // O(L) per check
                    replacement = word.substr(0, i);
                    break;
                }
            }
            if (!result.empty()) result += " ";
            result += replacement;
        }
        return result;
    }
};

// ============================================================
// Solution 2: Trie — O(L) prefix match per word
// Time: O(N × L) | Space: O(D × L)
// ============================================================
class Solution2 {
    struct TrieNode { TrieNode* ch[26] = {}; bool isEnd = false; };
    TrieNode* root = new TrieNode();
    
    void insert(string& s) {
        TrieNode* n = root;
        for (char c : s) {
            if (!n->ch[c-'a']) n->ch[c-'a'] = new TrieNode();
            n = n->ch[c-'a'];
        }
        n->isEnd = true;
    }
    
    string findRoot(string& word) {
        TrieNode* n = root;
        for (int i = 0; i < (int)word.size(); i++) {
            if (!n->ch[word[i]-'a']) break;
            n = n->ch[word[i]-'a'];
            if (n->isEnd) return word.substr(0, i+1); // Shortest root found!
        }
        return word;
    }
public:
    string replaceWords(vector<string>& dict, string sentence) {
        for (auto& d : dict) insert(d);
        istringstream iss(sentence);
        string word, result;
        while (iss >> word) {
            if (!result.empty()) result += " ";
            result += findRoot(word);
        }
        return result;
    }
};
