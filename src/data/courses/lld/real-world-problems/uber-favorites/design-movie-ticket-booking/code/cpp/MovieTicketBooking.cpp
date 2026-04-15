#include <iostream>
#include <string>
#include <vector>
#include <mutex>
#include <chrono>
using namespace std;

enum class SeatType { REGULAR, PREMIUM, VIP };
enum class SeatStatus { AVAILABLE, LOCKED, BOOKED };

class Seat {
    int row, col;
    SeatType type;
    SeatStatus status = SeatStatus::AVAILABLE;
    string lockedBy;
    long lockExpiry = 0;
    mutex mtx;
    
    void checkExpiry() {
        if (status == SeatStatus::LOCKED) {
            long now = chrono::duration_cast<chrono::milliseconds>(
                chrono::steady_clock::now().time_since_epoch()).count();
            if (now > lockExpiry) { status = SeatStatus::AVAILABLE; lockedBy.clear(); lockExpiry = 0; }
        }
    }
public:
    Seat(int r = 0, int c = 0, SeatType t = SeatType::REGULAR) : row(r), col(c), type(t) {}
    
    bool lock(const string& userId, long durationMs) {
        lock_guard<mutex> lock(mtx);
        checkExpiry();
        if (status != SeatStatus::AVAILABLE) return false;
        status = SeatStatus::LOCKED;
        lockedBy = userId;
        lockExpiry = chrono::duration_cast<chrono::milliseconds>(
            chrono::steady_clock::now().time_since_epoch()).count() + durationMs;
        return true;
    }
    
    bool book(const string& userId) {
        lock_guard<mutex> lock(mtx);
        if (status != SeatStatus::LOCKED || lockedBy != userId) return false;
        status = SeatStatus::BOOKED;
        return true;
    }
    
    void release() {
        lock_guard<mutex> lock(mtx);
        status = SeatStatus::AVAILABLE;
        lockedBy.clear();
        lockExpiry = 0;
    }
    
    bool isAvailable() { lock_guard<mutex> lock(mtx); checkExpiry(); return status == SeatStatus::AVAILABLE; }
    SeatType getType() const { return type; }
    string getPosition() const { return "R" + to_string(row) + "C" + to_string(col); }
};

class Movie {
    string id, title, genre;
    int durationMinutes;
public:
    Movie(const string& id, const string& title, const string& genre, int dur)
        : id(id), title(title), genre(genre), durationMinutes(dur) {}
    const string& getTitle() const { return title; }
};

class Show {
    string id;
    Movie* movie;
    vector<vector<Seat>> seats;
public:
    Show(const string& id, Movie* movie, int rows, int cols)
        : id(id), movie(movie), seats(rows, vector<Seat>(cols)) {
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                seats[r][c] = Seat(r, c, r < 2 ? SeatType::VIP : r < 5 ? SeatType::PREMIUM : SeatType::REGULAR);
    }
    
    vector<Seat*> getAvailableSeats() {
        vector<Seat*> avail;
        for (auto& row : seats) for (auto& s : row) if (s.isAvailable()) avail.push_back(&s);
        return avail;
    }
    
    bool lockSeats(vector<pair<int,int>>& positions, const string& userId) {
        long LOCK_DURATION = 5 * 60 * 1000;
        vector<Seat*> locked;
        for (auto& [r, c] : positions) {
            if (!seats[r][c].lock(userId, LOCK_DURATION)) {
                for (auto* s : locked) s->release();
                return false;
            }
            locked.push_back(&seats[r][c]);
        }
        return true;
    }
    
    bool confirmBooking(vector<pair<int,int>>& positions, const string& userId) {
        for (auto& [r, c] : positions)
            if (!seats[r][c].book(userId)) return false;
        return true;
    }
};

struct Booking {
    string id, userId;
    Show* show;
    vector<Seat*> seats;
    double totalPrice;
    string status = "CONFIRMED";
    
    void cancel() {
        status = "CANCELLED";
        for (auto* s : seats) s->release();
    }
};
