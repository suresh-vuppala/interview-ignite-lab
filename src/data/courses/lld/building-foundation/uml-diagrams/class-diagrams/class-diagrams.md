# Class Diagrams

Class diagrams are the **most important UML diagram for LLD interviews**. They show classes, their attributes, methods, and relationships.

<br>

---

## Why It Matters in LLD Interviews

In 90% of LLD interviews, you'll be asked to draw a class diagram. It demonstrates:
- Your ability to **identify entities and their relationships**
- Your understanding of **access modifiers, types, multiplicity**
- How you translate requirements into an **object-oriented design**

<br>

---

## Class Box Structure

```
┌──────────────────────────┐
│       <<ClassName>>       │   ← Class name (bold, centered)
├──────────────────────────┤
│ - privateField: Type      │   ← Attributes
│ # protectedField: Type    │
│ + publicField: Type       │
├──────────────────────────┤
│ + publicMethod(): RetType │   ← Methods
│ - privateHelper(): void   │
│ # calculate(x: int): int  │
└──────────────────────────┘
```

## Visibility Symbols

| Symbol | Meaning | Java Keyword |
|--------|---------|-------------|
| `+` | Public | `public` |
| `-` | Private | `private` |
| `#` | Protected | `protected` |
| `~` | Package | (default) |

## Relationship Lines

| Line | Relationship | Meaning |
|------|-------------|---------|
| `────` | Association | Uses/knows about |
| `◇────` | Aggregation | HAS-A (part survives) |
| `◆────` | Composition | OWNS (part dies with whole) |
| `- - -►` | Dependency | Temporarily uses |
| `────▷` | Inheritance | IS-A (extends) |
| `- - -▷` | Implementation | Implements interface |

<br>

---

## Interview Example: Library Management

```
┌──────────────┐         ┌──────────────┐
│   Library     │◆───────│    Book       │
├──────────────┤  1   *  ├──────────────┤
│ - name       │         │ - isbn       │
│ - books[]    │         │ - title      │
├──────────────┤         │ - author     │
│ + addBook()  │         ├──────────────┤
│ + search()   │         │ + getInfo()  │
└──────────────┘         └──────────────┘
        │                       │
        │ 1                     │
        ◇                       │ borrowed by
        │ *                     │
┌──────────────┐         ┌──────────────┐
│   Member     │─────────│  BorrowRecord│
├──────────────┤   1  *  ├──────────────┤
│ - memberId   │         │ - borrowDate │
│ - name       │         │ - dueDate    │
├──────────────┤         │ - returnDate │
│ + borrow()   │         ├──────────────┤
│ + return()   │         │ + isOverdue()│
└──────────────┘         └──────────────┘
```

**Relationships explained:**
- Library **◆** Book = Composition (books belong to library)
- Library **◇** Member = Aggregation (members exist independently)
- Member **──** BorrowRecord = Association (member has borrow history)

<br>

---

## Tips for Drawing Class Diagrams in Interviews

1. **Start with nouns** from requirements → these become classes
2. **Verbs become methods**
3. **"Has"/"Contains" → Composition/Aggregation**
4. **"Is a" → Inheritance**
5. **Don't over-detail** — focus on core entities and key methods
6. **Label multiplicity** on all relationships

<br>

---

## Key Takeaways

1. **Most frequently drawn diagram in LLD interviews**
2. **Three sections:** name, attributes (with visibility), methods
3. **Master the 6 relationship types** and when to use each
4. **Multiplicity is crucial** — 1:1, 1:N, M:N
5. **Start from requirements** — nouns = classes, verbs = methods
