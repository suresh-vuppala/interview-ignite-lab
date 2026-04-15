// DIP Example — Pluggable Storage System
interface Storage {
    void save(String key, String data);
    String load(String key);
    void delete(String key);
}

class LocalFileStorage implements Storage {
    public void save(String key, String data) { /* Write to file system */ }
    public String load(String key) { return "file data"; }
    public void delete(String key) { /* Delete file */ }
}

class S3Storage implements Storage {
    public void save(String key, String data) { /* Upload to S3 */ }
    public String load(String key) { return "s3 data"; }
    public void delete(String key) { /* Delete from S3 */ }
}

class RedisCache implements Storage {
    public void save(String key, String data) { /* SET in Redis */ }
    public String load(String key) { return "cached data"; }
    public void delete(String key) { /* DEL from Redis */ }
}

// High-level service — depends ONLY on Storage interface
class DocumentService {
    private final Storage primaryStorage;
    private final Storage cacheStorage;
    
    // Constructor injection — DIP in action
    public DocumentService(Storage primary, Storage cache) {
        this.primaryStorage = primary;
        this.cacheStorage = cache;
    }
    
    public void saveDocument(String id, String content) {
        primaryStorage.save(id, content);
        cacheStorage.save(id, content);  // Cache for fast reads
    }
    
    public String getDocument(String id) {
        String cached = cacheStorage.load(id);
        return cached != null ? cached : primaryStorage.load(id);
    }
}

// Wiring — swap implementations freely
// Production: S3 + Redis
// DocumentService svc = new DocumentService(new S3Storage(), new RedisCache());
// Dev: Local files + no cache
// DocumentService svc = new DocumentService(new LocalFileStorage(), new LocalFileStorage());
