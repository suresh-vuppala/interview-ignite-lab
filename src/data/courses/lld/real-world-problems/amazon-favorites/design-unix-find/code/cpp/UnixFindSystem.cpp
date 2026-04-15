#include <string>
#include <vector>
#include <memory>
#include <regex>
#include <iostream>
#include <chrono>
using namespace std;

// ========== FILE SYSTEM (Composite Pattern) ==========
class FileSystemEntry {
protected:
    string name, path;
    long size;
public:
    FileSystemEntry(string name, string path, long size)
        : name(move(name)), path(move(path)), size(size) {}
    virtual ~FileSystemEntry() = default;
    const string& getName() const { return name; }
    const string& getPath() const { return path; }
    virtual long getSize() const { return size; }
    virtual bool isDirectory() const { return false; }
};

class File : public FileSystemEntry {
    string extension;
public:
    File(string name, string path, long size) : FileSystemEntry(move(name), move(path), size) {
        auto dot = this->name.rfind('.');
        extension = (dot != string::npos) ? this->name.substr(dot + 1) : "";
    }
    const string& getExtension() const { return extension; }
};

class Directory : public FileSystemEntry {
    vector<shared_ptr<FileSystemEntry>> children;
public:
    Directory(string name, string path) : FileSystemEntry(move(name), move(path), 0) {}
    bool isDirectory() const override { return true; }
    void add(shared_ptr<FileSystemEntry> entry) { children.push_back(move(entry)); }
    const vector<shared_ptr<FileSystemEntry>>& getChildren() const { return children; }
    long getSize() const override {
        long total = 0;
        for (auto& c : children) total += c->getSize();
        return total;
    }
};

// ========== FILTERS (Strategy Pattern) ==========
class Filter {
public:
    virtual ~Filter() = default;
    virtual bool matches(const FileSystemEntry& entry) const = 0;
};

class NameFilter : public Filter {
    regex pattern;
public:
    NameFilter(const string& pat) {
        string regexPat = regex_replace(pat, regex("\*"), ".*");
        regexPat = regex_replace(regexPat, regex("\?"), ".");
        pattern = regex(regexPat);
    }
    bool matches(const FileSystemEntry& entry) const override {
        return regex_match(entry.getName(), pattern);
    }
};

class ExtensionFilter : public Filter {
    string ext;
public:
    ExtensionFilter(string ext) : ext(move(ext)) {}
    bool matches(const FileSystemEntry& entry) const override {
        auto* file = dynamic_cast<const File*>(&entry);
        return file && file->getExtension() == ext;
    }
};

enum class SizeOp { GT, LT, EQ };
class SizeFilter : public Filter {
    long threshold; SizeOp op;
public:
    SizeFilter(long threshold, SizeOp op) : threshold(threshold), op(op) {}
    bool matches(const FileSystemEntry& entry) const override {
        switch (op) {
            case SizeOp::GT: return entry.getSize() > threshold;
            case SizeOp::LT: return entry.getSize() < threshold;
            case SizeOp::EQ: return entry.getSize() == threshold;
        }
        return false;
    }
};

// Composite Filters
class ANDFilter : public Filter {
    vector<shared_ptr<Filter>> filters;
public:
    ANDFilter(initializer_list<shared_ptr<Filter>> fs) : filters(fs) {}
    bool matches(const FileSystemEntry& entry) const override {
        for (auto& f : filters) if (!f->matches(entry)) return false;
        return true;
    }
};

class ORFilter : public Filter {
    vector<shared_ptr<Filter>> filters;
public:
    ORFilter(initializer_list<shared_ptr<Filter>> fs) : filters(fs) {}
    bool matches(const FileSystemEntry& entry) const override {
        for (auto& f : filters) if (f->matches(entry)) return true;
        return false;
    }
};

// ========== FINDER ==========
class UnixFind {
    void searchRecursive(const Directory& dir, const Filter& filter,
                         vector<shared_ptr<FileSystemEntry>>& results) {
        for (auto& entry : dir.getChildren()) {
            if (filter.matches(*entry)) results.push_back(entry);
            auto* subDir = dynamic_cast<Directory*>(entry.get());
            if (subDir) searchRecursive(*subDir, filter, results);
        }
    }
public:
    vector<shared_ptr<FileSystemEntry>> search(const Directory& root, const Filter& filter) {
        vector<shared_ptr<FileSystemEntry>> results;
        searchRecursive(root, filter, results);
        return results;
    }
};
