// ===========================================================================
// DESIGN: Amazon Alexa Smart Home Device System — Low Level Design
// ===========================================================================
// Single-file Java | Patterns: Command, Composite, Macro Command
// Principles: SOLID, Composition over Inheritance
// ===========================================================================

// 1. FUNCTIONAL REQUIREMENTS
// FR1: Control smart devices — lights, thermostat, locks
// FR2: Device groups — control multiple devices as one
// FR3: Routines — execute sequence of commands (macro)
// FR4: Undo last command
// FR5: Query device status

// 2. CONSTRAINTS: Max 100 devices, 20 groups, 50 routines

// 3. RELATIONSHIPS (see C++ file for full table)
// 4. PLANTUML (see C++ file for full diagram)

import java.util.*;

// ===========================================================================
// INTERFACE: SmartDevice [Composite Pattern: Component]
// ===========================================================================
interface SmartDevice {
    String getName();
    void turnOn();
    void turnOff();
    boolean isOn();
    String getStatus();
}

// SmartLight with brightness
class SmartLight implements SmartDevice {
    private String name;
    private boolean on = false;
    private int brightness = 100;

    public SmartLight(String name) { this.name = name; }
    public String getName() { return name; }
    public void turnOn() { on = true; System.out.println("  [Light] " + name + " ON (" + brightness + "%)"); }
    public void turnOff() { on = false; System.out.println("  [Light] " + name + " OFF"); }
    public boolean isOn() { return on; }
    public int getBrightness() { return brightness; }
    public void setBrightness(int b) { brightness = b; System.out.println("  [Light] " + name + " brightness=" + b + "%"); }
    public String getStatus() { return name + ": " + (on ? "ON" : "OFF") + " (" + brightness + "%)"; }
}

// SmartThermostat with temperature
class SmartThermostat implements SmartDevice {
    private String name;
    private boolean on = false;
    private int temperature = 72;

    public SmartThermostat(String name) { this.name = name; }
    public String getName() { return name; }
    public void turnOn() { on = true; System.out.println("  [Thermo] " + name + " ON at " + temperature + "F"); }
    public void turnOff() { on = false; System.out.println("  [Thermo] " + name + " OFF"); }
    public boolean isOn() { return on; }
    public int getTemperature() { return temperature; }
    public void setTemperature(int t) { temperature = t; System.out.println("  [Thermo] " + name + " set to " + t + "F"); }
    public String getStatus() { return name + ": " + (on ? "ON" : "OFF") + " (" + temperature + "F)"; }
}

// SmartLock
class SmartLock implements SmartDevice {
    private String name;
    private boolean locked = true;

    public SmartLock(String name) { this.name = name; }
    public String getName() { return name; }
    public void turnOn() { locked = true; System.out.println("  [Lock] " + name + " LOCKED"); }
    public void turnOff() { locked = false; System.out.println("  [Lock] " + name + " UNLOCKED"); }
    public boolean isOn() { return locked; }
    public String getStatus() { return name + ": " + (locked ? "LOCKED" : "UNLOCKED"); }
}

// ===========================================================================
// CLASS: DeviceGroup [Composite Pattern]
// ===========================================================================
class DeviceGroup implements SmartDevice {
    private String name;
    private List<SmartDevice> devices = new ArrayList<>();

    public DeviceGroup(String name) { this.name = name; }
    public void addDevice(SmartDevice d) { devices.add(d); }
    public String getName() { return name + " (Group)"; }

    public void turnOn() {
        System.out.println("  [Group] " + name + " — ON all:");
        for (SmartDevice d : devices) { System.out.print("    "); d.turnOn(); }
    }
    public void turnOff() {
        System.out.println("  [Group] " + name + " — OFF all:");
        for (SmartDevice d : devices) { System.out.print("    "); d.turnOff(); }
    }
    public boolean isOn() { return devices.stream().anyMatch(SmartDevice::isOn); }
    public String getStatus() {
        StringBuilder sb = new StringBuilder(name + " Group [");
        for (int i = 0; i < devices.size(); i++) {
            if (i > 0) sb.append(", ");
            sb.append(devices.get(i).getStatus());
        }
        return sb.append("]").toString();
    }
}

// ===========================================================================
// INTERFACE: DeviceCommand [Command Pattern]
// ===========================================================================
interface DeviceCommand {
    void execute();
    void undo();
    String describe();
}

// TurnOn command
class TurnOnCommand implements DeviceCommand {
    private SmartDevice device;
    public TurnOnCommand(SmartDevice d) { this.device = d; }
    public void execute() { device.turnOn(); }
    public void undo() { device.turnOff(); }
    public String describe() { return "TurnOn(" + device.getName() + ")"; }
}

// TurnOff command
class TurnOffCommand implements DeviceCommand {
    private SmartDevice device;
    public TurnOffCommand(SmartDevice d) { this.device = d; }
    public void execute() { device.turnOff(); }
    public void undo() { device.turnOn(); }
    public String describe() { return "TurnOff(" + device.getName() + ")"; }
}

// Set Brightness (stores old value for undo)
class SetBrightnessCommand implements DeviceCommand {
    private SmartLight light;
    private int oldVal, newVal;
    public SetBrightnessCommand(SmartLight l, int newVal) {
        this.light = l; this.newVal = newVal; this.oldVal = l.getBrightness();
    }
    public void execute() { light.setBrightness(newVal); }
    public void undo() { light.setBrightness(oldVal); }
    public String describe() { return "SetBrightness(" + light.getName() + "," + newVal + "%)"; }
}

// Set Temperature (stores old value for undo)
class SetTemperatureCommand implements DeviceCommand {
    private SmartThermostat thermo;
    private int oldVal, newVal;
    public SetTemperatureCommand(SmartThermostat t, int newVal) {
        this.thermo = t; this.newVal = newVal; this.oldVal = t.getTemperature();
    }
    public void execute() { thermo.setTemperature(newVal); }
    public void undo() { thermo.setTemperature(oldVal); }
    public String describe() { return "SetTemp(" + thermo.getName() + "," + newVal + "F)"; }
}

// ===========================================================================
// CLASS: Routine [Macro Command]
// Executes multiple commands as one, undo reverses all in reverse order
// ===========================================================================
class Routine implements DeviceCommand {
    private String name;
    private List<DeviceCommand> commands = new ArrayList<>();

    public Routine(String name) { this.name = name; }
    public void addCommand(DeviceCommand cmd) { commands.add(cmd); }

    public void execute() {
        System.out.println("  [Routine] '" + name + "' — executing " + commands.size() + " steps:");
        for (int i = 0; i < commands.size(); i++) {
            System.out.print("    Step " + (i+1) + ": ");
            commands.get(i).execute();
        }
    }

    public void undo() {
        System.out.println("  [Routine] '" + name + "' — undoing in reverse:");
        for (int i = commands.size() - 1; i >= 0; i--) {
            System.out.print("    Undo step " + (i+1) + ": ");
            commands.get(i).undo();
        }
    }

    public String describe() { return "Routine('" + name + "'," + commands.size() + " steps)"; }
}

// ===========================================================================
// CLASS: VoiceAssistant [Invoker — Command Pattern]
// ===========================================================================
class VoiceAssistant {
    private String name;
    private List<SmartDevice> devices = new ArrayList<>();
    private Deque<DeviceCommand> undoStack = new ArrayDeque<>();

    public VoiceAssistant(String name) { this.name = name; }
    public void registerDevice(SmartDevice d) { devices.add(d); }

    public void executeCommand(DeviceCommand cmd) {
        System.out.println("\n>> " + name + ": " + cmd.describe());
        cmd.execute();
        undoStack.push(cmd);
    }

    public void undoLast() {
        if (undoStack.isEmpty()) { System.out.println("\n>> Nothing to undo."); return; }
        DeviceCommand cmd = undoStack.pop();
        System.out.println("\n>> " + name + ": Undoing " + cmd.describe());
        cmd.undo();
    }

    public void showStatus() {
        System.out.println("\n--- Device Status ---");
        for (SmartDevice d : devices) System.out.println("  " + d.getStatus());
    }
}

// ===========================================================================
// MAIN
// ===========================================================================
public class AlexaDeviceSystem {
    public static void main(String[] args) {
        System.out.println("============================================");
        System.out.println("  Alexa Smart Home — LLD Demo (Java)");
        System.out.println("============================================");

        SmartLight livingLight = new SmartLight("Living Light");
        SmartLight bedroomLight = new SmartLight("Bedroom Light");
        SmartThermostat thermo = new SmartThermostat("Thermostat");
        SmartLock door = new SmartLock("Front Door");

        DeviceGroup livingRoom = new DeviceGroup("Living Room");
        livingRoom.addDevice(livingLight);
        livingRoom.addDevice(thermo);

        VoiceAssistant alexa = new VoiceAssistant("Alexa");
        alexa.registerDevice(livingLight);
        alexa.registerDevice(bedroomLight);
        alexa.registerDevice(thermo);
        alexa.registerDevice(door);

        alexa.showStatus();

        // Individual commands
        alexa.executeCommand(new TurnOnCommand(livingLight));
        alexa.executeCommand(new SetBrightnessCommand(livingLight, 60));
        alexa.executeCommand(new TurnOnCommand(thermo));
        alexa.executeCommand(new SetTemperatureCommand(thermo, 68));

        alexa.showStatus();

        // Undo
        alexa.undoLast();  // Undo temp -> 72
        alexa.undoLast();  // Undo thermo on -> off

        // Group command
        alexa.executeCommand(new TurnOffCommand(livingRoom));

        // Routine (Macro Command)
        Routine morning = new Routine("Good Morning");
        morning.addCommand(new TurnOnCommand(bedroomLight));
        morning.addCommand(new SetBrightnessCommand(bedroomLight, 50));
        morning.addCommand(new TurnOnCommand(thermo));
        morning.addCommand(new SetTemperatureCommand(thermo, 72));
        morning.addCommand(new TurnOffCommand(door));  // Unlock

        alexa.executeCommand(morning);
        alexa.showStatus();

        // Undo entire routine
        alexa.undoLast();
        alexa.showStatus();

        System.out.println("\n=== All scenarios complete ===");
    }
}

// ===========================================================================
// 5. SUMMARY
// ===========================================================================
// EXECUTION FLOW: main() -> devices -> groups -> VoiceAssistant
//   -> executeCommand(TurnOn) -> device.turnOn() + push to undoStack
//   -> executeCommand(Routine) -> routine.execute() -> each cmd.execute()
//   -> undoLast() -> routine.undo() -> each cmd.undo() in REVERSE

// METHOD CALL TREE:
//   alexa.executeCommand(cmd) -> cmd.execute() [polymorphic]
//   alexa.undoLast() -> cmd.undo() [polymorphic]
//   routine.execute() -> forEach cmd.execute()
//   routine.undo() -> reverse forEach cmd.undo()

// CLASS RESPONSIBILITY TABLE:
//   SmartDevice(i) | Uniform device contract
//   SmartLight     | on/off + brightness
//   SmartThermostat| on/off + temperature
//   SmartLock      | lock/unlock
//   DeviceGroup    | Composite: controls group as one device
//   DeviceCommand(i)| execute() + undo() contract
//   TurnOnCommand  | on, undo=off
//   TurnOffCommand | off, undo=on
//   SetBrightnessCmd| set, undo=restore old
//   SetTempCmd     | set, undo=restore old
//   Routine        | Macro: sequence, undo=reverse all
//   VoiceAssistant | Invoker: execute + undo stack

// DESIGN PATTERNS:
//   1. Command   -> Actions as objects (execute + undo)
//   2. Composite -> DeviceGroup IS-A SmartDevice
//   3. Macro Cmd -> Routine = list of commands

// BEST PRACTICES:
//   1. Polymorphism  -> SmartDevice + DeviceCommand dispatched at runtime
//   2. OCP           -> New device/command = new class only
//   3. SRP           -> Each command does one thing
//   4. Undo          -> Commands store old state for reversal
