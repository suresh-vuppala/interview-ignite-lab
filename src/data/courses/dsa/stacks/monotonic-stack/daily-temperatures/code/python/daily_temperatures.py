def daily_temperatures(temps):
    n = len(temps)
    res = [0] * n
    st = []
    for i in range(n):
        while st and temps[st[-1]] < temps[i]:
            idx = st.pop()
            res[idx] = i - idx
        st.append(i)
    return res