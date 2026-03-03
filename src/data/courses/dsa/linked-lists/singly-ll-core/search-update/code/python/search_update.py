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
    
    def search_by_value(self, val):
        curr = self.head
        while curr:
            if curr.data == val:
                return True
            curr = curr.next
        return False
    
    def search_by_position(self, pos):
        curr = self.head
        for _ in range(pos):
            if not curr:
                return -1
            curr = curr.next
        return curr.data if curr else -1
    
    def update_by_position(self, pos, new_val):
        curr = self.head
        for _ in range(pos):
            if not curr:
                return
            curr = curr.next
        if curr:
            curr.data = new_val
    
    def update_by_value(self, old_val, new_val):
        curr = self.head
        while curr:
            if curr.data == old_val:
                curr.data = new_val
                return
            curr = curr.next
    
    def display(self):
        curr = self.head
        while curr:
            print(curr.data, end=" -> ")
            curr = curr.next
        print("None")

if __name__ == "__main__":
    ll = LinkedList()
    for i in range(1, 6):
        ll.insert(i)
    print(f"Search 3: {ll.search_by_value(3)}")
    print(f"Value at pos 2: {ll.search_by_position(2)}")
    ll.update_by_position(1, 10)
    ll.update_by_value(5, 50)
    ll.display()