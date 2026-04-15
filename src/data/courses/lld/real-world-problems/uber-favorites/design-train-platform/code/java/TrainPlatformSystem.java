// Train Platform Management
import java.util.*;

class Train {
    private String id, name;
    private int arrivalTime, departureTime; // Minutes from midnight
    public Train(String id, String name, int arr, int dep) {
        this.id = id; this.name = name; this.arrivalTime = arr; this.departureTime = dep;
    }
    public String getId() { return id; }
    public String getName() { return name; }
    public int getArrivalTime() { return arrivalTime; }
    public int getDepartureTime() { return departureTime; }
}

class Platform {
    private int id;
    private Train currentTrain;
    private List<Train> schedule = new ArrayList<>();
    public Platform(int id) { this.id = id; }
    public int getId() { return id; }
    public boolean isAvailable(int time) { return currentTrain == null || currentTrain.getDepartureTime() <= time; }
    public void assignTrain(Train t) { currentTrain = t; schedule.add(t); }
    public void releaseTrain() { currentTrain = null; }
    public Train getCurrentTrain() { return currentTrain; }
}

interface AllocationStrategy {
    Platform allocate(List<Platform> platforms, Train train);
}

class FirstAvailableStrategy implements AllocationStrategy {
    public Platform allocate(List<Platform> platforms, Train train) {
        return platforms.stream()
            .filter(p -> p.isAvailable(train.getArrivalTime()))
            .findFirst().orElse(null);
    }
}

class Station {
    private List<Platform> platforms = new ArrayList<>();
    private AllocationStrategy strategy;
    
    public Station(int numPlatforms, AllocationStrategy strategy) {
        this.strategy = strategy;
        for (int i = 1; i <= numPlatforms; i++) platforms.add(new Platform(i));
    }
    
    public Platform scheduleTrain(Train train) {
        // Release departed trains
        for (Platform p : platforms) {
            if (p.getCurrentTrain() != null && p.getCurrentTrain().getDepartureTime() <= train.getArrivalTime())
                p.releaseTrain();
        }
        Platform platform = strategy.allocate(platforms, train);
        if (platform != null) {
            platform.assignTrain(train);
            System.out.println("Train " + train.getName() + " → Platform " + platform.getId());
        } else System.out.println("No platform available for " + train.getName());
        return platform;
    }
    
    public static int minPlatformsNeeded(List<Train> trains) {
        int[] arrivals = trains.stream().mapToInt(Train::getArrivalTime).sorted().toArray();
        int[] departures = trains.stream().mapToInt(Train::getDepartureTime).sorted().toArray();
        int plat = 0, maxPlat = 0, i = 0, j = 0;
        while (i < arrivals.length) {
            if (arrivals[i] < departures[j]) { plat++; i++; }
            else { plat--; j++; }
            maxPlat = Math.max(maxPlat, plat);
        }
        return maxPlat;
    }
}
