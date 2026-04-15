// Composition over Inheritance — Character Abilities in a Game
interface Ability {
    void use();
    String getName();
}

class FireAttack implements Ability {
    public void use() { System.out.println("🔥 Fire attack!"); }
    public String getName() { return "Fire Attack"; }
}

class HealingSpell implements Ability {
    public void use() { System.out.println("💚 Healing!"); }
    public String getName() { return "Healing Spell"; }
}

class Shield implements Ability {
    public void use() { System.out.println("🛡️ Shield activated!"); }
    public String getName() { return "Shield"; }
}

class Stealth implements Ability {
    public void use() { System.out.println("👤 Invisible!"); }
    public String getName() { return "Stealth"; }
}

// Character uses COMPOSITION — mix any abilities
class GameCharacter {
    private String name;
    private List<Ability> abilities = new ArrayList<>();
    
    public GameCharacter(String name) { this.name = name; }
    
    public void addAbility(Ability ability) { abilities.add(ability); }
    public void removeAbility(Ability ability) { abilities.remove(ability); }
    
    public void useAbility(int index) { abilities.get(index).use(); }
    public void useAll() { abilities.forEach(Ability::use); }
}

// Create diverse characters WITHOUT subclasses!
// Mage: fire + healing
// Rogue: stealth + fire
// Paladin: healing + shield + fire
// No class explosion — just compose!
