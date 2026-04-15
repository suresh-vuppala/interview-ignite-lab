# Prototype Pattern

> **Intent:** Create new objects by copying an existing object (prototype), avoiding the cost of creating from scratch.

<br>

---

## When to Use

- Object creation is **expensive** (DB queries, network calls, complex setup)
- Need **many similar objects** with slight variations
- Want to avoid **subclass proliferation** for each configuration
- **Clone + modify** is cheaper than creating from scratch

<br>

---

## Implementation

```java
interface Prototype<T> {
    T clone();
}

class GameUnit implements Prototype<GameUnit> {
    private String type;
    private int health;
    private int attack;
    private int defense;
    private Map<String, Integer> abilities;
    
    public GameUnit(String type, int health, int attack, int defense) {
        this.type = type; this.health = health;
        this.attack = attack; this.defense = defense;
        this.abilities = new HashMap<>();
    }
    
    // Deep clone — creates independent copy
    public GameUnit clone() {
        GameUnit copy = new GameUnit(type, health, attack, defense);
        copy.abilities = new HashMap<>(this.abilities); // Deep copy of map
        return copy;
    }
    
    public void setHealth(int h) { this.health = h; }
    public void addAbility(String name, int level) { abilities.put(name, level); }
}

// Prototype Registry — pre-configured templates
class UnitRegistry {
    private Map<String, GameUnit> prototypes = new HashMap<>();
    
    public void register(String key, GameUnit unit) { prototypes.put(key, unit); }
    
    public GameUnit create(String key) {
        GameUnit proto = prototypes.get(key);
        if (proto == null) throw new IllegalArgumentException("Unknown unit: " + key);
        return proto.clone(); // Clone, don't reuse!
    }
}

// Setup prototypes once
UnitRegistry registry = new UnitRegistry();
GameUnit warrior = new GameUnit("Warrior", 100, 20, 15);
warrior.addAbility("Slash", 3);
registry.register("warrior", warrior);

// Create many warriors by cloning — fast!
GameUnit w1 = registry.create("warrior");
GameUnit w2 = registry.create("warrior");
w2.setHealth(120); // Modify copy without affecting prototype
```

<br>

---

## Shallow vs Deep Copy

| Shallow Copy | Deep Copy |
|-------------|-----------|
| Copies references | Copies actual objects |
| Changes to nested objects affect original | Fully independent |
| `Object.clone()` default behavior | Must implement manually |

```java
// ⚠️ SHALLOW: list is shared!
GameUnit shallow = new GameUnit(original.type, original.health, ...);
shallow.abilities = original.abilities; // Same reference!

// ✅ DEEP: list is independent
GameUnit deep = new GameUnit(original.type, original.health, ...);
deep.abilities = new HashMap<>(original.abilities); // New map with copied entries
```

<br>

---

## Key Takeaways

1. **Clone instead of construct** when creation is expensive
2. **Always use deep copy** for mutable nested objects
3. **Prototype Registry** stores pre-configured templates
4. **Java's `Cloneable`** is poorly designed — implement your own `clone()`
5. **Useful in game dev, document editing, config templates**
