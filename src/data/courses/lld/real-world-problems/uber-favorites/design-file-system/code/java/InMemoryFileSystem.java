// DESIGN: In-Memory File System — LLD (Java) | Composite Pattern
import java.util.*;
class FSNode { String name; FSNode parent;
    FSNode(String n) { name=n; } String getName() { return name; }
    boolean isDirectory() { return false; } void setParent(FSNode p) { parent=p; }
}
class FSFile extends FSNode { String content="";
    FSFile(String n) { super(n); }
    void write(String c) { content=c; } String read() { return content; }
}
class FSDir extends FSNode { Map<String,FSNode> children = new LinkedHashMap<>();
    FSDir(String n) { super(n); } boolean isDirectory() { return true; }
    void add(FSNode n) { children.put(n.getName(),n); n.setParent(this); }
    FSNode getChild(String n) { return children.get(n); }
    List<String> list() { List<String> r=new ArrayList<>(); for(var e:children.entrySet()) r.add(e.getKey()+(e.getValue().isDirectory()?"/":"")); return r; }
}
class InMemoryFS {
    FSDir root = new FSDir("/"); FSDir current = root;
    void mkdir(String path) {
        String[] parts=path.split("/"); FSDir dir=path.startsWith("/")?root:current;
        for(String p:parts) { if(p.isEmpty()) continue; FSNode c=dir.getChild(p);
            if(c==null){FSDir nd=new FSDir(p);dir.add(nd);dir=nd;} else if(c.isDirectory()) dir=(FSDir)c; }
        System.out.println("  mkdir: "+path);
    }
    void touch(String n) { if(current.getChild(n)==null) current.add(new FSFile(n)); System.out.println("  touch: "+n); }
    void cd(String p) {
        if("/".equals(p)) current=root;
        else if("..".equals(p)) { if(current.parent!=null) current=(FSDir)current.parent; }
        else { FSNode n=current.getChild(p); if(n!=null&&n.isDirectory()) current=(FSDir)n; }
    }
    String pwd() { Deque<String> parts=new ArrayDeque<>(); FSNode d=current;
        while(d!=null&&d!=root){parts.push(d.getName());d=d.parent;} return "/"+String.join("/",parts); }
    void ls() { System.out.println("  ls "+pwd()+": "+current.list()); }
    void writeFile(String n, String c) { FSNode nd=current.getChild(n); if(nd!=null&&!nd.isDirectory()) ((FSFile)nd).write(c); }
    void cat(String n) { FSNode nd=current.getChild(n); if(nd!=null&&!nd.isDirectory()) System.out.println("  cat: "+((FSFile)nd).read()); }
}
public class InMemoryFileSystem {
    public static void main(String[] args) {
        System.out.println("=== File System — Java ===");
        InMemoryFS fs=new InMemoryFS();
        fs.mkdir("src/main"); fs.cd("src"); fs.cd("main");
        System.out.println("  pwd: "+fs.pwd());
        fs.touch("App.java"); fs.writeFile("App.java","public class App{}"); fs.cat("App.java"); fs.ls();
        fs.cd(".."); System.out.println("  pwd: "+fs.pwd()); fs.ls();
        System.out.println("=== Complete ===");
    }
}
// SUMMARY: Composite(FSDir contains FSNode), path resolution, cd/pwd
