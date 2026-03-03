def largest_rectangle(heights):
    st = []
    max_area = 0
    n = len(heights)
    for i in range(n):
        while st and heights[st[-1]] > heights[i]:
            h = heights[st.pop()]
            w = i if not st else i - st[-1] - 1
            max_area = max(max_area, h * w)
        st.append(i)
    while st:
        h = heights[st.pop()]
        w = n if not st else n - st[-1] - 1
        max_area = max(max_area, h * w)
    return max_area