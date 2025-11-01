
**Dynamic Programming (DP)** is an algorithmic technique for solving a problem by **breaking it down into smaller subproblems** and using the fact that the **optimal solution to the overall problem depends on the optimal solutions to its subproblems**.

It **solves each subproblem once** and then **remembers its result**, avoiding redundant computations.

---

### 🍎 The Fruit Basket Story — Understanding DP

A father gave two identical fruit baskets to **Kid 1** and **Kid 2**, asking both to find the **total time to peel all the fruits**.


**Kid 1 — The Hard Worker**

Peels **each fruit one by one**, measuring time for every fruit —  
even when fruits repeat.  
→ **Recomputes** the same thing again and again.


**Kid 2 — The Smart Thinker**

Notices there are **only 5 unique fruit types**.  
Peels **one of each type**, records the time, and **reuses** the stored value whenever that fruit reappears.  
→ **Solves each subproblem once** and **reuses results**.


### 🧠 The Insight

Kid 2’s method reflects **Dynamic Programming**:

> - Breaks a big task (peeling all fruits) into smaller subproblems (each fruit type).  
> - Solves each subproblem **only once**.  
> - **Reuses** stored results instead of recalculating.

> **Kid 1 = Brute Force (recomputes everything)**  
> **Kid 2 = Dynamic Programming (remembers & reuses results)**
