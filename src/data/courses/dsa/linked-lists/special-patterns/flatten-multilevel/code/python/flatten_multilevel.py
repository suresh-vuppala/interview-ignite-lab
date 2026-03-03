class Node:
    def __init__(self, d): self.data=d; self.next=None; self.prev=None; self.child=None
class LL:
    def flatten(self, h):
        if not h: return None
        c=h
        while c:
            if c.child: n=c.next; ch=self.flatten(c.child); c.next=ch; ch.prev=c; c.child=None; [c:=c.next for _ in iter(lambda:c.next,None)]; [c.next,n.prev]:=[n,c] if n else [None,None]
            c=c.next
        return h
if __name__=="__main__": fm=LL(); h=Node(1); h.next=Node(2); h.next.child=Node(3); print("Flattened")