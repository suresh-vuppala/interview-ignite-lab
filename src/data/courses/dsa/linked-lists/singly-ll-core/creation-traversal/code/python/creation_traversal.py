class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    # 1. Create linked list from list
    def create(self, values):
        if not values:
            return
        
        self.head = Node(values[0])
        current = self.head
        
        for val in values[1:]:
            current.next = Node(val)
            current = current.next
    
    # 2. Traverse and print
    def traverse(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")
    
    # 3. Count nodes
    def count_nodes(self):
        count = 0
        current = self.head
        while current:
            count += 1
            current = current.next
        return count

if __name__ == "__main__":
    ll = LinkedList()
    
    # Create linked list
    ll.create([1, 2, 3, 4, 5])
    
    # Traverse and print
    print("List: ", end="")
    ll.traverse()
    
    # Count nodes
    print(f"Total nodes: {ll.count_nodes()}")