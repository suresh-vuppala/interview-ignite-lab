# ============================================================
# Celebrity Problem
# ============================================================

# def knows(a, b) -> bool — provided

class Solution:
    def findCelebrity(self, n: int) -> int:
        stack = list(range(n))

        # Eliminate: each comparison removes one
        while len(stack) > 1:
            a, b = stack.pop(), stack.pop()
            if knows(a, b):
                stack.append(b)  # A knows B → A not celeb
            else:
                stack.append(a)  # A doesn't know B → B not celeb

        # Verify candidate
        candidate = stack[0]
        for i in range(n):
            if i == candidate: continue
            if knows(candidate, i) or not knows(i, candidate):
                return -1
        return candidate
