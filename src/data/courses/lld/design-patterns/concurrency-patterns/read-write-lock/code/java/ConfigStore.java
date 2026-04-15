// Read-Write Lock — In-memory Configuration Store
import java.util.concurrent.locks.*;

class ConfigStore {
    private final Map<String, String> config = new HashMap<>();
    private final ReadWriteLock lock = new ReentrantReadWriteLock(true); // fair=true
    
    // Multiple threads can read config simultaneously
    public String get(String key) {
        lock.readLock().lock();
        try { return config.get(key); }
        finally { lock.readLock().unlock(); }
    }
    
    public Map<String, String> getAll() {
        lock.readLock().lock();
        try { return new HashMap<>(config); } // Defensive copy
        finally { lock.readLock().unlock(); }
    }
    
    // Only one thread can update config
    public void set(String key, String value) {
        lock.writeLock().lock();
        try { config.put(key, value); }
        finally { lock.writeLock().unlock(); }
    }
    
    // Bulk update — still single writer
    public void reload(Map<String, String> newConfig) {
        lock.writeLock().lock();
        try {
            config.clear();
            config.putAll(newConfig);
            System.out.println("Config reloaded: " + newConfig.size() + " entries");
        } finally {
            lock.writeLock().unlock();
        }
    }
}
