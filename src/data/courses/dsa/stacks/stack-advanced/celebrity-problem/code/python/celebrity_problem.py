class CelebrityProblem:
    def findCelebrity(self, M: list[list[int]]) -> int:
        n = len(M)
        stack = []
        
        # Push all people
        for i in range(n):
            stack.append(i)
        
        # Find candidate
        while len(stack) > 1:
            a = stack.pop()
            b = stack.pop()
            if M[a][b] == 1:
                stack.append(b)  # a knows b, so a is not celebrity
            else:
                stack.append(a)  # a doesn't know b, so b is not celebrity
        
        candidate = stack.pop()
        
        # Verify candidate
        for i in range(n):
            if i != candidate:
                if M[candidate][i] == 1 or M[i][candidate] == 0:
                    return -1  # Not a celebrity
        
        return candidate
