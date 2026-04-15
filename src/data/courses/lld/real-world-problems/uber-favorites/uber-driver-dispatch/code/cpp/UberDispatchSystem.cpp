#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <memory>
using namespace std;

class Location {
    double lat, lng;
public:
    Location(double lat = 0, double lng = 0) : lat(lat), lng(lng) {}
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
    Driver(const string& id, const string& name, Location loc)
        : id(id), name(name), location(loc), status(DriverStatus::AVAILABLE), rating(5.0) {}
    const string& getId() const { return id; }
    const string& getName() const { return name; }
    const Location& getLocation() const { return location; }
    DriverStatus getStatus() const { return status; }
    void setStatus(DriverStatus s) { status = s; }
    double getRating() const { return rating; }
    void setLocation(Location l) { location = l; }
};

class Rider {
    string id, name;
    Location location;
public:
    Rider(const string& id, const string& name, Location loc)
        : id(id), name(name), location(loc) {}
    const string& getName() const { return name; }
    const Location& getLocation() const { return location; }
};

enum class RideStatus { REQUESTED, MATCHED, PICKED_UP, IN_PROGRESS, COMPLETED, CANCELLED };

class Ride {
    string rideId;
    Rider* rider;
    Driver* driver = nullptr;
    Location pickup, destination;
    RideStatus status;
    double fare = 0;
public:
    Ride(const string& id, Rider* rider, Location pickup, Location dest)
        : rideId(id), rider(rider), pickup(pickup), destination(dest), status(RideStatus::REQUESTED) {}
    void assignDriver(Driver* d) { driver = d; status = RideStatus::MATCHED; d->setStatus(DriverStatus::BUSY); }
    void complete(double f) { fare = f; status = RideStatus::COMPLETED; driver->setStatus(DriverStatus::AVAILABLE); }
    const Location& getPickup() const { return pickup; }
    const Location& getDestination() const { return destination; }
};

// ========== MATCHING STRATEGY ==========
class MatchingStrategy {
public:
    virtual ~MatchingStrategy() = default;
    virtual Driver* findDriver(const Location& pickup, vector<Driver*>& drivers) = 0;
};

class NearestDriverStrategy : public MatchingStrategy {
public:
    Driver* findDriver(const Location& pickup, vector<Driver*>& drivers) override {
        Driver* best = nullptr;
        double minDist = 1e18;
        for (auto* d : drivers) {
            if (d->getStatus() != DriverStatus::AVAILABLE) continue;
            double dist = d->getLocation().distanceTo(pickup);
            if (dist < minDist) { minDist = dist; best = d; }
        }
        return best;
    }
};

class HighestRatedStrategy : public MatchingStrategy {
    double maxRadius;
public:
    HighestRatedStrategy(double radius) : maxRadius(radius) {}
    Driver* findDriver(const Location& pickup, vector<Driver*>& drivers) override {
        Driver* best = nullptr;
        for (auto* d : drivers) {
            if (d->getStatus() != DriverStatus::AVAILABLE) continue;
            if (d->getLocation().distanceTo(pickup) > maxRadius) continue;
            if (!best || d->getRating() > best->getRating()) best = d;
        }
        return best;
    }
};

// ========== FARE CALCULATOR ==========
class FareCalculator {
    static constexpr double BASE_FARE = 2.50, PER_KM = 1.50, PER_MIN = 0.25;
public:
    double calculate(double distKm, double durMin, double surge) const {
        return (BASE_FARE + PER_KM * distKm + PER_MIN * durMin) * surge;
    }
};

// ========== RIDE SERVICE ==========
class RideService {
    vector<Driver*> drivers;
    unique_ptr<MatchingStrategy> strategy;
    FareCalculator fareCalc;
    int rideCounter = 0;
public:
    RideService(unique_ptr<MatchingStrategy> strat) : strategy(move(strat)) {}
    void registerDriver(Driver* d) { drivers.push_back(d); }
    
    unique_ptr<Ride> requestRide(Rider* rider, Location pickup, Location dest) {
        auto ride = make_unique<Ride>("RIDE-" + to_string(++rideCounter), rider, pickup, dest);
        Driver* driver = strategy->findDriver(pickup, drivers);
        if (!driver) { cout << "No drivers available" << endl; return nullptr; }
        ride->assignDriver(driver);
        cout << "Matched " << rider->getName() << " with driver " << driver->getName() << endl;
        return ride;
    }
};
