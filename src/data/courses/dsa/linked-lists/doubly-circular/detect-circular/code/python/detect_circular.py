class Node:
    def __init__(self, d): self.data=d; self.next=None
class LL:
    def is_circular(self, h):
        if not h: return False
        s,f=h,h; [(s,f):=(s.next,f.next.next) for _ in iter(lambda:f and f.next and s!=f,None)]; return s==f and s==h
if __name__=="__main__": dc=LL(); h=Node(1); h.next=Node(2); h.next.next=Node(3); h.next.next.next=h; print(f"Is circular: {dc.is_circular(h)}")