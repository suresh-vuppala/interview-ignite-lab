# Design for Amazon Alexa Devices

Design a voice assistant system that processes voice commands, controls smart home devices, and manages skills/plugins.

<br>

---

## Requirements

### Main Requirements
1. **Voice command processing** — parse commands, identify intent and entities
2. **Device control** — lights, thermostat, locks, speakers
3. **Skills/Plugins** — extensible third-party integrations
4. **Device groups** — "turn off all living room devices"
5. **Routines** — "Good morning" triggers multiple actions in sequence

<br>

---

## Design Patterns Used

| Pattern | Where | Why |
|---------|-------|-----|
| **Command** | Each voice action is a command object | Undo, queue, macro |
| **Observer** | Device state changes notify listeners | Dashboard updates |
| **Strategy** | Different command parsers (voice, text, API) | Swappable input handling |
| **Composite** | Device groups (Room contains Devices) | Uniform treatment |
| **Factory** | Create device-specific commands | Decouple creation from usage |

<br>

---

## Core Entities

```
VoiceAssistant → CommandParser → Command → Device
                                    │
                    ┌───────────────┼──────────────┐
                 LightCommand  ThermostatCommand  LockCommand

Device (interface)
├── Light (on/off/brightness/color)
├── Thermostat (temperature)
├── SmartLock (lock/unlock)
├── Speaker (play/pause/volume)

DeviceGroup implements Device (Composite)
├── devices: List<Device>

Routine
├── name, commands: List<Command>
├── execute() → runs all commands in sequence
```

<br>

---

## Interview Tips

- Command pattern is the core — every voice action becomes a serializable command
- Composite for device groups — "turn off living room" = turn off all devices in group
- Routine = Macro Command (list of commands executed sequentially)
- Mention extensibility: new device types, new skills without modifying core
