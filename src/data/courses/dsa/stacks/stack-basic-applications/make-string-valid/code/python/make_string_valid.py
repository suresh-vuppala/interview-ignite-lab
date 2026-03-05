class MakeStringValid:
    def minAddToMakeValid(self, s: str) -> int:
        open_count = 0
        close_count = 0
        
        for c in s:
            if c == '(':
                open_count += 1
            else:
                if open_count > 0:
                    open_count -= 1  # Match with opening
                else:
                    close_count += 1  # Unmatched closing
        
        return open_count + close_count  # Total additions needed
