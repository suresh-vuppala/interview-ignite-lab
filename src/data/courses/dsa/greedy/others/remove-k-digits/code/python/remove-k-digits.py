def remove_k_digits(num, k):
    stack = []
    for c in num:
        while stack and k > 0 and stack[-1] > c:
            stack.pop()  # Remove larger digit
            k -= 1
        stack.append(c)
    while k > 0:
        stack.pop()  # Remove remaining k digits
        k -= 1
    result = ''.join(stack).lstrip('0')  # Remove leading zeros
    return result if result else '0'