def insert(st, x):
    if not st or st[-1] <= x:
        st.append(x)
        return
    top = st.pop()
    insert(st, x)
    st.append(top)

def sort_stack(st):
    if not st:
        return
    top = st.pop()
    sort_stack(st)
    insert(st, top)