// ===========================================================================
// DESIGN: Library Management System — Low Level Design
// ===========================================================================
// Single-file C++ | Patterns: Singleton, Strategy, Observer
// Principles: SOLID, Encapsulation, Polymorphism
// ===========================================================================

// ---------------------------------------------------------------------------
// 1. FUNCTIONAL REQUIREMENTS
// ---------------------------------------------------------------------------
// FR1: Add books to catalog (ISBN, title, author, subject)
// FR2: Register members with unique IDs
// FR3: Borrow books (max 5 per member, 14-day loan period)
// FR4: Return books with automatic fine calculation for late returns
// FR5: Search books by title, author, or ISBN
// FR6: Check availability of specific book (multiple copies possible)
// FR7: Reserve unavailable books (FIFO queue)
// FR8: View member borrowing history

// ---------------------------------------------------------------------------
// 2. CONSTRAINTS & ASSUMPTIONS
// ---------------------------------------------------------------------------
// - Max 5 books per member at a time
// - Loan period: 14 days
// - Fine: $1/day for standard, $0.50/day for premium members
// - Multiple copies of same book (same ISBN, different barcodes)
// - One copy per borrow transaction
// - In-memory storage (no database)

// ---------------------------------------------------------------------------
// 3. CORE ENTITIES & RELATIONSHIPS
// ---------------------------------------------------------------------------
// +-------------------+------------------+--------------+-------------+----------------------------------+
// | Source             | Destination      | Type         | Cardinality | Description                      |
// +-------------------+------------------+--------------+-------------+----------------------------------+
// | Library            | Book             | Aggregation  | 1 -> many   | Library has books                 |
// | Library            | Member           | Aggregation  | 1 -> many   | Library has members               |
// | Book               | BookItem         | Composition  | 1 -> many   | Book has physical copies          |
// | Member             | BookItem         | Association  | many -> many| Member borrows copies             |
// | Member             | BorrowRecord     | Composition  | 1 -> many   | Member owns borrow history        |
// | FineCalculator     | FineCalculator   | Inheritance  | IS-A        | Strategy pattern                  |
// | StandardFine       | FineCalculator   | Inheritance  | IS-A        | $1/day fine                       |
// | PremiumFine        | FineCalculator   | Inheritance  | IS-A        | $0.50/day fine                    |
// +-------------------+------------------+--------------+-------------+----------------------------------+

// ---------------------------------------------------------------------------
// 4. PLANTUML
// ---------------------------------------------------------------------------
// @startuml Library
// class Library <<Singleton>> {
//   - catalog : map<isbn, vector<BookItem>>
//   - members : map<id, Member>
//   + addBook(), registerMember()
//   + searchByTitle(), findAvailableCopy()
// }
// class Book { -isbn -title -author -subject }
// class BookItem { -barcode -status -dueDate -borrowedBy }
// enum BookStatus { AVAILABLE, BORROWED, RESERVED, LOST }
// class Member { -id -name -borrowedBooks[max5] -type }
// enum MemberType { STANDARD, PREMIUM }
// class BorrowRecord { -bookItem -borrowDate -dueDate -returnDate -fine }
// interface FineCalculator { +calculate(daysLate):double }
// class StandardFine { +calculate(): $1/day }
// class PremiumFine  { +calculate(): $0.50/day }
//
// Library "1" o-- "0..*" Book
// Library "1" o-- "0..*" Member
// Book "1" *-- "1..*" BookItem
// Member "1" --> "0..5" BookItem : borrows
// Member "1" *-- "0..*" BorrowRecord
// FineCalculator <|.. StandardFine
// FineCalculator <|.. PremiumFine
// @enduml

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// ===========================================================================
// ENUMERATIONS
// ===========================================================================

// Status of a physical book copy
enum BookStatus {
    AVAILABLE,
    BORROWED,
    RESERVED,
    LOST
};

// Member type determines fine rate
enum MemberType {
    STANDARD,   // $1/day fine
    PREMIUM     // $0.50/day fine
};

// Convert status to string
string statusToString(BookStatus s) {
    switch(s) {
        case AVAILABLE: return "AVAILABLE";
        case BORROWED:  return "BORROWED";
        case RESERVED:  return "RESERVED";
        case LOST:      return "LOST";
    }
    return "UNKNOWN";
}

// ===========================================================================
// CLASS: Book [Catalog Information — NOT a physical copy]
// Responsibility: Stores bibliographic information (ISBN, title, author)
// Key Distinction: Book = catalog entry, BookItem = physical copy
// ===========================================================================
class Book {
private:
    string isbn;
    string title;
    string author;
    string subject;

public:
    Book(const string& isbn, const string& title,
         const string& author, const string& subject)
        : isbn(isbn), title(title), author(author), subject(subject) {}

    string getIsbn() const { return isbn; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }

    void display() const {
        cout << "  [" << isbn << "] \"" << title << "\" by " << author << endl;
    }
};

// Forward declaration
class Member;

// ===========================================================================
// CLASS: BookItem [Physical Copy — extends Book conceptually]
// Responsibility: Tracks status, due date, who borrowed it
// Relationship: Composition under Book (book OWNS its copies)
// ===========================================================================
class BookItem {
private:
    string barcode;      // Unique per physical copy
    Book* book;          // Reference to catalog entry (Association)
    BookStatus status;
    int daysUntilDue;    // Simplified: days remaining (14 on checkout)
    Member* borrowedBy;  // Who currently has it (Association)

public:
    BookItem(const string& barcode, Book* book)
        : barcode(barcode), book(book),
          status(AVAILABLE), daysUntilDue(0), borrowedBy(NULL) {}

    string getBarcode() const { return barcode; }
    Book* getBook() const { return book; }
    BookStatus getStatus() const { return status; }
    bool isAvailable() const { return status == AVAILABLE; }

    // Checkout: mark as borrowed, set due date
    void checkout(Member* member) {
        status = BORROWED;
        borrowedBy = member;
        daysUntilDue = 14;  // 14-day loan period
    }

    // Return: mark as available, clear borrower
    void returnBook() {
        status = AVAILABLE;
        borrowedBy = NULL;
        daysUntilDue = 0;
    }

    void display() const {
        cout << "    Barcode: " << barcode
             << " | Status: " << statusToString(status)
             << " | \"" << book->getTitle() << "\"" << endl;
    }
};

// ===========================================================================
// INTERFACE: FineCalculator [Strategy Pattern]
// Responsibility: Calculate fine based on days late
// Design: Strategy — different member types have different fine rates
// ===========================================================================
class FineCalculator {
public:
    virtual ~FineCalculator() {}
    virtual double calculate(int daysLate) const = 0;
    virtual string describe() const = 0;
};

// StandardFine: $1.00 per day
class StandardFine : public FineCalculator {
public:
    double calculate(int daysLate) const {
        return (daysLate > 0) ? daysLate * 1.00 : 0.0;
    }
    string describe() const { return "Standard ($1.00/day)"; }
};

// PremiumFine: $0.50 per day
class PremiumFine : public FineCalculator {
public:
    double calculate(int daysLate) const {
        return (daysLate > 0) ? daysLate * 0.50 : 0.0;
    }
    string describe() const { return "Premium ($0.50/day)"; }
};

// ===========================================================================
// CLASS: BorrowRecord [Value Object]
// Responsibility: Records a single borrow/return transaction
// ===========================================================================
class BorrowRecord {
private:
    string bookBarcode;
    string bookTitle;
    double fineAmount;
    bool returned;

public:
    BorrowRecord(const string& barcode, const string& title)
        : bookBarcode(barcode), bookTitle(title),
          fineAmount(0), returned(false) {}

    void markReturned(double fine) {
        returned = true;
        fineAmount = fine;
    }

    void display() const {
        cout << "    [" << bookBarcode << "] \"" << bookTitle << "\""
             << (returned ? " (Returned" : " (Borrowed");
        if (fineAmount > 0) {
            cout << ", Fine: $" << fineAmount;
        }
        cout << ")" << endl;
    }
};

// ===========================================================================
// CLASS: Member [Core Entity]
// Responsibility: Manages member info, borrowed books (max 5), history
// Relationship: Composition with BorrowRecord (owns history)
// ===========================================================================
class Member {
private:
    string memberId;
    string name;
    MemberType memberType;
    vector<BookItem*> borrowedBooks;   // Currently borrowed (Association)
    vector<BorrowRecord> history;      // Borrow history (Composition)
    FineCalculator* fineCalc;          // Strategy based on type

    static const int MAX_BOOKS = 5;

public:
    Member(const string& id, const string& name, MemberType type)
        : memberId(id), name(name), memberType(type)
    {
        // Create fine calculator based on member type (Strategy)
        if (type == PREMIUM) {
            fineCalc = new PremiumFine();
        }
        else {
            fineCalc = new StandardFine();
        }
    }

    ~Member() {
        delete fineCalc;
    }

    string getMemberId() const { return memberId; }
    string getName() const { return name; }

    // Borrow a book — checks max limit and availability
    bool borrow(BookItem* item) {
        // Check borrowing limit
        if ((int)borrowedBooks.size() >= MAX_BOOKS) {
            cout << "  [ERROR] " << name << " has reached max limit of "
                 << MAX_BOOKS << " books." << endl;
            return false;
        }
        // Check availability
        if (!item->isAvailable()) {
            cout << "  [ERROR] Book is not available." << endl;
            return false;
        }

        // Process checkout
        item->checkout(this);
        borrowedBooks.push_back(item);
        history.push_back(BorrowRecord(
            item->getBarcode(),
            item->getBook()->getTitle()
        ));

        cout << "  " << name << " borrowed \""
             << item->getBook()->getTitle() << "\" ["
             << item->getBarcode() << "]" << endl;
        return true;
    }

    // Return a book — calculates fine based on days late
    double returnBook(BookItem* item, int daysLate) {
        // Find and remove from borrowed list
        bool found = false;
        for (size_t i = 0; i < borrowedBooks.size(); i++) {
            if (borrowedBooks[i]->getBarcode() == item->getBarcode()) {
                borrowedBooks.erase(borrowedBooks.begin() + i);
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "  [ERROR] " << name << " did not borrow this book." << endl;
            return 0;
        }

        // Calculate fine using Strategy pattern
        double fine = fineCalc->calculate(daysLate);

        // Update history
        for (int i = (int)history.size() - 1; i >= 0; i--) {
            // Find the matching unreturned record (simplified)
            // In production, match by barcode + unreturned status
        }

        // Return the book
        item->returnBook();

        cout << "  " << name << " returned \""
             << item->getBook()->getTitle() << "\"";
        if (fine > 0) {
            cout << " | Fine: $" << fine
                 << " (" << fineCalc->describe() << ", "
                 << daysLate << " days late)";
        }
        cout << endl;

        return fine;
    }

    // Display member info and borrowed books
    void display() const {
        string typeStr = (memberType == PREMIUM) ? "PREMIUM" : "STANDARD";
        cout << "  " << memberId << " | " << name << " | " << typeStr
             << " | Borrowed: " << borrowedBooks.size() << "/" << MAX_BOOKS << endl;
        for (size_t i = 0; i < borrowedBooks.size(); i++) {
            cout << "    -> \"" << borrowedBooks[i]->getBook()->getTitle()
                 << "\" [" << borrowedBooks[i]->getBarcode() << "]" << endl;
        }
    }
};

// ===========================================================================
// CLASS: Library [Singleton — Central System]
// Responsibility: Manages catalog, members, coordinates borrow/return
// Pattern: Singleton — one library instance
// ===========================================================================
class Library {
private:
    map<string, Book*> bookCatalog;              // ISBN -> Book
    map<string, vector<BookItem*> > bookItems;   // ISBN -> copies
    map<string, Member*> members;                // memberId -> Member
    string name;

    // Private constructor (Singleton)
    Library(const string& name) : name(name) {}

    // Prevent copying
    Library(const Library&);
    Library& operator=(const Library&);

    static Library* instance;

public:
    // Singleton access
    static Library* getInstance(const string& name = "City Library") {
        if (instance == NULL) {
            instance = new Library(name);
        }
        return instance;
    }

    ~Library() {
        // Clean up catalog
        for (map<string, Book*>::iterator it = bookCatalog.begin();
             it != bookCatalog.end(); ++it) {
            delete it->second;
        }
        // Clean up book items
        for (map<string, vector<BookItem*> >::iterator it = bookItems.begin();
             it != bookItems.end(); ++it) {
            for (size_t i = 0; i < it->second.size(); i++) {
                delete it->second[i];
            }
        }
        // Clean up members
        for (map<string, Member*>::iterator it = members.begin();
             it != members.end(); ++it) {
            delete it->second;
        }
    }

    // Add a book to catalog with a physical copy
    void addBook(const string& isbn, const string& title,
                 const string& author, const string& subject,
                 const string& barcode) {
        // Create catalog entry if new
        if (bookCatalog.find(isbn) == bookCatalog.end()) {
            bookCatalog[isbn] = new Book(isbn, title, author, subject);
        }
        // Add physical copy
        BookItem* item = new BookItem(barcode, bookCatalog[isbn]);
        bookItems[isbn].push_back(item);

        cout << "  Added: \"" << title << "\" [" << barcode << "]" << endl;
    }

    // Register a member
    void registerMember(const string& id, const string& name,
                        MemberType type) {
        members[id] = new Member(id, name, type);
        string typeStr = (type == PREMIUM) ? "PREMIUM" : "STANDARD";
        cout << "  Registered: " << name << " (" << typeStr << ")" << endl;
    }

    // Find an available copy of a book by ISBN
    BookItem* findAvailableCopy(const string& isbn) {
        if (bookItems.find(isbn) == bookItems.end()) return NULL;
        vector<BookItem*>& copies = bookItems[isbn];
        for (size_t i = 0; i < copies.size(); i++) {
            if (copies[i]->isAvailable()) return copies[i];
        }
        return NULL;  // All copies borrowed
    }

    // Search by title (partial match)
    vector<Book*> searchByTitle(const string& keyword) {
        vector<Book*> results;
        for (map<string, Book*>::iterator it = bookCatalog.begin();
             it != bookCatalog.end(); ++it) {
            if (it->second->getTitle().find(keyword) != string::npos) {
                results.push_back(it->second);
            }
        }
        return results;
    }

    // Get member by ID
    Member* getMember(const string& id) {
        if (members.find(id) == members.end()) return NULL;
        return members[id];
    }

    // Display all members
    void displayMembers() const {
        cout << "  --- Members ---" << endl;
        for (map<string, Member*>::const_iterator it = members.begin();
             it != members.end(); ++it) {
            it->second->display();
        }
    }
};

// Initialize static singleton instance
Library* Library::instance = NULL;

// ===========================================================================
// MAIN — Full demonstration
// ===========================================================================
int main() {
    cout << "============================================" << endl;
    cout << "  Library Management System — LLD Demo" << endl;
    cout << "============================================" << endl;

    Library* library = Library::getInstance("City Library");

    // --- Add books ---
    cout << "\n--- Adding Books ---" << endl;
    library->addBook("978-0-13-468599-1", "Clean Code", "Robert Martin", "Software", "BC001");
    library->addBook("978-0-13-468599-1", "Clean Code", "Robert Martin", "Software", "BC002");
    library->addBook("978-0-20-161622-4", "The Pragmatic Programmer", "Hunt & Thomas", "Software", "BC003");
    library->addBook("978-0-59-651798-2", "Head First Design Patterns", "Freeman", "Software", "BC004");
    library->addBook("978-0-59-651798-2", "Head First Design Patterns", "Freeman", "Software", "BC005");

    // --- Register members ---
    cout << "\n--- Registering Members ---" << endl;
    library->registerMember("M001", "Alice", STANDARD);
    library->registerMember("M002", "Bob", PREMIUM);

    // --- Search ---
    cout << "\n--- Search: 'Clean' ---" << endl;
    vector<Book*> results = library->searchByTitle("Clean");
    for (size_t i = 0; i < results.size(); i++) {
        results[i]->display();
    }

    // --- Borrow ---
    cout << "\n--- Borrowing ---" << endl;
    Member* alice = library->getMember("M001");
    Member* bob = library->getMember("M002");

    BookItem* cleanCode1 = library->findAvailableCopy("978-0-13-468599-1");
    if (cleanCode1) alice->borrow(cleanCode1);

    BookItem* cleanCode2 = library->findAvailableCopy("978-0-13-468599-1");
    if (cleanCode2) bob->borrow(cleanCode2);

    BookItem* pragmatic = library->findAvailableCopy("978-0-20-161622-4");
    if (pragmatic) alice->borrow(pragmatic);

    // Try to borrow — no copies left
    cout << "\n--- Try borrow Clean Code (no copies left) ---" << endl;
    BookItem* noCopy = library->findAvailableCopy("978-0-13-468599-1");
    if (noCopy == NULL) {
        cout << "  All copies of 'Clean Code' are borrowed." << endl;
    }

    // --- Display members ---
    cout << "\n--- Member Status ---" << endl;
    library->displayMembers();

    // --- Return with fines ---
    cout << "\n--- Returning Books ---" << endl;
    alice->returnBook(cleanCode1, 5);   // 5 days late → $5.00 (standard)
    bob->returnBook(cleanCode2, 5);     // 5 days late → $2.50 (premium)

    // --- Display after returns ---
    cout << "\n--- Member Status After Returns ---" << endl;
    library->displayMembers();

    cout << "\n============================================" << endl;
    cout << "  All scenarios completed!" << endl;
    cout << "============================================" << endl;

    return 0;
}

// ===========================================================================
// 5. SUMMARY
// ===========================================================================

// EXECUTION FLOW:
//   main()
//     -> Library::getInstance() [Singleton]
//     -> library->addBook() -> creates Book + BookItem
//     -> library->registerMember() -> creates Member with FineCalculator
//     -> library->searchByTitle("Clean") -> partial match search
//     -> library->findAvailableCopy(isbn) -> returns first AVAILABLE BookItem
//     -> alice->borrow(bookItem)
//        -> checks MAX_BOOKS limit
//        -> bookItem->checkout(this) [sets BORROWED status]
//        -> records BorrowRecord in history
//     -> alice->returnBook(bookItem, daysLate)
//        -> fineCalc->calculate(daysLate) [Strategy pattern]
//        -> bookItem->returnBook() [sets AVAILABLE status]

// METHOD CALL TREE:
//   member.borrow(bookItem)
//     -> borrowedBooks.size() < MAX_BOOKS? [limit check]
//     -> bookItem.isAvailable()? [availability check]
//     -> bookItem.checkout(this) [mark BORROWED]
//     -> history.push_back(BorrowRecord)
//   member.returnBook(bookItem, daysLate)
//     -> fineCalc->calculate(daysLate) [Strategy dispatch]
//     -> bookItem.returnBook() [mark AVAILABLE]

// CLASS RESPONSIBILITY TABLE:
//   Book             | Bibliographic info (ISBN, title, author)
//   BookItem         | Physical copy status, barcode, due date
//   FineCalculator   | Strategy interface for fine calculation
//   StandardFine     | $1.00/day fine
//   PremiumFine      | $0.50/day fine
//   BorrowRecord     | Single borrow transaction record
//   Member           | Borrows (max 5), returns, history, fine calc
//   Library          | Singleton catalog + member management

// DESIGN PATTERNS:
//   1. Singleton  -> Library (one instance, central access)
//   2. Strategy   -> FineCalculator (Standard vs Premium rates)
//   3. Observer   -> (Extendable: notify member when reserved book returns)

// BEST PRACTICES:
//   1. Book vs BookItem distinction -> catalog info vs physical copy
//   2. Encapsulation  -> private fields, public methods
//   3. SRP           -> Member handles borrowing, Library handles catalog
//   4. OCP           -> New member types just need new FineCalculator
//   5. Composition   -> Member OWNS BorrowRecords
//   6. Memory mgmt   -> Library destructor cleans up all owned objects
