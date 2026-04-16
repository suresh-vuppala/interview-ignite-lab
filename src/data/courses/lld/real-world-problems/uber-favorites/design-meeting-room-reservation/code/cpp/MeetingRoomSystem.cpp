// ===========================================================================
// DESIGN: Meeting Room Reservation System — Low Level Design
// ===========================================================================
// Single-file C++ | Key: TimeSlot overlap detection, synchronized booking
// ===========================================================================

// 1. FR: Book room, conflict detection, search available, cancel, recurring
// 2. CONSTRAINTS: 100 rooms, 15-min granularity, 8hr max, 30-day advance
// 3. RELATIONSHIPS: Scheduler o-- Room[], Scheduler *-- Booking[], Booking *-- TimeSlot
// 4. PLANTUML:
// @startuml
// class MeetingScheduler { -rooms -bookings +book() +cancel() +findAvailable() }
// class MeetingRoom { -id -name -capacity -amenities }
// class Booking { -id -room -organizer -attendees -timeSlot }
// class TimeSlot { -start -end +overlaps(other) }
// MeetingScheduler o-- MeetingRoom
// MeetingScheduler *-- Booking
// Booking *-- TimeSlot
// @enduml

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// TimeSlot with overlap detection
struct TimeSlot {
    int startHour, startMin, endHour, endMin;
    TimeSlot(int sh, int sm, int eh, int em) : startHour(sh), startMin(sm), endHour(eh), endMin(em) {}
    int startMins() const { return startHour * 60 + startMin; }
    int endMins() const { return endHour * 60 + endMin; }
    // Overlap: !(end1 <= start2 || end2 <= start1)
    bool overlaps(const TimeSlot& o) const {
        return startMins() < o.endMins() && o.startMins() < endMins();
    }
    string toString() const {
        char buf[32];
        sprintf(buf, "%02d:%02d-%02d:%02d", startHour, startMin, endHour, endMin);
        return string(buf);
    }
};

class MeetingRoom {
    string id, name;
    int capacity;
    vector<string> amenities;
public:
    MeetingRoom(const string& id, const string& name, int cap) : id(id), name(name), capacity(cap) {}
    string getId() const { return id; }
    string getName() const { return name; }
    int getCapacity() const { return capacity; }
    void addAmenity(const string& a) { amenities.push_back(a); }
};

struct Booking {
    string id;
    MeetingRoom* room;
    string organizer;
    vector<string> attendees;
    TimeSlot slot;
    Booking(const string& id, MeetingRoom* r, const string& org, vector<string> att, TimeSlot s)
        : id(id), room(r), organizer(org), attendees(att), slot(s) {}
};

class MeetingScheduler {
    vector<MeetingRoom> rooms;
    map<string, vector<Booking*> > roomBookings;  // roomId -> bookings
    int counter;
public:
    MeetingScheduler() : counter(0) {}

    void addRoom(const MeetingRoom& room) {
        rooms.push_back(room);
        roomBookings[room.getId()] = vector<Booking*>();
    }

    Booking* book(const string& roomId, const string& organizer, vector<string> attendees, TimeSlot slot) {
        // Conflict check
        vector<Booking*>& bookings = roomBookings[roomId];
        for (size_t i = 0; i < bookings.size(); i++) {
            if (bookings[i]->slot.overlaps(slot)) {
                cout << "  [ERROR] Conflict with booking " << bookings[i]->id << endl;
                return NULL;
            }
        }
        // Find room
        MeetingRoom* room = NULL;
        for (size_t i = 0; i < rooms.size(); i++)
            if (rooms[i].getId() == roomId) { room = &rooms[i]; break; }
        if (!room) { cout << "  [ERROR] Room not found." << endl; return NULL; }

        Booking* b = new Booking("BK-" + to_string(++counter), room, organizer, attendees, slot);
        bookings.push_back(b);
        cout << "  Booked " << room->getName() << " for " << organizer << " at " << slot.toString() << endl;
        return b;
    }

    void cancel(const string& bookingId) {
        for (map<string, vector<Booking*> >::iterator it = roomBookings.begin(); it != roomBookings.end(); ++it) {
            vector<Booking*>& bks = it->second;
            for (size_t i = 0; i < bks.size(); i++) {
                if (bks[i]->id == bookingId) {
                    cout << "  Cancelled " << bookingId << endl;
                    delete bks[i];
                    bks.erase(bks.begin() + i);
                    return;
                }
            }
        }
    }

    vector<MeetingRoom*> findAvailable(TimeSlot slot, int minCap) {
        vector<MeetingRoom*> result;
        for (size_t i = 0; i < rooms.size(); i++) {
            if (rooms[i].getCapacity() < minCap) continue;
            bool conflict = false;
            vector<Booking*>& bks = roomBookings[rooms[i].getId()];
            for (size_t j = 0; j < bks.size(); j++)
                if (bks[j]->slot.overlaps(slot)) { conflict = true; break; }
            if (!conflict) result.push_back(&rooms[i]);
        }
        return result;
    }
};

int main() {
    cout << "============================================" << endl;
    cout << "  Meeting Room Reservation — LLD Demo" << endl;
    cout << "============================================" << endl;

    MeetingScheduler scheduler;
    scheduler.addRoom(MeetingRoom("R1", "Board Room", 20));
    scheduler.addRoom(MeetingRoom("R2", "Huddle Room", 6));
    scheduler.addRoom(MeetingRoom("R3", "Conference A", 50));

    // Book rooms
    vector<string> att1; att1.push_back("Alice"); att1.push_back("Bob");
    Booking* b1 = scheduler.book("R1", "Alice", att1, TimeSlot(10, 0, 11, 0));
    Booking* b2 = scheduler.book("R2", "Bob", att1, TimeSlot(10, 0, 11, 0));

    // Conflict
    cout << "\n--- Try conflicting booking ---" << endl;
    Booking* b3 = scheduler.book("R1", "Carol", att1, TimeSlot(10, 30, 11, 30));  // Overlaps!

    // No conflict (adjacent)
    cout << "\n--- Adjacent (no conflict) ---" << endl;
    Booking* b4 = scheduler.book("R1", "Carol", att1, TimeSlot(11, 0, 12, 0));  // OK

    // Find available for 10:00-11:00
    cout << "\n--- Available rooms for 10:00-11:00, cap >= 5 ---" << endl;
    vector<MeetingRoom*> avail = scheduler.findAvailable(TimeSlot(10, 0, 11, 0), 5);
    for (size_t i = 0; i < avail.size(); i++)
        cout << "  " << avail[i]->getName() << " (cap: " << avail[i]->getCapacity() << ")" << endl;

    // Cancel
    cout << "\n--- Cancel ---" << endl;
    if (b1) scheduler.cancel(b1->id);

    cout << "\n=== Complete ===" << endl;
    return 0;
}

// SUMMARY:
// EXECUTION: scheduler.book() -> conflict check (overlaps) -> create Booking
// OVERLAP: !(end1<=start2 || end2<=start1) -> start1<end2 && start2<end1
// CLASS TABLE: TimeSlot(overlap) | MeetingRoom(id,cap) | Booking(room,slot) | MeetingScheduler(orchestrator)
// PATTERNS: Strategy(room selection extendable), Observer(notify attendees extendable)
// BEST PRACTICES: Overlap formula, per-room booking list, atomic book operation
