// ===========================================================================
// DESIGN: Logging Framework — Low Level Design
// Patterns: Chain of Responsibility, Strategy, Singleton
// ===========================================================================
// FR: Log levels (DEBUG→FATAL), multiple outputs, formatters, level filtering
// PLANTUML: Logger(Singleton)*--LogHandler(chain), LogHandler-->LogFormatter(Strategy)

#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>
using namespace std;

enum LogLevel { LOG_DEBUG=0, LOG_INFO=1, LOG_WARN=2, LOG_ERROR=3, LOG_FATAL=4 };

string levelStr(LogLevel l) {
    switch(l) { case LOG_DEBUG:return"DEBUG"; case LOG_INFO:return"INFO"; case LOG_WARN:return"WARN";
        case LOG_ERROR:return"ERROR"; case LOG_FATAL:return"FATAL"; }
    return"";
}

struct LogMessage {
    LogLevel level;
    string message, timestamp;
    LogMessage(LogLevel l, const string& m) : level(l), message(m) {
        time_t now = time(0);
        char buf[20];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
        timestamp = string(buf);
    }
};

// Strategy: Formatter
class LogFormatter {
public:
    virtual ~LogFormatter() {}
    virtual string format(const LogMessage& msg) const = 0;
};

class PlainFormatter : public LogFormatter {
public:
    string format(const LogMessage& msg) const {
        return "[" + msg.timestamp + "] [" + levelStr(msg.level) + "] " + msg.message;
    }
};

class JSONFormatter : public LogFormatter {
public:
    string format(const LogMessage& msg) const {
        return "{\"ts\":\"" + msg.timestamp + "\",\"level\":\"" + levelStr(msg.level) + "\",\"msg\":\"" + msg.message + "\"}";
    }
};

// Chain of Responsibility: Handler
class LogHandler {
protected:
    LogLevel minLevel;
    LogHandler* next;
    LogFormatter* formatter;
public:
    LogHandler(LogLevel min, LogFormatter* fmt) : minLevel(min), next(NULL), formatter(fmt) {}
    virtual ~LogHandler() {}
    void setNext(LogHandler* h) { next = h; }

    void handle(const LogMessage& msg) {
        if ((int)msg.level >= (int)minLevel) write(formatter->format(msg));
        if (next) next->handle(msg);  // ALWAYS pass to next (unlike approval chain)
    }

    virtual void write(const string& formatted) = 0;
};

class ConsoleHandler : public LogHandler {
public:
    ConsoleHandler(LogLevel min, LogFormatter* fmt) : LogHandler(min, fmt) {}
    void write(const string& msg) { cout << msg << endl; }
};

class FileHandler : public LogHandler {
    string filename;
public:
    FileHandler(LogLevel min, LogFormatter* fmt, const string& file)
        : LogHandler(min, fmt), filename(file) {}
    void write(const string& msg) { cout << "[FILE:" << filename << "] " << msg << endl; }
};

// Singleton Logger
class Logger {
    LogHandler* chain;
    Logger() : chain(NULL) {}
    Logger(const Logger&);
    static Logger* instance;
public:
    static Logger* getInstance() {
        if (!instance) instance = new Logger();
        return instance;
    }
    void setChain(LogHandler* h) { chain = h; }
    void log(LogLevel level, const string& msg) { if(chain) chain->handle(LogMessage(level, msg)); }
    void debug(const string& m) { log(LOG_DEBUG, m); }
    void info(const string& m)  { log(LOG_INFO, m); }
    void warn(const string& m)  { log(LOG_WARN, m); }
    void error(const string& m) { log(LOG_ERROR, m); }
    void fatal(const string& m) { log(LOG_FATAL, m); }
};
Logger* Logger::instance = NULL;

int main() {
    cout << "============================================\n  Logging Framework — LLD Demo\n============================================" << endl;

    PlainFormatter plain;
    JSONFormatter json;
    ConsoleHandler console(LOG_DEBUG, &plain);  // Console: all levels
    FileHandler file(LOG_INFO, &json, "app.log"); // File: INFO+
    console.setNext(&file);  // Chain: Console -> File

    Logger::getInstance()->setChain(&console);
    Logger::getInstance()->debug("App starting...");     // Console only
    Logger::getInstance()->info("Server listening");      // Console + File
    Logger::getInstance()->warn("High memory usage");     // Console + File
    Logger::getInstance()->error("Connection timeout");   // Console + File
    Logger::getInstance()->fatal("System crash!");         // Console + File

    cout << "\n=== Complete ===" << endl;
    return 0;
}
// SUMMARY: CoR(handler chain processes AND passes), Strategy(formatters), Singleton(logger)
// KEY: Logging chain ALWAYS passes (unlike approval chain that stops)
// PRACTICES: SRP per handler, OCP(new handlers/formatters), DIP(Logger->LogHandler abstraction)
