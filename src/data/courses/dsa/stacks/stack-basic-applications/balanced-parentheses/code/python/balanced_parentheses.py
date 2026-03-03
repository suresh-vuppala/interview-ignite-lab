def is_valid(s):
    st = []
    for c in s:
        if c in '({[':
            st.append(c)
        else:
            if not st:
                return False
            top = st.pop()
            if c == ')' and top != '(':
                return False
            if c == '}' and top != '{':
                return False
            if c == ']' and top != '[':
                return False
    return len(st) == 0