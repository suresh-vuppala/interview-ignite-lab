def remove_outer(s):
    res = ""
    depth = 0
    for c in s:
        if c == '(':
            if depth > 0:
                res += c
            depth += 1
        else:
            depth -= 1
            if depth > 0:
                res += c
    return res