// Singleton — Thread-safe Database Connection Pool
public class ConnectionPool {
    private static volatile ConnectionPool instance;
    private final List<Connection> pool;
    private final int maxSize;
    
    private ConnectionPool(int maxSize) {
        this.maxSize = maxSize;
        this.pool = new ArrayList<>(maxSize);
        for (int i = 0; i < maxSize; i++) {
            pool.add(createConnection());
        }
    }
    
    // Double-checked locking
    public static ConnectionPool getInstance() {
        if (instance == null) {
            synchronized (ConnectionPool.class) {
                if (instance == null) {
                    instance = new ConnectionPool(10);
                }
            }
        }
        return instance;
    }
    
    public synchronized Connection acquire() {
        if (pool.isEmpty()) throw new RuntimeException("No available connections");
        return pool.remove(pool.size() - 1);
    }
    
    public synchronized void release(Connection conn) {
        if (pool.size() < maxSize) pool.add(conn);
    }
    
    private Connection createConnection() {
        // Create actual DB connection
        return new Connection();
    }
}
