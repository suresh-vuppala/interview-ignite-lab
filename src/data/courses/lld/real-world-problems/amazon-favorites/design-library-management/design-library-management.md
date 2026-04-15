# Design a Library Management System

Design a library management system that handles book cataloging, member management, borrowing/returning, and fine calculation.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **Book catalog** — add, remove, search books (by title, author, ISBN)
2. **Member management** — register, remove members
3. **Borrowing** — borrow books (max 5 per member), generate receipt
4. **Returning** — return books, calculate fines for late returns
5. **Availability** — check if a book is available, reserve if not
6. **Fine calculation** — $1/day for late returns

### Extended Requirements

1. Multiple copies of same book
2. Reservation queue (FIFO)
3. Librarian vs Member roles
4. Email notification for due dates

<br>

---

## Core Entities

```
Library (Singleton)
├─ books: Map<ISBN, BookItem[]>
├─ members: Map<MemberId, Member>
├─ search(query): List<Book>

Book
├─ isbn, title, author, subject, publisher

BookItem extends Book
├─ barcode, status (AVAILABLE, BORROWED, RESERVED, LOST)
├─ dueDate, borrowedBy

Member
├─ memberId, name, borrowedBooks[], reservations[]
├─ borrow(BookItem), return(BookItem)

BorrowRecord
├─ bookItem, member, borrowDate, dueDate, returnDate, fine

FineCalculator (Strategy)
├─ StandardFine ($1/day)
├─ PremiumFine ($0.50/day for premium members)
```

<br>

---

## Design Patterns Used

| Pattern | Where | Why |
|---------|-------|-----|
| **Singleton** | Library instance | One library system |
| **Strategy** | FineCalculator | Different fine rules per member type |
| **Observer** | Notify member when reserved book is available | Decoupled notification |

<br>

---

## Interview Tips

- Distinguish Book (catalog info) from BookItem (physical copy)
- BookItem has status (state machine: Available → Borrowed → Returned)
- Fine calculation as Strategy allows different policies
- Reservation queue for popular books
