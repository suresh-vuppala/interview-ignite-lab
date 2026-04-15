# Template Method Pattern

> **Intent:** Define the skeleton of an algorithm in a superclass, letting subclasses override specific steps without changing the algorithm's structure.

<br>

---

## When to Use

- **Common algorithm skeleton** with varying steps
- **"Don't call us, we'll call you"** (Hollywood Principle) — framework calls your code
- **Prevent code duplication** of shared workflow steps

<br>

---

## Example: Data Processing Pipeline

```java
abstract class DataProcessor {
    // Template method — defines the algorithm skeleton (FINAL!)
    public final void process() {
        readData();
        parseData();
        validate();
        transform();
        save();
        notifyComplete();
    }
    
    protected abstract void readData();     // Subclass must implement
    protected abstract void parseData();    // Subclass must implement
    
    // Hook methods — optional override
    protected void validate() { System.out.println("Default validation..."); }
    protected void transform() { /* No-op by default */ }
    
    // Common steps — shared by all
    protected void save() { System.out.println("Saving to database..."); }
    protected void notifyComplete() { System.out.println("Processing complete!"); }
}

class CSVProcessor extends DataProcessor {
    protected void readData() { System.out.println("Reading CSV file..."); }
    protected void parseData() { System.out.println("Parsing CSV rows..."); }
    protected void validate() { System.out.println("Validating CSV headers..."); }
}

class JSONProcessor extends DataProcessor {
    protected void readData() { System.out.println("Reading JSON file..."); }
    protected void parseData() { System.out.println("Parsing JSON objects..."); }
    // Uses default validate() and transform()
}
```

<br>

---

## Template Method vs Strategy

| Template Method | Strategy |
|----------------|----------|
| **Inheritance** — subclass overrides steps | **Composition** — inject strategy object |
| Algorithm structure is **fixed** | Entire algorithm is **swapped** |
| Override **some steps** | Replace **whole behavior** |
| Compile-time binding | Runtime binding |

<br>

---

## Key Takeaways

1. **`final` template method** prevents subclasses from changing the algorithm skeleton
2. **Abstract methods** = required customization points
3. **Hook methods** = optional customization (empty default)
4. **Hollywood Principle** — don't call us, we'll call you
5. **Used in:** frameworks (Spring, JUnit), build pipelines, data processing
