# Design a Movie Ticket Booking System

Design a system for booking movie tickets with show management, seat selection, payment, and concurrent booking handling.

<br>

---

## Requirements

### Main Requirements
1. **Browse movies** — by name, genre, city
2. **View shows** — available shows for a movie at a theater
3. **Select seats** — visual seat map, choose available seats
4. **Book tickets** — reserve seats, process payment
5. **Concurrent handling** — two users selecting same seat simultaneously
6. **Cancellation** — cancel booking, release seats

<br>

---

## Core Entities

```
Movie: id, title, genre, duration, rating
Theater: id, name, city, screens[]
Screen: id, seats[][], shows[]
Show: id, movie, screen, startTime, availableSeats
Seat: row, col, type (REGULAR/PREMIUM/VIP), status (AVAILABLE/BOOKED/LOCKED)
Booking: id, show, seats[], user, status, payment
```

<br>

---

## Concurrency: Seat Locking

```java
// Optimistic locking with timeout
1. User selects seats → LOCK seats for 5 minutes
2. User pays → change to BOOKED
3. Timeout expires → release back to AVAILABLE
4. If another user tries same seat → "Seat unavailable"
```

<br>

---

## Interview Tips

- Seat locking is THE critical discussion point
- Two approaches: pessimistic (lock upfront) vs optimistic (check at payment)
- Temporary lock with TTL prevents abandoned bookings holding seats
- Discuss: how BookMyShow/Fandango handle concurrent seat selection
