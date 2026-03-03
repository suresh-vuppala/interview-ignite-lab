def stock_span(prices):
    n = len(prices)
    res = [0] * n
    st = []
    for i in range(n):
        while st and prices[st[-1]] <= prices[i]:
            st.pop()
        res[i] = i + 1 if not st else i - st[-1]
        st.append(i)
    return res