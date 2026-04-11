class Solution:
    def backspaceCompare(self, s, t):
        def build(string):
            result = []
            for c in string:
                if c == '#': result and result.pop()
                else: result.append(c)
            return result
        return build(s) == build(t)