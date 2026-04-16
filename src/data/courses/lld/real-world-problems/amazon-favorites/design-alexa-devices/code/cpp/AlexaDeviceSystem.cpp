// ===========================================================================
// DESIGN: Amazon Alexa Smart Home Device System — Low Level Design
// ===========================================================================
// Single-file C++ | Patterns: Command, Composite, Observer
// Principles: SOLID, Composition over Inheritance
// ===========================================================================

// 1. FUNCTIONAL REQUIREMENTS
// FR1: Control smart devices — lights (on/off/brightness), thermostat (temp), locks
// FR2: Device groups — "turn off living room" controls all devices in group
// FR3: Routines — "Good Morning" executes sequence of commands
// FR4: Undo last command — reverse the most recent action
// FR5: Query device status — check current state of any device

// 2. CONSTRAINTS: Max 100 devices, 20 groups, 50 routines, <500ms latency

// 3. ENTITIES & RELATIONSHIPS
// +-------------------+------------------+--------------+-------------+----------------------------+
// | Source             | Destination      | Type         | Cardinality | Description                |
// +-------------------+------------------+--------------+-------------+----------------------------+
// | VoiceAssistant     | SmartDevice      | Aggregation  | 1 -> many   | Assistant manages devices  |
// | DeviceGroup        | SmartDevice      | Aggregation  | 1 -> many   | Group has devices          |
// | DeviceGroup        | SmartDevice      | Inheritance  | IS-A        | Group IS-A device (Comp.)  |
// | Routine            | DeviceCommand    | Composition  | 1 -> many   | Routine owns commands      |
// | TurnOnCommand      | DeviceCommand    | Inheritance  | IS-A        | Concrete command           |
// | TurnOffCommand     | DeviceCommand    | Inheritance  | IS-A        | Concrete command           |
// | DeviceCommand      | SmartDevice      | Association  | 1 -> 1      | Command targets device     |
// | VoiceAssistant     | DeviceCommand    | Aggregation  | 1 -> many   | Undo stack                 |
// +-------------------+------------------+--------------+-------------+----------------------------+

// 4. PLANTUML
// @startuml Alexa
// interface SmartDevice { +getName() +turnOn() +turnOff() +isOn() +getStatus() }
// class SmartLight { -brightness:int }
// class SmartThermostat { -temperature:int }
// class SmartLock { -locked:bool }
// class DeviceGroup { -devices:vector }
// interface DeviceCommand { +execute() +undo() +describe() }
// class TurnOnCommand
// class TurnOffCommand
// class SetBrightnessCmd { -oldVal -newVal }
// class SetTemperatureCmd { -oldVal -newVal }
// class Routine { -commands:vector }
// class VoiceAssistant { -devices -groups -undoStack }
// SmartDevice <|.. SmartLight
// SmartDevice <|.. SmartThermostat
// SmartDevice <|.. SmartLock
// SmartDevice <|.. DeviceGroup
// DeviceGroup o-- "0..*" SmartDevice
// DeviceCommand <|.. TurnOnCommand
// DeviceCommand <|.. TurnOffCommand
// DeviceCommand <|.. SetBrightnessCmd
// DeviceCommand <|.. SetTemperatureCmd
// DeviceCommand <|.. Routine
// DeviceCommand --> SmartDevice : targets
// VoiceAssistant o-- SmartDevice
// VoiceAssistant o-- DeviceCommand : undoStack
// @enduml

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// ===========================================================================
// INTERFACE: SmartDevice [Component for Composite Pattern]
// Responsibility: Uniform interface for all smart home devices
// ===========================================================================
class SmartDevice {
public:
    virtual ~SmartDevice() {}
    virtual string getName() const = 0;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool isOn() const = 0;
    virtual string getStatus() const = 0;
};

// ===========================================================================
// CLASS: SmartLight [Leaf Device]
// ===========================================================================
class SmartLight : public SmartDevice {
private:
    string name;
    bool on;
    int brightness;  // 0-100%

public:
    SmartLight(const string& name) : name(name), on(false), brightness(100) {}

    string getName() const { return name; }
    void turnOn() { on = true; cout << "  [Light] " << name << " ON (brightness: " << brightness << "%)" << endl; }
    void turnOff() { on = false; cout << "  [Light] " << name << " OFF" << endl; }
    bool isOn() const { return on; }

    int getBrightness() const { return brightness; }
    void setBrightness(int b) {
        brightness = b;
        cout << "  [Light] " << name << " brightness set to " << b << "%" << endl;
    }

    string getStatus() const {
        return name + ": " + (on ? "ON" : "OFF") + " (" + to_string(brightness) + "%)";
    }
};

// ===========================================================================
// CLASS: SmartThermostat [Leaf Device]
// ===========================================================================
class SmartThermostat : public SmartDevice {
private:
    string name;
    bool on;
    int temperature;  // In Fahrenheit

public:
    SmartThermostat(const string& name) : name(name), on(false), temperature(72) {}

    string getName() const { return name; }
    void turnOn() { on = true; cout << "  [Thermo] " << name << " ON at " << temperature << "F" << endl; }
    void turnOff() { on = false; cout << "  [Thermo] " << name << " OFF" << endl; }
    bool isOn() const { return on; }

    int getTemperature() const { return temperature; }
    void setTemperature(int t) {
        temperature = t;
        cout << "  [Thermo] " << name << " set to " << t << "F" << endl;
    }

    string getStatus() const {
        return name + ": " + (on ? "ON" : "OFF") + " (" + to_string(temperature) + "F)";
    }
};

// ===========================================================================
// CLASS: SmartLock [Leaf Device]
// ===========================================================================
class SmartLock : public SmartDevice {
private:
    string name;
    bool locked;

public:
    SmartLock(const string& name) : name(name), locked(true) {}

    string getName() const { return name; }
    void turnOn() { locked = true; cout << "  [Lock] " << name << " LOCKED" << endl; }   // on = locked
    void turnOff() { locked = false; cout << "  [Lock] " << name << " UNLOCKED" << endl; } // off = unlocked
    bool isOn() const { return locked; }

    string getStatus() const {
        return name + ": " + (locked ? "LOCKED" : "UNLOCKED");
    }
};

// ===========================================================================
// CLASS: DeviceGroup [Composite Pattern — treats group as single device]
// Responsibility: Controls multiple devices uniformly
// Relationship: Aggregation with SmartDevice (group HAS devices)
// ===========================================================================
class DeviceGroup : public SmartDevice {
private:
    string name;
    vector<SmartDevice*> devices;  // Aggregation: group doesn't own devices

public:
    DeviceGroup(const string& name) : name(name) {}

    void addDevice(SmartDevice* d) { devices.push_back(d); }
    string getName() const { return name + " (Group)"; }

    // Composite: turnOn all devices in group
    void turnOn() {
        cout << "  [Group] " << name << " — turning ON all:" << endl;
        for (size_t i = 0; i < devices.size(); i++) {
            cout << "    ";
            devices[i]->turnOn();
        }
    }

    // Composite: turnOff all devices in group
    void turnOff() {
        cout << "  [Group] " << name << " — turning OFF all:" << endl;
        for (size_t i = 0; i < devices.size(); i++) {
            cout << "    ";
            devices[i]->turnOff();
        }
    }

    bool isOn() const {
        for (size_t i = 0; i < devices.size(); i++)
            if (devices[i]->isOn()) return true;
        return false;
    }

    string getStatus() const {
        string s = name + " Group [";
        for (size_t i = 0; i < devices.size(); i++) {
            if (i > 0) s += ", ";
            s += devices[i]->getStatus();
        }
        return s + "]";
    }
};

// ===========================================================================
// INTERFACE: DeviceCommand [Command Pattern]
// Responsibility: Encapsulates device action for execute/undo
// ===========================================================================
class DeviceCommand {
public:
    virtual ~DeviceCommand() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual string describe() const = 0;
};

// ===========================================================================
// Concrete Commands
// ===========================================================================

// Turn ON command
class TurnOnCommand : public DeviceCommand {
private:
    SmartDevice* device;
public:
    TurnOnCommand(SmartDevice* d) : device(d) {}
    void execute() { device->turnOn(); }
    void undo() { device->turnOff(); }
    string describe() const { return "TurnOn(" + device->getName() + ")"; }
};

// Turn OFF command
class TurnOffCommand : public DeviceCommand {
private:
    SmartDevice* device;
public:
    TurnOffCommand(SmartDevice* d) : device(d) {}
    void execute() { device->turnOff(); }
    void undo() { device->turnOn(); }
    string describe() const { return "TurnOff(" + device->getName() + ")"; }
};

// Set Brightness command (stores old value for undo)
class SetBrightnessCommand : public DeviceCommand {
private:
    SmartLight* light;
    int oldBrightness;
    int newBrightness;
public:
    SetBrightnessCommand(SmartLight* l, int newVal)
        : light(l), newBrightness(newVal) {
        oldBrightness = light->getBrightness();  // Save for undo
    }
    void execute() { light->setBrightness(newBrightness); }
    void undo() { light->setBrightness(oldBrightness); }
    string describe() const {
        return "SetBrightness(" + light->getName() + ", " + to_string(newBrightness) + "%)";
    }
};

// Set Temperature command
class SetTemperatureCommand : public DeviceCommand {
private:
    SmartThermostat* thermo;
    int oldTemp;
    int newTemp;
public:
    SetTemperatureCommand(SmartThermostat* t, int newVal)
        : thermo(t), newTemp(newVal) {
        oldTemp = thermo->getTemperature();
    }
    void execute() { thermo->setTemperature(newTemp); }
    void undo() { thermo->setTemperature(oldTemp); }
    string describe() const {
        return "SetTemp(" + thermo->getName() + ", " + to_string(newTemp) + "F)";
    }
};

// ===========================================================================
// CLASS: Routine [Macro Command — Command Pattern]
// Responsibility: Sequence of commands executed as one action
// Relationship: Composition with DeviceCommand (routine OWNS commands)
// ===========================================================================
class Routine : public DeviceCommand {
private:
    string name;
    vector<DeviceCommand*> commands;  // Composition: routine owns commands

public:
    Routine(const string& name) : name(name) {}

    ~Routine() {
        for (size_t i = 0; i < commands.size(); i++) delete commands[i];
    }

    void addCommand(DeviceCommand* cmd) { commands.push_back(cmd); }

    // Execute all commands in sequence
    void execute() {
        cout << "  [Routine] '" << name << "' — executing " << commands.size() << " steps:" << endl;
        for (size_t i = 0; i < commands.size(); i++) {
            cout << "    Step " << (i + 1) << ": ";
            commands[i]->execute();
        }
    }

    // Undo all commands in REVERSE order
    void undo() {
        cout << "  [Routine] '" << name << "' — undoing in reverse:" << endl;
        for (int i = (int)commands.size() - 1; i >= 0; i--) {
            cout << "    Undo step " << (i + 1) << ": ";
            commands[i]->undo();
        }
    }

    string describe() const { return "Routine('" + name + "', " + to_string(commands.size()) + " steps)"; }
};

// ===========================================================================
// CLASS: VoiceAssistant [Controller/Invoker]
// Responsibility: Processes commands, maintains undo history
// ===========================================================================
class VoiceAssistant {
private:
    string name;
    vector<SmartDevice*> devices;     // All registered devices
    vector<DeviceGroup*> groups;      // Device groups
    stack<DeviceCommand*> undoStack;  // Command history for undo

public:
    VoiceAssistant(const string& name) : name(name) {}

    ~VoiceAssistant() {
        while (!undoStack.empty()) {
            delete undoStack.top();
            undoStack.pop();
        }
    }

    void registerDevice(SmartDevice* d) { devices.push_back(d); }
    void registerGroup(DeviceGroup* g) { groups.push_back(g); }

    // Execute a command and push to undo stack
    void executeCommand(DeviceCommand* cmd) {
        cout << "\n>> " << name << ": " << cmd->describe() << endl;
        cmd->execute();
        undoStack.push(cmd);
    }

    // Execute routine (macro command)
    void executeRoutine(Routine* routine) {
        cout << "\n>> " << name << ": Starting routine..." << endl;
        routine->execute();
        undoStack.push(routine);
    }

    // Undo the last command
    void undoLast() {
        if (undoStack.empty()) {
            cout << "\n>> " << name << ": Nothing to undo." << endl;
            return;
        }
        DeviceCommand* lastCmd = undoStack.top();
        undoStack.pop();
        cout << "\n>> " << name << ": Undoing " << lastCmd->describe() << endl;
        lastCmd->undo();
        delete lastCmd;
    }

    // Display all device statuses
    void showStatus() const {
        cout << "\n--- Device Status ---" << endl;
        for (size_t i = 0; i < devices.size(); i++) {
            cout << "  " << devices[i]->getStatus() << endl;
        }
    }
};

// ===========================================================================
// MAIN — Full demonstration
// ===========================================================================
int main() {
    cout << "============================================" << endl;
    cout << "  Alexa Smart Home System — LLD Demo" << endl;
    cout << "============================================" << endl;

    // Create devices
    SmartLight livingLight("Living Room Light");
    SmartLight bedroomLight("Bedroom Light");
    SmartThermostat thermostat("Home Thermostat");
    SmartLock frontDoor("Front Door Lock");

    // Create device group (Composite)
    DeviceGroup livingRoom("Living Room");
    livingRoom.addDevice(&livingLight);
    livingRoom.addDevice(&thermostat);

    // Create voice assistant
    VoiceAssistant alexa("Alexa");
    alexa.registerDevice(&livingLight);
    alexa.registerDevice(&bedroomLight);
    alexa.registerDevice(&thermostat);
    alexa.registerDevice(&frontDoor);
    alexa.registerGroup(&livingRoom);

    // Show initial status
    alexa.showStatus();

    // --- Individual commands ---
    alexa.executeCommand(new TurnOnCommand(&livingLight));
    alexa.executeCommand(new SetBrightnessCommand(&livingLight, 60));
    alexa.executeCommand(new TurnOnCommand(&thermostat));
    alexa.executeCommand(new SetTemperatureCommand(&thermostat, 68));

    alexa.showStatus();

    // --- Undo last command ---
    alexa.undoLast();  // Undo SetTemperature(68) -> back to 72
    alexa.undoLast();  // Undo TurnOn thermostat -> OFF

    alexa.showStatus();

    // --- Group command (Composite) ---
    alexa.executeCommand(new TurnOffCommand(&livingRoom));

    // --- Routine (Macro Command) ---
    Routine* goodMorning = new Routine("Good Morning");
    goodMorning->addCommand(new TurnOnCommand(&bedroomLight));
    goodMorning->addCommand(new SetBrightnessCommand(&bedroomLight, 50));
    goodMorning->addCommand(new TurnOnCommand(&thermostat));
    goodMorning->addCommand(new SetTemperatureCommand(&thermostat, 72));
    goodMorning->addCommand(new TurnOffCommand(&frontDoor));  // Unlock

    alexa.executeRoutine(goodMorning);
    alexa.showStatus();

    // Undo entire routine (reverses all 5 steps!)
    alexa.undoLast();
    alexa.showStatus();

    cout << "\n============================================" << endl;
    cout << "  All scenarios completed!" << endl;
    cout << "============================================" << endl;

    return 0;
}

// ===========================================================================
// 5. SUMMARY
// ===========================================================================

// EXECUTION FLOW:
//   main() -> create devices -> create DeviceGroup -> create VoiceAssistant
//     -> alexa.executeCommand(TurnOnCommand(light))
//        -> cmd->execute() -> light.turnOn()
//        -> undoStack.push(cmd)
//     -> alexa.executeRoutine(goodMorning)
//        -> routine->execute() -> each sub-command.execute()
//        -> undoStack.push(routine)
//     -> alexa.undoLast()
//        -> routine->undo() -> each sub-command.undo() in REVERSE

// METHOD CALL TREE:
//   alexa.executeCommand(cmd) -> cmd->execute() [polymorphic]
//     -> TurnOnCommand.execute() -> device->turnOn() [polymorphic]
//     -> SetBrightnessCommand.execute() -> light->setBrightness(newVal)
//   alexa.executeRoutine(routine) -> routine->execute()
//     -> for each cmd: cmd->execute()
//   alexa.undoLast() -> cmd->undo() [polymorphic]

// CLASS RESPONSIBILITY TABLE:
//   SmartDevice(interface) | Uniform device contract
//   SmartLight             | Light with on/off + brightness
//   SmartThermostat        | Thermostat with on/off + temperature
//   SmartLock              | Lock with lock/unlock
//   DeviceGroup            | Composite: group of devices as one
//   DeviceCommand(interface)| Command contract: execute + undo
//   TurnOnCommand          | Turns device on, undo turns off
//   TurnOffCommand         | Turns device off, undo turns on
//   SetBrightnessCommand   | Sets brightness, undo restores old value
//   SetTemperatureCommand  | Sets temperature, undo restores old value
//   Routine                | Macro: list of commands, undo reverses all
//   VoiceAssistant         | Invoker: executes commands, manages undo stack

// DESIGN PATTERNS:
//   1. Command    -> Every action is an object (execute + undo)
//   2. Composite  -> DeviceGroup IS-A SmartDevice, contains SmartDevices
//   3. Macro Command -> Routine = list of commands
//   4. Observer   -> (Extendable: notify dashboard on state change)

// BEST PRACTICES:
//   1. Encapsulation     -> Device state private, accessed via methods
//   2. Polymorphism      -> SmartDevice and DeviceCommand dispatched at runtime
//   3. Composition       -> Routine OWNS commands, Group AGGREGATES devices
//   4. OCP               -> New device/command = new class, no existing changes
//   5. SRP               -> Each command does one thing
//   6. Undo support      -> Commands store old state for reversal
//   7. Macro commands    -> Routine composes commands without modification
