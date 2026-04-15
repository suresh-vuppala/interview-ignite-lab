# Design a Parking Lot

Design a parking lot system that can handle multiple floors, different vehicle types, and parking spot allocation.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **Multiple Floors**: The parking lot should support multiple floors
2. **Vehicle Types**: Support different vehicle types (Motorcycle, Car, Truck/Bus)
3. **Spot Types**: Different spot sizes (Compact, Regular, Large)
4. **Entry/Exit**: Vehicles can enter and exit the parking lot
5. **Spot Assignment**: Automatically assign appropriate parking spots based on vehicle type
6. **Availability Check**: Check if parking is available for a vehicle type
7. **Ticket Generation**: Generate parking ticket on entry with timestamp
8. **Fee Calculation**: Calculate parking fee based on duration and vehicle type
9. **Payment Processing**: Process payment on exit

### Extended Requirements (If Time Permits)

1. **Reserved Parking**: Support for reserved spots (VIP, Handicapped, Electric Vehicle charging)
2. **Multiple Entry/Exit Points**: Handle multiple entry and exit panels
3. **Parking History**: Track historical parking data for analytics
4. **Dynamic Pricing**: Peak hour pricing, weekend rates, loyalty discounts
5. **Notifications**: SMS/Email notifications for parking expiry
6. **Mobile App Integration**: QR code scanning, digital payment
7. **Admin Dashboard**: Real-time monitoring, reports, manual overrides
8. **Valet Parking**: Support for valet service with key management

<br>

---

## Constraints

- Maximum 10 floors per parking lot
- Each floor has 100-500 parking spots
- Spot types: Compact (40%), Regular (40%), Large (20%)
- Vehicle types: Motorcycle (can park in any spot), Car (needs Regular or Large), Truck (needs Large only)
- Pricing: $2/hour for Motorcycle, $4/hour for Car, $6/hour for Truck
- Minimum charge: 1 hour
- Maximum parking duration: 24 hours
- Payment methods: Cash, Credit Card, Digital Wallet

<br>

---

## Identify Primary Actors

Primary actors are the users or systems that interact with the parking lot system:

1. **Customer/Driver**: Person who parks their vehicle
   - Actions: Enter parking lot, receive ticket, park vehicle, exit parking lot, make payment

2. **Parking Attendant**: Staff member who assists customers
   - Actions: Issue tickets manually, help with lost tickets, handle disputes, override system

3. **Admin/Manager**: System administrator
   - Actions: Configure pricing, add/remove floors, view reports, manage spots, handle maintenance

4. **System**: Automated components
   - Actions: Assign spots automatically, calculate fees, update display boards, process payments

5. **Payment Gateway**: External payment processing system
   - Actions: Validate payment, process transactions, send confirmations

<br>

---

## Core Entities

### 1. ParkingLot
- **Attributes**: name, address, floors[], entryPanels[], exitPanels[]
- **Responsibilities**: Manage floors, process entry/exit, coordinate operations

### 2. ParkingFloor
- **Attributes**: floorNumber, spots[], displayBoard
- **Responsibilities**: Manage spots on a floor, track availability

### 3. ParkingSpot
- **Attributes**: spotId, spotType, floor, isOccupied, vehicle
- **Responsibilities**: Track occupancy status, hold vehicle reference

### 4. Vehicle
- **Attributes**: licensePlate, vehicleType, color
- **Responsibilities**: Store vehicle information

### 5. ParkingTicket
- **Attributes**: ticketId, vehicle, spot, entryTime, exitTime, status
- **Responsibilities**: Track parking session, calculate duration

### 6. Payment
- **Attributes**: amount, paymentMethod, timestamp, status
- **Responsibilities**: Process payment, track transaction

### 7. DisplayBoard
- **Attributes**: floor, availableSpots (by type)
- **Responsibilities**: Show real-time availability

### 8. EntryPanel / ExitPanel
- **Attributes**: panelId, location
- **Responsibilities**: Handle vehicle entry/exit operations

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Cardinality | Description |
|----------|--------------|----------|-------------|-------------|
| ParkingLot | contains | ParkingFloor | 1:N | One parking lot has multiple floors |
| ParkingLot | has | EntryPanel | 1:N | One parking lot has multiple entry panels |
| ParkingLot | has | ExitPanel | 1:N | One parking lot has multiple exit panels |
| ParkingFloor | contains | ParkingSpot | 1:N | One floor has multiple parking spots |
| ParkingFloor | has | DisplayBoard | 1:1 | Each floor has one display board |
| ParkingSpot | occupiedBy | Vehicle | 1:0..1 | A spot can have zero or one vehicle |
| ParkingTicket | issuedFor | Vehicle | 1:1 | Each ticket is for one vehicle |
| ParkingTicket | assignedTo | ParkingSpot | 1:1 | Each ticket assigns one spot |
| ParkingTicket | requires | Payment | 1:1 | Each ticket requires one payment on exit |
| Vehicle | hasType | VehicleType | N:1 | Multiple vehicles of same type |
| ParkingSpot | hasType | SpotType | N:1 | Multiple spots of same type |

<br>

---

## Relationships Diagram (Textual UML)

```
┌─────────────────────────────────────────────────────────────────┐
│                         ParkingLot                              │
├─────────────────────────────────────────────────────────────────┤
│ - name: String                                                  │
│ - address: String                                               │
│ - floors: List<ParkingFloor>                                    │
│ - entryPanels: List<EntryPanel>                                │
│ - exitPanels: List<ExitPanel>                                  │
├─────────────────────────────────────────────────────────────────┤
│ + addFloor(floor: ParkingFloor): void                          │
│ + getAvailableSpot(vehicleType: VehicleType): ParkingSpot     │
│ + processEntry(vehicle: Vehicle): ParkingTicket               │
│ + processExit(ticket: ParkingTicket): Payment                 │
└─────────────────────────────────────────────────────────────────┘
                    │
                    │ 1
                    │
                    │ *
                    ▼
┌─────────────────────────────────────────────────────────────────┐
│                       ParkingFloor                              │
├─────────────────────────────────────────────────────────────────┤
│ - floorNumber: int                                              │
│ - spots: Map<String, ParkingSpot>                              │
│ - displayBoard: DisplayBoard                                    │
├─────────────────────────────────────────────────────────────────┤
│ + addSpot(spot: ParkingSpot): void                             │
│ + getAvailableSpot(vehicleType: VehicleType): ParkingSpot     │
│ + updateDisplayBoard(): void                                    │
└─────────────────────────────────────────────────────────────────┘
                    │
                    │ 1
                    │
                    │ *
                    ▼
┌─────────────────────────────────────────────────────────────────┐
│                       ParkingSpot                               │
├─────────────────────────────────────────────────────────────────┤
│ - spotId: String                                                │
│ - spotType: SpotType                                            │
│ - floor: int                                                    │
│ - isOccupied: boolean                                           │
│ - vehicle: Vehicle                                              │
├─────────────────────────────────────────────────────────────────┤
│ + assignVehicle(vehicle: Vehicle): boolean                      │
│ + removeVehicle(): void                                         │
│ + canFitVehicle(vehicleType: VehicleType): boolean            │
└─────────────────────────────────────────────────────────────────┘
                    │
                    │ 0..1
                    │
                    │ 1
                    ▼
┌─────────────────────────────────────────────────────────────────┐
│                          Vehicle                                │
├─────────────────────────────────────────────────────────────────┤
│ - licensePlate: String                                          │
│ - vehicleType: VehicleType                                      │
│ - color: String                                                 │
├─────────────────────────────────────────────────────────────────┤
│ + getVehicleType(): VehicleType                                │
└─────────────────────────────────────────────────────────────────┘
                    │
                    │ 1
                    │
                    │ 1
                    ▼
┌─────────────────────────────────────────────────────────────────┐
│                      ParkingTicket                              │
├─────────────────────────────────────────────────────────────────┤
│ - ticketId: String                                              │
│ - vehicle: Vehicle                                              │
│ - spot: ParkingSpot                                             │
│ - entryTime: DateTime                                           │
│ - exitTime: DateTime                                            │
│ - status: TicketStatus                                          │
├─────────────────────────────────────────────────────────────────┤
│ + calculateDuration(): long                                     │
│ + markExit(): void                                              │
└─────────────────────────────────────────────────────────────────┘
                    │
                    │ 1
                    │
                    │ 1
                    ▼
┌─────────────────────────────────────────────────────────────────┐
│                         Payment                                 │
├─────────────────────────────────────────────────────────────────┤
│ - amount: double                                                │
│ - paymentMethod: PaymentMethod                                  │
│ - timestamp: DateTime                                           │
│ - status: PaymentStatus                                         │
├─────────────────────────────────────────────────────────────────┤
│ + processPayment(): boolean                                     │
└─────────────────────────────────────────────────────────────────┘

┌──────────────────┐     ┌──────────────────┐     ┌──────────────────┐
│   <<enumeration>>│     │   <<enumeration>>│     │   <<enumeration>>│
│   VehicleType    │     │     SpotType     │     │  TicketStatus    │
├──────────────────┤     ├──────────────────┤     ├──────────────────┤
│ MOTORCYCLE       │     │ COMPACT          │     │ ACTIVE           │
│ CAR              │     │ REGULAR          │     │ PAID             │
│ TRUCK            │     │ LARGE            │     │ LOST             │
└──────────────────┘     └──────────────────┘     └──────────────────┘
```

<br>

---

## Design Patterns Used

### 1. **Singleton Pattern**
**Used For**: ParkingLot class

**Reasoning**: 
> - Only one instance of the parking lot should exist in the system
> - Provides global access point to the parking lot
> - Ensures centralized management of all parking operations
> - Thread-safe initialization prevents multiple instances in concurrent environment

**Implementation**: Thread-safe lazy initialization with double-checked locking

---

### 2. **Factory Pattern**
**Used For**: Vehicle and ParkingSpot creation

**Reasoning**:
> - Encapsulates object creation logic
> - Easy to add new vehicle types (Electric, Handicapped) without modifying existing code
> - Centralizes validation and initialization logic
> - Follows Open-Closed Principle (open for extension, closed for modification)

**Implementation**: VehicleFactory and SpotFactory classes

---

### 3. **Strategy Pattern**
**Used For**: Pricing calculation and spot allocation

**Reasoning**:
> - Different pricing strategies for different vehicle types
> - Different spot allocation strategies (First Available, Nearest to Entry, etc.)
> - Allows runtime selection of algorithm
> - Easy to add new strategies without modifying existing code

**Implementation**: PricingStrategy interface with HourlyPricingStrategy, FlatRatePricingStrategy implementations

---

### 4. **Observer Pattern**
**Used For**: DisplayBoard updates

**Reasoning**:
> - Display boards need to be notified when spot availability changes
> - Loose coupling between ParkingFloor and DisplayBoard
> - Multiple observers (display boards, mobile app, website) can be notified
> - Real-time updates without tight coupling

**Implementation**: DisplayBoard implements Observer interface, ParkingFloor is Subject

---

### 5. **State Pattern**
**Used For**: ParkingTicket status management

**Reasoning**:
> - Ticket has different states (Active, Paid, Lost, Expired)
> - Different behavior based on current state
> - Clean state transitions
> - Avoids complex conditional logic

**Implementation**: TicketState interface with ActiveState, PaidState, LostState classes

---

### 6. **Command Pattern**
**Used For**: Entry/Exit operations

**Reasoning**:
> - Encapsulates entry/exit requests as objects
> - Supports undo operations (cancel entry)
> - Logging and auditing of all operations
> - Queue management for concurrent requests

**Implementation**: ParkingCommand interface with EntryCommand, ExitCommand classes

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms

1. **Synchronized Spot Allocation**
   - Use `synchronized` blocks or `ReentrantLock` for spot assignment
   - Prevents double-booking of spots
   - Atomic check-and-assign operation

2. **Concurrent Collections**
   - Use `ConcurrentHashMap` for spot storage
   - Use `CopyOnWriteArrayList` for observers
   - Thread-safe without explicit locking

3. **Atomic Operations**
   - Use `AtomicInteger` for available spot counters
   - Use `AtomicBoolean` for spot occupancy flag
   - Lock-free thread-safe updates

4. **Read-Write Locks**
   - Use `ReentrantReadWriteLock` for display board
   - Multiple readers, single writer
   - Better performance for read-heavy operations

### Race Conditions Handled

1. **Multiple vehicles requesting same spot**: Synchronized allocation method
2. **Concurrent display board updates**: Atomic counter updates
3. **Payment processing during exit**: Transaction isolation
4. **Ticket generation with unique IDs**: Atomic ID generator

<br>

---

## Edge Cases & Error Handling

### Edge Cases

1. **No Available Spots**
   - Return null or throw `NoAvailableSpotException`
   - Suggest alternative vehicle types or floors

2. **Invalid Vehicle Type**
   - Validate vehicle type on entry
   - Reject unsupported vehicle types

3. **Lost Ticket**
   - Charge maximum fee (24 hours)
   - Require additional verification (license plate)

4. **Overstay (> 24 hours)**
   - Calculate extended fees
   - Flag for manual review

5. **Payment Failure**
   - Retry mechanism
   - Allow alternative payment methods
   - Hold vehicle until payment succeeds

6. **Spot Already Occupied**
   - Re-check availability
   - Assign alternative spot
   - Log inconsistency for investigation

7. **System Downtime During Parking**
   - Persist ticket data to database
   - Recovery mechanism on restart
   - Manual override for exit

8. **Concurrent Entry/Exit**
   - Queue management
   - Timeout handling
   - Deadlock prevention

### Error Handling Strategy

```
try {
    // Allocate spot
} catch (NoAvailableSpotException e) {
    // Notify user, suggest alternatives
} catch (InvalidVehicleException e) {
    // Reject entry, log error
} catch (ConcurrencyException e) {
    // Retry operation
} finally {
    // Release locks, update display
}
```

<br>

---

## Implementation

The complete implementation is provided in three languages:

- **C++**: Object-oriented design with smart pointers and thread safety
- **Java**: Enterprise-grade implementation with design patterns
- **Python**: Clean, Pythonic implementation with type hints

Each implementation includes:
- All core entities and enums
- Design patterns (Singleton, Factory, Strategy, Observer)
- Thread-safe operations
- Comprehensive error handling
- Example usage and test cases

<br>

---

```code```
