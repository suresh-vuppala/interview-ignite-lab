# ============================================================
# Evaluate Nested Expression
# ============================================================

# ============================================================
# Solution: Stack-Based Evaluation
# Time: O(N) | Space: O(N)
# ============================================================
class Solution:
    def evaluate(self, s: str) -> int:
        # Stack of [operator, operands]
        stack = []

        i = 0
        while i < len(s):
            c = s[i]
            
            # Parse operator (letters)
            if c.isalpha():
                op = ""
                while i < len(s) and s[i].isalpha():
                    op += s[i]
                    i += 1

                # Validate operator
                if op not in ["add", "sub", "mult"]:
                    return -1  # Invalid operator

                stack.append([op, []])
                continue  # i already incremented

            # Parse number (digits)
            elif c.isdigit():
                # Number without operator frame → invalid
                if not stack:
                    return -1

                num = 0
                while i < len(s) and s[i].isdigit():
                    num = num * 10 + int(s[i])
                    i += 1

                # Add operand to current frame
                stack[-1][1].append(num)
                continue  # i already incremented

            # Closing bracket → compute result
            elif c == ')':
                # No frame to close → invalid
                if not stack:
                    return -1

                op, nums = stack.pop()

                # Validate: exactly 2 operands
                if len(nums) != 2:
                    return -1

                # Compute result based on operator
                if op == "add":
                    result = nums[0] + nums[1]
                elif op == "sub":
                    result = nums[0] - nums[1]
                else:  # mult
                    result = nums[0] * nums[1]

                # Pass result to parent or return if outermost
                if stack:
                    stack[-1][1].append(result)
                else:
                    # Check if we've consumed entire string
                    if i == len(s) - 1:
                        return result
                    else:
                        return -1  # Extra characters after result

            # Ignore commas, spaces, opening parentheses
            elif c in [',', ' ', '(']:
                pass

            # Invalid character
            else:
                return -1
            
            i += 1

        # If stack not empty → unfinished expression
        return -1
