#include <string>
#include <vector>
#include <map>
#include <set>
#include <mutex>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <memory>
using namespace std;

struct MeetingRoom {
    string id, name;
    int capacity, floor;
    set<string> amenities;
    bool hasAmenity(const string& a) const { return amenities.count(a); }
};

struct TimeSlot {
    long startMin, endMin; // Minutes from epoch for simplicity
    bool overlaps(const TimeSlot& other) const {
        return startMin < other.endMin && other.startMin < endMin;
    }
};

struct Booking {
    string id;
    MeetingRoom* room;
    string organizer;
    vector<string> attendees;
    TimeSlot slot;
};

class MeetingScheduler {
    vector<unique_ptr<MeetingRoom>> rooms;
    map<string, vector<unique_ptr<Booking>>> roomBookings; // roomId -> bookings
    int bookingCounter = 0;
    mutex mtx;
public:
    void addRoom(unique_ptr<MeetingRoom> room) {
        roomBookings[room->id] = {};
        rooms.push_back(move(room));
    }

    Booking* book(const string& roomId, const string& organizer, vector<string> attendees, TimeSlot slot) {
        lock_guard<mutex> lock(mtx);
        auto it = roomBookings.find(roomId);
        if (it == roomBookings.end()) throw runtime_error("Room not found");
        for (auto& b : it->second)
            if (b->slot.overlaps(slot)) throw runtime_error("Room already booked");
        MeetingRoom* room = nullptr;
        for (auto& r : rooms) if (r->id == roomId) { room = r.get(); break; }
        auto booking = make_unique<Booking>();
        booking->id = "BK-" + to_string(++bookingCounter);
        booking->room = room;
        booking->organizer = organizer;
        booking->attendees = move(attendees);
        booking->slot = slot;
        auto* ptr = booking.get();
        it->second.push_back(move(booking));
        cout << "Booked " << room->name << " for " << organizer << endl;
        return ptr;
    }

    void cancel(const string& bookingId) {
        lock_guard<mutex> lock(mtx);
        for (auto& [rid, bookings] : roomBookings)
            bookings.erase(remove_if(bookings.begin(), bookings.end(),
                [&](auto& b) { return b->id == bookingId; }), bookings.end());
        cout << "Cancelled " << bookingId << endl;
    }

    vector<MeetingRoom*> findAvailable(TimeSlot slot, int minCapacity) {
        vector<MeetingRoom*> result;
        for (auto& r : rooms) {
            if (r->capacity < minCapacity) continue;
            bool free = true;
            for (auto& b : roomBookings[r->id])
                if (b->slot.overlaps(slot)) { free = false; break; }
            if (free) result.push_back(r.get());
        }
        return result;
    }
};
