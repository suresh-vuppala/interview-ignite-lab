// DESIGN: Logging Framework — LLD (Java) | CoR + Strategy + Singleton
import java.util.*;
import java.time.*;
import java.time.format.*;
enum LogLevel { DEBUG, INFO, WARN, ERROR, FATAL }
class LogMessage { LogLevel level; String message, timestamp;
    LogMessage(LogLevel l,String m){level=l;message=m;timestamp=LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"));}
}
interface LogFormatter { String format(LogMessage msg); }
class PlainFmt implements LogFormatter { public String format(LogMessage m){return "["+m.timestamp+"] ["+m.level+"] "+m.message;} }
class JSONFmt implements LogFormatter { public String format(LogMessage m){return "{ts:"+m.timestamp+",level:"+m.level+",msg:"+m.message+"}";} }
abstract class LogHandler {
    LogLevel minLevel; LogHandler next; LogFormatter formatter;
    LogHandler(LogLevel min,LogFormatter fmt){minLevel=min;formatter=fmt;}
    LogHandler setNext(LogHandler h){next=h;return h;}
    void handle(LogMessage msg){if(msg.level.ordinal()>=minLevel.ordinal())write(formatter.format(msg));if(next!=null)next.handle(msg);}
    abstract void write(String formatted);
}
class ConsoleHandler extends LogHandler {
    ConsoleHandler(LogLevel min,LogFormatter f){super(min,f);} void write(String m){System.out.println(m);}
}
class FileHandler extends LogHandler {
    String file; FileHandler(LogLevel min,LogFormatter f,String file){super(min,f);this.file=file;}
    void write(String m){System.out.println("[FILE:"+file+"] "+m);}
}
class Logger {
    private static Logger instance; LogHandler chain;
    private Logger(){} static Logger getInstance(){if(instance==null)instance=new Logger();return instance;}
    void setChain(LogHandler h){chain=h;}
    void log(LogLevel l,String m){if(chain!=null)chain.handle(new LogMessage(l,m));}
    void debug(String m){log(LogLevel.DEBUG,m);} void info(String m){log(LogLevel.INFO,m);}
    void warn(String m){log(LogLevel.WARN,m);} void error(String m){log(LogLevel.ERROR,m);}
}
public class LoggingFramework {
    public static void main(String[] args) {
        System.out.println("=== Logging — Java ===");
        ConsoleHandler con=new ConsoleHandler(LogLevel.DEBUG,new PlainFmt());
        FileHandler fil=new FileHandler(LogLevel.INFO,new JSONFmt(),"app.log");
        con.setNext(fil);
        Logger.getInstance().setChain(con);
        Logger.getInstance().debug("Starting...");
        Logger.getInstance().info("Server up");
        Logger.getInstance().error("Timeout!");
        System.out.println("=== Complete ===");
    }
}
// SUMMARY: CoR(console->file, ALWAYS passes), Strategy(formatters), Singleton(logger)
