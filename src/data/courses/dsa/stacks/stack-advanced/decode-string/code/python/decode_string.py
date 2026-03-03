def decode_string(s):
    num_st = []
    str_st = []
    curr = ""
    num = 0
    for c in s:
        if c.isdigit():
            num = num * 10 + int(c)
        elif c == '[':
            num_st.append(num)
            str_st.append(curr)
            num = 0
            curr = ""
        elif c == ']':
            k = num_st.pop()
            prev = str_st.pop()
            curr = prev + curr * k
        else:
            curr += c
    return curr