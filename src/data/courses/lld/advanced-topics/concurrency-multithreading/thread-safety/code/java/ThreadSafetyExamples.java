// Thread Safety — Bank Account with different approaches
import java.util.concurrent.atomic.*;
import java.util.concurrent.locks.*;

// Approach 1: synchronized methods
class SynchronizedAccount {
    private double balance;
    public synchronized void deposit(double amount) { balance += amount; }
    public synchronized void withdraw(double amount) {
        if (balance >= amount) balance -= amount;
    }
    public synchronized double getBalance() { return balance; }
}

// Approach 2: Explicit Lock (more control)
class LockAccount {
    private double balance;
    private final ReentrantLock lock = new ReentrantLock();
    
    public void deposit(double amount) {
        lock.lock();
        try { balance += amount; }
        finally { lock.unlock(); } // ALWAYS unlock in finally
    }
    
    public boolean withdraw(double amount) {
        lock.lock();
        try {
            if (balance >= amount) { balance -= amount; return true; }
            return false;
        } finally { lock.unlock(); }
    }
}

// Approach 3: Atomic (for simple counters)
class AtomicCounter {
    private final AtomicLong count = new AtomicLong(0);
    public void increment() { count.incrementAndGet(); }
    public long get() { return count.get(); }
    
    // Compare-and-swap for complex atomic operations
    public boolean tryDeduct(long amount) {
        long current;
        do { current = count.get(); if (current < amount) return false; }
        while (!count.compareAndSet(current, current - amount));
        return true;
    }
}
