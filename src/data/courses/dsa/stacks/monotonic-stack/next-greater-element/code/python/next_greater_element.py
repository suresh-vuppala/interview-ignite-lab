def next_greater_element(arr):
    n = len(arr)
    result = [0] * n
    stack = []
    
    for i in range(n - 1, -1, -1):
        while stack and stack[-1] <= arr[i]:
            stack.pop()
        result[i] = -1 if not stack else stack[-1]
        stack.append(arr[i])
    
    return result
