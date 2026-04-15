// Command — Smart Home Remote Control
interface Command {
    void execute();
    void undo();
    String getDescription();
}

class Light {
    private String room;
    private boolean on;
    public Light(String room) { this.room = room; }
    public void turnOn() { on = true; System.out.println(room + " light ON"); }
    public void turnOff() { on = false; System.out.println(room + " light OFF"); }
}

class LightOnCommand implements Command {
    private Light light;
    public LightOnCommand(Light light) { this.light = light; }
    public void execute() { light.turnOn(); }
    public void undo() { light.turnOff(); }
    public String getDescription() { return "Turn on light"; }
}

class Thermostat {
    private int temperature;
    public void setTemperature(int temp) { temperature = temp; System.out.println("Thermostat: " + temp + "°C"); }
    public int getTemperature() { return temperature; }
}

class SetTemperatureCommand implements Command {
    private Thermostat thermostat;
    private int newTemp, prevTemp;
    public SetTemperatureCommand(Thermostat t, int temp) { this.thermostat = t; this.newTemp = temp; }
    public void execute() { prevTemp = thermostat.getTemperature(); thermostat.setTemperature(newTemp); }
    public void undo() { thermostat.setTemperature(prevTemp); }
    public String getDescription() { return "Set temp to " + newTemp; }
}

// Macro command — group multiple commands
class MacroCommand implements Command {
    private List<Command> commands;
    private String name;
    public MacroCommand(String name, List<Command> cmds) { this.name = name; this.commands = cmds; }
    public void execute() { commands.forEach(Command::execute); }
    public void undo() { for (int i = commands.size()-1; i >= 0; i--) commands.get(i).undo(); }
    public String getDescription() { return "Macro: " + name; }
}
