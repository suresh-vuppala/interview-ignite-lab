# YAGNI — You Aren't Gonna Need It

> "Don't implement something until it is necessary."

<br>

---

## The Problem: Speculative Design

```java
// ❌ "We MIGHT need to support XML, YAML, TOML someday..."
interface ConfigParser { Config parse(String content); }
class JSONParser implements ConfigParser { ... }
class XMLParser implements ConfigParser { ... }      // Nobody asked for this
class YAMLParser implements ConfigParser { ... }     // Nobody asked for this
class TOMLParser implements ConfigParser { ... }     // Nobody asked for this
class ConfigParserFactory { ... }                    // Factory for 4 parsers
```

## The Fix: Build What's Needed NOW

```java
// ✅ Only JSON is needed today
class JSONConfigParser {
    public Config parse(String json) { ... }
}
// When XML is actually needed, THEN refactor to interface + multiple implementations
```

<br>

---

## In LLD Interviews

- **Do mention extensibility** — "I'd use an interface here so we can add more types later"
- **Don't implement every extension** — build the core, describe the extension point
- **The interviewer wants to see you can DESIGN for extension, not IMPLEMENT everything**

<br>

---

## Key Takeaways

1. **Build what's needed now** — not what might be needed
2. **Design for extension** (interfaces), implement for today (concrete classes)
3. **Speculative code = maintenance burden with zero value**
4. **In interviews: mention extension points, implement core only**
