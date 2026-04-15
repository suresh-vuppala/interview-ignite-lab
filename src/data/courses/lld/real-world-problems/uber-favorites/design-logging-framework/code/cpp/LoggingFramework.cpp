#include <string>
#include <chrono>
#include <ctime>
#include <iostream>
#include <memory>
#include <thread>
#include <sstream>
#include <iomanip>
using namespace std;

enum class LogLevel { DEBUG, INFO, WARN, ERROR, FATAL };

string logLevelToString(LogLevel level) {
    switch (level) {
        case LogLevel::DEBUG: return "DEBUG";
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARN: return "WARN";
        case LogLevel::ERROR: return "ERROR";
        case LogLevel::FATAL: return "FATAL";
    }
    return "UNKNOWN";
}

struct LogMessage {
    LogLevel level;
    string message;
    string threadName;
    string timestamp;

    LogMessage(LogLevel level, string msg) : level(level), message(move(msg)) {
        auto now = chrono::system_clock::now();
        auto t = chrono::system_clock::to_time_t(now);
        ostringstream oss;
        oss << put_time(localtime(&t), "%Y-%m-%d %H:%M:%S");
        timestamp = oss.str();
        ostringstream tid; tid << this_thread::get_id();
        threadName = "thread-" + tid.str();
    }
};

// ========== FORMATTER (Strategy) ==========
class LogFormatter {
public:
    virtual ~LogFormatter() = default;
    virtual string format(const LogMessage& msg) const = 0;
};

class PlainFormatter : public LogFormatter {
public:
    string format(const LogMessage& msg) const override {
        return "[" + msg.timestamp + "] [" + logLevelToString(msg.level) + "] [" + msg.threadName + "] " + msg.message;
    }
};

class JSONFormatter : public LogFormatter {
public:
    string format(const LogMessage& msg) const override {
        return "{"timestamp":"" + msg.timestamp + "","level":"" + logLevelToString(msg.level)
             + "","thread":"" + msg.threadName + "","message":"" + msg.message + ""}";
    }
};

// ========== HANDLER (Chain of Responsibility) ==========
class LogHandler {
protected:
    LogLevel minLevel;
    shared_ptr<LogHandler> next;
    unique_ptr<LogFormatter> formatter;
public:
    LogHandler(LogLevel minLevel, unique_ptr<LogFormatter> fmt)
        : minLevel(minLevel), formatter(move(fmt)) {}
    virtual ~LogHandler() = default;

    LogHandler* setNext(shared_ptr<LogHandler> handler) {
        next = move(handler);
        return next.get();
    }

    void handle(const LogMessage& msg) {
        if ((int)msg.level >= (int)minLevel) write(formatter->format(msg));
        if (next) next->handle(msg);
    }

    virtual void write(const string& formattedMsg) = 0;
};

class ConsoleHandler : public LogHandler {
public:
    ConsoleHandler(LogLevel min, unique_ptr<LogFormatter> fmt) : LogHandler(min, move(fmt)) {}
    void write(const string& msg) override { cout << msg << endl; }
};

class FileHandler : public LogHandler {
    string filename;
public:
    FileHandler(LogLevel min, unique_ptr<LogFormatter> fmt, string fn)
        : LogHandler(min, move(fmt)), filename(move(fn)) {}
    void write(const string& msg) override { cout << "[FILE:" << filename << "] " << msg << endl; }
};

// ========== LOGGER (Singleton) ==========
class Logger {
    shared_ptr<LogHandler> handlerChain;
    Logger() = default;
public:
    static Logger& getInstance() { static Logger instance; return instance; }
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    void setHandlerChain(shared_ptr<LogHandler> chain) { handlerChain = move(chain); }
    void log(LogLevel level, const string& message) {
        if (handlerChain) handlerChain->handle(LogMessage(level, message));
    }
    void debug(const string& msg) { log(LogLevel::DEBUG, msg); }
    void info(const string& msg) { log(LogLevel::INFO, msg); }
    void warn(const string& msg) { log(LogLevel::WARN, msg); }
    void error(const string& msg) { log(LogLevel::ERROR, msg); }
    void fatal(const string& msg) { log(LogLevel::FATAL, msg); }
};
