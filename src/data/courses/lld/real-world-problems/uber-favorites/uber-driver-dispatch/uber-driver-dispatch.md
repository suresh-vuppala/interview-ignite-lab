# Uber Driver Dispatch System

Design a driver dispatch system that matches ride requests with the nearest available driver.

<br>

---

## Requirements

### Main Requirements
1. **Rider requests ride** — pickup location, destination
2. **Find nearby drivers** — within radius, sorted by distance
3. **Match rider to driver** — nearest available driver
4. **Driver accepts/rejects** — timeout → try next driver
5. **Ride lifecycle** — Requested → Matched → PickedUp → Completed → Rated
6. **Fare calculation** — base + distance + time + surge multiplier

### Extended Requirements
1. Surge pricing during peak hours
2. Driver rating system
3. Ride pooling / shared rides
4. ETA calculation

<br>

---

## Design Patterns Used

| Pattern | Where | Why |
|---------|-------|-----|
| **Strategy** | Matching algorithm (nearest, highest-rated, pool) | Swappable matching |
| **Observer** | Notify driver of new ride requests | Decoupled notification |
| **State** | Ride lifecycle states | Clear transitions |

<br>

---

## Core Entities

```
RideService
├─ matchingStrategy: MatchingStrategy
├─ requestRide(Rider, Location, Location): Ride

MatchingStrategy (interface)
├── NearestDriverStrategy
├── HighestRatedStrategy

Driver: id, name, location, status (AVAILABLE/BUSY/OFFLINE), rating
Rider: id, name, location
Ride: rider, driver, pickup, destination, status, fare
Location: latitude, longitude + distanceTo()

FareCalculator
├─ baseFare + perKm * distance + perMin * time + surge
```

<br>

---

## Interview Tips

- Location class with distanceTo() using Haversine formula
- MatchingStrategy as pluggable algorithm — nearest vs rated vs pooled
- Ride status: Requested → Accepted → PickedUp → InProgress → Completed → Cancelled
- Discuss concurrency: two riders requesting same driver simultaneously
