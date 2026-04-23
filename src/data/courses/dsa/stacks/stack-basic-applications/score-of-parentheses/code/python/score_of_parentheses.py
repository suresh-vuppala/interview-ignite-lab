# ============================================================
# Score of Parentheses
# ============================================================

# ============================================================
# Solution 1: Stack with Score Tracking
# Time: O(N) | Space: O(N)
# ============================================================
class Solution1:
    def scoreOfParentheses(self, s: str) -> int:
        stack = []         # score for each open '(' frame
        total = 0          # final result (outermost level)
        
        for c in s:
            if c == '(':
                stack.append(0)
                # start a new frame → begin collecting inner score
            else:
                # compute value of current "( ... )"
                inside = stack.pop()
                
                if inside == 0:
                    # Case: "()"
                    value = 1
                else:
                    # Case: "(A)"
                    value = 2 * inside
                
                if not stack:
                    # no parent → contributes directly to final result
                    # Example: "()()" → both pairs go directly to total
                    total += value
                else:
                    # child block contributes its value to its parent
                    # Example: "(())" → inner "()" contributes 1 to outer
                    parent_score = stack.pop()
                    parent_score = parent_score + value
                    stack.append(parent_score)
        
        return total

# ============================================================
# Solution 2: Stack with Depth Tracking
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def scoreOfParentheses(self, s: str) -> int:
        score = 0
        depth = 0
        
        for i in range(len(s)):
            if s[i] == '(':
                depth += 1
            else:
                depth -= 1
                # Check if this forms "()" - previous char was '('
                if s[i - 1] == '(':
                    # Add 2^depth to score (depth before decrement)
                    score += (1 << depth)  # Equivalent to 2 ** depth
        
        return score

# ============================================================
# Solution 3: Divide and Conquer (Recursive)
# Time: O(N²) | Space: O(N)
# ============================================================
class Solution3:
    def helper(self, s: str, start: int, end: int) -> int:
        # Base case: empty string
        if start >= end:
            return 0
        
        # Check if entire string is wrapped: (A)
        balance = 0
        is_wrapped = True
        
        for i in range(start, end):
            balance += 1 if s[i] == '(' else -1
            # If balance becomes 0 before the end, not fully wrapped
            if balance == 0 and i < end - 1:
                is_wrapped = False
                break
        
        # If wrapped like (A), return 2 * score(A)
        if is_wrapped:
            return 2 * self.helper(s, start + 1, end - 1)
        
        # Otherwise, split into balanced parts and sum
        total_score = 0
        balance = 0
        part_start = start
        
        for i in range(start, end):
            balance += 1 if s[i] == '(' else -1
            
            # Found a balanced part
            if balance == 0:
                total_score += self.helper(s, part_start, i + 1)
                part_start = i + 1
        
        return total_score
    
    def scoreOfParentheses(self, s: str) -> int:
        # Base case for "()"
        if s == "()":
            return 1
        return self.helper(s, 0, len(s))
