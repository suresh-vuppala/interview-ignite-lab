# Command Pattern

> **Intent:** Encapsulate a request as an object, thereby letting you parameterize clients with different requests, queue or log requests, and support undoable operations.

<br>

---

## When to Use

- **Undo/Redo** functionality
- **Transaction logging** — replay commands for recovery
- **Task queuing** — schedule commands for later execution
- **Macro recording** — group commands into a sequence
- **Decouple** invoker from the object that performs the action

<br>

---

## Structure

```
Invoker → Command (interface)    → Receiver
           ├─ execute()
           └─ undo()
           
  ConcreteCommandA(receiver)
  ConcreteCommandB(receiver)
```

<br>

---

## Example: Text Editor with Undo

```java
interface Command {
    void execute();
    void undo();
}

class TextEditor {
    private StringBuilder text = new StringBuilder();
    
    public void insert(String s, int pos) { text.insert(pos, s); }
    public void delete(int pos, int length) { text.delete(pos, pos + length); }
    public String getText() { return text.toString(); }
}

class InsertCommand implements Command {
    private TextEditor editor;
    private String text;
    private int position;
    
    public InsertCommand(TextEditor editor, String text, int position) {
        this.editor = editor; this.text = text; this.position = position;
    }
    
    public void execute() { editor.insert(text, position); }
    public void undo() { editor.delete(position, text.length()); }
}

class DeleteCommand implements Command {
    private TextEditor editor;
    private String deletedText;
    private int position;
    private int length;
    
    public DeleteCommand(TextEditor editor, int position, int length) {
        this.editor = editor; this.position = position; this.length = length;
    }
    
    public void execute() {
        deletedText = editor.getText().substring(position, position + length);
        editor.delete(position, length);
    }
    public void undo() { editor.insert(deletedText, position); }
}

// Command Manager — handles undo/redo stack
class CommandManager {
    private Stack<Command> undoStack = new Stack<>();
    private Stack<Command> redoStack = new Stack<>();
    
    public void execute(Command cmd) {
        cmd.execute();
        undoStack.push(cmd);
        redoStack.clear(); // New action invalidates redo history
    }
    
    public void undo() {
        if (!undoStack.isEmpty()) {
            Command cmd = undoStack.pop();
            cmd.undo();
            redoStack.push(cmd);
        }
    }
    
    public void redo() {
        if (!redoStack.isEmpty()) {
            Command cmd = redoStack.pop();
            cmd.execute();
            undoStack.push(cmd);
        }
    }
}
```

<br>

---

## Key Takeaways

1. **Encapsulate actions as objects** — store, queue, undo, replay
2. **Undo/Redo** = push executed commands on stack, call `undo()` to reverse
3. **Decouples invoker from receiver** — button doesn't know what it triggers
4. **Used in:** text editors, transaction systems, game actions, task schedulers
