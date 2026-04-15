#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <thread>
using namespace std;

enum class LogLevel { DEBUG, INFO, WARN, ERROR, FATAL };

string logLevelStr(LogLevel l) {
    switch(l) { case LogLevel::DEBUG:return"DEBUG"; case LogLevel::INFO:return"INFO";
    case LogLevel::WARN:return"WARN"; case LogLevel::ERROR:return"ERROR"; case LogLevel::FATAL:return"FATAL"; }
    return"";
}

struct LogMessage {
    LogLevel level;
    string message, threadName;
    string timestamp;
    
    LogMessage(LogLevel lvl, const string& msg) : level(lvl), message(msg) {
        auto now = chrono::system_clock::now();
        auto t = chrono::system_clock::to_time_t(now);
        stringstream ss; ss << put_time(localtime(&t), "%Y-%m-%d %H:%M:%S");
        timestamp = ss.str();
        
        stringstream tid; tid << this_thread::get_id();
        threadName = "Thread-" + tid.str();
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
        return "[" + msg.timestamp + "] [" + logLevelStr(msg.level) + "] [" + msg.threadName + "] " + msg.message;
    }
};

class JSONFormatter : public LogFormatter {
public:
    string format(const LogMessage& msg) const override {
        return "{"timestamp":"" + msg.timestamp + "","level":"" + logLevelStr(msg.level) + 
               "","thread":"" + msg.threadName + "","message":"" + msg.message + ""}";
    }
};

// ========== HANDLER (Chain of Responsibility) ==========
class LogHandler {
protected:
    LogLevel minLevel;
    shared_ptr<LogHandler> next;
    shared_ptr<LogFormatter> formatter;
public:
    LogHandler(LogLevel minLvl, shared_ptr<LogFormatter> fmt) : minLevel(minLvl), formatter(fmt) {}
    virtual ~LogHandler() = default;
    
    shared_ptr<LogHandler> setNext(shared_ptr<LogHandler> handler) { next = handler; return handler; }
    
    void handle(const LogMessage& msg) {
        if ((int)msg.level >= (int)minLevel) write(formatter->format(msg));
        if (next) next->handle(msg);
    }
    
    virtual void write(const string& formatted) = 0;
};

class ConsoleHandler : public LogHandler {
public:
    ConsoleHandler(LogLevel min, shared_ptr<LogFormatter> fmt) : LogHandler(min, fmt) {}
    void write(const string& msg) override { cout << msg << endl; }
};

class FileHandler : public LogHandler {
    string filename;
public:
    FileHandler(LogLevel min, shared_ptr<LogFormatter> fmt, const string& file)
        : LogHandler(min, fmt), filename(file) {}
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
    
    void setHandlerChain(shared_ptr<LogHandler> chain) { handlerChain = chain; }
    
    void log(LogLevel level, const string& message) {
        if (handlerChain) handlerChain->handle(LogMessage(level, message));
    }
    void debug(const string& msg) { log(LogLevel::DEBUG, msg); }
    void info(const string& msg) { log(LogLevel::INFO, msg); }
    void warn(const string& msg) { log(LogLevel::WARN, msg); }
    void error(const string& msg) { log(LogLevel::ERROR, msg); }
    void fatal(const string& msg) { log(LogLevel::FATAL, msg); }
};

// Setup:
// auto plainFmt = make_shared<PlainFormatter>();
// auto jsonFmt = make_shared<JSONFormatter>();
// auto console = make_shared<ConsoleHandler>(LogLevel::DEBUG, plainFmt);
// auto file = make_shared<FileHandler>(LogLevel::INFO, jsonFmt, "app.log");
// console->setNext(file);
// Logger::getInstance().setHandlerChain(console);
// Logger::getInstance().info("Server started");
