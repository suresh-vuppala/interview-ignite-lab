// DESIGN: Uber Driver Dispatch — LLD (Java) | Patterns: Strategy, State
// FR: Match riders to nearest/highest-rated drivers, fare calculation
// PLANTUML: (see C++ for full diagram)
import java.util.*;
import java.util.stream.*;

class Location {
    double lat, lng;
    Location(double lat, double lng) { this.lat = lat; this.lng = lng; }
    double distanceTo(Location o) { return Math.sqrt(Math.pow(lat-o.lat,2)+Math.pow(lng-o.lng,2)); }
}

enum DriverStatus { AVAILABLE, BUSY, OFFLINE }
enum RideStatus { REQUESTED, MATCHED, COMPLETED, CANCELLED }

class Driver {
    String id, name; Location location; DriverStatus status; double rating;
    Driver(String id, String name, Location loc) { this.id=id; this.name=name; this.location=loc; status=DriverStatus.AVAILABLE; rating=5.0; }
    String getName() { return name; } Location getLocation() { return location; }
    DriverStatus getStatus() { return status; } void setStatus(DriverStatus s) { status=s; }
    double getRating() { return rating; }
}

class Rider {
    String id, name; Location location;
    Rider(String id, String name, Location loc) { this.id=id; this.name=name; this.location=loc; }
    String getName() { return name; }
}

class Ride {
    String rideId; Rider rider; Driver driver; Location pickup, dest; RideStatus status; double fare;
    Ride(String id, Rider r, Location p, Location d) { rideId=id; rider=r; pickup=p; dest=d; status=RideStatus.REQUESTED; }
    void assignDriver(Driver d) { driver=d; status=RideStatus.MATCHED; d.setStatus(DriverStatus.BUSY); }
    void complete(double f) { fare=f; status=RideStatus.COMPLETED; if(driver!=null) driver.setStatus(DriverStatus.AVAILABLE); }
}

interface MatchingStrategy { Driver findDriver(Location pickup, List<Driver> drivers); String describe(); }

class NearestDriverStrategy implements MatchingStrategy {
    public Driver findDriver(Location pickup, List<Driver> drivers) {
        return drivers.stream().filter(d->d.getStatus()==DriverStatus.AVAILABLE)
            .min(Comparator.comparingDouble(d->d.getLocation().distanceTo(pickup))).orElse(null);
    }
    public String describe() { return "Nearest"; }
}

class HighestRatedStrategy implements MatchingStrategy {
    double maxRadius;
    HighestRatedStrategy(double r) { maxRadius=r; }
    public Driver findDriver(Location pickup, List<Driver> drivers) {
        return drivers.stream().filter(d->d.getStatus()==DriverStatus.AVAILABLE)
            .filter(d->d.getLocation().distanceTo(pickup)<=maxRadius)
            .max(Comparator.comparingDouble(Driver::getRating)).orElse(null);
    }
    public String describe() { return "HighestRated"; }
}

class FareCalculator {
    double baseFare=2.50, perKm=1.50, perMin=0.25;
    double calculate(double dist, double dur, double surge) { return (baseFare+perKm*dist+perMin*dur)*surge; }
}

class RideService {
    List<Driver> drivers = new ArrayList<>();
    MatchingStrategy strategy; FareCalculator fareCalc = new FareCalculator(); int counter = 0;
    RideService(MatchingStrategy s) { strategy=s; }
    void registerDriver(Driver d) { drivers.add(d); }
    void setStrategy(MatchingStrategy s) { strategy=s; }
    Ride requestRide(Rider rider, Location pickup, Location dest) {
        Ride ride = new Ride("RIDE-"+(++counter), rider, pickup, dest);
        System.out.println("  Request by "+rider.getName()+" ["+strategy.describe()+"]");
        Driver d = strategy.findDriver(pickup, drivers);
        if (d==null) { System.out.println("  [ERROR] No drivers"); return ride; }
        ride.assignDriver(d);
        double dist = pickup.distanceTo(dest);
        double fare = fareCalc.calculate(dist, dist*2, 1.0);
        ride.complete(fare);
        System.out.printf("  Matched %s. Fare: $%.2f%n", d.getName(), fare);
        return ride;
    }
}

public class UberDispatchSystem {
    public static void main(String[] args) {
        System.out.println("=== Uber Dispatch — Java ===");
        Driver d1=new Driver("D1","Alice",new Location(0,0));
        Driver d2=new Driver("D2","Bob",new Location(1,1));
        Rider r1=new Rider("R1","Dave",new Location(0.5,0.5));
        NearestDriverStrategy nearest = new NearestDriverStrategy();
        RideService svc = new RideService(nearest);
        svc.registerDriver(d1); svc.registerDriver(d2);
        svc.requestRide(r1, new Location(0.5,0.5), new Location(3,3));
        svc.requestRide(r1, new Location(0,0), new Location(5,5));
        System.out.println("=== Complete ===");
    }
}
// SUMMARY: Strategy(MatchingStrategy), FareCalculator, Ride lifecycle
