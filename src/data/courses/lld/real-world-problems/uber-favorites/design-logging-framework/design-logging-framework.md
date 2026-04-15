# Design a Logging Framework (Chain of Responsibility)

Design a flexible logging framework supporting multiple log levels, output targets, and formatting.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **Log levels** — DEBUG, INFO, WARN, ERROR, FATAL (ordered by severity)
2. **Multiple outputs** — Console, File, Database, Remote server (simultaneously)
3. **Log formatting** — timestamp, level, thread name, class name, message
4. **Level filtering** — each handler has a minimum level; only processes messages at or above
5. **Singleton logger** — one logger instance per application
6. **Thread-safe** — concurrent logging from multiple threads

### Extended Requirements (If Time Permits)

1. Async logging with background queue (Producer-Consumer)
2. Log rotation (new file per day or per size limit)
3. Structured logging (JSON output for ELK stack)
4. MDC (Mapped Diagnostic Context) for request tracing
5. Performance metrics (log throughput, queue depth)
6. Dynamic level change at runtime (no restart)

<br>

---

## Constraints

- Log levels (ordered): DEBUG(0) < INFO(1) < WARN(2) < ERROR(3) < FATAL(4)
- Log message max size: 10 KB
- File handler: max file size 100 MB, then rotate
- Async queue size: 10,000 messages
- Timestamp format: ISO-8601 (`2024-01-15T14:30:00.123Z`)
- Thread-safe for 100+ concurrent logging threads

<br>

---

## Identify Primary Actors

1. **Application Code** — generates log messages
   - Actions: logger.info("message"), logger.error("message", exception)

2. **Logger** — routes messages to handlers
   - Actions: accept message, check global level, forward to handler chain

3. **Log Handlers** — write messages to specific destinations
   - Actions: filter by level, format message, write to output

4. **Admin** — configures logging
   - Actions: set log levels, add/remove handlers, configure output destinations

<br>

---

## Core Entities

### 1. Logger (Singleton)
- **Attributes**: handlerChain: LogHandler, globalLevel: LogLevel
- **Methods**: log(level, message), debug(), info(), warn(), error(), fatal()
- **Responsibilities**: Central entry point, route to handler chain

### 2. LogMessage
- **Attributes**: level, message, timestamp, threadName, className, exception (optional)
- **Responsibilities**: Immutable value object carrying log data

### 3. LogHandler (Abstract — Chain of Responsibility)
- **Attributes**: minLevel, nextHandler, formatter
- **Methods**: handle(LogMessage), write(formattedString)
- **Responsibilities**: Filter by level, format, write to destination, pass to next

### 4. Concrete Handlers
- **ConsoleHandler**: writes to System.out/System.err
- **FileHandler**: writes to file with rotation
- **DatabaseHandler**: inserts into log table

### 5. LogFormatter (Interface — Strategy Pattern)
- **Method**: format(LogMessage): String
- **Implementations**: PlainFormatter, JSONFormatter, XMLFormatter

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Type |
|----------|-------------|----------|------|
| Logger (Singleton) | chains | LogHandler | Composition (◆) |
| LogHandler | chains to | LogHandler (next) | Association (linked list) |
| LogHandler | uses | LogFormatter | Composition (◆) |
| ConsoleHandler | extends | LogHandler | Inheritance |
| FileHandler | extends | LogHandler | Inheritance |
| PlainFormatter | implements | LogFormatter | Implementation |
| JSONFormatter | implements | LogFormatter | Implementation |

<br>

---

## Relationships Diagram (Textual UML)

```
  Logger (Singleton)
  -handlerChain: LogHandler ◆
  -globalLevel: LogLevel
  +log(), +debug(), +info(), +warn(), +error(), +fatal()
       │
       ▼
  LogHandler (abstract — Chain)
  -minLevel, -next → LogHandler
  -formatter: LogFormatter ◆
  +handle(LogMessage)
  #write(String) — abstract
       △
  ┌────┼──────────┬──────────────┐
Console      File         Database
Handler      Handler      Handler

  Message flow: logger.error("msg")
  → ConsoleHandler(DEBUG) → writes ✅
  → FileHandler(INFO) → writes ✅
  → DatabaseHandler(ERROR) → writes ✅
  (each handler processes AND passes to next)


  <<interface>> LogFormatter
  +format(LogMessage): String
       △
  ┌────┼────┐
Plain   JSON  XML
```

<br>

---

## Design Patterns Used

### 1. **Chain of Responsibility**
- **Where**: LogHandler chain — Console → File → Database
- **Why**: Each handler decides whether to process based on its minLevel, then ALWAYS passes to next
- **Key difference from approval chain**: Logging chain does NOT stop — every matching handler processes
- **Benefit**: Add/remove handlers without changing logger or other handlers

### 2. **Strategy Pattern**
- **Where**: LogFormatter — Plain, JSON, XML formatting
- **Why**: Different outputs need different formats (console=plain, ELK=JSON)
- **Benefit**: Each handler can use a different formatter

### 3. **Singleton Pattern**
- **Where**: Logger instance — one per application
- **Why**: All classes share the same logger configuration
- **Benefit**: Configure once, use everywhere

### 4. **Producer-Consumer** (extended — async logging)
- **Where**: Log messages queued → background thread writes
- **Why**: Logging shouldn't block application threads
- **Benefit**: Application thread returns immediately, writing happens asynchronously

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms
- **Logger methods**: Thread-safe — LogMessage is immutable, created per call
- **Handler chain traversal**: Read-only during logging — safe for concurrent access
- **File writing**: `synchronized(fileWriter)` or use `BufferedWriter` with explicit lock
- **Async mode**: `BlockingQueue<LogMessage>` between producer (app) and consumer (writer thread)

### Race Conditions Handled
- **Two threads logging simultaneously**: Each creates own LogMessage (immutable) — no shared state
- **Dynamic handler chain modification**: Use `volatile` reference to chain head; swap atomically
- **File rotation during write**: Lock file handler, close old file, open new, release lock

<br>

---

## Edge Cases & Error Handling

### Edge Cases
1. **Null message** — log "(null)" or skip with warning
2. **Exception in handler** — catch, log to stderr, continue chain (never break logging)
3. **File system full** — FileHandler fails → fall through to ConsoleHandler
4. **Database connection lost** — DatabaseHandler skips, retries next message
5. **Circular handler chain** — detect during setup, throw ConfigurationException
6. **Log level FATAL** — should it terminate application? (Configurable)
7. **Very large message (> 10KB)** — truncate with "[TRUNCATED]" suffix
8. **Logging from within a log handler** — prevent infinite recursion with re-entrancy guard

### Error Handling Strategy
- **Handler failure**: Catch exception, write to stderr, continue to next handler — NEVER break the chain
- **Configuration error**: Fail fast at startup with clear error message
- **Queue overflow (async)**: Drop oldest messages or block producer (configurable)

<br>

---

## Implementation

> See the **Java code tab** for the complete implementation including Chain of Responsibility handler chain, Strategy-based formatters (Plain + JSON), Singleton logger, and log level filtering.
