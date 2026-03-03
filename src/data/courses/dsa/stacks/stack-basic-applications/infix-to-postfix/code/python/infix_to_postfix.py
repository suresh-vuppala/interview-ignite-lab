def prec(c):
    if c in '+-':
        return 1
    if c in '*/':
        return 2
    return 0

def infix_to_postfix(s):
    st = []
    res = ""
    for c in s:
        if c.isalnum():
            res += c
        elif c == '(':
            st.append(c)
        elif c == ')':
            while st and st[-1] != '(':
                res += st.pop()
            st.pop()
        else:
            while st and prec(st[-1]) >= prec(c):
                res += st.pop()
            st.append(c)
    while st:
        res += st.pop()
    return res