# Design a Train Platform Management System

Design a system to allocate platforms to incoming trains, minimizing the number of platforms needed.

<br>

---

## Requirements

### Main Requirements
1. **Schedule train** — arrival time, departure time, train ID
2. **Allocate platform** — assign available platform to arriving train
3. **Release platform** — free platform when train departs
4. **Minimum platforms** — calculate minimum platforms needed for a schedule
5. **Real-time status** — which train is on which platform

<br>

---

## Design Patterns Used

| Pattern | Where | Why |
|---------|-------|-----|
| **Strategy** | Platform allocation (first-available, shortest-wait, preferred) | Swappable allocation logic |
| **Observer** | Notify display board on platform changes | Decoupled UI updates |

<br>

---

## Core Entities

```
Train: id, name, arrivalTime, departureTime
Platform: id, currentTrain, schedule[]
Station: platforms[], allocate(Train), release(Platform)
AllocationStrategy (interface): FirstAvailable, ShortestWait
```

<br>

---

## Key Algorithm

Minimum platforms = max concurrent trains at any point. Use event-based approach:
sort arrivals and departures, sweep to find max overlap.

<br>

---

## Interview Tips

- This is the classic "minimum platforms" DSA problem wrapped in OOP
- Strategy for allocation policy makes it extensible
- Discuss: what if a train is delayed? Dynamic reallocation needed
