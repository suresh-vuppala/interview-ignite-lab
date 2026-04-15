#include <string>
#include <vector>
#include <mutex>
#include <chrono>
#include <iostream>
#include <memory>
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
    Seat(int r, int c, SeatType t) : row(r), col(c), type(t) {}

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
        status = SeatStatus::AVAILABLE; lockedBy.clear(); lockExpiry = 0;
    }

    bool isAvailable() { lock_guard<mutex> lock(mtx); checkExpiry(); return status == SeatStatus::AVAILABLE; }
    string getPosition() const { return "R" + to_string(row) + "C" + to_string(col); }
    SeatType getType() const { return type; }
};

struct Movie {
    string id, title, genre;
    int durationMinutes;
};

class Show {
    string id;
    Movie movie;
    vector<vector<unique_ptr<Seat>>> seats;
    int rows, cols;
public:
    Show(string id, Movie movie, int rows, int cols)
        : id(move(id)), movie(move(movie)), rows(rows), cols(cols) {
        seats.resize(rows);
        for (int r = 0; r < rows; r++) {
            seats[r].resize(cols);
            for (int c = 0; c < cols; c++)
                seats[r][c] = make_unique<Seat>(r, c, r < 2 ? SeatType::VIP : r < 5 ? SeatType::PREMIUM : SeatType::REGULAR);
        }
    }

    vector<Seat*> getAvailableSeats() {
        vector<Seat*> avail;
        for (auto& row : seats) for (auto& s : row) if (s->isAvailable()) avail.push_back(s.get());
        return avail;
    }

    bool lockSeats(const vector<pair<int,int>>& positions, const string& userId) {
        constexpr long LOCK_DURATION = 5 * 60 * 1000; // 5 min
        vector<Seat*> locked;
        for (auto& [r, c] : positions) {
            if (!seats[r][c]->lock(userId, LOCK_DURATION)) {
                for (auto* s : locked) s->release(); // Rollback
                return false;
            }
            locked.push_back(seats[r][c].get());
        }
        return true;
    }

    bool confirmBooking(const vector<pair<int,int>>& positions, const string& userId) {
        for (auto& [r, c] : positions)
            if (!seats[r][c]->book(userId)) return false;
        return true;
    }
};
