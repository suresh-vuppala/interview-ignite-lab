// ATM System — State + Chain of Responsibility
import java.util.*;

// ========== ACCOUNT ==========
class Account {
    private String accountId;
    private double balance;
    private String pin;
    private double dailyWithdrawn = 0;
    private static final double DAILY_LIMIT = 5000;
    
    public Account(String id, double balance, String pin) {
        this.accountId = id; this.balance = balance; this.pin = pin;
    }
    
    public boolean verifyPin(String inputPin) { return pin.equals(inputPin); }
    public double getBalance() { return balance; }
    
    public boolean withdraw(double amount) {
        if (amount > balance) return false;
        if (dailyWithdrawn + amount > DAILY_LIMIT) return false;
        balance -= amount;
        dailyWithdrawn += amount;
        return true;
    }
    
    public void deposit(double amount) { balance += amount; }
    public void changePin(String newPin) { this.pin = newPin; }
}

// ========== CASH DISPENSER (Chain of Responsibility) ==========
abstract class CashHandler {
    protected CashHandler next;
    protected int denomination;
    protected int count; // Bills available
    
    public CashHandler(int denomination, int count) {
        this.denomination = denomination; this.count = count;
    }
    public CashHandler setNext(CashHandler handler) { this.next = handler; return handler; }
    
    public Map<Integer, Integer> dispense(int amount) {
        Map<Integer, Integer> result = new LinkedHashMap<>();
        int bills = Math.min(amount / denomination, count);
        if (bills > 0) {
            result.put(denomination, bills);
            count -= bills;
            amount -= bills * denomination;
        }
        if (amount > 0 && next != null) result.putAll(next.dispense(amount));
        else if (amount > 0) throw new RuntimeException("Cannot dispense exact amount");
        return result;
    }
}

class HundredHandler extends CashHandler { public HundredHandler(int count) { super(100, count); } }
class FiftyHandler extends CashHandler { public FiftyHandler(int count) { super(50, count); } }
class TwentyHandler extends CashHandler { public TwentyHandler(int count) { super(20, count); } }
class TenHandler extends CashHandler { public TenHandler(int count) { super(10, count); } }

// ========== ATM STATE ==========
interface ATMState {
    void insertCard(ATM atm);
    void enterPin(ATM atm, String pin);
    void withdraw(ATM atm, double amount);
    void deposit(ATM atm, double amount);
    void checkBalance(ATM atm);
    void ejectCard(ATM atm);
}

class IdleState implements ATMState {
    public void insertCard(ATM atm) { System.out.println("Card inserted"); atm.setState(new CardInsertedState()); }
    public void enterPin(ATM a, String p) { System.out.println("Insert card first"); }
    public void withdraw(ATM a, double amt) { System.out.println("Insert card first"); }
    public void deposit(ATM a, double amt) { System.out.println("Insert card first"); }
    public void checkBalance(ATM a) { System.out.println("Insert card first"); }
    public void ejectCard(ATM a) { System.out.println("No card inserted"); }
}

class CardInsertedState implements ATMState {
    private int attempts = 0;
    public void insertCard(ATM a) { System.out.println("Card already inserted"); }
    public void enterPin(ATM atm, String pin) {
        if (atm.getAccount().verifyPin(pin)) {
            System.out.println("PIN verified"); atm.setState(new AuthenticatedState());
        } else {
            attempts++;
            if (attempts >= 3) { System.out.println("Card blocked!"); atm.setState(new IdleState()); }
            else System.out.println("Wrong PIN. " + (3-attempts) + " attempts left");
        }
    }
    public void withdraw(ATM a, double amt) { System.out.println("Enter PIN first"); }
    public void deposit(ATM a, double amt) { System.out.println("Enter PIN first"); }
    public void checkBalance(ATM a) { System.out.println("Enter PIN first"); }
    public void ejectCard(ATM a) { System.out.println("Card ejected"); a.setState(new IdleState()); }
}

class AuthenticatedState implements ATMState {
    public void insertCard(ATM a) { System.out.println("Already authenticated"); }
    public void enterPin(ATM a, String p) { System.out.println("Already authenticated"); }
    public void withdraw(ATM atm, double amount) {
        if (atm.getAccount().withdraw(amount)) {
            Map<Integer, Integer> bills = atm.getDispenser().dispense((int) amount);
            System.out.println("Dispensed: " + bills);
        } else System.out.println("Insufficient funds or daily limit reached");
    }
    public void deposit(ATM atm, double amount) {
        atm.getAccount().deposit(amount);
        System.out.println("Deposited $" + amount + ". New balance: $" + atm.getAccount().getBalance());
    }
    public void checkBalance(ATM atm) {
        System.out.println("Balance: $" + atm.getAccount().getBalance());
    }
    public void ejectCard(ATM a) { System.out.println("Card ejected. Thank you!"); a.setState(new IdleState()); }
}

// ========== ATM ==========
class ATM {
    private ATMState state;
    private Account account;
    private CashHandler dispenser;
    
    public ATM() {
        this.state = new IdleState();
        HundredHandler h100 = new HundredHandler(100);
        FiftyHandler h50 = new FiftyHandler(100);
        TwentyHandler h20 = new TwentyHandler(100);
        TenHandler h10 = new TenHandler(100);
        h100.setNext(h50).setNext(h20).setNext(h10);
        this.dispenser = h100;
    }
    
    public void setState(ATMState s) { this.state = s; }
    public void setAccount(Account a) { this.account = a; }
    public Account getAccount() { return account; }
    public CashHandler getDispenser() { return dispenser; }
    
    public void insertCard() { state.insertCard(this); }
    public void enterPin(String pin) { state.enterPin(this, pin); }
    public void withdraw(double amount) { state.withdraw(this, amount); }
    public void deposit(double amount) { state.deposit(this, amount); }
    public void checkBalance() { state.checkBalance(this); }
    public void ejectCard() { state.ejectCard(this); }
}
