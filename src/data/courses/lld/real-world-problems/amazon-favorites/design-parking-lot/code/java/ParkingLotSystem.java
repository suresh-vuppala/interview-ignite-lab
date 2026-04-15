import java.time.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.atomic.*;
import java.util.concurrent.locks.*;

// ============================================================
// Enumerations
// ============================================================

enum VehicleType {
    MOTORCYCLE, CAR, TRUCK
}

enum SpotType {
    COMPACT, REGULAR, LARGE
}

enum TicketStatus {
    ACTIVE, PAID, LOST
}

enum PaymentMethod {
    CASH, CREDIT_CARD, DIGITAL_WALLET
}

// ============================================================
// Vehicle Class
// ============================================================

class Vehicle {
    private final String licensePlate;
    private final VehicleType vehicleType;
    private final String color;

    public Vehicle(String licensePlate, VehicleType vehicleType, String color) {
        this.licensePlate = licensePlate;
        this.vehicleType = vehicleType;
        this.color = color;
    }

    public VehicleType getVehicleType() { return vehicleType; }
    public String getLicensePlate() { return licensePlate; }
    public String getColor() { return color; }
}

// ============================================================
// ParkingSpot Class
// ============================================================

class ParkingSpot {
    private final String spotId;
    private final SpotType spotType;
    private final int floor;
    private final AtomicBoolean isOccupied;
    private Vehicle vehicle;
    private final ReentrantLock spotLock;  // Thread safety

    public ParkingSpot(String spotId, SpotType spotType, int floor) {
        this.spotId = spotId;
        this.spotType = spotType;
        this.floor = floor;
        this.isOccupied = new AtomicBoolean(false);
        this.vehicle = null;
        this.spotLock = new ReentrantLock();
    }

    // Check if vehicle can fit in this spot
    public boolean canFitVehicle(VehicleType vehicleType) {
        switch (vehicleType) {
            case MOTORCYCLE:
                return true;  // Can park anywhere
            case CAR:
                return spotType == SpotType.REGULAR || spotType == SpotType.LARGE;
            case TRUCK:
                return spotType == SpotType::LARGE;
            default:
                return false;
        }
    }

    // Thread-safe vehicle assignment
    public boolean assignVehicle(Vehicle vehicle) {
        spotLock.lock();
        try {
            if (isOccupied.get()) {
                return false;  // Already occupied
            }
            
            if (!canFitVehicle(vehicle.getVehicleType())) {
                return false;  // Vehicle doesn't fit
            }
            
            this.vehicle = vehicle;
            isOccupied.set(true);
            return true;
        } finally {
            spotLock.unlock();
        }
    }

    // Thread-safe vehicle removal
    public void removeVehicle() {
        spotLock.lock();
        try {
            this.vehicle = null;
            isOccupied.set(false);
        } finally {
            spotLock.unlock();
        }
    }

    public boolean isOccupied() { return isOccupied.get(); }
    public SpotType getSpotType() { return spotType; }
    public String getSpotId() { return spotId; }
    public int getFloor() { return floor; }
}

// ============================================================
// ParkingTicket Class
// ============================================================

class ParkingTicket {
    private final String ticketId;
    private final Vehicle vehicle;
    private final ParkingSpot spot;
    private final LocalDateTime entryTime;
    private LocalDateTime exitTime;
    private TicketStatus status;

    public ParkingTicket(String ticketId, Vehicle vehicle, ParkingSpot spot) {
        this.ticketId = ticketId;
        this.vehicle = vehicle;
        this.spot = spot;
        this.entryTime = LocalDateTime.now();
        this.status = TicketStatus.ACTIVE;
    }

    // Calculate parking duration in hours
    public long calculateDuration() {
        LocalDateTime end = (status == TicketStatus.ACTIVE) ? LocalDateTime.now() : exitTime;
        long hours = Duration.between(entryTime, end).toHours();
        return Math.max(1, hours);  // Minimum 1 hour
    }

    public void markExit() {
        this.exitTime = LocalDateTime.now();
        this.status = TicketStatus.PAID;
    }

    public String getTicketId() { return ticketId; }
    public Vehicle getVehicle() { return vehicle; }
    public ParkingSpot getSpot() { return spot; }
    public TicketStatus getStatus() { return status; }
    public void setStatus(TicketStatus status) { this.status = status; }
}

// ============================================================
// Strategy Pattern: Pricing Strategy
// ============================================================

interface PricingStrategy {
    double calculateFee(VehicleType type, long hours);
}

class HourlyPricingStrategy implements PricingStrategy {
    @Override
    public double calculateFee(VehicleType type, long hours) {
        double hourlyRate;
        switch (type) {
            case MOTORCYCLE: hourlyRate = 2.0; break;
            case CAR: hourlyRate = 4.0; break;
            case TRUCK: hourlyRate = 6.0; break;
            default: hourlyRate = 4.0;
        }
        return hourlyRate * hours;
    }
}

// ============================================================
// Payment Class
// ============================================================

class Payment {
    private final double amount;
    private final PaymentMethod paymentMethod;
    private final LocalDateTime timestamp;
    private boolean processed;

    public Payment(double amount, PaymentMethod paymentMethod) {
        this.amount = amount;
        this.paymentMethod = paymentMethod;
        this.timestamp = LocalDateTime.now();
        this.processed = false;
    }

    public boolean processPayment() {
        // Simulate payment processing
        processed = true;
        System.out.println("Payment of $" + amount + " processed successfully.");
        return true;
    }

    public double getAmount() { return amount; }
    public boolean isProcessed() { return processed; }
}

// ============================================================
// Observer Pattern: DisplayBoard
// ============================================================

class DisplayBoard {
    private final int floorNumber;
    private final Map<SpotType, Integer> availableSpots;

    public DisplayBoard(int floorNumber) {
        this.floorNumber = floorNumber;
        this.availableSpots = new ConcurrentHashMap<>();
        availableSpots.put(SpotType.COMPACT, 0);
        availableSpots.put(SpotType.REGULAR, 0);
        availableSpots.put(SpotType.LARGE, 0);
    }

    public void update(SpotType type, int count) {
        availableSpots.put(type, count);
        display();
    }

    public void display() {
        System.out.println("Floor " + floorNumber + " - Available Spots: " +
                "Compact=" + availableSpots.get(SpotType.COMPACT) + ", " +
                "Regular=" + availableSpots.get(SpotType.REGULAR) + ", " +
                "Large=" + availableSpots.get(SpotType.LARGE));
    }
}

// ============================================================
// ParkingFloor Class
// ============================================================

class ParkingFloor {
    private final int floorNumber;
    private final Map<String, ParkingSpot> spots;
    private final DisplayBoard displayBoard;
    private final ReentrantReadWriteLock floorLock;

    public ParkingFloor(int floorNumber) {
        this.floorNumber = floorNumber;
        this.spots = new ConcurrentHashMap<>();
        this.displayBoard = new DisplayBoard(floorNumber);
        this.floorLock = new ReentrantReadWriteLock();
    }

    public void addSpot(ParkingSpot spot) {
        floorLock.writeLock().lock();
        try {
            spots.put(spot.getSpotId(), spot);
            updateDisplayBoard();
        } finally {
            floorLock.writeLock().unlock();
        }
    }

    // Find available spot for vehicle type
    public ParkingSpot getAvailableSpot(VehicleType vehicleType) {
        floorLock.readLock().lock();
        try {
            for (ParkingSpot spot : spots.values()) {
                if (!spot.isOccupied() && spot.canFitVehicle(vehicleType)) {
                    return spot;
                }
            }
            return null;
        } finally {
            floorLock.readLock().unlock();
        }
    }

    public void updateDisplayBoard() {
        // Count available spots by type
        Map<SpotType, Integer> counts = new EnumMap<>(SpotType.class);
        counts.put(SpotType.COMPACT, 0);
        counts.put(SpotType.REGULAR, 0);
        counts.put(SpotType.LARGE, 0);

        for (ParkingSpot spot : spots.values()) {
            if (!spot.isOccupied()) {
                counts.put(spot.getSpotType(), counts.get(spot.getSpotType()) + 1);
            }
        }

        // Update display board
        for (Map.Entry<SpotType, Integer> entry : counts.entrySet()) {
            displayBoard.update(entry.getKey(), entry.getValue());
        }
    }

    public int getFloorNumber() { return floorNumber; }
}

// ============================================================
// Singleton Pattern: ParkingLot
// ============================================================

class ParkingLot {
    private static volatile ParkingLot instance;
    private static final Object lock = new Object();

    private final String name;
    private final String address;
    private final List<ParkingFloor> floors;
    private final Map<String, ParkingTicket> activeTickets;
    private final PricingStrategy pricingStrategy;
    private final AtomicInteger ticketCounter;
    private final ReentrantLock lotLock;

    // Private constructor for Singleton
    private ParkingLot(String name, String address) {
        this.name = name;
        this.address = address;
        this.floors = new CopyOnWriteArrayList<>();
        this.activeTickets = new ConcurrentHashMap<>();
        this.pricingStrategy = new HourlyPricingStrategy();
        this.ticketCounter = new AtomicInteger(0);
        this.lotLock = new ReentrantLock();
    }

    // Thread-safe Singleton instance (Double-checked locking)
    public static ParkingLot getInstance(String name, String address) {
        if (instance == null) {
            synchronized (lock) {
                if (instance == null) {
                    instance = new ParkingLot(name, address);
                }
            }
        }
        return instance;
    }

    public static ParkingLot getInstance() {
        return getInstance("Main Parking Lot", "123 Main St");
    }

    public void addFloor(ParkingFloor floor) {
        floors.add(floor);
    }

    // Find available spot across all floors
    public ParkingSpot getAvailableSpot(VehicleType vehicleType) {
        for (ParkingFloor floor : floors) {
            ParkingSpot spot = floor.getAvailableSpot(vehicleType);
            if (spot != null) {
                return spot;
            }
        }
        return null;
    }

    // Process vehicle entry
    public ParkingTicket processEntry(Vehicle vehicle) throws Exception {
        lotLock.lock();
        try {
            // Find available spot
            ParkingSpot spot = getAvailableSpot(vehicle.getVehicleType());
            if (spot == null) {
                throw new Exception("No available spot for vehicle type");
            }

            // Assign vehicle to spot
            if (!spot.assignVehicle(vehicle)) {
                throw new Exception("Failed to assign vehicle to spot");
            }

            // Generate ticket
            String ticketId = "T" + ticketCounter.incrementAndGet();
            ParkingTicket ticket = new ParkingTicket(ticketId, vehicle, spot);
            activeTickets.put(ticketId, ticket);

            System.out.println("Vehicle " + vehicle.getLicensePlate() +
                    " parked at spot " + spot.getSpotId() +
                    " on floor " + spot.getFloor());

            // Update display boards
            for (ParkingFloor floor : floors) {
                floor.updateDisplayBoard();
            }

            return ticket;
        } finally {
            lotLock.unlock();
        }
    }

    // Process vehicle exit
    public Payment processExit(ParkingTicket ticket) throws Exception {
        lotLock.lock();
        try {
            if (ticket.getStatus() != TicketStatus.ACTIVE) {
                throw new Exception("Ticket is not active");
            }

            // Calculate fee
            long hours = ticket.calculateDuration();
            double fee = pricingStrategy.calculateFee(ticket.getVehicle().getVehicleType(), hours);

            // Create payment
            Payment payment = new Payment(fee, PaymentMethod.CREDIT_CARD);

            // Process payment
            if (payment.processPayment()) {
                // Mark ticket as paid
                ticket.markExit();

                // Free the spot
                ticket.getSpot().removeVehicle();

                // Remove from active tickets
                activeTickets.remove(ticket.getTicketId());

                System.out.println("Vehicle " + ticket.getVehicle().getLicensePlate() +
                        " exited. Duration: " + hours + " hours, Fee: $" + fee);

                // Update display boards
                for (ParkingFloor floor : floors) {
                    floor.updateDisplayBoard();
                }
            }

            return payment;
        } finally {
            lotLock.unlock();
        }
    }

    public void displayStatus() {
        System.out.println("\n=== Parking Lot Status ===");
        System.out.println("Name: " + name);
        System.out.println("Active Tickets: " + activeTickets.size());
        for (ParkingFloor floor : floors) {
            floor.updateDisplayBoard();
        }
        System.out.println("========================\n");
    }
}

// ============================================================
// Main - Example Usage
// ============================================================

public class ParkingLotSystem {
    public static void main(String[] args) {
        try {
            // Get parking lot instance (Singleton)
            ParkingLot parkingLot = ParkingLot.getInstance("City Center Parking", "Downtown");

            // Create floors
            ParkingFloor floor1 = new ParkingFloor(1);
            ParkingFloor floor2 = new ParkingFloor(2);

            // Add spots to floor 1
            floor1.addSpot(new ParkingSpot("F1-C1", SpotType.COMPACT, 1));
            floor1.addSpot(new ParkingSpot("F1-C2", SpotType.COMPACT, 1));
            floor1.addSpot(new ParkingSpot("F1-R1", SpotType.REGULAR, 1));
            floor1.addSpot(new ParkingSpot("F1-R2", SpotType.REGULAR, 1));
            floor1.addSpot(new ParkingSpot("F1-L1", SpotType.LARGE, 1));

            // Add spots to floor 2
            floor2.addSpot(new ParkingSpot("F2-C1", SpotType.COMPACT, 2));
            floor2.addSpot(new ParkingSpot("F2-R1", SpotType.REGULAR, 2));
            floor2.addSpot(new ParkingSpot("F2-L1", SpotType.LARGE, 2));

            // Add floors to parking lot
            parkingLot.addFloor(floor1);
            parkingLot.addFloor(floor2);

            parkingLot.displayStatus();

            // Create vehicles
            Vehicle car1 = new Vehicle("ABC123", VehicleType.CAR, "Red");
            Vehicle bike1 = new Vehicle("XYZ789", VehicleType.MOTORCYCLE, "Black");
            Vehicle truck1 = new Vehicle("TRK456", VehicleType.TRUCK, "White");

            // Process entries
            ParkingTicket ticket1 = parkingLot.processEntry(car1);
            ParkingTicket ticket2 = parkingLot.processEntry(bike1);
            ParkingTicket ticket3 = parkingLot.processEntry(truck1);

            parkingLot.displayStatus();

            // Simulate some time passing
            System.out.println("\n[Simulating time passage...]\n");
            Thread.sleep(1000);

            // Process exits
            parkingLot.processExit(ticket1);
            parkingLot.processExit(ticket2);

            parkingLot.displayStatus();

            // Try to park another car
            Vehicle car2 = new Vehicle("DEF456", VehicleType.CAR, "Blue");
            ParkingTicket ticket4 = parkingLot.processEntry(car2);

            parkingLot.displayStatus();

        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
