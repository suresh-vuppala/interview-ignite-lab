def reverse(s):
    st = []
    for c in s:
        st.append(c)
    res = ""
    while st:
        res += st.pop()
    return res