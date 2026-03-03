class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def insert(self, data):
        if not self.head:
            self.head = Node(data)
        else:
            curr = self.head
            while curr.next:
                curr = curr.next
            curr.next = Node(data)
    
    def create_cycle(self, pos):
        if not self.head:
            return
        tail = self.head
        cycle_node = None
        index = 0
        while tail.next:
            if index == pos:
                cycle_node = tail
            tail = tail.next
            index += 1
        if cycle_node:
            tail.next = cycle_node
    
    def has_cycle(self):
        if not self.head:
            return False
        slow = fast = self.head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False

if __name__ == "__main__":
    ll = LinkedList()
    for i in range(1, 6):
        ll.insert(i)
    print(f"Has cycle: {ll.has_cycle()}")
    ll.create_cycle(2)
    print(f"Has cycle after creating: {ll.has_cycle()}")