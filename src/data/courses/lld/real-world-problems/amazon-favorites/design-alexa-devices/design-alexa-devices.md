# Design for Amazon Alexa Devices

Design a voice assistant system that processes voice commands, controls smart home devices, and manages routines.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **Voice command processing** — parse commands, identify intent (turn on/off, set temp, play music)
2. **Device control** — lights (on/off/brightness/color), thermostat (temperature), locks (lock/unlock), speakers (play/pause/volume)
3. **Device groups** — control all devices in a room ("turn off living room")
4. **Routines** — "Good Morning" triggers: lights on + thermostat 72°F + news briefing
5. **Undo last command** — reverse the most recent action
6. **Device status** — query current state of any device

### Extended Requirements (If Time Permits)

1. Skills/Plugins — third-party app integrations
2. Voice profiles — different users with personalized settings
3. Scheduling — "turn off lights at 10 PM"
4. Scenes — preset configurations (Movie mode, Party mode)
5. Device discovery — auto-detect new devices on network
6. Multi-room audio — sync music across multiple speakers

<br>

---

## Constraints

- Maximum 100 devices per home
- Maximum 20 device groups
- Maximum 50 routines
- Command processing latency: < 500ms
- Device types: Light, Thermostat, SmartLock, Speaker, Camera
- Routine max steps: 20 commands

<br>

---

## Identify Primary Actors

1. **User** — speaks voice commands, creates routines
   - Actions: issue commands, create/edit routines, group devices, query status

2. **Voice Assistant (Alexa)** — central hub processing commands
   - Actions: parse voice, match intent, execute commands, manage state

3. **Smart Devices** — physical devices that receive commands
   - Actions: execute on/off, report status, send state change events

4. **Admin** — configures system
   - Actions: add/remove devices, manage network, set permissions

<br>

---

## Core Entities

### 1. VoiceAssistant
- **Attributes**: devices: Map, groups: Map, routines: List, commandHistory: Stack
- **Responsibilities**: Central hub — parse commands, route to devices, manage undo stack

### 2. SmartDevice (Interface)
- **Methods**: getName(), turnOn(), turnOff(), isOn(), getStatus()
- **Implementations**: SmartLight, SmartThermostat, SmartLock, SmartSpeaker

### 3. DeviceGroup (Composite — implements SmartDevice)
- **Attributes**: name, devices: List<SmartDevice>
- **Responsibilities**: Treat group of devices as single device — "turn off living room"

### 4. DeviceCommand (Interface — Command Pattern)
- **Methods**: execute(), undo()
- **Implementations**: TurnOnCommand, TurnOffCommand, SetTemperatureCommand, SetBrightnessCommand

### 5. Routine (Macro Command)
- **Attributes**: name, commands: List<DeviceCommand>, schedule (optional)
- **Responsibilities**: Execute sequence of commands as single action, support undo all

### 6. CommandHistory
- **Attributes**: undoStack: Stack<DeviceCommand>
- **Responsibilities**: Track executed commands for undo functionality

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Type |
|----------|-------------|----------|------|
| VoiceAssistant | manages | SmartDevice[] | Aggregation (◇) |
| VoiceAssistant | manages | DeviceGroup[] | Aggregation (◇) |
| VoiceAssistant | stores | CommandHistory | Composition (◆) |
| DeviceGroup | contains | SmartDevice[] | Aggregation (◇) |
| DeviceGroup | implements | SmartDevice | Implementation |
| Routine | contains | DeviceCommand[] | Composition (◆) |
| TurnOnCommand | targets | SmartDevice | Association |
| SmartLight | implements | SmartDevice | Implementation |
| SmartThermostat | implements | SmartDevice | Implementation |

<br>

---

## Relationships Diagram (Textual UML)

```
  VoiceAssistant
  -devices, -groups, -routines
  -commandHistory: Stack<DeviceCommand>
       │
       ├──◇──→ SmartDevice (interface)
       │         +turnOn(), +turnOff(), +isOn()
       │              △
       │         ┌────┼────┬────┐
       │      Light  Thermo  Lock  Speaker
       │
       ├──◇──→ DeviceGroup ◇──→ SmartDevice[]
       │        (implements SmartDevice — Composite)
       │
       └──◆──→ Routine ◆──→ DeviceCommand[]
                              +execute(), +undo()
                                   △
                              ┌────┼────┐
                         TurnOn  TurnOff  SetTemp
```

<br>

---

## Design Patterns Used

### 1. **Command Pattern**
- **Where**: Every device action is encapsulated as a DeviceCommand object
- **Why**: Commands can be stored, undone, queued, and composed into routines
- **Benefit**: Full undo/redo support, routine = list of commands, scheduling = delayed command

### 2. **Composite Pattern**
- **Where**: DeviceGroup implements SmartDevice — contains multiple devices
- **Why**: "Turn off living room" treats the group identically to a single device
- **Benefit**: Uniform interface — client code doesn't distinguish device from group

### 3. **Observer Pattern**
- **Where**: Device state changes notify dashboard/app listeners
- **Why**: UI updates automatically when device state changes
- **Benefit**: Decoupled — devices don't know about the UI

### 4. **Factory Pattern**
- **Where**: Create device-specific commands from voice intent
- **Why**: Voice parser identifies intent → factory creates appropriate command object
- **Benefit**: Decouples parsing from execution

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms
- **Command execution**: Queue commands in `BlockingQueue`, process sequentially per device
- **Device state**: Each device uses `synchronized` for state changes
- **Routine execution**: Commands in a routine execute sequentially (not parallel)
- **Command history**: `ConcurrentLinkedDeque` for thread-safe undo stack

### Race Conditions Handled
- **Two voice commands for same device**: Queue ensures sequential processing
- **Routine overlapping manual command**: Routine takes precedence, manual command queued after
- **Undo during routine execution**: Block undo until routine completes

<br>

---

## Edge Cases & Error Handling

### Edge Cases
1. **Device offline/unreachable** — skip, report failure, continue with remaining devices in group
2. **Undo with empty history** — no-op, display "Nothing to undo"
3. **Routine with failed command** — continue remaining commands, report partial failure
4. **Conflicting commands** — "turn on lights" then "turn off lights" in same routine → last wins
5. **Unknown device in command** — "turn on garage" but no garage device → error with suggestion
6. **Device added to multiple groups** — allowed, same device in "Living Room" and "All Lights"
7. **Undo a routine** — reverses ALL commands in reverse order
8. **Command timeout** — device doesn't respond within 5 seconds → mark as failed

### Error Handling Strategy
- **DeviceNotFoundException**: Unknown device name → suggest similar device names
- **DeviceOfflineException**: Device unreachable → retry once, then report failure
- **CommandTimeoutException**: No response → mark device as potentially offline
- **InvalidCommandException**: Unrecognized intent → "Sorry, I didn't understand that"

<br>

---

## Implementation

> See the **Java code tab** for the complete implementation including Command pattern for device actions, Composite for device groups, Macro command for routines, and undo support via command history stack.
