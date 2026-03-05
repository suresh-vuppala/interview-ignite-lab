class Solution:
    def countPrefixSuffixPairs(self, words):
        count = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if self.is_prefix_and_suffix(words[i], words[j]):
                    count += 1
        return count
    
    def is_prefix_and_suffix(self, str1, str2):
        if len(str1) > len(str2):
            return False
        return str2.startswith(str1) and str2.endswith(str1)
