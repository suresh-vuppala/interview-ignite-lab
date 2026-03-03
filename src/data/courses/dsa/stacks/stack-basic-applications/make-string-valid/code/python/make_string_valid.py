def min_remove(s):
    st = []
    remove = 0
    for c in s:
        if c == '(':
            st.append(c)
        elif c == ')':
            if st:
                st.pop()
            else:
                remove += 1
    return remove + len(st)