#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

class Train {
    string id, name;
    int arrivalTime, departureTime;
public:
    Train(const string& id, const string& name, int arr, int dep)
        : id(id), name(name), arrivalTime(arr), departureTime(dep) {}
    const string& getId() const { return id; }
    const string& getName() const { return name; }
    int getArrivalTime() const { return arrivalTime; }
    int getDepartureTime() const { return departureTime; }
};

class Platform {
    int id;
    Train* currentTrain = nullptr;
    vector<Train*> schedule;
public:
    Platform(int id) : id(id) {}
    int getId() const { return id; }
    bool isAvailable(int time) const { return !currentTrain || currentTrain->getDepartureTime() <= time; }
    void assignTrain(Train* t) { currentTrain = t; schedule.push_back(t); }
    void releaseTrain() { currentTrain = nullptr; }
    Train* getCurrentTrain() const { return currentTrain; }
};

class AllocationStrategy {
public:
    virtual ~AllocationStrategy() = default;
    virtual Platform* allocate(vector<Platform>& platforms, Train& train) = 0;
};

class FirstAvailableStrategy : public AllocationStrategy {
public:
    Platform* allocate(vector<Platform>& platforms, Train& train) override {
        for (auto& p : platforms)
            if (p.isAvailable(train.getArrivalTime())) return &p;
        return nullptr;
    }
};

class Station {
    vector<Platform> platforms;
    unique_ptr<AllocationStrategy> strategy;
public:
    Station(int numPlatforms, unique_ptr<AllocationStrategy> strat)
        : strategy(move(strat)) {
        for (int i = 1; i <= numPlatforms; i++) platforms.emplace_back(i);
    }
    
    Platform* scheduleTrain(Train& train) {
        for (auto& p : platforms)
            if (p.getCurrentTrain() && p.getCurrentTrain()->getDepartureTime() <= train.getArrivalTime())
                p.releaseTrain();
        Platform* platform = strategy->allocate(platforms, train);
        if (platform) {
            platform->assignTrain(&train);
            cout << "Train " << train.getName() << " -> Platform " << platform->getId() << endl;
        } else cout << "No platform available for " << train.getName() << endl;
        return platform;
    }
    
    static int minPlatformsNeeded(vector<Train>& trains) {
        vector<int> arrivals, departures;
        for (auto& t : trains) { arrivals.push_back(t.getArrivalTime()); departures.push_back(t.getDepartureTime()); }
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
