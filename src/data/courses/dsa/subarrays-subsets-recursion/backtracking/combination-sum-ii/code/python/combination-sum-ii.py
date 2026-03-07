# Time: O(2^N), Space: O(N)

def combination_sum2(candidates, target):
    result = []
    candidates.sort()
    
    def backtrack(index, current, total):
        if total == target:
            result.append(current[:])
            return
        if total > target:
            return
        
        for i in range(index, len(candidates)):
            if i > index and candidates[i] == candidates[i-1]:
                continue
            
            current.append(candidates[i])
            backtrack(i + 1, current, total + candidates[i])
            current.pop()
    
    backtrack(0, [], 0)
    return result

candidates = [10, 1, 2, 7, 6, 1, 5]
target = 8
print(combination_sum2(candidates, target))
