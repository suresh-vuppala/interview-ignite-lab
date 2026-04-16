// DESIGN: Meeting Room Reservation — LLD (Java) | Key: Overlap detection
import java.util.*;

class TimeSlot {
    int startH, startM, endH, endM;
    TimeSlot(int sh, int sm, int eh, int em) { startH=sh; startM=sm; endH=eh; endM=em; }
    int startMins() { return startH*60+startM; } int endMins() { return endH*60+endM; }
    boolean overlaps(TimeSlot o) { return startMins()<o.endMins() && o.startMins()<endMins(); }
    String toString2() { return String.format("%02d:%02d-%02d:%02d",startH,startM,endH,endM); }
}
class MeetingRoom { String id, name; int capacity;
    MeetingRoom(String id, String name, int cap) { this.id=id; this.name=name; this.capacity=cap; }
    String getId() { return id; } String getName() { return name; } int getCapacity() { return capacity; }
}
class Booking { String id; MeetingRoom room; String organizer; TimeSlot slot;
    Booking(String id, MeetingRoom r, String org, TimeSlot s) { this.id=id; room=r; organizer=org; slot=s; }
}
class MeetingScheduler {
    List<MeetingRoom> rooms = new ArrayList<>();
    Map<String, List<Booking>> bookings = new HashMap<>(); int counter = 0;
    void addRoom(MeetingRoom r) { rooms.add(r); bookings.put(r.getId(), new ArrayList<>()); }
    synchronized Booking book(String roomId, String org, TimeSlot slot) {
        for (Booking b : bookings.get(roomId))
            if (b.slot.overlaps(slot)) { System.out.println("  [ERROR] Conflict"); return null; }
        MeetingRoom room = rooms.stream().filter(r->r.getId().equals(roomId)).findFirst().orElse(null);
        Booking b = new Booking("BK-"+(++counter), room, org, slot);
        bookings.get(roomId).add(b);
        System.out.println("  Booked "+room.getName()+" for "+org+" at "+slot.toString2());
        return b;
    }
    void cancel(String bookingId) {
        for (List<Booking> bks : bookings.values()) bks.removeIf(b->b.id.equals(bookingId));
        System.out.println("  Cancelled "+bookingId);
    }
    List<MeetingRoom> findAvailable(TimeSlot slot, int minCap) {
        List<MeetingRoom> result = new ArrayList<>();
        for (MeetingRoom r : rooms) {
            if (r.getCapacity()<minCap) continue;
            boolean conflict = bookings.get(r.getId()).stream().anyMatch(b->b.slot.overlaps(slot));
            if (!conflict) result.add(r);
        }
        return result;
    }
}
public class MeetingRoomSystem {
    public static void main(String[] args) {
        System.out.println("=== Meeting Room — Java ===");
        MeetingScheduler s = new MeetingScheduler();
        s.addRoom(new MeetingRoom("R1","Board Room",20));
        s.addRoom(new MeetingRoom("R2","Huddle",6));
        s.book("R1","Alice",new TimeSlot(10,0,11,0));
        s.book("R1","Bob",new TimeSlot(10,30,11,30)); // Conflict!
        s.book("R1","Bob",new TimeSlot(11,0,12,0)); // OK
        System.out.println("Available 10-11: "+s.findAvailable(new TimeSlot(10,0,11,0),5).stream()
            .map(MeetingRoom::getName).reduce("",(a,b)->a+" "+b));
        System.out.println("=== Complete ===");
    }
}
// SUMMARY: Overlap formula: start1<end2 && start2<end1, synchronized booking
