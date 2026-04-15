// Logging Framework — Chain of Responsibility + Strategy
import java.util.*;
import java.time.*;
import java.time.format.*;

enum LogLevel { DEBUG, INFO, WARN, ERROR, FATAL }

class LogMessage {
    private LogLevel level;
    private String message;
    private String threadName;
    private LocalDateTime timestamp;
    
    public LogMessage(LogLevel level, String message) {
        this.level = level; this.message = message;
        this.threadName = Thread.currentThread().getName();
        this.timestamp = LocalDateTime.now();
    }
    public LogLevel getLevel() { return level; }
    public String getMessage() { return message; }
    public String getThreadName() { return threadName; }
    public LocalDateTime getTimestamp() { return timestamp; }
}

// Formatter (Strategy)
interface LogFormatter {
    String format(LogMessage msg);
}

class PlainFormatter implements LogFormatter {
    private static final DateTimeFormatter FMT = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
    public String format(LogMessage msg) {
        return String.format("[%s] [%-5s] [%s] %s",
            msg.getTimestamp().format(FMT), msg.getLevel(), msg.getThreadName(), msg.getMessage());
    }
}

class JSONFormatter implements LogFormatter {
    public String format(LogMessage msg) {
        return String.format("{"timestamp":"%s","level":"%s","thread":"%s","message":"%s"}",
            msg.getTimestamp(), msg.getLevel(), msg.getThreadName(), msg.getMessage());
    }
}

// Handler (Chain of Responsibility)
abstract class LogHandler {
    protected LogLevel minLevel;
    protected LogHandler next;
    protected LogFormatter formatter;
    
    public LogHandler(LogLevel minLevel, LogFormatter formatter) {
        this.minLevel = minLevel; this.formatter = formatter;
    }
    
    public LogHandler setNext(LogHandler handler) { this.next = handler; return handler; }
    
    public void handle(LogMessage msg) {
        if (msg.getLevel().ordinal() >= minLevel.ordinal()) {
            write(formatter.format(msg));
        }
        if (next != null) next.handle(msg); // Always pass along (unlike approval chain)
    }
    
    protected abstract void write(String formattedMsg);
}

class ConsoleHandler extends LogHandler {
    public ConsoleHandler(LogLevel min, LogFormatter fmt) { super(min, fmt); }
    protected void write(String msg) { System.out.println(msg); }
}

class FileHandler extends LogHandler {
    private String filename;
    public FileHandler(LogLevel min, LogFormatter fmt, String filename) {
        super(min, fmt); this.filename = filename;
    }
    protected void write(String msg) {
        // In real impl: write to file
        System.out.println("[FILE:" + filename + "] " + msg);
    }
}

// Logger (Singleton)
class Logger {
    private static volatile Logger instance;
    private LogHandler handlerChain;
    
    private Logger() {}
    
    public static Logger getInstance() {
        if (instance == null) {
            synchronized (Logger.class) {
                if (instance == null) instance = new Logger();
            }
        }
        return instance;
    }
    
    public void setHandlerChain(LogHandler chain) { this.handlerChain = chain; }
    
    public void log(LogLevel level, String message) {
        if (handlerChain != null) handlerChain.handle(new LogMessage(level, message));
    }
    
    public void debug(String msg) { log(LogLevel.DEBUG, msg); }
    public void info(String msg) { log(LogLevel.INFO, msg); }
    public void warn(String msg) { log(LogLevel.WARN, msg); }
    public void error(String msg) { log(LogLevel.ERROR, msg); }
    public void fatal(String msg) { log(LogLevel.FATAL, msg); }
}

// Setup:
// LogHandler console = new ConsoleHandler(LogLevel.DEBUG, new PlainFormatter());
// LogHandler file = new FileHandler(LogLevel.INFO, new JSONFormatter(), "app.log");
// console.setNext(file);
// Logger.getInstance().setHandlerChain(console);
// Logger.getInstance().info("Server started"); // → console + file
// Logger.getInstance().debug("Detail");         // → console only
