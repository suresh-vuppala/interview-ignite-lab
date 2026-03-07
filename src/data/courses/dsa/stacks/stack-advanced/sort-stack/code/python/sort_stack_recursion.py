class SortStackRecursion:
    def sortStack(self, stack: list[int]) -> None:
        if not stack:
            return
        
        top = stack.pop()
        self.sortStack(stack)  # Sort remaining
        self.insertSorted(stack, top)  # Insert in sorted position
    
    def insertSorted(self, stack: list[int], element: int) -> None:
        if not stack or stack[-1] < element:
            stack.append(element)
            return
        
        top = stack.pop()
        self.insertSorted(stack, element)
        stack.append(top)
