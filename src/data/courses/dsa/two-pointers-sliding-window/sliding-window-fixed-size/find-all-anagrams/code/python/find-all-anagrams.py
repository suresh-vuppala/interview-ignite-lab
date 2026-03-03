def find_anagrams(s, p):
    if len(s) < len(p):
        return []
    res = []
    p_count = [0] * 26
    s_count = [0] * 26
    for c in p:
        p_count[ord(c) - ord('a')] += 1
    for i in range(len(s)):
        s_count[ord(s[i]) - ord('a')] += 1
        if i >= len(p):
            s_count[ord(s[i - len(p)]) - ord('a')] -= 1
        if i >= len(p) - 1 and p_count == s_count:
            res.append(i - len(p) + 1)
    return res