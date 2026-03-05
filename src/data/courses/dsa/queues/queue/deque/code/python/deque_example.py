from collections import deque

class DequeExample:
    def demonstrate(self):
        dq = deque()
        
        dq.append(5)        # [5]
        dq.appendleft(3)    # [3, 5]
        dq.append(7)        # [3, 5, 7]
        
        print(f"Front: {dq.popleft()}")  # 3
        print(f"Rear: {dq.pop()}")       # 7
        print(f"Remaining: {list(dq)}")  # [5]

# Usage
example = DequeExample()
example.demonstrate()
