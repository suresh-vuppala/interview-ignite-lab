// Library Management System
import java.util.*;
import java.time.*;

// ========== BOOK ==========
class Book {
    private String isbn;
    private String title;
    private String author;
    private String subject;
    public Book(String isbn, String title, String author, String subject) {
        this.isbn = isbn; this.title = title; this.author = author; this.subject = subject;
    }
    public String getIsbn() { return isbn; }
    public String getTitle() { return title; }
    public String getAuthor() { return author; }
}

enum BookStatus { AVAILABLE, BORROWED, RESERVED, LOST }

class BookItem {
    private String barcode;
    private Book book;
    private BookStatus status;
    private LocalDate dueDate;
    private Member borrowedBy;
    
    public BookItem(String barcode, Book book) {
        this.barcode = barcode; this.book = book; this.status = BookStatus.AVAILABLE;
    }
    public boolean isAvailable() { return status == BookStatus.AVAILABLE; }
    public void checkout(Member member) {
        this.status = BookStatus.BORROWED;
        this.borrowedBy = member;
        this.dueDate = LocalDate.now().plusDays(14);
    }
    public void returnBook() {
        this.status = BookStatus.AVAILABLE;
        this.borrowedBy = null;
        this.dueDate = null;
    }
    public Book getBook() { return book; }
    public BookStatus getStatus() { return status; }
    public LocalDate getDueDate() { return dueDate; }
    public String getBarcode() { return barcode; }
}

// ========== MEMBER ==========
class Member {
    private String memberId;
    private String name;
    private List<BookItem> borrowedBooks = new ArrayList<>();
    private static final int MAX_BOOKS = 5;
    
    public Member(String id, String name) { this.memberId = id; this.name = name; }
    
    public boolean borrow(BookItem item) {
        if (borrowedBooks.size() >= MAX_BOOKS) return false;
        if (!item.isAvailable()) return false;
        item.checkout(this);
        borrowedBooks.add(item);
        return true;
    }
    
    public double returnBook(BookItem item, FineCalculator fineCalc) {
        borrowedBooks.remove(item);
        double fine = fineCalc.calculate(item.getDueDate(), LocalDate.now());
        item.returnBook();
        return fine;
    }
    
    public String getName() { return name; }
    public List<BookItem> getBorrowedBooks() { return borrowedBooks; }
}

// ========== FINE CALCULATOR (Strategy) ==========
interface FineCalculator {
    double calculate(LocalDate dueDate, LocalDate returnDate);
}

class StandardFineCalculator implements FineCalculator {
    public double calculate(LocalDate dueDate, LocalDate returnDate) {
        long daysLate = java.time.temporal.ChronoUnit.DAYS.between(dueDate, returnDate);
        return daysLate > 0 ? daysLate * 1.0 : 0; // $1/day
    }
}

class PremiumFineCalculator implements FineCalculator {
    public double calculate(LocalDate dueDate, LocalDate returnDate) {
        long daysLate = java.time.temporal.ChronoUnit.DAYS.between(dueDate, returnDate);
        return daysLate > 0 ? daysLate * 0.5 : 0; // $0.50/day for premium
    }
}

// ========== LIBRARY ==========
class Library {
    private static Library instance;
    private Map<String, List<BookItem>> catalog = new HashMap<>(); // ISBN → copies
    private Map<String, Member> members = new HashMap<>();
    
    private Library() {}
    public static Library getInstance() {
        if (instance == null) instance = new Library();
        return instance;
    }
    
    public void addBook(Book book, String barcode) {
        catalog.computeIfAbsent(book.getIsbn(), k -> new ArrayList<>())
               .add(new BookItem(barcode, book));
    }
    
    public void registerMember(Member member) { members.put(member.getName(), member); }
    
    public List<BookItem> searchByTitle(String title) {
        return catalog.values().stream().flatMap(List::stream)
            .filter(bi -> bi.getBook().getTitle().toLowerCase().contains(title.toLowerCase()))
            .toList();
    }
    
    public BookItem findAvailableCopy(String isbn) {
        return catalog.getOrDefault(isbn, List.of()).stream()
            .filter(BookItem::isAvailable).findFirst().orElse(null);
    }
}
