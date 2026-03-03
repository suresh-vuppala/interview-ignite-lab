def eval_postfix(s):
    st = []
    for token in s.split():
        if token.lstrip('-').isdigit():
            st.append(int(token))
        else:
            b = st.pop()
            a = st.pop()
            if token == '+':
                st.append(a + b)
            elif token == '-':
                st.append(a - b)
            elif token == '*':
                st.append(a * b)
            else:
                st.append(a // b)
    return st.pop()