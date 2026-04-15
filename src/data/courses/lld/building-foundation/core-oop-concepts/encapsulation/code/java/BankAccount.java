// Encapsulation Example — Bank Account with invariant protection
class BankAccount {
    private String accountId;
    private String ownerName;
    private double balance;
    
    public BankAccount(String accountId, String ownerName, double initialDeposit) {
        this.accountId = accountId;
        this.ownerName = ownerName;
        if (initialDeposit < 0) throw new IllegalArgumentException("Initial deposit can't be negative");
        this.balance = initialDeposit;
    }
    
    // Read-only access
    public String getAccountId() { return accountId; }
    public String getOwnerName() { return ownerName; }
    public double getBalance() { return balance; }
    
    // Behavior with validation — NOT raw setters
    public void deposit(double amount) {
        if (amount <= 0) throw new IllegalArgumentException("Deposit must be positive");
        this.balance += amount;
    }
    
    public void withdraw(double amount) {
        if (amount <= 0) throw new IllegalArgumentException("Withdrawal must be positive");
        if (amount > balance) throw new IllegalStateException("Insufficient funds");
        this.balance -= amount;
    }
    
    public void transfer(BankAccount target, double amount) {
        this.withdraw(amount);   // Validates internally
        target.deposit(amount);  // Validates internally
    }
}
