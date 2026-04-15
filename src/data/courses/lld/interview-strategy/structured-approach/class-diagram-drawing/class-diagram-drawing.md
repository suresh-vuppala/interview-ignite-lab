# Step 4: Class Diagram Drawing

> **The class diagram is the centerpiece of your LLD interview.** A clear diagram shows you understand entities, relationships, and design patterns.

<br>

---

## Speed Drawing Technique (5-8 minutes)

### Pass 1: Boxes (2 min)
Draw a box for each entity with just the name:
```
[ParkingLot]  [Floor]  [ParkingSpot]  [Vehicle]  [Ticket]  [Payment]
```

### Pass 2: Key Attributes (2 min)
Add the most important 2-3 attributes to each box:
```
┌─────────────┐    ┌──────────────┐
│ ParkingLot   │    │ ParkingSpot   │
│ -floors[]    │    │ -spotId       │
│ -capacity    │    │ -type         │
│ +parkVehicle│    │ -isOccupied   │
└─────────────┘    └──────────────┘
```

### Pass 3: Relationships (2 min)
Draw lines with labels:
```
ParkingLot ◆──1:N──→ Floor ◆──1:N──→ ParkingSpot
Vehicle ──uses──→ ParkingSpot
Ticket ──links──→ Vehicle + ParkingSpot
```

### Pass 4: Patterns (2 min)
Mark interfaces and pattern annotations:
```
<<interface>> PricingStrategy
    △
┌───┴───┐
Hourly  Flat
```

<br>

---

## Relationship Cheat Sheet

| Symbol | Meaning | Example |
|--------|---------|---------|
| `◆────` | Composition (owns, dies with) | Order ◆── OrderItem |
| `◇────` | Aggregation (has, survives) | Team ◇── Player |
| `─────` | Association (uses/knows) | Doctor ── Patient |
| `─ ─ ─►` | Dependency (temporary use) | Service ─ ─ ─► Logger |
| `────▷` | Inheritance (extends) | Dog ────▷ Animal |
| `─ ─ ─▷` | Implementation (implements) | EmailSender ─ ─ ─▷ Notification |

<br>

---

## Interview Whiteboard Tips

1. **Draw BIG** — small diagrams are hard to discuss
2. **Leave space** between entities — you'll add more later
3. **Use consistent notation** — pick one style and stick with it
4. **Label relationships** with multiplicity (1:1, 1:N, M:N)
5. **Circle the core entity** — helps interviewer follow your thinking
6. **Talk while drawing** — "ParkingLot HAS many Floors, each Floor HAS many Spots..."

<br>

---

## Common Mistakes

| Mistake | Fix |
|---------|-----|
| **Too many entities (10+)** | Focus on 5-8 core entities |
| **No relationship labels** | Always show 1:1, 1:N, M:N |
| **Missing interfaces** | Show Strategy/Observer interfaces |
| **All associations, no composition** | Distinguish owned vs shared |
| **No methods shown** | Add 1-2 key methods per entity |

<br>

---

## Key Takeaways

1. **4-pass technique:** Boxes → Attributes → Relationships → Patterns
2. **5-8 entities max** for a clear, discussable diagram
3. **Talk while drawing** — narrate your design decisions
4. **Show patterns visually** — interface triangles, decorator wrapping
5. **It doesn't need to be pretty** — clarity > aesthetics
