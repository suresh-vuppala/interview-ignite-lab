#include <string>
#include <vector>
#include <memory>
#include <iostream>
using namespace std;

// ========== SMART DEVICE (Interface) ==========
class SmartDevice {
public:
    virtual ~SmartDevice() = default;
    virtual string getName() const = 0;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool isOn() const = 0;
};

class SmartLight : public SmartDevice {
    string name; bool on = false; int brightness = 100;
public:
    SmartLight(string n) : name(move(n)) {}
    string getName() const override { return name; }
    void turnOn() override { on = true; cout << "Light " << name << " ON (" << brightness << "%)" << endl; }
    void turnOff() override { on = false; cout << "Light " << name << " OFF" << endl; }
    bool isOn() const override { return on; }
    void setBrightness(int b) { brightness = b; }
};

class SmartThermostat : public SmartDevice {
    string name; bool on = false; int temp = 72;
public:
    SmartThermostat(string n) : name(move(n)) {}
    string getName() const override { return name; }
    void turnOn() override { on = true; cout << "Thermostat " << name << " ON at " << temp << "F" << endl; }
    void turnOff() override { on = false; cout << "Thermostat " << name << " OFF" << endl; }
    bool isOn() const override { return on; }
    void setTemperature(int t) { temp = t; }
};

// Composite — Device Group
class DeviceGroup : public SmartDevice {
    string name;
    vector<shared_ptr<SmartDevice>> devices;
public:
    DeviceGroup(string n) : name(move(n)) {}
    void addDevice(shared_ptr<SmartDevice> d) { devices.push_back(move(d)); }
    string getName() const override { return name; }
    void turnOn() override { for (auto& d : devices) d->turnOn(); }
    void turnOff() override { for (auto& d : devices) d->turnOff(); }
    bool isOn() const override { for (auto& d : devices) if (d->isOn()) return true; return false; }
};

// ========== COMMANDS ==========
class DeviceCommand {
public:
    virtual ~DeviceCommand() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class TurnOnCommand : public DeviceCommand {
    shared_ptr<SmartDevice> device;
public:
    TurnOnCommand(shared_ptr<SmartDevice> d) : device(move(d)) {}
    void execute() override { device->turnOn(); }
    void undo() override { device->turnOff(); }
};

class TurnOffCommand : public DeviceCommand {
    shared_ptr<SmartDevice> device;
public:
    TurnOffCommand(shared_ptr<SmartDevice> d) : device(move(d)) {}
    void execute() override { device->turnOff(); }
    void undo() override { device->turnOn(); }
};

// Routine = Macro Command
class Routine : public DeviceCommand {
    string name;
    vector<shared_ptr<DeviceCommand>> commands;
public:
    Routine(string n, vector<shared_ptr<DeviceCommand>> cmds) : name(move(n)), commands(move(cmds)) {}
    void execute() override {
        cout << "Running routine: " << name << endl;
        for (auto& cmd : commands) cmd->execute();
    }
    void undo() override {
        for (int i = commands.size() - 1; i >= 0; i--) commands[i]->undo();
    }
};
