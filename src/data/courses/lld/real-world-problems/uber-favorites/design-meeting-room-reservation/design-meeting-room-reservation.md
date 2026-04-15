# Design a Meeting Room Reservation System

Design a meeting room booking system with conflict detection, capacity filtering, and recurring meetings.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **Book a room** — specify room, time slot, organizer, attendees
2. **Conflict detection** — prevent double-booking same room at overlapping times
3. **Search available rooms** — filter by time slot, minimum capacity, amenities
4. **Cancel bookings** — free up the room for others
5. **View room schedule** — see all bookings for a specific room on a date
6. **Recurring meetings** — daily, weekly, monthly recurrence

### Extended Requirements (If Time Permits)

1. Room amenities filter (projector, whiteboard, video conferencing, phone)
2. Floor/building filter
3. Waitlist for popular rooms
4. Auto-suggest best available room based on requirements
5. Calendar integration (Google Calendar, Outlook)
6. Check-in requirement — release room if organizer doesn't check in within 15 min

<br>

---

## Constraints

- Rooms: up to 100 per building
- Capacity: 2 to 50 people
- Booking granularity: 15-minute slots
- Maximum booking duration: 8 hours
- Booking ahead: up to 30 days in advance
- Recurring: up to 52 occurrences (1 year of weekly)
- Operating hours: 7:00 AM to 10:00 PM

<br>

---

## Identify Primary Actors

1. **Employee/Organizer** — books meeting rooms
   - Actions: search rooms, book room, cancel booking, view schedule

2. **Attendees** — invited to meetings
   - Actions: view meeting details, accept/decline invitation

3. **Admin** — manages rooms and policies
   - Actions: add/remove rooms, configure amenities, set booking rules

4. **System** — automated operations
   - Actions: detect conflicts, send reminders, auto-release unreserved rooms

<br>

---

## Core Entities

### 1. MeetingRoom
- **Attributes**: id, name, capacity, floor, building, amenities: Set<String>
- **Responsibilities**: Store room information, check amenity requirements

### 2. TimeSlot
- **Attributes**: startTime: LocalDateTime, endTime: LocalDateTime
- **Methods**: overlaps(TimeSlot other): boolean, duration(): Duration
- **Responsibilities**: Time range with overlap detection

### 3. Booking
- **Attributes**: id, room, organizer, attendees[], timeSlot, isRecurring, recurrenceRule
- **Responsibilities**: Represent a confirmed room reservation

### 4. MeetingScheduler
- **Attributes**: rooms[], bookings: Map<roomId, List<Booking>>
- **Methods**: book(), cancel(), findAvailable()
- **Responsibilities**: Central orchestrator — conflict check, room allocation

### 5. RecurrenceRule (optional)
- **Attributes**: frequency (DAILY/WEEKLY/MONTHLY), count, endDate
- **Responsibilities**: Generate recurring time slots

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Type |
|----------|-------------|----------|------|
| MeetingScheduler | manages | MeetingRoom[] | Aggregation (◇) |
| MeetingScheduler | manages | Booking[] | Composition (◆) |
| Booking | references | MeetingRoom | Association |
| Booking | has | TimeSlot | Composition (◆) |
| Booking | has | RecurrenceRule (optional) | Composition (◆) |
| Booking | references | Employee (organizer) | Association |
| Booking | references | Employee[] (attendees) | Association |

<br>

---

## Relationships Diagram (Textual UML)

```
  MeetingScheduler
  -rooms: List<MeetingRoom> ◇
  -bookings: Map<roomId, List<Booking>> ◆
  +book(roomId, organizer, attendees, slot): Booking
  +cancel(bookingId): void
  +findAvailable(slot, minCapacity, amenities): List<MeetingRoom>
       │
       ├──◇──→ MeetingRoom
       │        -id, -name, -capacity
       │        -floor, -amenities[]
       │
       └──◆──→ Booking
                -id, -organizer, -attendees[]
                -room → MeetingRoom
                -timeSlot → TimeSlot ◆
                -recurrenceRule (optional)

  TimeSlot
  -startTime, -endTime
  +overlaps(other): boolean
  // overlap = start1 < end2 AND start2 < end1
```

<br>

---

## Design Patterns Used

### 1. **Strategy Pattern**
- **Where**: Room selection strategy (smallest-fit, preferred-floor, nearest-amenity)
- **Why**: Different organizations prefer different room allocation policies
- **Benefit**: Swap allocation logic without changing scheduler

### 2. **Observer Pattern**
- **Where**: Notify attendees on booking/cancellation/change
- **Why**: Attendees receive automatic calendar updates
- **Benefit**: Decoupled notification — scheduler doesn't know about email/Slack/calendar

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms
- **Booking operation**: `synchronized(room)` — lock per room, not global lock
- **Concurrent searches**: Read-only — safe without locks
- **Booking ID generation**: `AtomicInteger` for unique IDs

### Race Conditions Handled
- **Two employees book same room, same time**: First `synchronized` block wins, second gets `ConflictException`
- **Cancel while someone is booking**: Cancel acquires same room lock, waits for booking to complete
- **Concurrent recurring booking creation**: Each occurrence checked individually under room lock

<br>

---

## Edge Cases & Error Handling

### Edge Cases
1. **Overlapping bookings** — `!(end1 <= start2 || end2 <= start1)` → conflict
2. **Booking exactly at boundary** — 10:00-11:00 and 11:00-12:00 do NOT overlap (end is exclusive)
3. **Room capacity exceeded** — attendees > room capacity → reject or warn
4. **Recurring meeting conflicts** — one occurrence conflicts → reject entire recurrence or skip that occurrence
5. **Cancel one occurrence of recurring** — remove single occurrence, keep others
6. **Past time booking** — reject, can't book in the past
7. **Zero-duration booking** — reject, minimum 15 minutes
8. **All rooms booked** — suggest alternative time slots or waitlist
9. **Room under maintenance** — temporarily unavailable, reject bookings

### Error Handling Strategy
- **RoomConflictException**: Room already booked at that time — suggest alternatives
- **RoomCapacityExceededException**: Too many attendees for room size
- **InvalidTimeSlotException**: Past time, zero duration, or outside operating hours
- **RoomNotFoundException**: Invalid room ID

<br>

---

## Implementation

> See the **Java code tab** for the complete implementation including TimeSlot overlap detection, synchronized booking, available room search, and MeetingRoom with amenities.
