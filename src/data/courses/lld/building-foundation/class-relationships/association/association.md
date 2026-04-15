# Association

Association is the most general relationship between classes — it means one object **uses or knows about** another object. Neither object owns the other; they have **independent lifecycles**.

<br>

---

## Why It Matters in LLD Interviews

Understanding association vs aggregation vs composition is a **frequent interview question**. It affects:
- How you draw class diagrams
- Whether objects should exist independently
- Memory management and lifecycle decisions

<br>

---

## Types of Association

### Unidirectional
```java
class Student {
    private String name;
    // Student doesn't know about Teacher
}

class Teacher {
    private String name;
    private List<Student> students;  // Teacher knows Students (one-way)
}
```

### Bidirectional
```java
class Doctor {
    private List<Patient> patients;  // Doctor knows Patients
}

class Patient {
    private Doctor doctor;           // Patient knows Doctor
}
```

<br>

---

## Multiplicity

| Notation | Meaning |
|----------|---------|
| `1` | Exactly one |
| `0..1` | Zero or one |
| `*` or `0..*` | Zero or more |
| `1..*` | One or more |
| `m..n` | Between m and n |

**Examples:**
- Teacher `1` ←→ `*` Student (one teacher, many students)
- Student `*` ←→ `*` Course (many-to-many)
- Person `1` ←→ `0..1` Passport (one person, zero or one passport)

<br>

---

## Key Characteristics

1. **Independent lifecycles** — both objects exist independently
2. **No ownership** — neither object "owns" the other
3. **Can be temporary** — objects may associate and disassociate

```java
// Association: Teacher and Student exist independently
class Teacher {
    private String name;
    private List<Student> students = new ArrayList<>();
    
    public void addStudent(Student s) { students.add(s); }
    public void removeStudent(Student s) { students.remove(s); }
    // Students continue to exist even if teacher is removed
}
```

<br>

---

## Common Interview Questions

1. **"What is association?"** → Objects that use/know each other, independent lifecycles
2. **"Association vs Dependency?"** → Association = long-term relationship; Dependency = temporary (method parameter)
3. **"How do you represent in UML?"** → Solid line between classes, with multiplicity labels

<br>

---

## Key Takeaways

1. **Most general relationship** — "uses" or "knows about"
2. **Independent lifecycles** — deleting one doesn't affect the other
3. **Can be uni- or bidirectional**
4. **Multiplicity matters** — 1:1, 1:N, M:N
5. **Association is the parent** of aggregation and composition
