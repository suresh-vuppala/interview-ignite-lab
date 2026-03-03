def partition(s):
    result = []
    
    def is_palindrome(left, right):
        while left < right:
            if s[left] != s[right]:
                return False
            left, right = left+1, right-1
        return True
    
    def backtrack(start, curr):
        if start == len(s):
            result.append(curr[:])
            return
        for end in range(start, len(s)):
            if is_palindrome(start, end):
                curr.append(s[start:end+1])
                backtrack(end+1, curr)
                curr.pop()
    
    backtrack(0, [])
    return result