def letter_combinations(digits):
    if not digits:
        return []
    
    mapping = {"2": "abc", "3": "def", "4": "ghi", "5": "jkl",
               "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}
    result = []
    
    def backtrack(i, curr):
        if i == len(digits):
            result.append(curr)
            return
        for c in mapping[digits[i]]:
            backtrack(i+1, curr+c)
    
    backtrack(0, "")
    return result