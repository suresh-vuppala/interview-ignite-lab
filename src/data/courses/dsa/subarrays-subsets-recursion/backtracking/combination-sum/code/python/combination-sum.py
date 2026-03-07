# Time: O(N^(T/M)), Space: O(T/M)

def combination_sum(candidates, target):
    result = []
    
    def backtrack(index, current, total):
        if total == target:
            result.append(current[:])
            return
        if total > target:
            return
        
        for i in range(index, len(candidates)):
            current.append(candidates[i])
            backtrack(i, current, total + candidates[i])
            current.pop()
    
    backtrack(0, [], 0)
    return result

candidates = [2, 3, 6, 7]
target = 7
print(combination_sum(candidates, target))
