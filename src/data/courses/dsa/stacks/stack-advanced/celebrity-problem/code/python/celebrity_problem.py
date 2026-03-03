def find_celebrity(mat, n):
    st = list(range(n))
    while len(st) > 1:
        a = st.pop()
        b = st.pop()
        if mat[a][b] == 1:
            st.append(b)
        else:
            st.append(a)
    cand = st.pop()
    for i in range(n):
        if i != cand and (mat[cand][i] == 1 or mat[i][cand] == 0):
            return -1
    return cand