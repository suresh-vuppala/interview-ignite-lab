def str_str(text, pattern):
    n, m = len(text), len(pattern)
    for i in range(n-m+1):
        if text[i:i+m] == pattern:
            return i
    return -1