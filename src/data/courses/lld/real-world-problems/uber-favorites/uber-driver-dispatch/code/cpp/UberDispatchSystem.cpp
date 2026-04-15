#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <memory>
using namespace std;

struct Location {
    double lat, lng;
    double distanceTo(const Location& other) const {
        return sqrt(pow(lat - other.lat, 2) + pow(lng - other.lng, 2));
    }
};

enum class DriverStatus { AVAILABLE, BUSY, OFFLINE };

class Driver {
    string id, name;
    Location location;
    DriverStatus status;
    double rating;
public:
    Driver(string id, string name, Location loc)
        : id(move(id)), name(move(name)), location(loc), status(DriverStatus::AVAILABLE), rating(5.0) {}
    const string& getId() const { return id; }
    const string& getName() const { return name; }
    const Location& getLocation() const { return location; }
    DriverStatus getStatus() const { return status; }
    void setStatus(DriverStatus s) { status = s; }
    double getRating() const { return rating; }
};

struct Rider {
    string id, name;
    Location location;
};

enum class RideStatus { REQUESTED, MATCHED, PICKED_UP, IN_PROGRESS, COMPLETED, CANCELLED };

class Ride {
    string rideId;
    Rider rider;
    Driver* driver = nullptr;
    Location pickup, destination;
    RideStatus status;
    double fare = 0;
public:
    Ride(string id, Rider rider, Location pickup, Location dest)
        : rideId(move(id)), rider(move(rider)), pickup(pickup), destination(dest), status(RideStatus::REQUESTED) {}
    void assignDriver(Driver* d) { driver = d; status = RideStatus::MATCHED; d->setStatus(DriverStatus::BUSY); }
    void complete(double f) { fare = f; status = RideStatus::COMPLETED; if (driver) driver->setStatus(DriverStatus::AVAILABLE); }
    const Location& getPickup() const { return pickup; }
    const Location& getDestination() const { return destination; }
};

// ========== MATCHING STRATEGY ==========
class MatchingStrategy {
public:
    virtual ~MatchingStrategy() = default;
    virtual Driver* findDriver(const Location& pickup, vector<unique_ptr<Driver>>& drivers) = 0;
};

class NearestDriverStrategy : public MatchingStrategy {
public:
    Driver* findDriver(const Location& pickup, vector<unique_ptr<Driver>>& drivers) override {
        Driver* best = nullptr;
        double bestDist = 1e18;
        for (auto& d : drivers) {
            if (d->getStatus() != DriverStatus::AVAILABLE) continue;
            double dist = d->getLocation().distanceTo(pickup);
            if (dist < bestDist) { bestDist = dist; best = d.get(); }
        }
        return best;
    }
};

class HighestRatedStrategy : public MatchingStrategy {
    double maxRadius;
public:
    HighestRatedStrategy(double radius) : maxRadius(radius) {}
    Driver* findDriver(const Location& pickup, vector<unique_ptr<Driver>>& drivers) override {
        Driver* best = nullptr;
        for (auto& d : drivers) {
            if (d->getStatus() != DriverStatus::AVAILABLE) continue;
            if (d->getLocation().distanceTo(pickup) > maxRadius) continue;
            if (!best || d->getRating() > best->getRating()) best = d.get();
        }
        return best;
    }
};

// ========== FARE CALCULATOR ==========
struct FareCalculator {
    static constexpr double BASE_FARE = 2.50, PER_KM = 1.50, PER_MIN = 0.25;
    static double calculate(double distKm, double durMin, double surge) {
        return (BASE_FARE + PER_KM * distKm + PER_MIN * durMin) * surge;
    }
};

// ========== RIDE SERVICE ==========
class RideService {
    vector<unique_ptr<Driver>> drivers;
    unique_ptr<MatchingStrategy> strategy;
    int rideCounter = 0;
public:
    RideService(unique_ptr<MatchingStrategy> s) : strategy(move(s)) {}
    void registerDriver(unique_ptr<Driver> d) { drivers.push_back(move(d)); }
    unique_ptr<Ride> requestRide(Rider rider, Location pickup, Location dest) {
        auto ride = make_unique<Ride>("RIDE-" + to_string(++rideCounter), rider, pickup, dest);
        Driver* driver = strategy->findDriver(pickup, drivers);
        if (!driver) { cout << "No drivers available" << endl; return nullptr; }
        ride->assignDriver(driver);
        cout << "Matched " << rider.name << " with driver " << driver->getName() << endl;
        return ride;
    }
};
