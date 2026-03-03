class Node:
    def __init__(self, d): self.data=d; self.next=None; self.prev=None
class DLL:
    def __init__(self): self.head=None
    def insert(self, d): n=Node(d); [self.head:=n for _ in [1] if not self.head] or [(c:=c.next for _ in iter(lambda:c.next,None)) or (c.next,n.prev):=(n,c) for c in [self.head]]
    def reverse(self): c,t=self.head,None; [(t,c.prev,c.next,c):=(c.prev,c.next,t,c.prev) for _ in iter(lambda:c,None)]; [self.head:=t.prev for _ in [1] if t]
    def display(self): c=self.head; [print(c.data,end=" ") or (c:=c.next) for _ in iter(lambda:c,None)]; print()
if __name__=="__main__": dl=DLL(); [dl.insert(i) for i in range(1,5)]; dl.reverse(); dl.display()