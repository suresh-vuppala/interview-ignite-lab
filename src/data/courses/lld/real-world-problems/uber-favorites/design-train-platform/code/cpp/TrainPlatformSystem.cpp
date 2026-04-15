#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>
using namespace std;

struct Train {
    string id, name;
    int arrivalTime, departureTime;
};

class Platform {
    int id;
    Train* currentTrain = nullptr;
    vector<Train*> schedule;
public:
    Platform(int id) : id(id) {}
    int getId() const { return id; }
    bool isAvailable(int time) const { return !currentTrain || currentTrain->departureTime <= time; }
    void assignTrain(Train* t) { currentTrain = t; schedule.push_back(t); }
    void releaseTrain() { currentTrain = nullptr; }
    Train* getCurrentTrain() const { return currentTrain; }
};

class AllocationStrategy {
public:
    virtual ~AllocationStrategy() = default;
    virtual Platform* allocate(vector<unique_ptr<Platform>>& platforms, Train* train) = 0;
};

class FirstAvailableStrategy : public AllocationStrategy {
public:
    Platform* allocate(vector<unique_ptr<Platform>>& platforms, Train* train) override {
        for (auto& p : platforms)
            if (p->isAvailable(train->arrivalTime)) return p.get();
        return nullptr;
    }
};

class Station {
    vector<unique_ptr<Platform>> platforms;
    unique_ptr<AllocationStrategy> strategy;
public:
    Station(int numPlatforms, unique_ptr<AllocationStrategy> strat) : strategy(move(strat)) {
        for (int i = 1; i <= numPlatforms; i++)
            platforms.push_back(make_unique<Platform>(i));
    }

    Platform* scheduleTrain(Train* train) {
        for (auto& p : platforms)
            if (p->getCurrentTrain() && p->getCurrentTrain()->departureTime <= train->arrivalTime)
                p->releaseTrain();
        Platform* plat = strategy->allocate(platforms, train);
        if (plat) { plat->assignTrain(train); cout << "Train " << train->name << " -> Platform " << plat->getId() << endl; }
        else cout << "No platform available for " << train->name << endl;
        return plat;
    }

    static int minPlatformsNeeded(vector<Train>& trains) {
        vector<int> arrivals, departures;
        for (auto& t : trains) { arrivals.push_back(t.arrivalTime); departures.push_back(t.departureTime); }
        sort(arrivals.begin(), arrivals.end());
        sort(departures.begin(), departures.end());
        int plat = 0, maxPlat = 0, i = 0, j = 0;
        while (i < (int)arrivals.size()) {
            if (arrivals[i] < departures[j]) { plat++; i++; }
            else { plat--; j++; }
            maxPlat = max(maxPlat, plat);
        }
        return maxPlat;
    }
};
