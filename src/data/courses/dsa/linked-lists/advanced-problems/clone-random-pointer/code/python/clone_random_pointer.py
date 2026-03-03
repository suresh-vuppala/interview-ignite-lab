class Node:
    def __init__(self, v): self.val=v; self.next=None; self.random=None
class Solution:
    def clone(self, head):
        if not head: return None
        c=head; [(c.next,c):=(Node(c.val),c.next) or (c.next.next,c):=(c.next,c.next.next) for _ in iter(lambda:c,None)]
        c=head; [(c.next.random,c):=(c.random.next if c.random else None,c.next.next) for _ in iter(lambda:c,None)]
        oh,nh,nc=head,head.next,head.next; [(oh.next,nc.next,oh,nc):=(oh.next.next,nc.next.next if nc.next else None,oh.next,nc.next) for _ in iter(lambda:oh,None)]; return nh
if __name__=="__main__": s=Solution(); h=Node(1); h.next=Node(2); h.next.next=Node(3); h.random=h.next.next; h.next.random=h; copy=s.clone(h); print(f"Cloned: {copy.val}")