def generate_subsequences(arr):
    result = []
    
    def generate(i, curr):
        if i == len(arr):
            result.append(curr[:])
            return
        generate(i+1, curr)
        curr.append(arr[i])
        generate(i+1, curr)
        curr.pop()
    
    generate(0, [])
    return result