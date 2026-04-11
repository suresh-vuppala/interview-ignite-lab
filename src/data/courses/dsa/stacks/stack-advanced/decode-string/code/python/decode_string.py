# ============================================================
# Decode String
# ============================================================

class Solution:
    def decodeString(self, s: str) -> str:
        stack = []  # (previous_string, repeat_count)
        current_str = ""
        current_num = 0

        for c in s:
            if c.isdigit():
                current_num = current_num * 10 + int(c)
            elif c == '[':
                # Save state and reset
                stack.append((current_str, current_num))
                current_str = ""
                current_num = 0
            elif c == ']':
                # Pop and build
                prev_str, count = stack.pop()
                current_str = prev_str + current_str * count
            else:
                current_str += c

        return current_str
