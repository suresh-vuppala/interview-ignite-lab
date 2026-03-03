def next_greater(arr):
    n = len(arr)
    res = [0] * n
    st = []
    for i in range(n - 1, -1, -1):
        while st and st[-1] <= arr[i]:
            st.pop()
        res[i] = -1 if not st else st[-1]
        st.append(arr[i])
    return res