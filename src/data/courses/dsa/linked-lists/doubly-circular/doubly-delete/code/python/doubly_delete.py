class Node:
    def __init__(self, d): self.data=d; self.next=None; self.prev=None
class DLL:
    def __init__(self): self.head=None
    def insert(self, d): n=Node(d); [self.head:=n for _ in [1] if not self.head] or [(c:=c.next for _ in iter(lambda:c.next,None)) or (c.next,n.prev):=(n,c) for c in [self.head]]
    def delete_begin(self): [self.head:=self.head.next for _ in [1] if self.head]; [self.head.prev:=None for _ in [1] if self.head]
    def delete_end(self): [self.head:=None for _ in [1] if not self.head or not self.head.next] or [(c:=c.next for _ in iter(lambda:c.next,None)) or (c.prev.next:=None) for c in [self.head]]
    def display(self): c=self.head; [print(c.data,end=" ") or (c:=c.next) for _ in iter(lambda:c,None)]; print()
if __name__=="__main__": dl=DLL(); [dl.insert(i) for i in range(1,5)]; dl.delete_begin(); dl.delete_end(); dl.display()