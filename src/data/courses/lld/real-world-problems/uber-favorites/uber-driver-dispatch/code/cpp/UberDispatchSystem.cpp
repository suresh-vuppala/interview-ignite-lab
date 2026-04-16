// ===========================================================================
// DESIGN: Uber Driver Dispatch System — Low Level Design
// ===========================================================================
// Single-file C++ | Patterns: Strategy, Observer, State
// ===========================================================================

// 1. FUNCTIONAL REQUIREMENTS
// FR1: Rider requests ride — pickup location, destination
// FR2: Find nearby available drivers within radius
// FR3: Match rider to driver using configurable strategy (nearest/rated)
// FR4: Driver accept/reject with timeout -> try next
// FR5: Ride lifecycle: Requested→Matched→PickedUp→Completed
// FR6: Fare calculation: base + distance*rate + time*rate * surge

// 2. CONSTRAINTS: 5km radius, 30s accept timeout, max 3 attempts
// 3. RELATIONSHIPS:
//   RideService --uses--> MatchingStrategy (Strategy), RideService o-- Driver[]
//   Ride --> Rider + Driver + Location, NearestDriver/HighestRated impl Strategy
// 4. PLANTUML:
// @startuml
// class RideService { -drivers -strategy:MatchingStrategy -fareCalc }
// interface MatchingStrategy { +findDriver(pickup, drivers) }
// class NearestDriverStrategy
// class HighestRatedStrategy
// class Ride { -rider -driver -pickup -dest -status -fare }
// class Driver { -id -location -status -rating }
// class Rider { -id -location }
// class Location { -lat -lng +distanceTo() }
// class FareCalculator { +calculate(dist, time, surge) }
// MatchingStrategy <|.. NearestDriverStrategy
// MatchingStrategy <|.. HighestRatedStrategy
// RideService ..> MatchingStrategy
// RideService o-- Driver
// Ride --> Rider
// Ride --> Driver
// @enduml

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

// Location with distance calculation
class Location {
    double lat, lng;
public:
    Location(double lat = 0, double lng = 0) : lat(lat), lng(lng) {}
    double distanceTo(const Location& o) const {
        return sqrt((lat-o.lat)*(lat-o.lat) + (lng-o.lng)*(lng-o.lng));
    }
    void display() const { printf("(%.2f, %.2f)", lat, lng); }
};

enum DriverStatus { AVAILABLE, BUSY, OFFLINE };
enum RideStatus { REQUESTED, MATCHED, PICKED_UP, IN_PROGRESS, COMPLETED, CANCELLED };

// Driver entity
class Driver {
    string id, name;
    Location location;
    DriverStatus status;
    double rating;
public:
    Driver(const string& id, const string& name, Location loc)
        : id(id), name(name), location(loc), status(AVAILABLE), rating(5.0) {}
    string getId() const { return id; }
    string getName() const { return name; }
    Location getLocation() const { return location; }
    DriverStatus getStatus() const { return status; }
    void setStatus(DriverStatus s) { status = s; }
    double getRating() const { return rating; }
};

// Rider entity
class Rider {
    string id, name;
    Location location;
public:
    Rider(const string& id, const string& name, Location loc) : id(id), name(name), location(loc) {}
    string getName() const { return name; }
    Location getLocation() const { return location; }
};

// Ride entity with lifecycle
class Ride {
    string rideId;
    Rider* rider;
    Driver* driver;
    Location pickup, destination;
    RideStatus status;
    double fare;
public:
    Ride(const string& id, Rider* r, Location p, Location d)
        : rideId(id), rider(r), driver(NULL), pickup(p), destination(d), status(REQUESTED), fare(0) {}
    void assignDriver(Driver* d) { driver = d; status = MATCHED; d->setStatus(BUSY); }
    void complete(double f) { fare = f; status = COMPLETED; if(driver) driver->setStatus(AVAILABLE); }
    Location getPickup() const { return pickup; }
    Location getDestination() const { return destination; }
    double getFare() const { return fare; }
    void display() const {
        cout << "  Ride " << rideId << ": " << rider->getName();
        if(driver) cout << " -> Driver: " << driver->getName();
        printf(" | Fare: $%.2f | Status: %d\n", fare, status);
    }
};

// ========== MATCHING STRATEGY (Strategy Pattern) ==========
class MatchingStrategy {
public:
    virtual ~MatchingStrategy() {}
    virtual Driver* findDriver(const Location& pickup, vector<Driver*>& drivers) = 0;
    virtual string describe() const = 0;
};

// Nearest available driver
class NearestDriverStrategy : public MatchingStrategy {
public:
    Driver* findDriver(const Location& pickup, vector<Driver*>& drivers) {
        Driver* best = NULL;
        double minDist = 1e18;
        for (size_t i = 0; i < drivers.size(); i++) {
            if (drivers[i]->getStatus() != AVAILABLE) continue;
            double dist = drivers[i]->getLocation().distanceTo(pickup);
            if (dist < minDist) { minDist = dist; best = drivers[i]; }
        }
        return best;
    }
    string describe() const { return "NearestDriver"; }
};

// Highest rated within radius
class HighestRatedStrategy : public MatchingStrategy {
    double maxRadius;
public:
    HighestRatedStrategy(double r) : maxRadius(r) {}
    Driver* findDriver(const Location& pickup, vector<Driver*>& drivers) {
        Driver* best = NULL;
        for (size_t i = 0; i < drivers.size(); i++) {
            if (drivers[i]->getStatus() != AVAILABLE) continue;
            if (drivers[i]->getLocation().distanceTo(pickup) > maxRadius) continue;
            if (!best || drivers[i]->getRating() > best->getRating()) best = drivers[i];
        }
        return best;
    }
    string describe() const { return "HighestRated"; }
};

// Fare calculator
class FareCalculator {
    double baseFare, perKm, perMin;
public:
    FareCalculator(double base = 2.50, double km = 1.50, double min = 0.25)
        : baseFare(base), perKm(km), perMin(min) {}
    double calculate(double dist, double dur, double surge) const {
        return (baseFare + perKm * dist + perMin * dur) * surge;
    }
};

// Ride Service — orchestrator
class RideService {
    vector<Driver*> drivers;
    MatchingStrategy* strategy;
    FareCalculator fareCalc;
    int rideCounter;
public:
    RideService(MatchingStrategy* strat) : strategy(strat), rideCounter(0) {}
    void registerDriver(Driver* d) { drivers.push_back(d); }
    void setStrategy(MatchingStrategy* s) { strategy = s; }

    Ride* requestRide(Rider* rider, Location pickup, Location dest) {
        Ride* ride = new Ride("RIDE-" + to_string(++rideCounter), rider, pickup, dest);
        cout << "  Ride requested by " << rider->getName() << " [" << strategy->describe() << "]" << endl;
        Driver* driver = strategy->findDriver(pickup, drivers);
        if (!driver) {
            cout << "  [ERROR] No drivers available." << endl;
            return ride;
        }
        ride->assignDriver(driver);
        cout << "  Matched with " << driver->getName() << endl;
        // Calculate fare
        double dist = pickup.distanceTo(dest);
        double fare = fareCalc.calculate(dist, dist * 2, 1.0); // simplified
        ride->complete(fare);
        printf("  Fare: $%.2f\n", fare);
        return ride;
    }
};

// ===========================================================================
// MAIN
// ===========================================================================
int main() {
    cout << "============================================" << endl;
    cout << "  Uber Driver Dispatch — LLD Demo" << endl;
    cout << "============================================" << endl;

    Driver d1("D1", "Alice Driver", Location(0, 0));
    Driver d2("D2", "Bob Driver", Location(1, 1));
    Driver d3("D3", "Carol Driver", Location(5, 5));
    Rider r1("R1", "Dave Rider", Location(0.5, 0.5));
    Rider r2("R2", "Eve Rider", Location(4, 4));

    // Nearest driver strategy
    NearestDriverStrategy nearest;
    RideService service(&nearest);
    service.registerDriver(&d1);
    service.registerDriver(&d2);
    service.registerDriver(&d3);

    cout << "\n--- Nearest Strategy ---" << endl;
    Ride* ride1 = service.requestRide(&r1, Location(0.5, 0.5), Location(3, 3));
    Ride* ride2 = service.requestRide(&r2, Location(4, 4), Location(8, 8));

    // Switch to highest rated strategy
    cout << "\n--- Highest Rated Strategy ---" << endl;
    HighestRatedStrategy rated(10.0);
    service.setStrategy(&rated);
    Ride* ride3 = service.requestRide(&r1, Location(0, 0), Location(2, 2));

    cout << "\n=== All scenarios complete ===" << endl;
    delete ride1; delete ride2; delete ride3;
    return 0;
}

// SUMMARY:
// EXECUTION FLOW: main() -> RideService(strategy) -> requestRide() -> strategy->findDriver() -> ride->assignDriver()
// METHOD CALL TREE: requestRide() -> strategy->findDriver(pickup, drivers) [Strategy] -> fareCalc.calculate()
// CLASS TABLE: Location|Driver|Rider|Ride|MatchingStrategy(i)|NearestDriver|HighestRated|FareCalculator|RideService
// PATTERNS: 1. Strategy->MatchingStrategy 2. Observer(extendable)->notify rider/driver 3. State->Ride lifecycle
// BEST PRACTICES: Encapsulation, Polymorphism, DIP(RideService depends on abstraction), OCP, SRP
