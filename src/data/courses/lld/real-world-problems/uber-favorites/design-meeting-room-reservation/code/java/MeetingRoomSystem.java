// Meeting Room Reservation System
import java.util.*;
import java.time.*;

class MeetingRoom {
    private String id, name;
    private int capacity;
    private int floor;
    private Set<String> amenities;
    
    public MeetingRoom(String id, String name, int capacity, int floor, String... amenities) {
        this.id = id; this.name = name; this.capacity = capacity;
        this.floor = floor; this.amenities = new HashSet<>(List.of(amenities));
    }
    public String getId() { return id; }
    public String getName() { return name; }
    public int getCapacity() { return capacity; }
    public boolean hasAmenity(String a) { return amenities.contains(a); }
}

class TimeSlot {
    private LocalDateTime start, end;
    public TimeSlot(LocalDateTime start, LocalDateTime end) {
        if (!end.isAfter(start)) throw new IllegalArgumentException("End must be after start");
        this.start = start; this.end = end;
    }
    public boolean overlaps(TimeSlot other) {
        return start.isBefore(other.end) && other.start.isBefore(end);
    }
    public LocalDateTime getStart() { return start; }
    public LocalDateTime getEnd() { return end; }
}

class Booking {
    private String id;
    private MeetingRoom room;
    private String organizer;
    private List<String> attendees;
    private TimeSlot timeSlot;
    
    public Booking(String id, MeetingRoom room, String organizer, List<String> attendees, TimeSlot slot) {
        this.id = id; this.room = room; this.organizer = organizer;
        this.attendees = attendees; this.timeSlot = slot;
    }
    public String getId() { return id; }
    public MeetingRoom getRoom() { return room; }
    public TimeSlot getTimeSlot() { return timeSlot; }
}

class MeetingScheduler {
    private List<MeetingRoom> rooms = new ArrayList<>();
    private Map<String, List<Booking>> roomBookings = new HashMap<>(); // roomId → bookings
    private int bookingCounter = 0;
    
    public void addRoom(MeetingRoom room) {
        rooms.add(room);
        roomBookings.put(room.getId(), new ArrayList<>());
    }
    
    public synchronized Booking book(String roomId, String organizer, List<String> attendees, TimeSlot slot) {
        List<Booking> bookings = roomBookings.get(roomId);
        if (bookings == null) throw new IllegalArgumentException("Room not found");
        
        // Conflict check
        for (Booking b : bookings) {
            if (b.getTimeSlot().overlaps(slot))
                throw new IllegalStateException("Room already booked for this time");
        }
        
        MeetingRoom room = rooms.stream().filter(r -> r.getId().equals(roomId)).findFirst().orElseThrow();
        Booking booking = new Booking("BK-" + (++bookingCounter), room, organizer, attendees, slot);
        bookings.add(booking);
        System.out.println("✅ Booked " + room.getName() + " for " + organizer);
        return booking;
    }
    
    public synchronized void cancel(String bookingId) {
        for (List<Booking> bookings : roomBookings.values()) {
            bookings.removeIf(b -> b.getId().equals(bookingId));
        }
        System.out.println("Cancelled booking " + bookingId);
    }
    
    public List<MeetingRoom> findAvailable(TimeSlot slot, int minCapacity) {
        return rooms.stream()
            .filter(r -> r.getCapacity() >= minCapacity)
            .filter(r -> roomBookings.get(r.getId()).stream()
                .noneMatch(b -> b.getTimeSlot().overlaps(slot)))
            .toList();
    }
}
