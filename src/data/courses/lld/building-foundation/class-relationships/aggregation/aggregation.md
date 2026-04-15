# Aggregation

Aggregation is a special form of association representing a **whole-part (HAS-A)** relationship where the **part can exist independently** of the whole.

<br>

---

## The Key Rule

> **If the container is destroyed, the contained objects continue to exist.**

<br>

---

## Example

```java
class Department {
    private String name;
    private List<Employee> employees;  // Department HAS employees
    
    public Department(String name) {
        this.name = name;
        this.employees = new ArrayList<>();
    }
    
    public void addEmployee(Employee e) { employees.add(e); }
    public void removeEmployee(Employee e) { employees.remove(e); }
}

class Employee {
    private String name;
    // Employee exists independently — can move to another department
}

// If department is dissolved, employees still exist!
Department engineering = new Department("Engineering");
Employee alice = new Employee("Alice");
engineering.addEmployee(alice);
// Delete department → alice is still alive
```

<br>

---

## UML Notation

**Empty diamond (◇) on the whole side**

```
Department ◇──── Employee
(whole)          (part — can exist independently)
```

<br>

---

## Aggregation vs Composition

| Aspect | Aggregation | Composition |
|--------|-------------|-------------|
| **Lifecycle** | Part survives whole's destruction | Part dies with whole |
| **Ownership** | Weak (shared) | Strong (exclusive) |
| **UML** | Empty diamond ◇ | Filled diamond ◆ |
| **Example** | Team ◇── Player | House ◆── Room |

<br>

---

## Key Takeaways

1. **HAS-A with independent lifecycle**
2. **Parts are shared** — can belong to multiple wholes
3. **Empty diamond in UML** (◇)
4. **Objects passed in** from outside (not created inside)
