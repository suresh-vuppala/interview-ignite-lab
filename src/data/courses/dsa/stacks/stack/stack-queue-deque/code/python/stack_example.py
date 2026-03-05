class StackExample:
    def demonstrate(self):
        stack = []
        
        stack.append(5)
        stack.append(10)
        stack.append(15)
        
        print(f"Popped: {stack.pop()}")      # 15
        print(f"Top: {stack[-1]}")           # 10
        print(f"Size: {len(stack)}")         # 2
        print(f"Empty: {len(stack) == 0}")   # False

# Usage
example = StackExample()
example.demonstrate()
