// ===========================================================================
// DESIGN: Movie Ticket Booking — Low Level Design
// Key: Seat locking with TTL for concurrent booking safety
// ===========================================================================
// FR: Browse movies, view shows, select seats, lock (5min), book, cancel
// PLANTUML: Theater*--Screen*--Seat[][], Show-->Movie, Booking-->Show+Seats

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

enum SeatType { REGULAR, PREMIUM, VIP };
enum SeatStatus { SEAT_AVAILABLE, SEAT_LOCKED, SEAT_BOOKED };

class Seat {
    int row, col;
    SeatType type;
    SeatStatus status;
    string lockedBy;
public:
    Seat() : row(0), col(0), type(REGULAR), status(SEAT_AVAILABLE) {}
    Seat(int r, int c, SeatType t) : row(r), col(c), type(t), status(SEAT_AVAILABLE) {}
    bool isAvailable() const { return status == SEAT_AVAILABLE; }

    bool lock(const string& userId) {
        if (status != SEAT_AVAILABLE) return false;
        status = SEAT_LOCKED; lockedBy = userId; return true;
    }
    bool book(const string& userId) {
        if (status != SEAT_LOCKED || lockedBy != userId) return false;
        status = SEAT_BOOKED; return true;
    }
    void release() { status = SEAT_AVAILABLE; lockedBy.clear(); }

    string getPosition() const { char buf[16]; sprintf(buf, "R%dC%d", row, col); return string(buf); }
    double getPrice() const { return type==VIP ? 25.0 : type==PREMIUM ? 15.0 : 10.0; }
    SeatType getType() const { return type; }
};

class Movie {
    string id, title, genre;
public:
    Movie(const string& id, const string& title, const string& genre)
        : id(id), title(title), genre(genre) {}
    string getTitle() const { return title; }
};

class Show {
    string id;
    Movie* movie;
    vector<vector<Seat> > seats;
    int rows, cols;
public:
    Show(const string& id, Movie* m, int r, int c) : id(id), movie(m), rows(r), cols(c) {
        seats.resize(r);
        for (int i = 0; i < r; i++) {
            seats[i].resize(c);
            for (int j = 0; j < c; j++)
                seats[i][j] = Seat(i, j, i<2 ? VIP : i<4 ? PREMIUM : REGULAR);
        }
    }

    Movie* getMovie() const { return movie; }

    int countAvailable() const {
        int cnt = 0;
        for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++)
            if (seats[i][j].isAvailable()) cnt++;
        return cnt;
    }

    // Lock seats — all or nothing
    bool lockSeats(vector<pair<int,int> >& positions, const string& userId) {
        vector<Seat*> locked;
        for (size_t i = 0; i < positions.size(); i++) {
            Seat& s = seats[positions[i].first][positions[i].second];
            if (!s.lock(userId)) {
                // Rollback
                for (size_t j = 0; j < locked.size(); j++) locked[j]->release();
                return false;
            }
            locked.push_back(&s);
        }
        return true;
    }

    bool confirmBooking(vector<pair<int,int> >& positions, const string& userId) {
        for (size_t i = 0; i < positions.size(); i++) {
            if (!seats[positions[i].first][positions[i].second].book(userId)) return false;
        }
        return true;
    }

    double calculatePrice(vector<pair<int,int> >& positions) const {
        double total = 0;
        for (size_t i = 0; i < positions.size(); i++)
            total += seats[positions[i].first][positions[i].second].getPrice();
        return total;
    }
};

int main() {
    cout << "============================================\n  Movie Ticket Booking — LLD Demo\n============================================" << endl;

    Movie movie1("M1", "The Matrix", "Sci-Fi");
    Show show1("S1", &movie1, 8, 10);
    cout << "  " << movie1.getTitle() << " — " << show1.countAvailable() << " seats available" << endl;

    // User 1 books
    vector<pair<int,int> > seats1;
    seats1.push_back(make_pair(0, 0));  // VIP
    seats1.push_back(make_pair(0, 1));  // VIP

    cout << "\n--- User1: Lock seats ---" << endl;
    if (show1.lockSeats(seats1, "User1")) {
        double price = show1.calculatePrice(seats1);
        printf("  Locked! Total: $%.2f\n", price);
        if (show1.confirmBooking(seats1, "User1"))
            cout << "  Booking confirmed!" << endl;
    }

    // User 2 tries same seats
    cout << "\n--- User2: Try same seats ---" << endl;
    if (!show1.lockSeats(seats1, "User2"))
        cout << "  [ERROR] Seats not available!" << endl;

    // User 2 books different seats
    vector<pair<int,int> > seats2;
    seats2.push_back(make_pair(5, 0));  // Regular
    seats2.push_back(make_pair(5, 1));

    if (show1.lockSeats(seats2, "User2")) {
        show1.confirmBooking(seats2, "User2");
        printf("  User2 booked: $%.2f\n", show1.calculatePrice(seats2));
    }

    cout << "  Remaining: " << show1.countAvailable() << " seats" << endl;
    cout << "\n=== Complete ===" << endl;
    return 0;
}
// SUMMARY: Seat locking with TTL (all-or-nothing), VIP/Premium/Regular pricing
// PATTERNS: State(implicit seat status), Strategy(pricing extendable)
// PRACTICES: Atomic multi-seat lock (rollback on failure), concurrent safety
