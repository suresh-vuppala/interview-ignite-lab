# Step 3: API / Interface Design

> **Design the contract before the implementation.** What methods does your system expose? What are the inputs and outputs?

<br>

---

## Why Interface-First Design

1. **Forces you to think about behavior** before internals
2. **Defines the contract** clients will use
3. **Enables parallel implementation** — team can code against interfaces
4. **Shows interviewer you think about abstraction**

<br>

---

## The Technique: Start with Service Interface

For each major use case, define a method:

```java
// Parking Lot — Service Interface
interface ParkingLotService {
    Ticket parkVehicle(Vehicle vehicle);
    Payment unparkVehicle(Ticket ticket);
    boolean isSpotAvailable(VehicleType type);
    int getAvailableSpotCount(VehicleType type);
    ParkingSpot findNearestSpot(VehicleType type, int floor);
}
```

### Method Design Rules

| Rule | Example |
|------|---------|
| **Verb + noun** naming | `parkVehicle()`, `calculateFare()`, not `doStuff()` |
| **Clear return type** | `Ticket` not `Object`, `boolean` for yes/no |
| **Minimal parameters** | 2-3 max, group into objects if more |
| **Fail explicitly** | Throw specific exceptions, not return null |

<br>

---

## Strategy Interface Pattern

For any behavior that varies, define a strategy interface:

```java
// Pricing varies by strategy
interface PricingStrategy {
    double calculateFare(Vehicle vehicle, Duration duration);
}

// Matching varies by algorithm
interface MatchingStrategy {
    Driver findBestDriver(Location pickup, List<Driver> available);
}

// Notification varies by channel
interface NotificationService {
    void send(String recipient, String message);
}
```

**Rule:** If you see if-else on TYPE → extract to Strategy interface.

<br>

---

## Interface Design for LLD Problems

### Template for Any Problem

```java
// 1. Core Service — main operations
interface [System]Service {
    [Result] [action]([params]);  // Core use case 1
    [Result] [action]([params]);  // Core use case 2
    // ...
}

// 2. Strategy — for varying behavior
interface [Behavior]Strategy {
    [Result] [action]([params]);
}

// 3. Repository — for data access
interface [Entity]Repository {
    void save([Entity] entity);
    Optional<[Entity]> findById([IdType] id);
    List<[Entity]> findBy[Criteria]([params]);
}
```

<br>

---

## Example: Movie Ticket Booking

```java
interface BookingService {
    Show searchShows(String movieName, String city, LocalDate date);
    List<Seat> getAvailableSeats(Show show);
    BookingLock lockSeats(Show show, List<Seat> seats, String userId);
    Booking confirmBooking(BookingLock lock, PaymentInfo payment);
    Refund cancelBooking(String bookingId);
}

interface PricingStrategy {
    double calculatePrice(Seat seat, Show show);  // Matinee vs evening, VIP vs regular
}

interface PaymentGateway {
    PaymentResult charge(String userId, double amount);
    PaymentResult refund(String transactionId);
}
```

<br>

---

## Key Takeaways

1. **Define interfaces BEFORE implementation** — contract first
2. **One interface per responsibility** (ISP)
3. **Strategy interface** for any if-else on type → polymorphism
4. **Clear method names**: verb + noun, specific return types
5. **In interviews: write interfaces on the board first**, then implement
