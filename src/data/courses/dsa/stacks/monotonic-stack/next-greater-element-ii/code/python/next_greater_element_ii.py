def next_greater_circular(arr):
    n = len(arr)
    res = [0] * n
    st = []
    for i in range(2 * n - 1, -1, -1):
        while st and st[-1] <= arr[i % n]:
            st.pop()
        if i < n:
            res[i] = -1 if not st else st[-1]
        st.append(arr[i % n])
    return res