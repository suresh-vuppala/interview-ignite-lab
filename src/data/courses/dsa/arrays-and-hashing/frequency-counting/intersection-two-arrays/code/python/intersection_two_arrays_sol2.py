class Solution:
    def intersect(self, a, b):
        from collections import Counter
        return list((Counter(a) & Counter(b)).elements())