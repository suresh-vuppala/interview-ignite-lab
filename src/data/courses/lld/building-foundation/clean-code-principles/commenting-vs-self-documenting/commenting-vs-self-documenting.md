# Commenting vs Self-documenting Code

> "A comment is a failure to express yourself in code." — Robert C. Martin

<br>

---

## Bad Comments (Remove These)

```java
// ❌ Obvious — adds no value
i++; // Increment i

// ❌ Paraphrasing the code
// Check if user is active
if (user.isActive()) { ... }

// ❌ Commented-out code — use version control!
// double tax = calculateTax(amount);
// if (tax > 100) { applyDiscount(); }
```

## Good Comments (Keep These)

```java
// ✅ WHY — explains business rule, not what
// Customers in trial period get full access for 14 days
// per Product decision PRD-2024-Q3
if (daysSinceSignup <= 14) grantFullAccess(user);

// ✅ WARNING — non-obvious consequence
// This regex is O(2^N) for pathological inputs — don't remove the length check!
if (input.length() < 1000 && input.matches(COMPLEX_PATTERN)) { ... }

// ✅ TODO with context
// TODO(suresh): Replace with Redis cache after Q2 migration — JIRA-1234

// ✅ Javadoc for public APIs
/**
 * Calculates compound interest over the given period.
 * @param principal Initial amount (must be positive)
 * @param rate Annual rate as decimal (e.g., 0.05 for 5%)
 * @param years Number of years (must be positive)
 * @return Total amount including principal and interest
 */
public double compoundInterest(double principal, double rate, int years) { ... }
```

<br>

---

## Self-Documenting Code

```java
// ❌ Needs comment to explain
if (age >= 18 && score > 700 && !blacklisted) {
    // eligible for premium account
}

// ✅ Code explains itself
if (isEligibleForPremiumAccount(applicant)) {
    openPremiumAccount(applicant);
}

private boolean isEligibleForPremiumAccount(Applicant a) {
    return a.getAge() >= MINIMUM_AGE
        && a.getCreditScore() > PREMIUM_THRESHOLD
        && !a.isBlacklisted();
}
```

<br>

---

## Key Takeaways

1. **Comment the WHY, not the WHAT**
2. **If you need a comment, consider renaming/extracting first**
3. **Delete commented-out code** — it's in git history
4. **Javadoc for public APIs** is valuable
5. **Self-documenting code > comments** in almost every case
