#include <string>
#include <map>
#include <vector>
#include <memory>
#include <deque>
#include <regex>
#include <iostream>
#include <algorithm>
using namespace std;

class FileSystemNode {
protected:
    string name;
    FileSystemNode* parent = nullptr;
public:
    FileSystemNode(string n) : name(move(n)) {}
    virtual ~FileSystemNode() = default;
    const string& getName() const { return name; }
    virtual bool isDirectory() const { return false; }
    FileSystemNode* getParent() const { return parent; }
    void setParent(FileSystemNode* p) { parent = p; }
};

class File : public FileSystemNode {
    string content;
public:
    File(string name) : FileSystemNode(move(name)) {}
    const string& getContent() const { return content; }
    void setContent(const string& c) { content = c; }
    int getSize() const { return content.size(); }
};

class Directory : public FileSystemNode {
    map<string, shared_ptr<FileSystemNode>> children;
public:
    Directory(string name) : FileSystemNode(move(name)) {}
    bool isDirectory() const override { return true; }
    void addChild(shared_ptr<FileSystemNode> node) { node->setParent(this); children[node->getName()] = move(node); }
    void removeChild(const string& name) { children.erase(name); }
    FileSystemNode* getChild(const string& name) const {
        auto it = children.find(name);
        return it != children.end() ? it->second.get() : nullptr;
    }
    vector<string> list(const string& pattern = "") const {
        vector<string> result;
        string regexPat = pattern.empty() ? ".*" : regex_replace(regex_replace(pattern, regex("\."), "\\."), regex("\*"), ".*");
        regex re(regexPat);
        for (auto& [name, node] : children)
            if (pattern.empty() || regex_match(name, re))
                result.push_back(name + (node->isDirectory() ? "/" : ""));
        return result;
    }
};

class FileSystem {
    shared_ptr<Directory> root;
    Directory* currentDir;
public:
    FileSystem() : root(make_shared<Directory>("/")), currentDir(root.get()) {}

    void mkdir(const string& path) {
        Directory* dir = path[0] == '/' ? root.get() : currentDir;
        size_t pos = 0; string token;
        string p = path;
        while ((pos = p.find('/')) != string::npos || !p.empty()) {
            token = (pos != string::npos) ? p.substr(0, pos) : p;
            p = (pos != string::npos) ? p.substr(pos + 1) : "";
            if (token.empty()) continue;
            auto* child = dir->getChild(token);
            if (!child) { auto nd = make_shared<Directory>(token); dir->addChild(nd); dir = static_cast<Directory*>(nd.get()); }
            else if (child->isDirectory()) dir = static_cast<Directory*>(child);
            else throw runtime_error(token + " is a file");
            if (pos == string::npos) break;
        }
    }

    void touch(const string& name) {
        if (!currentDir->getChild(name)) currentDir->addChild(make_shared<File>(name));
    }

    void cd(const string& path) {
        if (path == "/") { currentDir = root.get(); return; }
        if (path == "..") { if (currentDir->getParent()) currentDir = static_cast<Directory*>(currentDir->getParent()); return; }
        auto* node = currentDir->getChild(path);
        if (node && node->isDirectory()) currentDir = static_cast<Directory*>(node);
        else throw runtime_error("Directory not found: " + path);
    }

    string pwd() const {
        deque<string> parts;
        auto* d = currentDir;
        while (d && d != root.get()) { parts.push_front(d->getName()); d = static_cast<Directory*>(d->getParent()); }
        string result = "/";
        for (auto& p : parts) result += p + "/";
        return result.size() > 1 ? result.substr(0, result.size()-1) : result;
    }

    vector<string> ls(const string& pattern = "") const { return currentDir->list(pattern); }
};
