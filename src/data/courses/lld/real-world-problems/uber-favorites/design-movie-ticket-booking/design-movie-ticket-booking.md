# Design a Movie Ticket Booking System

Design a system for booking movie tickets with show management, seat selection, payment, and concurrent booking handling.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **Browse movies** — search by name, genre, city, language
2. **View shows** — available shows for a movie at a theater on a date
3. **Select seats** — visual seat map, choose available seats
4. **Lock seats** — temporarily hold selected seats (5 min) during payment
5. **Book tickets** — confirm booking after payment, generate ticket
6. **Cancel booking** — release seats, process refund based on policy
7. **Concurrent handling** — two users cannot book the same seat

### Extended Requirements (If Time Permits)

1. Multiple screen formats (IMAX, 3D, Dolby Atmos)
2. Food/snack combo with ticket
3. Promo codes and discount coupons
4. Seat auto-suggestion (best available N seats together)
5. Waitlist for sold-out shows
6. Reviews and ratings per movie

<br>

---

## Constraints

- Seat lock timeout: 5 minutes (release if payment not completed)
- Seat types: REGULAR ($10), PREMIUM ($15), VIP ($25)
- Maximum 10 seats per booking
- Shows per screen per day: up to 5
- Screen capacity: 50-500 seats
- Booking window: up to 7 days in advance
- Cancellation: Full refund > 4 hours before show, 50% refund 2-4 hours, no refund < 2 hours

<br>

---

## Identify Primary Actors

1. **Customer** — browses movies, books tickets
   - Actions: search movies, select show, choose seats, pay, view tickets, cancel

2. **Theater Admin** — manages shows and seating
   - Actions: add movies/shows, configure screens, set pricing, view bookings

3. **Payment Gateway** — processes payments
   - Actions: charge card, process refund

4. **System** — automated operations
   - Actions: release expired seat locks, send booking confirmations, send reminders

<br>

---

## Core Entities

### 1. Movie
- **Attributes**: id, title, genre, duration, language, rating, releaseDate
- **Responsibilities**: Store movie metadata

### 2. Theater
- **Attributes**: id, name, city, address, screens: List<Screen>
- **Responsibilities**: Manage screens and shows

### 3. Screen
- **Attributes**: id, name, seats: Seat[][], shows: List<Show>
- **Responsibilities**: Define seating layout, host shows

### 4. Show
- **Attributes**: id, movie, screen, startTime, date
- **Responsibilities**: Link movie to screen at a specific time

### 5. Seat
- **Attributes**: row, col, type (REGULAR/PREMIUM/VIP), status (AVAILABLE/LOCKED/BOOKED)
- **Attributes**: lockedBy, lockExpiry
- **Methods**: lock(userId, duration), book(userId), release()
- **Responsibilities**: Track availability, manage locking with TTL

### 6. Booking
- **Attributes**: id, show, seats[], user, totalPrice, status (CONFIRMED/CANCELLED), paymentId
- **Responsibilities**: Record booking details, support cancellation

### 7. BookingService
- **Methods**: lockSeats(), confirmBooking(), cancelBooking()
- **Responsibilities**: Orchestrate the booking flow with concurrency safety

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Type |
|----------|-------------|----------|------|
| Theater | contains | Screen[] | Composition (◆) |
| Screen | contains | Seat[][] | Composition (◆) |
| Screen | hosts | Show[] | Aggregation (◇) |
| Show | references | Movie | Association |
| Show | hosted on | Screen | Association |
| Booking | references | Show | Association |
| Booking | contains | Seat[] | Association |
| Seat | locked by | User | Association (temporary) |

<br>

---

## Relationships Diagram (Textual UML)

```
  Theater ◆──→ Screen[] ◆──→ Seat[][]
                  │              -row, -col
                  │              -type, -status
                  ◇              -lockedBy, -lockExpiry
                  │              +lock(), +book(), +release()
                  ▼
               Show[]
               -movie → Movie
               -startTime, -date

  BookingService
  +lockSeats(show, seats[], userId): boolean
  +confirmBooking(show, seats[], userId, payment): Booking
  +cancelBooking(bookingId): Refund

  Booking
  -id, -show, -seats[]
  -user, -totalPrice
  -status (CONFIRMED/CANCELLED)
```

<br>

---

## Design Patterns Used

### 1. **State Pattern** (implicit)
- **Where**: Seat status transitions (AVAILABLE → LOCKED → BOOKED or AVAILABLE → LOCKED → AVAILABLE on timeout)
- **Why**: Seat behavior depends on status — lock only if available, book only if locked by same user
- **Benefit**: Clear state machine prevents invalid transitions

### 2. **Strategy Pattern**
- **Where**: Pricing strategy (flat, dynamic, time-based), Refund policy strategy
- **Why**: Pricing varies by time (matinee vs evening), day (weekday vs weekend)
- **Benefit**: New pricing rules without changing booking logic

### 3. **Observer Pattern**
- **Where**: Notify user on booking confirmation, seat release, show cancellation
- **Why**: Decoupled notifications — email, SMS, push without modifying booking service

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms
- **Seat locking**: `synchronized(seat)` — atomic check-and-lock per seat
- **Multi-seat lock**: Acquire locks on ALL requested seats or NONE (all-or-nothing)
- **Lock timeout**: Background scheduler releases expired locks every 30 seconds
- **Booking confirmation**: Verify locks are still held before confirming

### Race Conditions Handled
- **Two users select same seat**: First to acquire `synchronized(seat)` lock wins
- **Lock expires during payment**: Payment fails → user must re-select seats
- **Cancel while someone else waits for lock**: Release notifies waiting threads
- **Show sells out**: After locking seats, re-verify availability before confirming

<br>

---

## Edge Cases & Error Handling

### Edge Cases
1. **Lock timeout** — 5 min expires without payment → seats auto-released
2. **Partial lock failure** — can't lock all requested seats → rollback locked ones
3. **Double booking attempt** — same user tries to book already-locked seats → idempotent (allow)
4. **Show cancelled** — auto-cancel all bookings, full refund
5. **Seat damaged/blocked** — mark as UNAVAILABLE permanently
6. **User selects 0 seats** — reject booking
7. **Payment fails after lock** — release seats, show error, allow retry
8. **Concurrent cancellation** — two requests cancel same booking → idempotent, only one refund
9. **Booking after show started** — reject based on cutoff time (30 min before show)

### Error Handling Strategy
- **SeatUnavailableException**: Seats already taken → show updated seat map
- **LockExpiredException**: Payment too slow → redirect to seat selection
- **PaymentFailedException**: Release seats, allow retry
- **ShowFullException**: No available seats → suggest alternative shows
- **CancellationDeniedException**: Too close to show time for refund

<br>

---

## Implementation

```code```
