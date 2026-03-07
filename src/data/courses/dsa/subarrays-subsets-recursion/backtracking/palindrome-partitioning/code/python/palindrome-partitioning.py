# Time: O(N × 2^N), Space: O(N)

def partition(s):
    result = []
    
    def is_palindrome(left, right):
        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1
        return True
    
    def backtrack(index, current):
        if index == len(s):
            result.append(current[:])
            return
        
        for end in range(index, len(s)):
            if is_palindrome(index, end):
                current.append(s[index:end+1])
                backtrack(end + 1, current)
                current.pop()
    
    backtrack(0, [])
    return result

s = "aab"
print(partition(s))
