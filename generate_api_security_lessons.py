import os
import json

# Define the API Security lessons
api_security_lessons = [
    {
        "slug": "api-security-best-practices",
        "title": "API Security Best Practices",
        "interview_question": "How would you secure APIs in a microservices architecture handling sensitive financial data?"
    },
    {
        "slug": "cors-same-origin-policy", 
        "title": "CORS and Same-Origin Policy",
        "interview_question": "Explain how CORS works and how you'd configure it for a multi-domain application."
    },
    {
        "slug": "api-key-management",
        "title": "API Key Management and Rotation", 
        "interview_question": "Design a system for managing and rotating API keys for thousands of third-party integrations."
    },
    {
        "slug": "encryption-rest-transit",
        "title": "Encryption at Rest and in Transit",
        "interview_question": "How would you implement end-to-end encryption for API communications in a distributed system?"
    }
]

def create_lesson_content(lesson):
    return f"""## Interview Focus

**Critical Interview Questions:**
- "{lesson['interview_question']}"
- "What are the OWASP API Security Top 10 risks?"
- "How do you prevent API injection attacks?"
- "Design authentication flow for a multi-tenant SaaS platform"

---

## Why {lesson['title']} Matters

### In Technical Interviews
> **Key Point:** API security demonstrates your understanding of protecting sensitive data and preventing common attack vectors in distributed systems.

- **Shows security awareness** and defensive programming mindset
- **Demonstrates knowledge** of authentication and authorization patterns
- **Tests understanding** of encryption, certificates, and secure communication
- **Foundation for enterprise systems** - critical for production readiness

### In Real Systems
> **Important:** Poor API security can lead to data breaches, financial losses, and regulatory compliance violations.

- **Data protection** - prevent unauthorized access to sensitive information
- **Compliance requirements** - meet GDPR, HIPAA, PCI-DSS standards
- **Trust and reputation** - maintain customer confidence
- **Business continuity** - prevent security incidents and downtime

---

## Core Security Principles

> **Critical:** Security must be built into APIs from the ground up, not added as an afterthought.

### Authentication vs Authorization
```
Authentication: "Who are you?"
- Verifies identity of the user/system
- Methods: passwords, tokens, certificates, biometrics

Authorization: "What can you do?"
- Determines permissions and access levels
- Methods: RBAC, ABAC, ACLs, scopes
```

### Defense in Depth
> **Strategy:** Implement multiple layers of security controls to protect against various attack vectors.

- **Network security** - firewalls, VPNs, network segmentation
- **Transport security** - TLS/SSL encryption
- **Application security** - input validation, output encoding
- **Data security** - encryption at rest, field-level encryption

---

## Common API Security Threats

### OWASP API Security Top 10
> **Must Know:** These are the most critical API security risks according to OWASP.

| Risk | Description | Impact |
|------|-------------|---------|
| `API1:2023 Broken Object Level Authorization` | Insufficient access controls on object operations | Data exposure, unauthorized modifications |
| `API2:2023 Broken Authentication` | Weak authentication mechanisms | Account takeover, data breaches |
| `API3:2023 Broken Object Property Level Authorization` | Missing property-level access controls | Sensitive data exposure |
| `API4:2023 Unrestricted Resource Consumption` | Lack of rate limiting and resource controls | DoS attacks, service degradation |
| `API5:2023 Broken Function Level Authorization` | Missing function-level access controls | Privilege escalation |

---

## Interview Examples

### Example 1: Securing Financial APIs

**Question**: "Design security for a banking API that handles money transfers."

> **Key Insight:** Financial APIs require the highest level of security with multiple validation layers.

**Solution**:
```
Security Architecture:
1. Multi-Factor Authentication:
   - Primary: Username/password
   - Secondary: SMS/TOTP
   - Tertiary: Device fingerprinting

2. Authorization Layers:
   - Account ownership validation
   - Transaction limits enforcement
   - Fraud detection integration

3. Encryption:
   - TLS 1.3 for transport
   - Field-level encryption for PII
   - HSM for key management

4. Monitoring:
   - Real-time fraud detection
   - Anomaly detection
   - Audit logging
```

---

## Practice Problems

### Problem 1: Multi-Tenant API Security
**Scenario**: Design security for a SaaS platform serving multiple tenants through a single API.

[[start_hide]]
**Solution**:
```
Multi-Tenant Security Design:
1. Tenant Isolation:
   - Tenant ID in JWT claims
   - Database-level isolation
   - Resource namespace isolation

2. Authentication:
   - Tenant-specific identity providers
   - Federated authentication support
   - Single sign-on (SSO) integration

3. Authorization:
   - Tenant-scoped permissions
   - Role inheritance models
   - Cross-tenant access controls
```
[[end_hide]]

---

## References

| Resource | URL | Description |
|----------|-----|-------------|
| OWASP API Security Top 10 | https://owasp.org/www-project-api-security/ | Comprehensive API security risks |
| JWT Best Practices | https://tools.ietf.org/html/rfc8725 | JWT security considerations |
| OAuth 2.0 Security | https://tools.ietf.org/html/rfc6819 | OAuth security best practices |
| TLS Configuration | https://wiki.mozilla.org/Security/Server_Side_TLS | Mozilla TLS configuration guide |
| API Security Testing | https://owasp.org/www-project-web-security-testing-guide/ | OWASP testing methodology |"""

def create_lesson_json(lesson):
    return {
        "title": lesson['title'],
        "isPosted": True,
        "isPremium": False
    }

# Create the api-security directory
base_path = "src/data/courses/system-design/api-layer/api-security"
os.makedirs(base_path, exist_ok=True)

# Generate content for each lesson
for lesson in api_security_lessons:
    # Create lesson directory
    lesson_dir = os.path.join(base_path, lesson['slug'])
    os.makedirs(lesson_dir, exist_ok=True)
    
    # Create markdown file
    md_file = os.path.join(lesson_dir, f"{lesson['slug']}.md")
    with open(md_file, 'w', encoding='utf-8') as f:
        f.write(create_lesson_content(lesson))
    
    # Create JSON file
    json_file = os.path.join(lesson_dir, f"{lesson['slug']}.json")
    with open(json_file, 'w', encoding='utf-8') as f:
        json.dump(create_lesson_json(lesson), f, indent=2)
    
    print(f"Created lesson: {lesson['title']}")

print(f"\nSuccessfully generated {len(api_security_lessons)} API Security lessons!")
print("All lessons are marked as posted (isPosted: true)")