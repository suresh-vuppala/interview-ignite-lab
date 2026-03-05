class DecodeString:
    def decodeString(self, s: str) -> str:
        count_stack = []
        string_stack = []
        current = ""
        k = 0
        
        for c in s:
            if c.isdigit():
                k = k * 10 + int(c)  # Build multi-digit number
            elif c == '[':
                count_stack.append(k)
                string_stack.append(current)
                current = ""
                k = 0
            elif c == ']':
                count = count_stack.pop()
                prev = string_stack.pop()
                current = prev + current * count
            else:
                current += c
        
        return current
