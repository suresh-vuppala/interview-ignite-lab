# ============================================================
# Word Ladder II
# ============================================================
from collections import defaultdict
class Solution:
    def findLadders(self, beginWord, endWord, wordList):
        word_set = set(wordList)
        if endWord not in word_set: return []
        parents = defaultdict(list)
        current = {beginWord}; found = False
        while current and not found:
            word_set -= current
            nxt = set()
            for word in current:
                for j in range(len(word)):
                    for c in 'abcdefghijklmnopqrstuvwxyz':
                        s = word[:j] + c + word[j+1:]
                        if s == endWord: found = True
                        if s in word_set or s == endWord:
                            nxt.add(s); parents[s].append(word)
            current = nxt
        result = []
        def dfs(word, path):
            if word == beginWord: result.append(path[::-1]); return
            for p in parents[word]: dfs(p, path + [p])
        dfs(endWord, [endWord])
        return result
