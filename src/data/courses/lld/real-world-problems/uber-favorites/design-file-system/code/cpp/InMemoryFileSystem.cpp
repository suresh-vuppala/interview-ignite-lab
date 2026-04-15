#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <sstream>
#include <regex>
#include <deque>
using namespace std;

class FileSystemNode {
protected:
    string name;
    FileSystemNode* parent = nullptr;
public:
    FileSystemNode(const string& name) : name(name) {}
    virtual ~FileSystemNode() = default;
    const string& getName() const { return name; }
    virtual bool isDirectory() const { return false; }
    FileSystemNode* getParent() const { return parent; }
    void setParent(FileSystemNode* p) { parent = p; }
};

class File : public FileSystemNode {
    string content;
public:
    File(const string& name) : FileSystemNode(name) {}
    const string& getContent() const { return content; }
    void setContent(const string& c) { content = c; }
    int getSize() const { return content.size(); }
};

class Directory : public FileSystemNode {
    unordered_map<string, shared_ptr<FileSystemNode>> children;
public:
    Directory(const string& name) : FileSystemNode(name) {}
    bool isDirectory() const override { return true; }
    
    void addChild(shared_ptr<FileSystemNode> node) {
        children[node->getName()] = node;
        node->setParent(this);
    }
    void removeChild(const string& name) { children.erase(name); }
    FileSystemNode* getChild(const string& name) {
        auto it = children.find(name);
        return it != children.end() ? it->second.get() : nullptr;
    }
    vector<FileSystemNode*> listChildren() {
        vector<FileSystemNode*> result;
        for (auto& [k, v] : children) result.push_back(v.get());
        return result;
    }
    vector<FileSystemNode*> listMatching(const string& pattern) {
        string regexStr = pattern;
        // Replace * with .* for regex
        for (size_t i = 0; i < regexStr.size(); i++) {
            if (regexStr[i] == '.') { regexStr.insert(i, "\\"); i++; }
            else if (regexStr[i] == '*') { regexStr.replace(i, 1, ".*"); i++; }
        }
        vector<FileSystemNode*> result;
        regex re(regexStr);
        for (auto& [k, v] : children)
            if (regex_match(k, re)) result.push_back(v.get());
        return result;
    }
};

class FileSystem {
    shared_ptr<Directory> root;
    Directory* currentDir;
public:
    FileSystem() : root(make_shared<Directory>("/")), currentDir(root.get()) {}
    
    void mkdir(const string& path) {
        istringstream ss(path); string part;
        Directory* dir = path[0] == '/' ? root.get() : currentDir;
        while (getline(ss, part, '/')) {
            if (part.empty()) continue;
            auto* child = dir->getChild(part);
            if (!child) {
                auto newDir = make_shared<Directory>(part);
                dir->addChild(newDir);
                dir = static_cast<Directory*>(newDir.get());
            } else if (child->isDirectory()) {
                dir = static_cast<Directory*>(child);
            }
        }
    }
    
    void touch(const string& name) {
        if (!currentDir->getChild(name))
            currentDir->addChild(make_shared<File>(name));
    }
    
    void cd(const string& path) {
        if (path == "/") { currentDir = root.get(); return; }
        if (path == "..") {
            if (currentDir->getParent())
                currentDir = static_cast<Directory*>(currentDir->getParent());
            return;
        }
        auto* node = currentDir->getChild(path);
        if (node && node->isDirectory()) currentDir = static_cast<Directory*>(node);
        else throw runtime_error("Directory not found: " + path);
    }
    
    string pwd() {
        deque<string> parts;
        auto* d = currentDir;
        while (d && d != root.get()) { parts.push_front(d->getName()); d = static_cast<Directory*>(d->getParent()); }
        string result = "/";
        for (auto& p : parts) result += p + "/";
        if (result.size() > 1) result.pop_back();
        return result;
    }
    
    vector<string> ls(const string& pattern = "") {
        vector<FileSystemNode*> items;
        if (!pattern.empty() && pattern.find('*') != string::npos)
            items = currentDir->listMatching(pattern);
        else items = currentDir->listChildren();
        
        vector<string> result;
        for (auto* n : items)
            result.push_back(n->getName() + (n->isDirectory() ? "/" : ""));
        return result;
    }
};
