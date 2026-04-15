#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <mutex>
#include <chrono>
#include <atomic>
#include <stdexcept>

using namespace std;
using namespace chrono;

// ============================================================
// Enumerations
// ============================================================

enum class VehicleType {
    MOTORCYCLE,
    CAR,
    TRUCK
};

enum class SpotType {
    COMPACT,
    REGULAR,
    LARGE
};

enum class TicketStatus {
    ACTIVE,
    PAID,
    LOST
};

enum class PaymentMethod {
    CASH,
    CREDIT_CARD,
    DIGITAL_WALLET
};

// ============================================================
// Vehicle Class
// ============================================================

class Vehicle {
private:
    string licensePlate;
    VehicleType vehicleType;
    string color;

public:
    Vehicle(const string& plate, VehicleType type, const string& col)
        : licensePlate(plate), vehicleType(type), color(col) {}

    VehicleType getVehicleType() const { return vehicleType; }
    string getLicensePlate() const { return licensePlate; }
    string getColor() const { return color; }
};

// ============================================================
// ParkingSpot Class
// ============================================================

class ParkingSpot {
private:
    string spotId;
    SpotType spotType;
    int floor;
    atomic<bool> isOccupied;
    shared_ptr<Vehicle> vehicle;
    mutex spotMutex;  // Thread safety for spot assignment

public:
    ParkingSpot(const string& id, SpotType type, int floorNum)
        : spotId(id), spotType(type), floor(floorNum), isOccupied(false), vehicle(nullptr) {}

    // Check if vehicle can fit in this spot
    bool canFitVehicle(VehicleType vehicleType) const {
        switch (vehicleType) {
            case VehicleType::MOTORCYCLE:
                return true;  // Can park anywhere
            case VehicleType::CAR:
                return spotType == SpotType::REGULAR || spotType == SpotType::LARGE;
            case VehicleType::TRUCK:
                return spotType == SpotType::LARGE;
            default:
                return false;
        }
    }

    // Thread-safe vehicle assignment
    bool assignVehicle(shared_ptr<Vehicle> v) {
        lock_guard<mutex> lock(spotMutex);
        
        if (isOccupied) {
            return false;  // Already occupied
        }
        
        if (!canFitVehicle(v->getVehicleType())) {
            return false;  // Vehicle doesn't fit
        }
        
        vehicle = v;
        isOccupied = true;
        return true;
    }

    // Thread-safe vehicle removal
    void removeVehicle() {
        lock_guard<mutex> lock(spotMutex);
        vehicle = nullptr;
        isOccupied = false;
    }

    bool getIsOccupied() const { return isOccupied; }
    SpotType getSpotType() const { return spotType; }
    string getSpotId() const { return spotId; }
    int getFloor() const { return floor; }
};

// ============================================================
// ParkingTicket Class
// ============================================================

class ParkingTicket {
private:
    string ticketId;
    shared_ptr<Vehicle> vehicle;
    shared_ptr<ParkingSpot> spot;
    system_clock::time_point entryTime;
    system_clock::time_point exitTime;
    TicketStatus status;

public:
    ParkingTicket(const string& id, shared_ptr<Vehicle> v, shared_ptr<ParkingSpot> s)
        : ticketId(id), vehicle(v), spot(s), 
          entryTime(system_clock::now()), status(TicketStatus::ACTIVE) {}

    // Calculate parking duration in hours
    long calculateDuration() const {
        auto end = (status == TicketStatus::ACTIVE) ? system_clock::now() : exitTime;
        auto duration = duration_cast<hours>(end - entryTime).count();
        return max(1L, duration);  // Minimum 1 hour
    }

    void markExit() {
        exitTime = system_clock::now();
        status = TicketStatus::PAID;
    }

    string getTicketId() const { return ticketId; }
    shared_ptr<Vehicle> getVehicle() const { return vehicle; }
    shared_ptr<ParkingSpot> getSpot() const { return spot; }
    TicketStatus getStatus() const { return status; }
    void setStatus(TicketStatus s) { status = s; }
};

// ============================================================
// Strategy Pattern: Pricing Strategy
// ============================================================

class PricingStrategy {
public:
    virtual ~PricingStrategy() = default;
    virtual double calculateFee(VehicleType type, long hours) const = 0;
};

class HourlyPricingStrategy : public PricingStrategy {
public:
    double calculateFee(VehicleType type, long hours) const override {
        double hourlyRate;
        switch (type) {
            case VehicleType::MOTORCYCLE: hourlyRate = 2.0; break;
            case VehicleType::CAR: hourlyRate = 4.0; break;
            case VehicleType::TRUCK: hourlyRate = 6.0; break;
            default: hourlyRate = 4.0;
        }
        return hourlyRate * hours;
    }
};

// ============================================================
// Payment Class
// ============================================================

class Payment {
private:
    double amount;
    PaymentMethod paymentMethod;
    system_clock::time_point timestamp;
    bool processed;

public:
    Payment(double amt, PaymentMethod method)
        : amount(amt), paymentMethod(method), 
          timestamp(system_clock::now()), processed(false) {}

    bool processPayment() {
        // Simulate payment processing
        processed = true;
        cout << "Payment of $" << amount << " processed successfully." << endl;
        return true;
    }

    double getAmount() const { return amount; }
    bool isProcessed() const { return processed; }
};

// ============================================================
// Observer Pattern: DisplayBoard
// ============================================================

class DisplayBoard {
private:
    int floorNumber;
    map<SpotType, int> availableSpots;

public:
    DisplayBoard(int floor) : floorNumber(floor) {
        availableSpots[SpotType::COMPACT] = 0;
        availableSpots[SpotType::REGULAR] = 0;
        availableSpots[SpotType::LARGE] = 0;
    }

    void update(SpotType type, int count) {
        availableSpots[type] = count;
        display();
    }

    void display() const {
        cout << "Floor " << floorNumber << " - Available Spots: "
             << "Compact=" << availableSpots.at(SpotType::COMPACT) << ", "
             << "Regular=" << availableSpots.at(SpotType::REGULAR) << ", "
             << "Large=" << availableSpots.at(SpotType::LARGE) << endl;
    }
};

// ============================================================
// ParkingFloor Class
// ============================================================

class ParkingFloor {
private:
    int floorNumber;
    map<string, shared_ptr<ParkingSpot>> spots;
    shared_ptr<DisplayBoard> displayBoard;
    map<SpotType, atomic<int>> availableCount;
    mutex floorMutex;

public:
    ParkingFloor(int floor) : floorNumber(floor) {
        displayBoard = make_shared<DisplayBoard>(floor);
        availableCount[SpotType::COMPACT] = 0;
        availableCount[SpotType::REGULAR] = 0;
        availableCount[SpotType::LARGE] = 0;
    }

    void addSpot(shared_ptr<ParkingSpot> spot) {
        lock_guard<mutex> lock(floorMutex);
        spots[spot->getSpotId()] = spot;
        availableCount[spot->getSpotType()]++;
        updateDisplayBoard();
    }

    // Find available spot for vehicle type
    shared_ptr<ParkingSpot> getAvailableSpot(VehicleType vehicleType) {
        lock_guard<mutex> lock(floorMutex);
        
        for (auto& [id, spot] : spots) {
            if (!spot->getIsOccupied() && spot->canFitVehicle(vehicleType)) {
                return spot;
            }
        }
        return nullptr;
    }

    void updateDisplayBoard() {
        // Count available spots by type
        map<SpotType, int> counts;
        counts[SpotType::COMPACT] = 0;
        counts[SpotType::REGULAR] = 0;
        counts[SpotType::LARGE] = 0;

        for (const auto& [id, spot] : spots) {
            if (!spot->getIsOccupied()) {
                counts[spot->getSpotType()]++;
            }
        }

        // Update display board
        for (const auto& [type, count] : counts) {
            displayBoard->update(type, count);
        }
    }

    int getFloorNumber() const { return floorNumber; }
};

// ============================================================
// Singleton Pattern: ParkingLot
// ============================================================

class ParkingLot {
private:
    static ParkingLot* instance;
    static mutex instanceMutex;

    string name;
    string address;
    vector<shared_ptr<ParkingFloor>> floors;
    map<string, shared_ptr<ParkingTicket>> activeTickets;
    shared_ptr<PricingStrategy> pricingStrategy;
    atomic<int> ticketCounter;
    mutex lotMutex;

    // Private constructor for Singleton
    ParkingLot(const string& n, const string& addr)
        : name(n), address(addr), ticketCounter(0) {
        pricingStrategy = make_shared<HourlyPricingStrategy>();
    }

public:
    // Thread-safe Singleton instance
    static ParkingLot* getInstance(const string& name = "Main Parking Lot", 
                                   const string& address = "123 Main St") {
        if (instance == nullptr) {
            lock_guard<mutex> lock(instanceMutex);
            if (instance == nullptr) {
                instance = new ParkingLot(name, address);
            }
        }
        return instance;
    }

    void addFloor(shared_ptr<ParkingFloor> floor) {
        lock_guard<mutex> lock(lotMutex);
        floors.push_back(floor);
    }

    // Find available spot across all floors
    shared_ptr<ParkingSpot> getAvailableSpot(VehicleType vehicleType) {
        for (auto& floor : floors) {
            auto spot = floor->getAvailableSpot(vehicleType);
            if (spot != nullptr) {
                return spot;
            }
        }
        return nullptr;
    }

    // Process vehicle entry
    shared_ptr<ParkingTicket> processEntry(shared_ptr<Vehicle> vehicle) {
        lock_guard<mutex> lock(lotMutex);

        // Find available spot
        auto spot = getAvailableSpot(vehicle->getVehicleType());
        if (spot == nullptr) {
            throw runtime_error("No available spot for vehicle type");
        }

        // Assign vehicle to spot
        if (!spot->assignVehicle(vehicle)) {
            throw runtime_error("Failed to assign vehicle to spot");
        }

        // Generate ticket
        string ticketId = "T" + to_string(++ticketCounter);
        auto ticket = make_shared<ParkingTicket>(ticketId, vehicle, spot);
        activeTickets[ticketId] = ticket;

        cout << "Vehicle " << vehicle->getLicensePlate() 
             << " parked at spot " << spot->getSpotId() 
             << " on floor " << spot->getFloor() << endl;

        // Update display boards
        for (auto& floor : floors) {
            floor->updateDisplayBoard();
        }

        return ticket;
    }

    // Process vehicle exit
    shared_ptr<Payment> processExit(shared_ptr<ParkingTicket> ticket) {
        lock_guard<mutex> lock(lotMutex);

        if (ticket->getStatus() != TicketStatus::ACTIVE) {
            throw runtime_error("Ticket is not active");
        }

        // Calculate fee
        long hours = ticket->calculateDuration();
        double fee = pricingStrategy->calculateFee(
            ticket->getVehicle()->getVehicleType(), hours);

        // Create payment
        auto payment = make_shared<Payment>(fee, PaymentMethod::CREDIT_CARD);
        
        // Process payment
        if (payment->processPayment()) {
            // Mark ticket as paid
            ticket->markExit();
            
            // Free the spot
            ticket->getSpot()->removeVehicle();
            
            // Remove from active tickets
            activeTickets.erase(ticket->getTicketId());

            cout << "Vehicle " << ticket->getVehicle()->getLicensePlate() 
                 << " exited. Duration: " << hours << " hours, Fee: $" << fee << endl;

            // Update display boards
            for (auto& floor : floors) {
                floor->updateDisplayBoard();
            }
        }

        return payment;
    }

    void displayStatus() {
        cout << "\n=== Parking Lot Status ===" << endl;
        cout << "Name: " << name << endl;
        cout << "Active Tickets: " << activeTickets.size() << endl;
        for (auto& floor : floors) {
            floor->updateDisplayBoard();
        }
        cout << "========================\n" << endl;
    }
};

// Initialize static members
ParkingLot* ParkingLot::instance = nullptr;
mutex ParkingLot::instanceMutex;

// ============================================================
// Main - Example Usage
// ============================================================

int main() {
    try {
        // Get parking lot instance (Singleton)
        ParkingLot* parkingLot = ParkingLot::getInstance("City Center Parking", "Downtown");

        // Create floors
        auto floor1 = make_shared<ParkingFloor>(1);
        auto floor2 = make_shared<ParkingFloor>(2);

        // Add spots to floor 1
        floor1->addSpot(make_shared<ParkingSpot>("F1-C1", SpotType::COMPACT, 1));
        floor1->addSpot(make_shared<ParkingSpot>("F1-C2", SpotType::COMPACT, 1));
        floor1->addSpot(make_shared<ParkingSpot>("F1-R1", SpotType::REGULAR, 1));
        floor1->addSpot(make_shared<ParkingSpot>("F1-R2", SpotType::REGULAR, 1));
        floor1->addSpot(make_shared<ParkingSpot>("F1-L1", SpotType::LARGE, 1));

        // Add spots to floor 2
        floor2->addSpot(make_shared<ParkingSpot>("F2-C1", SpotType::COMPACT, 2));
        floor2->addSpot(make_shared<ParkingSpot>("F2-R1", SpotType::REGULAR, 2));
        floor2->addSpot(make_shared<ParkingSpot>("F2-L1", SpotType::LARGE, 2));

        // Add floors to parking lot
        parkingLot->addFloor(floor1);
        parkingLot->addFloor(floor2);

        parkingLot->displayStatus();

        // Create vehicles
        auto car1 = make_shared<Vehicle>("ABC123", VehicleType::CAR, "Red");
        auto bike1 = make_shared<Vehicle>("XYZ789", VehicleType::MOTORCYCLE, "Black");
        auto truck1 = make_shared<Vehicle>("TRK456", VehicleType::TRUCK, "White");

        // Process entries
        auto ticket1 = parkingLot->processEntry(car1);
        auto ticket2 = parkingLot->processEntry(bike1);
        auto ticket3 = parkingLot->processEntry(truck1);

        parkingLot->displayStatus();

        // Simulate some time passing
        cout << "\n[Simulating time passage...]\n" << endl;

        // Process exits
        parkingLot->processExit(ticket1);
        parkingLot->processExit(ticket2);

        parkingLot->displayStatus();

        // Try to park another car
        auto car2 = make_shared<Vehicle>("DEF456", VehicleType::CAR, "Blue");
        auto ticket4 = parkingLot->processEntry(car2);

        parkingLot->displayStatus();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
