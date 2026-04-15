# Design a Logging Framework

Design a flexible logging framework supporting multiple log levels, output targets, and formatting.

<br>

---

## Requirements

### Main Requirements
1. **Log levels** — DEBUG, INFO, WARN, ERROR, FATAL
2. **Multiple outputs** — Console, File, Database, Remote server
3. **Log formatting** — timestamp, level, message, thread, class name
4. **Level filtering** — only log messages at or above configured level
5. **Singleton logger** — one logger instance per application
6. **Thread-safe** — concurrent logging from multiple threads

<br>

---

## Design Patterns Used

| Pattern | Where | Why |
|---------|-------|-----|
| **Chain of Responsibility** | Log handlers (Console → File → Remote) | Each handler processes or passes |
| **Strategy** | Log formatters (JSON, Plain, XML) | Swappable formatting |
| **Singleton** | Logger instance | One per application |
| **Observer** | Log listeners for monitoring | Alert on ERROR/FATAL |

<br>

---

## Core Entities

```
Logger (Singleton)
├─ handlers: List<LogHandler>
├─ minLevel: LogLevel
├─ log(level, message)
├─ debug(), info(), warn(), error(), fatal()

LogHandler (abstract — Chain)
├── ConsoleHandler
├── FileHandler
├── DatabaseHandler

LogFormatter (Strategy)
├── PlainFormatter: "[2024-01-01 12:00:00] [INFO] message"
├── JSONFormatter: {"timestamp":"...","level":"INFO","message":"..."}
```

<br>

---

## Interview Tips

- Chain of Responsibility: each handler decides whether to process AND whether to pass along
- Unlike approval chain (stops at first handler), logging chain processes at EVERY matching handler
- Discuss: async logging with queue (Producer-Consumer) for performance
- Real-world: Log4j, SLF4J, Logback all use these patterns
