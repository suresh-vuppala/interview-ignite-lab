#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <mutex>
using namespace std;

struct TimeSlot {
    int startHour, startMin, endHour, endMin; // Simplified to hour:min
    bool overlaps(const TimeSlot& other) const {
        int s1 = startHour * 60 + startMin, e1 = endHour * 60 + endMin;
        int s2 = other.startHour * 60 + other.startMin, e2 = other.endHour * 60 + other.endMin;
        return s1 < e2 && s2 < e1;
    }
};

class MeetingRoom {
    string id, name;
    int capacity, floor;
    unordered_set<string> amenities;
public:
    MeetingRoom(const string& id, const string& name, int cap, int floor, 
                initializer_list<string> amens)
        : id(id), name(name), capacity(cap), floor(floor), amenities(amens) {}
    const string& getId() const { return id; }
    const string& getName() const { return name; }
    int getCapacity() const { return capacity; }
    bool hasAmenity(const string& a) const { return amenities.count(a); }
};

struct Booking {
    string id;
    MeetingRoom* room;
    string organizer;
    vector<string> attendees;
    TimeSlot slot;
};

class MeetingScheduler {
    vector<MeetingRoom> rooms;
    unordered_map<string, vector<Booking>> roomBookings;
    int bookingCounter = 0;
    mutex mtx;
public:
    void addRoom(MeetingRoom room) {
        roomBookings[room.getId()] = {};
        rooms.push_back(move(room));
    }
    
    Booking book(const string& roomId, const string& organizer, 
                 vector<string> attendees, TimeSlot slot) {
        lock_guard<mutex> lock(mtx);
        auto& bookings = roomBookings.at(roomId);
        for (auto& b : bookings)
            if (b.slot.overlaps(slot))
                throw runtime_error("Room already booked for this time");
        
        MeetingRoom* room = nullptr;
        for (auto& r : rooms) if (r.getId() == roomId) { room = &r; break; }
        if (!room) throw runtime_error("Room not found");
        
        Booking booking{"BK-" + to_string(++bookingCounter), room, organizer, move(attendees), slot};
        bookings.push_back(booking);
        cout << "Booked " << room->getName() << " for " << organizer << endl;
        return booking;
    }
    
    void cancel(const string& bookingId) {
        lock_guard<mutex> lock(mtx);
        for (auto& [roomId, bookings] : roomBookings)
            bookings.erase(remove_if(bookings.begin(), bookings.end(),
                [&](const Booking& b) { return b.id == bookingId; }), bookings.end());
    }
    
    vector<MeetingRoom*> findAvailable(TimeSlot slot, int minCapacity) {
        vector<MeetingRoom*> result;
        for (auto& r : rooms) {
            if (r.getCapacity() < minCapacity) continue;
            bool conflict = false;
            for (auto& b : roomBookings[r.getId()])
                if (b.slot.overlaps(slot)) { conflict = true; break; }
            if (!conflict) result.push_back(&r);
        }
        return result;
    }
};
