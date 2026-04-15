# Code Smells

> **A code smell is a surface indication that usually corresponds to a deeper problem in the system.** — Martin Fowler

<br>

---

## Top Code Smells for LLD Interviews

### 1. Long Method (> 20 lines)
**Smell:** Method does too many things.
**Fix:** Extract Method — break into smaller, named methods.

### 2. God Class (> 300 lines)
**Smell:** One class handles everything.
**Fix:** Extract Class — split by responsibility (SRP).

### 3. Switch Statements / Long if-else chains
**Smell:** Type-checking with switch/instanceof.
**Fix:** Replace with Polymorphism (Strategy/State pattern).

```java
// ❌ Smell
double calculatePay(Employee e) {
    switch (e.getType()) {
        case MANAGER: return e.getSalary() * 1.2;
        case ENGINEER: return e.getSalary() * 1.1;
        case INTERN: return e.getSalary() * 0.8;
    }
}

// ✅ Fix: Polymorphism
interface PayCalculator { double calculate(double salary); }
class ManagerPay implements PayCalculator { ... }
class EngineerPay implements PayCalculator { ... }
```

### 4. Primitive Obsession
**Smell:** Using primitives instead of small objects.
```java
// ❌ Primitives everywhere
void createUser(String email, String phone, int age, double lat, double lng) { ... }

// ✅ Value objects
void createUser(Email email, Phone phone, Age age, Location location) { ... }
```

### 5. Feature Envy
**Smell:** Method uses more data from another class than its own.
**Fix:** Move method to the class it's envious of.

### 6. Data Clumps
**Smell:** Same group of parameters appears in multiple methods.
**Fix:** Create a class to group them.

```java
// ❌ Same params repeated
void setAddress(String street, String city, String zip) { ... }
void validateAddress(String street, String city, String zip) { ... }

// ✅ Group into object
class Address { String street, city, zip; }
void setAddress(Address addr) { ... }
```

### 7. Shotgun Surgery
**Smell:** One change requires modifying many classes.
**Fix:** Move related code into one class (consolidate).

<br>

---

## Key Takeaways

1. **Smells are symptoms, not the disease** — investigate the underlying design problem
2. **Most smells point to SRP violations**
3. **Switch statements → Polymorphism** is the #1 refactoring in LLD
4. **Value objects** eliminate primitive obsession and add validation
5. **If a smell doesn't cause pain, don't fix it** — pragmatism over perfection
