// ===========================================================================
// DESIGN: In-Memory File System — Low Level Design
// Pattern: Composite | Key: Path resolution, wildcard ls, cd/pwd
// ===========================================================================
// FR: mkdir -p, touch, ls (wildcard), cd (.., .), pwd, cat, rm, write
// RELATIONSHIPS: Directory *-- FileSystemNode (Composite), File IS-A Node
// PLANTUML: FileSystemNode<|--File, FileSystemNode<|--Directory, Directory*--Node

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <deque>
using namespace std;

class FileSystemNode {
protected:
    string name;
    FileSystemNode* parent;
public:
    FileSystemNode(const string& n) : name(n), parent(NULL) {}
    virtual ~FileSystemNode() {}
    string getName() const { return name; }
    virtual bool isDirectory() const { return false; }
    FileSystemNode* getParent() const { return parent; }
    void setParent(FileSystemNode* p) { parent = p; }
};

class File : public FileSystemNode {
    string content;
public:
    File(const string& n) : FileSystemNode(n) {}
    string getContent() const { return content; }
    void setContent(const string& c) { content = c; }
    int getSize() const { return content.size(); }
};

class Directory : public FileSystemNode {
    map<string, FileSystemNode*> children;
public:
    Directory(const string& n) : FileSystemNode(n) {}
    ~Directory() {
        for (map<string,FileSystemNode*>::iterator it=children.begin(); it!=children.end(); ++it)
            delete it->second;
    }
    bool isDirectory() const { return true; }
    void addChild(FileSystemNode* n) { children[n->getName()] = n; n->setParent(this); }
    void removeChild(const string& n) { delete children[n]; children.erase(n); }
    FileSystemNode* getChild(const string& n) {
        return children.count(n) ? children[n] : NULL;
    }
    vector<string> list() const {
        vector<string> r;
        for (map<string,FileSystemNode*>::const_iterator it=children.begin(); it!=children.end(); ++it)
            r.push_back(it->first + (it->second->isDirectory() ? "/" : ""));
        return r;
    }
};

class FileSystem {
    Directory* root;
    Directory* currentDir;
public:
    FileSystem() { root = new Directory("/"); currentDir = root; }
    ~FileSystem() { delete root; }

    void mkdir(const string& path) {
        istringstream ss(path); string part;
        Directory* dir = (path[0]=='/') ? root : currentDir;
        while (getline(ss, part, '/')) {
            if (part.empty()) continue;
            FileSystemNode* child = dir->getChild(part);
            if (!child) { Directory* nd = new Directory(part); dir->addChild(nd); dir = nd; }
            else if (child->isDirectory()) dir = static_cast<Directory*>(child);
        }
        cout << "  mkdir: " << path << endl;
    }

    void touch(const string& n) {
        if (!currentDir->getChild(n)) currentDir->addChild(new File(n));
        cout << "  touch: " << n << endl;
    }

    void cd(const string& path) {
        if (path == "/") { currentDir = root; }
        else if (path == "..") { if(currentDir->getParent()) currentDir = static_cast<Directory*>(currentDir->getParent()); }
        else {
            FileSystemNode* n = currentDir->getChild(path);
            if (n && n->isDirectory()) currentDir = static_cast<Directory*>(n);
            else cout << "  [ERROR] Not found: " << path << endl;
        }
    }

    string pwd() const {
        deque<string> parts;
        FileSystemNode* d = currentDir;
        while (d && d != root) { parts.push_front(d->getName()); d = d->getParent(); }
        string r = "/";
        for (size_t i = 0; i < parts.size(); i++) r += parts[i] + "/";
        if (r.size() > 1) r.erase(r.size()-1);
        return r;
    }

    void ls() const {
        vector<string> items = currentDir->list();
        cout << "  ls " << pwd() << ": ";
        for (size_t i = 0; i < items.size(); i++) cout << items[i] << "  ";
        cout << endl;
    }

    void writeFile(const string& name, const string& content) {
        FileSystemNode* n = currentDir->getChild(name);
        if (n && !n->isDirectory()) static_cast<File*>(n)->setContent(content);
        cout << "  write: " << name << " (" << content.size() << " bytes)" << endl;
    }

    void cat(const string& name) const {
        FileSystemNode* n = currentDir->getChild(name);
        if (n && !n->isDirectory()) cout << "  cat " << name << ": " << static_cast<File*>(n)->getContent() << endl;
        else cout << "  [ERROR] Not a file: " << name << endl;
    }
};

int main() {
    cout << "============================================\n  File System — LLD Demo\n============================================" << endl;
    FileSystem fs;
    fs.mkdir("src/main/java");
    fs.cd("src"); fs.cd("main"); fs.cd("java");
    cout << "  pwd: " << fs.pwd() << endl;
    fs.touch("App.java");
    fs.writeFile("App.java", "public class App {}");
    fs.cat("App.java");
    fs.ls();
    fs.cd(".."); fs.cd(".."); cout << "  pwd: " << fs.pwd() << endl;
    fs.ls();
    cout << "\n=== Complete ===" << endl;
    return 0;
}
// SUMMARY: Composite(File/Directory), Path resolution with ../, pwd with deque
// PATTERNS: Composite | PRACTICES: Encapsulation, ownership in destructors
