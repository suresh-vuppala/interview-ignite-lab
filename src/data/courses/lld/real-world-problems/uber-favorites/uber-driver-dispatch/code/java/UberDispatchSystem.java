// Uber Driver Dispatch System
import java.util.*;
import java.util.stream.*;

class Location {
    private double lat, lng;
    public Location(double lat, double lng) { this.lat = lat; this.lng = lng; }
    public double distanceTo(Location other) {
        return Math.sqrt(Math.pow(lat - other.lat, 2) + Math.pow(lng - other.lng, 2)); // Simplified
    }
}

enum DriverStatus { AVAILABLE, BUSY, OFFLINE }
class Driver {
    private String id, name;
    private Location location;
    private DriverStatus status;
    private double rating;
    public Driver(String id, String name, Location loc) {
        this.id = id; this.name = name; this.location = loc;
        this.status = DriverStatus.AVAILABLE; this.rating = 5.0;
    }
    public String getId() { return id; }
    public String getName() { return name; }
    public Location getLocation() { return location; }
    public DriverStatus getStatus() { return status; }
    public void setStatus(DriverStatus s) { this.status = s; }
    public double getRating() { return rating; }
    public void setLocation(Location l) { this.location = l; }
}

class Rider {
    private String id, name;
    private Location location;
    public Rider(String id, String name, Location loc) { this.id = id; this.name = name; this.location = loc; }
    public Location getLocation() { return location; }
    public String getName() { return name; }
}

enum RideStatus { REQUESTED, MATCHED, PICKED_UP, IN_PROGRESS, COMPLETED, CANCELLED }
class Ride {
    private String rideId;
    private Rider rider;
    private Driver driver;
    private Location pickup, destination;
    private RideStatus status;
    private double fare;
    
    public Ride(String id, Rider rider, Location pickup, Location dest) {
        this.rideId = id; this.rider = rider; this.pickup = pickup;
        this.destination = dest; this.status = RideStatus.REQUESTED;
    }
    public void assignDriver(Driver d) { this.driver = d; this.status = RideStatus.MATCHED; d.setStatus(DriverStatus.BUSY); }
    public void complete(double fare) { this.fare = fare; this.status = RideStatus.COMPLETED; driver.setStatus(DriverStatus.AVAILABLE); }
    public Location getPickup() { return pickup; }
    public Location getDestination() { return destination; }
    public RideStatus getStatus() { return status; }
}

// Strategy — matching algorithm
interface MatchingStrategy {
    Driver findDriver(Location pickup, List<Driver> drivers);
}

class NearestDriverStrategy implements MatchingStrategy {
    public Driver findDriver(Location pickup, List<Driver> drivers) {
        return drivers.stream()
            .filter(d -> d.getStatus() == DriverStatus.AVAILABLE)
            .min(Comparator.comparingDouble(d -> d.getLocation().distanceTo(pickup)))
            .orElse(null);
    }
}

class HighestRatedStrategy implements MatchingStrategy {
    private double maxRadius;
    public HighestRatedStrategy(double radius) { this.maxRadius = radius; }
    public Driver findDriver(Location pickup, List<Driver> drivers) {
        return drivers.stream()
            .filter(d -> d.getStatus() == DriverStatus.AVAILABLE)
            .filter(d -> d.getLocation().distanceTo(pickup) <= maxRadius)
            .max(Comparator.comparingDouble(Driver::getRating))
            .orElse(null);
    }
}

// Fare calculation
class FareCalculator {
    private static final double BASE_FARE = 2.50;
    private static final double PER_KM = 1.50;
    private static final double PER_MIN = 0.25;
    
    public double calculate(double distanceKm, double durationMin, double surgeMultiplier) {
        return (BASE_FARE + PER_KM * distanceKm + PER_MIN * durationMin) * surgeMultiplier;
    }
}

// Service
class RideService {
    private List<Driver> drivers = new ArrayList<>();
    private MatchingStrategy strategy;
    private FareCalculator fareCalc = new FareCalculator();
    private int rideCounter = 0;
    
    public RideService(MatchingStrategy strategy) { this.strategy = strategy; }
    public void registerDriver(Driver d) { drivers.add(d); }
    
    public Ride requestRide(Rider rider, Location pickup, Location destination) {
        Ride ride = new Ride("RIDE-" + (++rideCounter), rider, pickup, destination);
        Driver driver = strategy.findDriver(pickup, drivers);
        if (driver == null) { System.out.println("No drivers available"); return null; }
        ride.assignDriver(driver);
        System.out.println("Matched " + rider.getName() + " with driver " + driver.getName());
        return ride;
    }
}
