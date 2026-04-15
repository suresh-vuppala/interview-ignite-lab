#include <string>
#include <vector>
#include <map>
#include <optional>
#include <algorithm>
#include <iostream>
#include <memory>
#include <chrono>
using namespace std;

class Member; // Forward declaration

// ========== BOOK ==========
struct Book {
    string isbn, title, author, subject;
};

enum class BookStatus { AVAILABLE, BORROWED, RESERVED, LOST };

class BookItem {
    string barcode;
    Book book;
    BookStatus status = BookStatus::AVAILABLE;
    Member* borrowedBy = nullptr;
    int dueDaysFromNow = 0;
public:
    BookItem(string barcode, Book book) : barcode(move(barcode)), book(move(book)) {}
    bool isAvailable() const { return status == BookStatus::AVAILABLE; }
    void checkout(Member* member) { status = BookStatus::BORROWED; borrowedBy = member; dueDaysFromNow = 14; }
    void returnBook() { status = BookStatus::AVAILABLE; borrowedBy = nullptr; dueDaysFromNow = 0; }
    const Book& getBook() const { return book; }
    const string& getBarcode() const { return barcode; }
    int getDueDays() const { return dueDaysFromNow; }
};

// ========== FINE CALCULATOR (Strategy) ==========
class FineCalculator {
public:
    virtual ~FineCalculator() = default;
    virtual double calculate(int daysLate) const = 0;
};

class StandardFine : public FineCalculator {
public:
    double calculate(int daysLate) const override { return daysLate > 0 ? daysLate * 1.0 : 0; }
};

class PremiumFine : public FineCalculator {
public:
    double calculate(int daysLate) const override { return daysLate > 0 ? daysLate * 0.5 : 0; }
};

// ========== MEMBER ==========
class Member {
    string memberId, name;
    vector<BookItem*> borrowedBooks;
    static constexpr int MAX_BOOKS = 5;
public:
    Member(string id, string name) : memberId(move(id)), name(move(name)) {}
    bool borrow(BookItem* item) {
        if ((int)borrowedBooks.size() >= MAX_BOOKS || !item->isAvailable()) return false;
        item->checkout(this);
        borrowedBooks.push_back(item);
        return true;
    }
    double returnBook(BookItem* item, const FineCalculator& fineCalc, int daysLate) {
        borrowedBooks.erase(remove(borrowedBooks.begin(), borrowedBooks.end(), item), borrowedBooks.end());
        double fine = fineCalc.calculate(daysLate);
        item->returnBook();
        return fine;
    }
    const string& getName() const { return name; }
};

// ========== LIBRARY (Singleton) ==========
class Library {
    map<string, vector<unique_ptr<BookItem>>> catalog; // ISBN -> copies
    map<string, unique_ptr<Member>> members;
    Library() = default;
public:
    static Library& getInstance() { static Library instance; return instance; }
    Library(const Library&) = delete;
    Library& operator=(const Library&) = delete;

    void addBook(Book book, const string& barcode) {
        catalog[book.isbn].push_back(make_unique<BookItem>(barcode, book));
    }
    void registerMember(string id, string name) {
        members[id] = make_unique<Member>(move(id), move(name));
    }
    BookItem* findAvailableCopy(const string& isbn) {
        auto it = catalog.find(isbn);
        if (it == catalog.end()) return nullptr;
        for (auto& item : it->second)
            if (item->isAvailable()) return item.get();
        return nullptr;
    }
    vector<BookItem*> searchByTitle(const string& title) {
        vector<BookItem*> results;
        for (auto& [isbn, items] : catalog)
            for (auto& item : items)
                if (item->getBook().title.find(title) != string::npos)
                    results.push_back(item.get());
        return results;
    }
};
