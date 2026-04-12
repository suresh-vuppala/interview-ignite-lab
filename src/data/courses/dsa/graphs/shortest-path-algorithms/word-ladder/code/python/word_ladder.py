# ============================================================
# Word Ladder
# ============================================================
from collections import deque
class Solution:
    def ladderLength(self, beginWord, endWord, wordList) -> int:
        word_set = set(wordList)
        if endWord not in word_set: return 0
        queue = deque([beginWord])
        steps = 1
        while queue:
            steps += 1
            for _ in range(len(queue)):
                word = list(queue.popleft())
                for j in range(len(word)):
                    orig = word[j]
                    for c in 'abcdefghijklmnopqrstuvwxyz':
                        word[j] = c
                        s = ''.join(word)
                        if s == endWord: return steps
                        if s in word_set:
                            word_set.remove(s)
                            queue.append(s)
                    word[j] = orig
        return 0
