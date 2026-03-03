def combination_sum2(candidates, target):
    result = []
    candidates.sort()
    
    def backtrack(start, curr, total):
        if total == 0:
            result.append(curr[:])
            return
        if total < 0:
            return
        for i in range(start, len(candidates)):
            if i > start and candidates[i] == candidates[i-1]:
                continue
            curr.append(candidates[i])
            backtrack(i+1, curr, total-candidates[i])
            curr.pop()
    
    backtrack(0, [], target)
    return result