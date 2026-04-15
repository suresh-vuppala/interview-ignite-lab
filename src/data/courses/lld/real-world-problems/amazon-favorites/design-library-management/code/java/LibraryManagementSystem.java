// ===========================================================================
// DESIGN: Library Management System — Low Level Design
// ===========================================================================
// Single-file Java | Patterns: Singleton, Strategy, Observer
// Principles: SOLID, Encapsulation, Composition over Inheritance
// ===========================================================================

// 1. FUNCTIONAL REQUIREMENTS
// FR1: Add books (ISBN, title, author, subject) with multiple copies
// FR2: Register members (Standard/Premium)
// FR3: Borrow books (max 5 per member, 14-day loan)
// FR4: Return books with fine calculation ($1/day standard, $0.50/day premium)
// FR5: Search books by title
// FR6: Check availability by ISBN
// FR7: View member borrowing status

// 2. CONSTRAINTS: Max 5 books/member, 14-day loan, in-memory storage

// 3. ENTITIES & RELATIONSHIPS
// +-------------------+------------------+--------------+-------------+----------------------------+
// | Source             | Destination      | Type         | Cardinality | Description                |
// +-------------------+------------------+--------------+-------------+----------------------------+
// | Library            | Book             | Aggregation  | 1 -> many   | Library has books           |
// | Library            | Member           | Aggregation  | 1 -> many   | Library has members         |
// | Book               | BookItem         | Composition  | 1 -> many   | Book owns copies            |
// | Member             | BookItem         | Association  | many -> many| Member borrows copies       |
// | StandardFine       | FineCalculator   | Inheritance  | IS-A        | $1/day                      |
// | PremiumFine        | FineCalculator   | Inheritance  | IS-A        | $0.50/day                   |
// +-------------------+------------------+--------------+-------------+----------------------------+

// 4. PLANTUML
// @startuml
// class Library <<Singleton>> { -catalog -members }
// class Book { -isbn -title -author }
// class BookItem { -barcode -status }
// class Member { -id -name -borrowedBooks[max5] }
// interface FineCalculator { +calculate(daysLate) }
// class StandardFine
// class PremiumFine
// Library o-- Book
// Library o-- Member
// Book *-- BookItem
// Member --> BookItem : borrows
// FineCalculator <|.. StandardFine
// FineCalculator <|.. PremiumFine
// @enduml

import java.util.*;

// ===========================================================================
// ENUMERATIONS
// ===========================================================================
enum BookStatus { AVAILABLE, BORROWED, RESERVED, LOST }
enum MemberType { STANDARD, PREMIUM }

// ===========================================================================
// CLASS: Book [Catalog info — not a physical copy]
// ===========================================================================
class Book {
    private String isbn, title, author, subject;

    public Book(String isbn, String title, String author, String subject) {
        this.isbn = isbn; this.title = title;
        this.author = author; this.subject = subject;
    }

    public String getIsbn() { return isbn; }
    public String getTitle() { return title; }
    public String getAuthor() { return author; }

    public void display() {
        System.out.println("  [" + isbn + "] \"" + title + "\" by " + author);
    }
}

// ===========================================================================
// CLASS: BookItem [Physical copy — tracks status and borrower]
// Relationship: Composition under Book (book owns copies)
// ===========================================================================
class BookItem {
    private String barcode;
    private Book book;
    private BookStatus status;
    private Member borrowedBy;

    public BookItem(String barcode, Book book) {
        this.barcode = barcode;
        this.book = book;
        this.status = BookStatus.AVAILABLE;
    }

    public String getBarcode() { return barcode; }
    public Book getBook() { return book; }
    public boolean isAvailable() { return status == BookStatus.AVAILABLE; }

    // Checkout: mark as borrowed
    public void checkout(Member member) {
        this.status = BookStatus.BORROWED;
        this.borrowedBy = member;
    }

    // Return: mark as available
    public void returnBook() {
        this.status = BookStatus.AVAILABLE;
        this.borrowedBy = null;
    }
}

// ===========================================================================
// INTERFACE: FineCalculator [Strategy Pattern]
// ===========================================================================
interface FineCalculator {
    double calculate(int daysLate);
    String describe();
}

// Standard: $1.00/day
class StandardFine implements FineCalculator {
    public double calculate(int daysLate) { return daysLate > 0 ? daysLate * 1.0 : 0; }
    public String describe() { return "Standard ($1/day)"; }
}

// Premium: $0.50/day
class PremiumFine implements FineCalculator {
    public double calculate(int daysLate) { return daysLate > 0 ? daysLate * 0.5 : 0; }
    public String describe() { return "Premium ($0.50/day)"; }
}

// ===========================================================================
// CLASS: Member [Core Entity]
// Responsibility: Borrow (max 5), return with fine, track history
// ===========================================================================
class Member {
    private String memberId, name;
    private MemberType memberType;
    private List<BookItem> borrowedBooks = new ArrayList<>();
    private FineCalculator fineCalc;
    private static final int MAX_BOOKS = 5;

    public Member(String id, String name, MemberType type) {
        this.memberId = id;
        this.name = name;
        this.memberType = type;
        // Strategy pattern: fine calculator based on member type
        this.fineCalc = (type == MemberType.PREMIUM) ? new PremiumFine() : new StandardFine();
    }

    public String getName() { return name; }

    // Borrow book — checks limit and availability
    public boolean borrow(BookItem item) {
        if (borrowedBooks.size() >= MAX_BOOKS) {
            System.out.println("  [ERROR] " + name + " at max limit (" + MAX_BOOKS + ")");
            return false;
        }
        if (!item.isAvailable()) {
            System.out.println("  [ERROR] Book not available.");
            return false;
        }
        item.checkout(this);
        borrowedBooks.add(item);
        System.out.println("  " + name + " borrowed \"" + item.getBook().getTitle() + "\" [" + item.getBarcode() + "]");
        return true;
    }

    // Return book — calculate fine via Strategy pattern
    public double returnBook(BookItem item, int daysLate) {
        boolean found = borrowedBooks.remove(item);
        if (!found) {
            System.out.println("  [ERROR] " + name + " didn't borrow this book.");
            return 0;
        }
        double fine = fineCalc.calculate(daysLate);
        item.returnBook();
        System.out.print("  " + name + " returned \"" + item.getBook().getTitle() + "\"");
        if (fine > 0)
            System.out.print(" | Fine: $" + fine + " (" + fineCalc.describe() + ", " + daysLate + " days late)");
        System.out.println();
        return fine;
    }

    public void display() {
        String type = (memberType == MemberType.PREMIUM) ? "PREMIUM" : "STANDARD";
        System.out.println("  " + memberId + " | " + name + " | " + type + " | Borrowed: " + borrowedBooks.size() + "/" + MAX_BOOKS);
        for (BookItem bi : borrowedBooks)
            System.out.println("    -> \"" + bi.getBook().getTitle() + "\" [" + bi.getBarcode() + "]");
    }
}

// ===========================================================================
// CLASS: Library [Singleton]
// Responsibility: Central catalog, member registry, search
// ===========================================================================
class Library {
    private static Library instance;
    private Map<String, Book> catalog = new HashMap<>();         // ISBN -> Book
    private Map<String, List<BookItem>> items = new HashMap<>(); // ISBN -> copies
    private Map<String, Member> members = new HashMap<>();

    private Library() {}

    public static Library getInstance() {
        if (instance == null) instance = new Library();
        return instance;
    }

    public void addBook(String isbn, String title, String author, String subject, String barcode) {
        catalog.putIfAbsent(isbn, new Book(isbn, title, author, subject));
        items.computeIfAbsent(isbn, k -> new ArrayList<>()).add(new BookItem(barcode, catalog.get(isbn)));
        System.out.println("  Added: \"" + title + "\" [" + barcode + "]");
    }

    public void registerMember(String id, String name, MemberType type) {
        members.put(id, new Member(id, name, type));
        System.out.println("  Registered: " + name + " (" + type + ")");
    }

    public BookItem findAvailableCopy(String isbn) {
        List<BookItem> copies = items.get(isbn);
        if (copies == null) return null;
        for (BookItem item : copies)
            if (item.isAvailable()) return item;
        return null;
    }

    public List<Book> searchByTitle(String keyword) {
        List<Book> results = new ArrayList<>();
        for (Book b : catalog.values())
            if (b.getTitle().toLowerCase().contains(keyword.toLowerCase()))
                results.add(b);
        return results;
    }

    public Member getMember(String id) { return members.get(id); }

    public void displayMembers() {
        System.out.println("  --- Members ---");
        for (Member m : members.values()) m.display();
    }
}

// ===========================================================================
// MAIN
// ===========================================================================
public class LibraryManagementSystem {
    public static void main(String[] args) {
        System.out.println("============================================");
        System.out.println("  Library Management System — LLD Demo");
        System.out.println("============================================");

        Library library = Library.getInstance();

        // Add books
        System.out.println("\n--- Adding Books ---");
        library.addBook("978-0-13-468599-1", "Clean Code", "Robert Martin", "SW", "BC001");
        library.addBook("978-0-13-468599-1", "Clean Code", "Robert Martin", "SW", "BC002");
        library.addBook("978-0-20-161622-4", "Pragmatic Programmer", "Hunt", "SW", "BC003");

        // Register members
        System.out.println("\n--- Registering Members ---");
        library.registerMember("M001", "Alice", MemberType.STANDARD);
        library.registerMember("M002", "Bob", MemberType.PREMIUM);

        // Search
        System.out.println("\n--- Search: 'Clean' ---");
        for (Book b : library.searchByTitle("Clean")) b.display();

        // Borrow
        System.out.println("\n--- Borrowing ---");
        Member alice = library.getMember("M001");
        Member bob = library.getMember("M002");

        BookItem cc1 = library.findAvailableCopy("978-0-13-468599-1");
        if (cc1 != null) alice.borrow(cc1);

        BookItem cc2 = library.findAvailableCopy("978-0-13-468599-1");
        if (cc2 != null) bob.borrow(cc2);

        // No copies left
        System.out.println("\n--- No copies left ---");
        BookItem cc3 = library.findAvailableCopy("978-0-13-468599-1");
        if (cc3 == null) System.out.println("  All copies of 'Clean Code' borrowed.");

        // Status
        System.out.println("\n--- Member Status ---");
        library.displayMembers();

        // Return with fines
        System.out.println("\n--- Returns ---");
        alice.returnBook(cc1, 5);  // $5.00 standard
        bob.returnBook(cc2, 5);    // $2.50 premium

        System.out.println("\n--- After Returns ---");
        library.displayMembers();

        System.out.println("\n=== All scenarios complete ===");
    }
}

// ===========================================================================
// 5. SUMMARY
// ===========================================================================

// EXECUTION FLOW:
//   main() -> Library.getInstance() [Singleton]
//     -> addBook() -> creates Book + BookItem
//     -> registerMember() -> creates Member + FineCalculator [Strategy]
//     -> findAvailableCopy() -> returns first AVAILABLE BookItem
//     -> member.borrow(item) -> limit check -> checkout
//     -> member.returnBook(item, daysLate) -> fineCalc.calculate() [Strategy]

// METHOD CALL TREE:
//   member.borrow(item)
//     -> borrowedBooks.size() < MAX? -> item.isAvailable()?
//     -> item.checkout(this) -> borrowedBooks.add(item)
//   member.returnBook(item, daysLate)
//     -> fineCalc.calculate(daysLate) [Strategy polymorphism]
//     -> item.returnBook()

// CLASS RESPONSIBILITY TABLE:
//   Book             | Catalog info (ISBN, title, author)
//   BookItem         | Physical copy with barcode + status
//   FineCalculator   | Strategy interface for fines
//   StandardFine     | $1/day
//   PremiumFine      | $0.50/day
//   Member           | Borrows (max 5), returns, fine calc
//   Library          | Singleton catalog + members

// DESIGN PATTERNS:
//   1. Singleton -> Library (central access)
//   2. Strategy  -> FineCalculator (different rates per member type)

// BEST PRACTICES:
//   1. Book vs BookItem -> catalog vs physical copy distinction
//   2. Encapsulation    -> private fields, methods for access
//   3. OCP              -> new MemberType = new FineCalculator only
//   4. SRP              -> Member borrows, Library manages catalog
