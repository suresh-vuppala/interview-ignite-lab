def remove_k_digits(num, k):
    st = []
    for c in num:
        while st and k > 0 and st[-1] > c:
            st.pop()
            k -= 1
        st.append(c)
    while k > 0:
        st.pop()
        k -= 1
    res = ''.join(st).lstrip('0')
    return res if res else '0'