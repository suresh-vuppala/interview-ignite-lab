// Producer-Consumer — Task Processing System
import java.util.concurrent.*;

class TaskProcessor {
    private final BlockingQueue<Runnable> taskQueue;
    private final List<Thread> consumers;
    private volatile boolean running = true;
    
    public TaskProcessor(int queueSize, int numConsumers) {
        this.taskQueue = new ArrayBlockingQueue<>(queueSize);
        this.consumers = new ArrayList<>();
        
        for (int i = 0; i < numConsumers; i++) {
            Thread t = new Thread(() -> {
                while (running || !taskQueue.isEmpty()) {
                    try {
                        Runnable task = taskQueue.poll(1, TimeUnit.SECONDS);
                        if (task != null) task.run();
                    } catch (InterruptedException e) { Thread.currentThread().interrupt(); }
                }
            }, "Consumer-" + i);
            consumers.add(t);
            t.start();
        }
    }
    
    // Producer method
    public void submit(Runnable task) throws InterruptedException {
        taskQueue.put(task); // Blocks if queue full
    }
    
    public void shutdown() {
        running = false;
        consumers.forEach(t -> { try { t.join(); } catch (InterruptedException e) {} });
    }
}
