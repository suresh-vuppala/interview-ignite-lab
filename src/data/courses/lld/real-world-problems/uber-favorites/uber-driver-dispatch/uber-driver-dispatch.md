# Uber Driver Dispatch System

Design a driver dispatch system that matches ride requests with the nearest available driver.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **Rider requests ride** — specify pickup location, destination
2. **Find nearby drivers** — within configurable radius, sorted by distance
3. **Match rider to driver** — assign nearest available driver
4. **Driver accepts/rejects** — timeout (30s) → try next nearest driver
5. **Ride lifecycle** — Requested → Matched → PickedUp → InProgress → Completed → Rated
6. **Fare calculation** — base fare + (distance × per-km rate) + (time × per-min rate) × surge multiplier

### Extended Requirements (If Time Permits)

1. Surge pricing during peak demand (2x, 3x multiplier)
2. Driver rating system (1-5 stars after ride)
3. Ride pooling / shared rides (multiple riders, same direction)
4. ETA calculation (estimated arrival time)
5. Ride history for rider and driver
6. Preferred driver (rider can request specific driver)
7. Ride cancellation with penalty fee

<br>

---

## Constraints

- Search radius: 5 km default, configurable up to 20 km
- Driver accept timeout: 30 seconds
- Maximum 3 driver match attempts before "No drivers available"
- Fare: base $2.50 + $1.50/km + $0.25/min, surge multiplier 1.0-3.0
- Location: latitude/longitude coordinates
- Driver statuses: AVAILABLE, BUSY, OFFLINE
- Ride statuses: REQUESTED, MATCHED, PICKED_UP, IN_PROGRESS, COMPLETED, CANCELLED

<br>

---

## Identify Primary Actors

1. **Rider** — requests and takes rides
   - Actions: request ride, view ETA, rate driver, cancel ride, view history

2. **Driver** — accepts ride requests and transports riders
   - Actions: go online/offline, accept/reject ride, navigate to pickup, start/complete ride

3. **Dispatch System** — matches riders with drivers
   - Actions: find nearby drivers, assign rides, handle timeouts, calculate fares

4. **Pricing Engine** — determines fare
   - Actions: calculate base fare, apply surge multiplier, apply promotions

<br>

---

## Core Entities

### 1. Location
- **Attributes**: latitude, longitude
- **Methods**: distanceTo(Location other): double (Haversine or Euclidean)

### 2. Driver
- **Attributes**: id, name, location, status (AVAILABLE/BUSY/OFFLINE), rating, vehicleType
- **Responsibilities**: Track availability, update location, accept/reject rides

### 3. Rider
- **Attributes**: id, name, location, paymentMethod
- **Responsibilities**: Request rides, rate drivers

### 4. Ride
- **Attributes**: rideId, rider, driver, pickup, destination, status, fare, startTime, endTime
- **Responsibilities**: Track ride lifecycle, calculate duration/distance

### 5. MatchingStrategy (Interface — Strategy Pattern)
- **Method**: findDriver(Location pickup, List<Driver> drivers): Driver
- **Implementations**: NearestDriverStrategy, HighestRatedStrategy, PoolMatchStrategy

### 6. FareCalculator
- **Attributes**: baseFare, perKmRate, perMinRate, surgeMultiplier
- **Methods**: calculate(distance, duration, surge): double

### 7. RideService
- **Attributes**: drivers[], matchingStrategy, fareCalculator
- **Responsibilities**: Orchestrate ride request → match → complete flow

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Type |
|----------|-------------|----------|------|
| Ride | has | Rider | Association |
| Ride | has | Driver | Association |
| Ride | has | Location (pickup, dest) | Composition (◆) |
| RideService | uses | MatchingStrategy | Dependency |
| RideService | uses | FareCalculator | Dependency |
| RideService | manages | Driver[] | Aggregation (◇) |
| NearestDriverStrategy | implements | MatchingStrategy | Implementation |
| HighestRatedStrategy | implements | MatchingStrategy | Implementation |

<br>

---

## Relationships Diagram (Textual UML)

```
  RideService
  -drivers: List<Driver> ◇
  -matchingStrategy: MatchingStrategy
  -fareCalculator: FareCalculator
  +requestRide(Rider, Location, Location): Ride
       │
       ├──uses──→ MatchingStrategy (interface)
       │           +findDriver(pickup, drivers): Driver
       │                △
       │           ┌────┴────────┐
       │      NearestDriver  HighestRated
       │
       └──uses──→ FareCalculator
                   +calculate(dist, time, surge): double


  Ride
  -rideId, -status
  -rider → Rider
  -driver → Driver
  -pickup → Location ◆
  -destination → Location ◆
  -fare, -startTime, -endTime

  Driver                    Rider
  -id, -name                -id, -name
  -location → Location      -location → Location
  -status (AVAILABLE/BUSY)  -paymentMethod
  -rating
```

<br>

---

## Design Patterns Used

### 1. **Strategy Pattern**
- **Where**: MatchingStrategy — NearestDriver, HighestRated, PoolMatch
- **Why**: Different matching algorithms for different scenarios (normal vs premium vs pool)
- **Benefit**: Swap matching logic at runtime, A/B test different strategies

### 2. **Observer Pattern**
- **Where**: Notify driver of new ride request; notify rider of driver arrival
- **Why**: Decoupled push notifications — driver doesn't poll for rides
- **Benefit**: Real-time updates without polling

### 3. **State Pattern**
- **Where**: Ride lifecycle (Requested → Matched → PickedUp → InProgress → Completed)
- **Why**: Each state has different allowed transitions and behaviors
- **Benefit**: Clean state machine, invalid transitions throw exceptions

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms
- **Driver availability**: `ConcurrentHashMap<DriverId, Driver>` for thread-safe lookup
- **Ride matching**: `synchronized` on driver assignment — prevent same driver matched to two riders
- **Location updates**: Drivers send location every 5 seconds — write-heavy, use lock-free `AtomicReference<Location>`
- **Surge calculation**: Read demand/supply metrics from `AtomicInteger` counters

### Race Conditions Handled
- **Two riders request same driver**: First `compareAndSet(AVAILABLE, BUSY)` wins, second retries with next driver
- **Driver goes offline during matching**: Timeout + retry with next available driver
- **Concurrent fare calculation**: FareCalculator is stateless — thread-safe by design

<br>

---

## Edge Cases & Error Handling

### Edge Cases
1. **No drivers available** — retry 3 times with increasing radius, then "No drivers found"
2. **Driver rejects ride** — try next nearest driver, max 3 attempts
3. **Driver goes offline after match** — reassign to next available driver
4. **Rider cancels after match** — free the driver, charge cancellation fee if > 2 min after match
5. **Zero distance ride** — minimum fare applies (base fare)
6. **Very long ride (> 100 km)** — apply long-distance rate, no surge
7. **Surge multiplier = 0** — impossible, floor at 1.0
8. **Multiple riders at exact same location** — each gets separate matching attempt
9. **Driver's GPS location stale (> 60 seconds)** — mark as "location unknown", skip in matching

### Error Handling Strategy
- **NoDriverAvailableException**: Show "No drivers nearby", suggest trying later
- **RideAlreadyActiveException**: Rider already has active ride
- **InvalidLocationException**: Coordinates out of valid range
- **PaymentFailedException**: Charge failed → hold ride, retry payment or cancel

<br>

---

## Implementation

> See the **Java code tab** for the complete implementation including Location with distance calculation, Strategy-based driver matching, FareCalculator, and RideService orchestration.
