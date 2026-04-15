// Alexa Device System — Command + Composite
import java.util.*;

interface SmartDevice {
    String getName();
    void turnOn();
    void turnOff();
    boolean isOn();
}

class SmartLight implements SmartDevice {
    private String name; private boolean on; private int brightness = 100;
    public SmartLight(String name) { this.name = name; }
    public String getName() { return name; }
    public void turnOn() { on = true; System.out.println("💡 " + name + " ON (brightness: " + brightness + "%)"); }
    public void turnOff() { on = false; System.out.println("💡 " + name + " OFF"); }
    public boolean isOn() { return on; }
    public void setBrightness(int b) { this.brightness = b; }
}

class SmartThermostat implements SmartDevice {
    private String name; private boolean on; private int temperature = 72;
    public SmartThermostat(String name) { this.name = name; }
    public String getName() { return name; }
    public void turnOn() { on = true; System.out.println("🌡️ " + name + " ON at " + temperature + "°F"); }
    public void turnOff() { on = false; System.out.println("🌡️ " + name + " OFF"); }
    public boolean isOn() { return on; }
    public void setTemperature(int t) { this.temperature = t; }
}

// Composite — device group
class DeviceGroup implements SmartDevice {
    private String name;
    private List<SmartDevice> devices = new ArrayList<>();
    public DeviceGroup(String name) { this.name = name; }
    public void addDevice(SmartDevice d) { devices.add(d); }
    public String getName() { return name; }
    public void turnOn() { devices.forEach(SmartDevice::turnOn); }
    public void turnOff() { devices.forEach(SmartDevice::turnOff); }
    public boolean isOn() { return devices.stream().anyMatch(SmartDevice::isOn); }
}

// Commands
interface DeviceCommand {
    void execute();
    void undo();
}

class TurnOnCommand implements DeviceCommand {
    private SmartDevice device;
    public TurnOnCommand(SmartDevice d) { this.device = d; }
    public void execute() { device.turnOn(); }
    public void undo() { device.turnOff(); }
}

class TurnOffCommand implements DeviceCommand {
    private SmartDevice device;
    public TurnOffCommand(SmartDevice d) { this.device = d; }
    public void execute() { device.turnOff(); }
    public void undo() { device.turnOn(); }
}

// Routine = Macro Command
class Routine implements DeviceCommand {
    private String name;
    private List<DeviceCommand> commands;
    public Routine(String name, List<DeviceCommand> cmds) { this.name = name; this.commands = cmds; }
    public void execute() { System.out.println("▶️ Running routine: " + name); commands.forEach(DeviceCommand::execute); }
    public void undo() { for (int i = commands.size()-1; i >= 0; i--) commands.get(i).undo(); }
}
