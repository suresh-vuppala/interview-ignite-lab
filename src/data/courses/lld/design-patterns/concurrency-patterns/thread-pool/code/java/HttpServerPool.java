// Thread Pool — HTTP Request Handler
import java.util.concurrent.*;

class HttpServer {
    private final ExecutorService threadPool;
    private volatile boolean running = true;
    
    public HttpServer(int maxThreads) {
        this.threadPool = new ThreadPoolExecutor(
            maxThreads / 2,        // Core threads
            maxThreads,             // Max threads
            60, TimeUnit.SECONDS,   // Idle timeout
            new ArrayBlockingQueue<>(200), // Request queue
            new ThreadPoolExecutor.CallerRunsPolicy()
        );
    }
    
    public void handleRequest(HttpRequest request) {
        threadPool.submit(() -> {
            try {
                HttpResponse response = processRequest(request);
                sendResponse(response);
            } catch (Exception e) {
                sendError(request, e);
            }
        });
    }
    
    private HttpResponse processRequest(HttpRequest req) {
        // Route, authenticate, execute, return response
        return new HttpResponse(200, "OK");
    }
    
    public void shutdown() {
        running = false;
        threadPool.shutdown();
        try { threadPool.awaitTermination(30, TimeUnit.SECONDS); }
        catch (InterruptedException e) { threadPool.shutdownNow(); }
    }
}
