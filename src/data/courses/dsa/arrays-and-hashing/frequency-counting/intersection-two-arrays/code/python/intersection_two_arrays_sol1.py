class Solution:
    def intersect(self, a, b):
        a.sort(); b.sort()
        result, i, j = [], 0, 0
        while i < len(a) and j < len(b):
            if a[i] == b[j]: result.append(a[i]); i+=1; j+=1
            elif a[i] < b[j]: i += 1
            else: j += 1
        return result