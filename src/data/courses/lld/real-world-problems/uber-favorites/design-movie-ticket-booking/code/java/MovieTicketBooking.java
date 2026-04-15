// Movie Ticket Booking System
import java.util.*;
import java.time.*;

enum SeatType { REGULAR, PREMIUM, VIP }
enum SeatStatus { AVAILABLE, LOCKED, BOOKED }

class Seat {
    private int row, col;
    private SeatType type;
    private SeatStatus status = SeatStatus.AVAILABLE;
    private long lockExpiry = 0; // Timestamp when lock expires
    private String lockedBy;
    
    public Seat(int row, int col, SeatType type) { this.row = row; this.col = col; this.type = type; }
    
    public synchronized boolean lock(String userId, long durationMs) {
        checkLockExpiry();
        if (status != SeatStatus.AVAILABLE) return false;
        status = SeatStatus.LOCKED;
        lockedBy = userId;
        lockExpiry = System.currentTimeMillis() + durationMs;
        return true;
    }
    
    public synchronized boolean book(String userId) {
        if (status != SeatStatus.LOCKED || !userId.equals(lockedBy)) return false;
        status = SeatStatus.BOOKED;
        return true;
    }
    
    public synchronized void release() {
        status = SeatStatus.AVAILABLE;
        lockedBy = null;
        lockExpiry = 0;
    }
    
    private void checkLockExpiry() {
        if (status == SeatStatus.LOCKED && System.currentTimeMillis() > lockExpiry) release();
    }
    
    public boolean isAvailable() { checkLockExpiry(); return status == SeatStatus.AVAILABLE; }
    public SeatType getType() { return type; }
    public String getPosition() { return "R" + row + "C" + col; }
}

class Movie {
    private String id, title, genre;
    private int durationMinutes;
    public Movie(String id, String title, String genre, int dur) {
        this.id = id; this.title = title; this.genre = genre; this.durationMinutes = dur;
    }
    public String getTitle() { return title; }
}

class Show {
    private String id;
    private Movie movie;
    private Seat[][] seats;
    private LocalDateTime startTime;
    
    public Show(String id, Movie movie, int rows, int cols, LocalDateTime time) {
        this.id = id; this.movie = movie; this.startTime = time;
        seats = new Seat[rows][cols];
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                seats[r][c] = new Seat(r, c, r < 2 ? SeatType.VIP : r < 5 ? SeatType.PREMIUM : SeatType.REGULAR);
    }
    
    public List<Seat> getAvailableSeats() {
        List<Seat> available = new ArrayList<>();
        for (Seat[] row : seats) for (Seat s : row) if (s.isAvailable()) available.add(s);
        return available;
    }
    
    public boolean lockSeats(List<int[]> positions, String userId) {
        long LOCK_DURATION = 5 * 60 * 1000; // 5 min
        List<Seat> locked = new ArrayList<>();
        for (int[] pos : positions) {
            Seat seat = seats[pos[0]][pos[1]];
            if (!seat.lock(userId, LOCK_DURATION)) {
                locked.forEach(Seat::release); // Rollback
                return false;
            }
            locked.add(seat);
        }
        return true;
    }
    
    public boolean confirmBooking(List<int[]> positions, String userId) {
        for (int[] pos : positions) {
            if (!seats[pos[0]][pos[1]].book(userId)) return false;
        }
        return true;
    }
    
    public Movie getMovie() { return movie; }
}

class Booking {
    private String id, userId;
    private Show show;
    private List<Seat> seats;
    private double totalPrice;
    private String status = "CONFIRMED";
    
    public Booking(String id, String userId, Show show, List<Seat> seats, double price) {
        this.id = id; this.userId = userId; this.show = show;
        this.seats = seats; this.totalPrice = price;
    }
    
    public void cancel() {
        status = "CANCELLED";
        seats.forEach(Seat::release);
    }
}
