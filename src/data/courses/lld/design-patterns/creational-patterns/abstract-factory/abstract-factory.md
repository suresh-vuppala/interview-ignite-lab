# Abstract Factory Pattern

> **Intent:** Provide an interface for creating **families of related or dependent objects** without specifying their concrete classes.

<br>

---

## When to Use

- Create objects that **belong together** (a UI theme has Button + Checkbox + TextField)
- System should be **independent of how products are created**
- **Multiple variants** of a product family (Light theme vs Dark theme, Windows vs Mac)

<br>

---

## Structure

```
AbstractFactory          ConcreteFactory1          ConcreteFactory2
├─ createButton()   →   ├─ createButton()     →   ├─ createButton()
├─ createCheckbox() →   ├─ createCheckbox()   →   ├─ createCheckbox()
                         returns DarkButton         returns LightButton
                         returns DarkCheckbox       returns LightCheckbox
```

<br>

---

## Example: Cross-Platform UI

```java
// Abstract products
interface Button { void render(); void onClick(Runnable action); }
interface Checkbox { void render(); boolean isChecked(); }

// Concrete products — Windows family
class WindowsButton implements Button { public void render() { System.out.println("[Win Button]"); } ... }
class WindowsCheckbox implements Checkbox { public void render() { System.out.println("[Win ✓]"); } ... }

// Concrete products — Mac family
class MacButton implements Button { public void render() { System.out.println("[Mac Button]"); } ... }
class MacCheckbox implements Checkbox { public void render() { System.out.println("[Mac ✓]"); } ... }

// Abstract factory
interface UIFactory {
    Button createButton();
    Checkbox createCheckbox();
}

// Concrete factories
class WindowsUIFactory implements UIFactory {
    public Button createButton() { return new WindowsButton(); }
    public Checkbox createCheckbox() { return new WindowsCheckbox(); }
}

class MacUIFactory implements UIFactory {
    public Button createButton() { return new MacButton(); }
    public Checkbox createCheckbox() { return new MacCheckbox(); }
}

// Client — works with ANY factory
class Application {
    private Button button;
    private Checkbox checkbox;
    
    public Application(UIFactory factory) {
        button = factory.createButton();     // Doesn't know Windows or Mac
        checkbox = factory.createCheckbox();
    }
}
```

<br>

---

## Factory Method vs Abstract Factory

| Factory Method | Abstract Factory |
|---------------|-----------------|
| Creates **one product** | Creates **family of products** |
| Uses inheritance | Uses composition |
| Single `create()` method | Multiple `create()` methods |
| `DocumentFactory.create("pdf")` | `UIFactory.createButton()` + `createCheckbox()` |

<br>

---

## Key Takeaways

1. **Families of related objects** — products that must work together
2. **Swap entire families** by changing one factory
3. **Guarantees consistency** — can't mix Windows button with Mac checkbox
4. **More complex than Factory Method** — use only when you have product families
