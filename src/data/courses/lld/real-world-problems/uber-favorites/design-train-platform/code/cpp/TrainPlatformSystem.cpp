// ===========================================================================
// DESIGN: Train Platform Management — Low Level Design
// Pattern: Strategy | Key: Min-platforms sweep algorithm
// ===========================================================================
// FR: Schedule train, allocate platform, min platforms needed
// PLANTUML: Station *-- Platform[], Station..>AllocationStrategy, Platform-->Train

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Train {
    string id, name;
    int arrival, departure;  // Minutes from midnight
public:
    Train(const string& id, const string& name, int arr, int dep)
        : id(id), name(name), arrival(arr), departure(dep) {}
    string getName() const { return name; }
    int getArrival() const { return arrival; }
    int getDeparture() const { return departure; }
};

class Platform {
    int id;
    Train* current;
public:
    Platform(int id) : id(id), current(NULL) {}
    int getId() const { return id; }
    bool isAvailable(int time) const { return !current || current->getDeparture() <= time; }
    void assign(Train* t) { current = t; }
    void release() { current = NULL; }
    Train* getCurrent() const { return current; }
};

// Strategy for platform allocation
class AllocationStrategy {
public:
    virtual ~AllocationStrategy() {}
    virtual Platform* allocate(vector<Platform>& platforms, Train& train) = 0;
};

class FirstAvailableStrategy : public AllocationStrategy {
public:
    Platform* allocate(vector<Platform>& platforms, Train& train) {
        for (size_t i = 0; i < platforms.size(); i++)
            if (platforms[i].isAvailable(train.getArrival())) return &platforms[i];
        return NULL;
    }
};

class Station {
    vector<Platform> platforms;
    AllocationStrategy* strategy;
public:
    Station(int numPlatforms, AllocationStrategy* strat) : strategy(strat) {
        for (int i = 1; i <= numPlatforms; i++) platforms.push_back(Platform(i));
    }

    void scheduleTrain(Train& train) {
        // Release departed trains
        for (size_t i = 0; i < platforms.size(); i++)
            if (platforms[i].getCurrent() && platforms[i].getCurrent()->getDeparture() <= train.getArrival())
                platforms[i].release();
        Platform* p = strategy->allocate(platforms, train);
        if (p) { p->assign(&train); cout << "  " << train.getName() << " -> Platform " << p->getId() << endl; }
        else cout << "  [ERROR] No platform for " << train.getName() << endl;
    }

    // Min platforms needed — sweep algorithm O(N logN)
    static int minPlatformsNeeded(vector<Train>& trains) {
        vector<int> arr, dep;
        for (size_t i = 0; i < trains.size(); i++) {
            arr.push_back(trains[i].getArrival());
            dep.push_back(trains[i].getDeparture());
        }
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int plat = 0, maxPlat = 0, i = 0, j = 0;
        while (i < (int)arr.size()) {
            if (arr[i] < dep[j]) { plat++; i++; }
            else { plat--; j++; }
            if (plat > maxPlat) maxPlat = plat;
        }
        return maxPlat;
    }
};

int main() {
    cout << "============================================\n  Train Platform — LLD Demo\n============================================" << endl;
    FirstAvailableStrategy strat;
    Station station(3, &strat);
    Train t1("T1", "Express 101", 540, 600);   // 9:00-10:00
    Train t2("T2", "Local 202", 550, 620);      // 9:10-10:20
    Train t3("T3", "Express 303", 570, 630);     // 9:30-10:30
    Train t4("T4", "Local 404", 610, 660);       // 10:10-11:00

    station.scheduleTrain(t1);
    station.scheduleTrain(t2);
    station.scheduleTrain(t3);
    station.scheduleTrain(t4);

    vector<Train> all; all.push_back(t1); all.push_back(t2); all.push_back(t3); all.push_back(t4);
    cout << "  Min platforms needed: " << Station::minPlatformsNeeded(all) << endl;
    cout << "\n=== Complete ===" << endl;
    return 0;
}
// SUMMARY: Strategy(allocation), Sweep algorithm(min platforms)
// PRACTICES: OCP(new strategies), Greedy sweep O(NlogN)
