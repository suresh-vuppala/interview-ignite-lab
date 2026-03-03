class Node:
    def __init__(self, d): self.data=d; self.next=None; self.random=None
class LL:
    def copy(self, h):
        if not h: return None
        c=h; [(c.next,c):=(Node(c.data),c.next) or (c.next.next,c):=(c.next,c.next.next) for _ in iter(lambda:c,None)]
        c=h; [(c.next.random,c):=(c.random.next if c.random else None,c.next.next) for _ in iter(lambda:c,None)]
        oh,nh,nc=h,h.next,h.next; [(oh.next,nc.next,oh,nc):=(oh.next.next,nc.next.next if nc.next else None,oh.next,nc.next) for _ in iter(lambda:oh,None)]; return nh
if __name__=="__main__": cr=LL(); h=Node(1); h.next=Node(2); h.random=h.next; print("Copied")