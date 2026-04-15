# Design a Meeting Room Reservation System

Design a meeting room booking system that handles room availability, booking conflicts, and recurring meetings.

<br>

---

## Requirements

### Main Requirements
1. **Book a room** — room, time slot, organizer, attendees
2. **Conflict detection** — prevent double-booking
3. **Search available rooms** — by time, capacity, amenities
4. **Cancel bookings** — free up the room
5. **Recurring meetings** — daily, weekly, monthly
6. **Notifications** — email attendees on booking/cancellation

### Extended Requirements
1. Room amenities (projector, whiteboard, video conferencing)
2. Floor/building filter
3. Waitlist for popular rooms

<br>

---

## Core Entities

```
MeetingRoom: id, name, capacity, floor, amenities[]
Booking: id, room, organizer, attendees[], startTime, endTime, isRecurring
MeetingScheduler: rooms[], bookings[]
├─ book(room, timeSlot): Booking
├─ cancel(bookingId): void
├─ findAvailable(timeSlot, capacity, amenities): List<MeetingRoom>

TimeSlot: startTime, endTime
├─ overlaps(TimeSlot other): boolean
```

<br>

---

## Interview Tips

- Overlap detection: `!(end1 <= start2 || end2 <= start1)` → overlaps
- Strategy for room selection: smallest room that fits, preferred floor, etc.
- Recurring meetings: generate occurrences lazily vs eagerly
- Thread safety: concurrent bookings for same room at same time
