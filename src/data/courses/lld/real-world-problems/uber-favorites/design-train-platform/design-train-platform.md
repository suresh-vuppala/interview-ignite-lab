# Design a Train Platform Management System

Design a system to allocate platforms to incoming trains, minimizing the number of platforms needed.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **Schedule train** — arrival time, departure time, train ID, train name
2. **Allocate platform** — assign an available platform to an arriving train
3. **Release platform** — free platform when train departs
4. **Minimum platforms** — calculate minimum platforms needed for the full schedule
5. **Real-time status** — which train is on which platform, upcoming arrivals
6. **Display board** — show platform assignments for passengers

### Extended Requirements (If Time Permits)

1. Platform preferences (express trains get Platform 1)
2. Dynamic reallocation (train delayed → reassign platforms)
3. Maintenance scheduling (platform out of service)
4. Train type priority (express > local > freight)
5. Historical analytics (platform utilization, peak hours)

<br>

---

## Constraints

- Maximum platforms per station: 20
- Train arrival/departure times: in minutes from midnight (0-1439)
- Minimum platform occupancy: 5 minutes (for boarding/alighting)
- A train occupies a platform from arrival to departure
- Two trains cannot occupy the same platform at the same time
- Platform allocation is greedy (first-available or strategy-based)

<br>

---

## Identify Primary Actors

1. **Station Controller** — manages train scheduling and platform allocation
   - Actions: schedule trains, allocate platforms, handle delays, view status

2. **Passenger** — views platform assignments
   - Actions: check display board for train platform

3. **Admin** — configures station
   - Actions: add/remove platforms, set maintenance windows, configure priority rules

<br>

---

## Core Entities

### 1. Train
- **Attributes**: id, name, arrivalTime, departureTime, type (EXPRESS/LOCAL/FREIGHT)
- **Responsibilities**: Store train schedule information

### 2. Platform
- **Attributes**: id, currentTrain, schedule: List<Train>
- **Methods**: isAvailable(time), assignTrain(train), releaseTrain()
- **Responsibilities**: Track occupancy, manage train assignments

### 3. Station
- **Attributes**: name, platforms: List<Platform>, allocationStrategy
- **Methods**: scheduleTrain(train), getStatus(), minPlatformsNeeded()
- **Responsibilities**: Central orchestrator for platform allocation

### 4. AllocationStrategy (Interface — Strategy Pattern)
- **Method**: allocate(List<Platform> platforms, Train train): Platform
- **Implementations**: FirstAvailableStrategy, PreferredPlatformStrategy, ShortestWaitStrategy

### 5. DisplayBoard
- **Attributes**: platformAssignments: Map<platformId, Train>
- **Responsibilities**: Real-time display of platform assignments for passengers

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Type |
|----------|-------------|----------|------|
| Station | contains | Platform[] | Composition (◆) |
| Station | uses | AllocationStrategy | Dependency |
| Station | has | DisplayBoard | Composition (◆) |
| Platform | hosts | Train (current) | Association |
| Platform | records | Train[] (schedule) | Aggregation (◇) |
| FirstAvailableStrategy | implements | AllocationStrategy | Implementation |

<br>

---

## Relationships Diagram (Textual UML)

```
  Station
  -name
  -platforms: List<Platform> ◆
  -strategy: AllocationStrategy
  -displayBoard: DisplayBoard ◆
  +scheduleTrain(Train): Platform
  +getStatus(): Map
  +minPlatformsNeeded(trains): int
       │
       ├──◆──→ Platform
       │        -id, -currentTrain
       │        -schedule: List<Train>
       │        +isAvailable(time): boolean
       │        +assignTrain(), +releaseTrain()
       │
       └──uses──→ AllocationStrategy (interface)
                   +allocate(platforms, train): Platform
                        △
                   ┌────┼────────────┐
              FirstAvailable  ShortestWait  PreferredPlatform
```

<br>

---

## Design Patterns Used

### 1. **Strategy Pattern**
- **Where**: AllocationStrategy — different algorithms for platform assignment
- **Why**: Some stations prefer first-available; others prioritize express trains on specific platforms
- **Benefit**: Swap allocation policy without modifying station logic

### 2. **Observer Pattern**
- **Where**: DisplayBoard observes platform assignment changes
- **Why**: Display updates automatically when trains are assigned/released
- **Benefit**: Decoupled — station doesn't directly update display

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms
- **Platform assignment**: `synchronized(platform)` — prevent two trains on same platform
- **Display board updates**: `ReadWriteLock` — frequent reads, rare writes
- **Schedule modifications**: Lock on Station for atomic schedule changes

### Race Conditions Handled
- **Two trains arrive simultaneously**: Sequential allocation under station lock
- **Delay notification during allocation**: Re-evaluate after allocation if delay reported
- **Display read during update**: ReadWriteLock ensures consistent display

<br>

---

## Edge Cases & Error Handling

### Edge Cases
1. **More trains than platforms** — queue trains, show "Platform pending"
2. **Train delayed** — update arrival time, re-evaluate platform assignment
3. **Zero trains scheduled** — all platforms idle
4. **All platforms under maintenance** — reject all train scheduling
5. **Train arrives before previous departs** — overlap → must wait or use different platform
6. **Overnight train** — departure after midnight (handle time wrap-around)
7. **Same arrival and departure time** — invalid, reject
8. **Train cancelled** — release platform, update display

### Error Handling Strategy
- **NoPlatformAvailableException**: All platforms occupied, suggest wait or next available time
- **InvalidScheduleException**: Arrival >= departure or negative times
- **PlatformMaintenanceException**: Requested platform is under maintenance

<br>

---

## Key Algorithm: Minimum Platforms

```
Sort all arrivals and departures separately.
Use two pointers to sweep through events:
  - Arrival event: platforms_needed++
  - Departure event: platforms_needed--
  - Track maximum at any point = minimum platforms required
Time complexity: O(N log N) for sorting
```

<br>

---

## Implementation

```code```
