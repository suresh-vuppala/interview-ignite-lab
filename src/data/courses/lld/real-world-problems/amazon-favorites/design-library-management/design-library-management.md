# Design a Library Management System

Design a library management system that handles book cataloging, member management, borrowing/returning, and fine calculation.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **Book catalog** — add, remove, search books (by title, author, ISBN, subject)
2. **Member management** — register members, remove members, track borrowing history
3. **Borrowing** — borrow books (max 5 per member), set due date (14 days)
4. **Returning** — return books, calculate fines for late returns
5. **Availability check** — check if a specific book is available
6. **Reservation** — reserve a book if all copies are borrowed (FIFO queue)
7. **Fine calculation** — $1/day for overdue returns

### Extended Requirements (If Time Permits)

1. Multiple copies of the same book (same ISBN, different barcodes)
2. Reservation queue with notification when book becomes available
3. Role-based access (Librarian can override fines, Member can only borrow)
4. Email notification for due dates (3 days before, on due date, overdue)
5. Renewal — extend due date once (if no reservations pending)
6. Book recommendation based on borrowing history
7. Annual membership fees and account balance tracking

<br>

---

## Constraints

- Maximum books per member: 5
- Loan period: 14 days
- Fine: $1.00/day for standard members, $0.50/day for premium members
- Maximum reservation queue: 10 per book
- ISBN: 13-digit string
- Barcode: unique per physical copy
- Member ID: auto-generated, unique
- One copy per borrow record (not the entire book)

<br>

---

## Identify Primary Actors

1. **Member** — borrows and returns books
   - Actions: search catalog, borrow book, return book, reserve book, pay fines, view history

2. **Librarian** — manages library operations
   - Actions: add/remove books, register members, override fines, manage reservations

3. **System** — automated processes
   - Actions: calculate fines, send due date reminders, process reservation queue, update availability

<br>

---

## Core Entities

### 1. Library (Singleton)
- **Attributes**: catalog: Map<ISBN, List<BookItem>>, members: Map<MemberId, Member>
- **Responsibilities**: Central orchestrator — search, borrow, return operations

### 2. Book (catalog information)
- **Attributes**: isbn, title, author, subject, publisher, publicationYear
- **Responsibilities**: Store bibliographic information (not a physical copy)

### 3. BookItem (physical copy, extends Book)
- **Attributes**: barcode, status (AVAILABLE/BORROWED/RESERVED/LOST), dueDate, borrowedBy
- **Responsibilities**: Track physical copy status, link to borrower

### 4. Member
- **Attributes**: memberId, name, email, borrowedBooks[], reservations[], memberType (STANDARD/PREMIUM)
- **Responsibilities**: Borrow (max 5), return with fine check, reserve books

### 5. BorrowRecord
- **Attributes**: bookItem, member, borrowDate, dueDate, returnDate, fine
- **Responsibilities**: Track individual borrowing session, calculate fine on return

### 6. FineCalculator (Strategy Pattern)
- **Method**: calculate(dueDate, returnDate): double
- **Implementations**: StandardFine ($1/day), PremiumFine ($0.50/day)

### 7. ReservationQueue
- **Attributes**: book, waitList: Queue<Member>
- **Responsibilities**: FIFO queue for reserved books, notify next member when available

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Type |
|----------|-------------|----------|------|
| Library | manages | BookItem[] | Composition (◆) |
| Library | manages | Member[] | Aggregation (◇) |
| Book | has copies | BookItem[] | Aggregation (◇) |
| BookItem | extends | Book | Inheritance |
| Member | borrows | BookItem[] | Association |
| Member | reserves | Book[] | Association |
| BorrowRecord | links | BookItem + Member | Association |
| Library | uses | FineCalculator | Dependency |
| ReservationQueue | queues | Member[] | Aggregation (◇) |

<br>

---

## Relationships Diagram (Textual UML)

```
  Library (Singleton)
  -catalog: Map<ISBN, List<BookItem>>
  -members: Map<MemberId, Member>
  +search(), +borrow(), +return()
       │
       ├──◆──→ Book ──◇──→ BookItem[]
       │        -isbn      -barcode
       │        -title     -status (AVAILABLE/BORROWED/RESERVED)
       │        -author    -dueDate
       │                   -borrowedBy → Member
       │
       ├──◇──→ Member
       │        -memberId, -name
       │        -borrowedBooks[max 5]
       │        -memberType
       │
       └──uses──→ FineCalculator (Strategy)
                     △
                ┌────┴────┐
          StandardFine  PremiumFine
           ($1/day)     ($0.50/day)

  ReservationQueue
  -book: Book
  -waitList: Queue<Member>
  +enqueue(), +notifyNext()
```

<br>

---

## Design Patterns Used

### 1. **Singleton Pattern**
- **Where**: Library class — one library system per application
- **Why**: Central catalog and member registry must be single instance
- **Benefit**: Global access point, prevents duplicate data

### 2. **Strategy Pattern**
- **Where**: FineCalculator with StandardFine and PremiumFine implementations
- **Why**: Different member types have different fine rates
- **Benefit**: New member tiers (Student, Senior, Employee) can have custom fine rates without modifying existing code

### 3. **Observer Pattern**
- **Where**: ReservationQueue notifies next member when book is returned
- **Why**: Member doesn't poll for availability — system pushes notification
- **Benefit**: Decoupled notification — member doesn't know about return process

### 4. **Factory Pattern** (optional)
- **Where**: Create BookItem from ISBN and barcode
- **Why**: Centralize book creation with proper initialization
- **Benefit**: Ensure all BookItems are properly linked to their Book catalog entry

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms
- **Borrow operation**: `synchronized` on BookItem — prevent two members borrowing same copy
- **Return + reservation**: Atomic operation — return book AND notify next reservee under same lock
- **Catalog search**: Read-only — safe for concurrent access
- **Fine calculation**: Stateless, thread-safe by design

### Race Conditions Handled
- **Two members borrow last copy simultaneously**: `synchronized(bookItem)` — first wins, second sees BORROWED
- **Return + reservation notification**: Single lock ensures book goes to next reservee, not a random borrower
- **Concurrent catalog updates**: `ReadWriteLock` on catalog — many readers, exclusive writer

<br>

---

## Edge Cases & Error Handling

### Edge Cases
1. **Member at max borrowing limit (5)** — reject borrow, inform member
2. **All copies borrowed** — offer reservation
3. **Book returned after reservation queue filled** — give to first in queue, not general availability
4. **Member returns book they didn't borrow** — reject with error
5. **Book reported lost** — change status to LOST, charge replacement fee
6. **Fine exceeds maximum** — cap at book replacement cost
7. **Member cancels reservation** — remove from queue, advance others
8. **Duplicate ISBN with different editions** — treat as separate Book entries
9. **Library closed (holidays)** — don't count closed days toward fine

### Error Handling Strategy
- **BookNotAvailableException**: All copies borrowed, offer reservation
- **MaxBooksExceededException**: Member already has 5 books
- **InvalidReturnException**: Member returning book they didn't borrow
- **MemberNotFoundException**: Invalid member ID
- **FineUnpaidException**: Block new borrows until outstanding fines cleared

<br>

---

## Implementation

> See the **Java code tab** for the complete implementation including Library singleton, Book/BookItem hierarchy, Member with borrowing limits, Strategy-based fine calculation, and reservation queue.
