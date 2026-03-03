def combination_sum(candidates, target):
    result = []
    
    def backtrack(start, curr, total):
        if total == 0:
            result.append(curr[:])
            return
        if total < 0:
            return
        for i in range(start, len(candidates)):
            curr.append(candidates[i])
            backtrack(i, curr, total-candidates[i])
            curr.pop()
    
    backtrack(0, [], target)
    return result