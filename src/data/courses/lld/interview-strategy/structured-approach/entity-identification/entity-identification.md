# Step 2: Entity Identification

> **Nouns in requirements become classes. Verbs become methods.** This simple rule drives your entire design.

<br>

---

## The Technique: Noun-Verb Extraction

### Step 1: Underline Nouns → These are your Entities

> "A **parking lot** has multiple **floors**. Each **floor** has **parking spots** of different **types**. A **vehicle** enters through an **entry panel**, gets a **ticket**, parks in a **spot**, and pays at an **exit panel**."

**Entities found:** ParkingLot, Floor, ParkingSpot, SpotType, Vehicle, EntryPanel, Ticket, ExitPanel

### Step 2: Underline Verbs → These are your Methods

> "A vehicle **enters**, **gets** a ticket, **parks** in a spot, and **pays** at an exit panel."

**Methods found:** enter(), generateTicket(), park(), pay()

### Step 3: Identify Attributes

For each entity, ask: "What data does this hold?"

| Entity | Attributes |
|--------|-----------|
| ParkingLot | name, address, floors[] |
| ParkingSpot | spotId, type, isOccupied, floor |
| Vehicle | licensePlate, type, color |
| Ticket | ticketId, entryTime, spot, vehicle |

<br>

---

## Entity Categories

### 1. Core Domain Entities (Always include)
- The main "things" in the system
- Examples: Order, User, Product, Account, Room

### 2. Actors (Who interacts with the system?)
- Examples: Customer, Admin, Driver, Librarian

### 3. State/Status Entities
- Enums for states: OrderStatus, PaymentStatus, SpotType
- Examples: AVAILABLE, OCCUPIED, RESERVED

### 4. Service/Manager Entities
- Orchestrators that coordinate operations
- Examples: ParkingService, BookingManager, RideDispatcher

### 5. Value Objects
- Small, immutable data holders
- Examples: Location(lat, lng), Money(amount, currency), TimeSlot(start, end)

<br>

---

## The Entity Validation Checklist

For each entity, verify:

- [ ] **Has clear responsibility** — can you describe it in one sentence?
- [ ] **Has 2+ attributes** — entities with zero attributes are probably unnecessary
- [ ] **Has 1+ methods** — entities with no behavior may just be data
- [ ] **Isn't duplicating another entity** — merge if too similar
- [ ] **Has a clear relationship** to at least one other entity

<br>

---

## Example: Library Management System

Requirements: "Members can borrow books from a library. Each book has an ISBN and multiple copies. Members can reserve unavailable books. Fines are charged for late returns."

| Noun | Entity? | Reasoning |
|------|---------|-----------|
| Member | ✅ Yes | Core actor |
| Book | ✅ Yes | Core domain |
| Library | ✅ Yes | System container |
| ISBN | ❌ No | Attribute of Book |
| Copy | ✅ Yes → BookItem | Physical copy ≠ catalog entry |
| Reservation | ✅ Yes | Tracks reserve requests |
| Fine | ✅ Yes → FineCalculator | Could be a service, not just data |

<br>

---

## Common Mistakes

| Mistake | Fix |
|---------|-----|
| **Too many entities** (15+) | Start with 5-8 core entities, add later |
| **Missing key entity** | Re-read requirements, check all nouns |
| **Confusing entity with attribute** | "ISBN" is an attribute of Book, not a class |
| **Skipping enums** | Status/type enums are critical — SpotType, OrderStatus |
| **No service classes** | Who orchestrates? Add a Manager/Service class |

<br>

---

## Key Takeaways

1. **Nouns → Classes, Verbs → Methods** — start here always
2. **5-8 entities is the sweet spot** for a 45-min interview
3. **Distinguish catalog from physical item** — Book vs BookItem, Movie vs Show
4. **Include enums** for status and types
5. **Don't forget service/manager classes** — they orchestrate the flow
