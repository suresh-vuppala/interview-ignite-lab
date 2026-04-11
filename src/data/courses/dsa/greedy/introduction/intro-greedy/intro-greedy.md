## Greedy Algorithms — Locally Optimal → Globally Optimal

A greedy algorithm makes the **locally optimal choice** at each step, hoping to find the global optimum. Unlike DP, greedy doesn't reconsider past choices.

<br>

## When Does Greedy Work?

Greedy works when the problem has:
1. **Greedy choice property** — A locally optimal choice leads to a globally optimal solution
2. **Optimal substructure** — Optimal solution contains optimal solutions to subproblems

<br>

## Greedy vs Dynamic Programming

| | Greedy | DP |
|---|--------|-----|
| Makes choice | Before solving subproblems | After solving subproblems |
| Looks at | Current state only | All states |
| Time | Usually faster | Usually slower |
| Correctness | Must prove greedy works | Always finds optimal |

**If greedy works, prefer it over DP** — it's simpler and faster. But you must prove correctness.

<br>

## Common Greedy Patterns

| Pattern | Example Problems |
|---------|-----------------|
| **Sort + Scan** | Activity Selection, Meeting Rooms, Merge Intervals |
| **Two-pass Greedy** | Candy Distribution |
| **Interval Scheduling** | Non-overlapping Intervals, Insert Interval |
| **Greedy Choice** | Jump Game, Gas Station, Task Scheduler |
| **Local Max/Min** | Partition Labels, Valid Parenthesis String |

<br>
