class Node:
    def __init__(self, d): self.data=d; self.next=None; self.prev=None
class DLL:
    def __init__(self): self.head=None
    def insert_begin(self, d): n=Node(d); n.next=self.head; [self.head.prev:=n for _ in [1] if self.head]; self.head=n
    def insert_end(self, d): n=Node(d); [self.head:=n for _ in [1] if not self.head] or [(c:=c.next for _ in iter(lambda:c.next,None)) or (c.next,n.prev):=(n,c) for c in [self.head]]
    def display(self): c=self.head; [print(c.data,end=" ") or (c:=c.next) for _ in iter(lambda:c,None)]; print()
if __name__=="__main__": dl=DLL(); dl.insert_end(1); dl.insert_end(3); dl.insert_begin(0); dl.display()