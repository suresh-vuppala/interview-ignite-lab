// Chain of Responsibility — Logging Framework
abstract class Logger {
    protected LogLevel level;
    protected Logger nextLogger;
    
    public Logger setNext(Logger next) { this.nextLogger = next; return next; }
    
    public void log(LogLevel msgLevel, String message) {
        if (msgLevel.ordinal() >= this.level.ordinal()) {
            write(message);
        }
        if (nextLogger != null) {
            nextLogger.log(msgLevel, message);
        }
    }
    
    protected abstract void write(String message);
}

enum LogLevel { DEBUG, INFO, WARN, ERROR }

class ConsoleLogger extends Logger {
    public ConsoleLogger() { this.level = LogLevel.DEBUG; }
    protected void write(String msg) { System.out.println("[CONSOLE] " + msg); }
}

class FileLogger extends Logger {
    public FileLogger() { this.level = LogLevel.INFO; }
    protected void write(String msg) { System.out.println("[FILE] " + msg); }
}

class ErrorAlertLogger extends Logger {
    public ErrorAlertLogger() { this.level = LogLevel.ERROR; }
    protected void write(String msg) { System.out.println("[ALERT] 🚨 " + msg); }
}

// Chain: Console(DEBUG+) → File(INFO+) → Alert(ERROR+)
// Logger chain = new ConsoleLogger();
// chain.setNext(new FileLogger()).setNext(new ErrorAlertLogger());
// chain.log(LogLevel.DEBUG, "Debug message");  // Console only
// chain.log(LogLevel.INFO, "Info message");     // Console + File
// chain.log(LogLevel.ERROR, "Error!!!");        // Console + File + Alert
