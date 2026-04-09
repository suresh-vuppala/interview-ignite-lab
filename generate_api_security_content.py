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
    content = f"""## Interview Focus

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
| `API6:2023 Unrestricted Access to Sensitive Business Flows` | Insufficient protection of critical workflows | Business logic abuse |
| `API7:2023 Server Side Request Forgery` | Improper validation of user-supplied URLs | Internal system access |
| `API8:2023 Security Misconfiguration` | Improper security settings | Various security vulnerabilities |
| `API9:2023 Improper Inventory Management` | Poor API lifecycle management | Exposure of deprecated/debug APIs |
| `API10:2023 Unsafe Consumption of APIs` | Trusting third-party APIs without validation | Supply chain attacks |

### Injection Attacks
> **Critical:** Always validate and sanitize input data to prevent injection attacks.

```
SQL Injection:
- Input: {"username": "admin'; DROP TABLE users; --"}
- Prevention: Parameterized queries, input validation

NoSQL Injection:
- Input: {"username": {"$ne": null}, "password": {"$ne": null}}
- Prevention: Input sanitization, query parameterization

Command Injection:
- Input: {"file": "data.txt; rm -rf /"}
- Prevention: Input validation, avoid system calls
```

---

## Authentication Mechanisms

### Token-Based Authentication
> **Best Practice:** Use stateless tokens for scalable authentication in distributed systems.

```
JWT (JSON Web Tokens):
Header: {"alg": "HS256", "typ": "JWT"}
Payload: {"sub": "user123", "exp": 1640995200, "iat": 1640908800}
Signature: HMACSHA256(base64UrlEncode(header) + "." + base64UrlEncode(payload), secret)

Benefits:
- Stateless and scalable
- Self-contained with claims
- Cross-domain support

Security Considerations:
- Use strong signing algorithms (RS256 > HS256)
- Implement proper token expiration
- Store securely (httpOnly cookies for web)
- Validate all claims on each request
```

### OAuth 2.0 and OpenID Connect
> **Enterprise Standard:** OAuth 2.0 for authorization, OpenID Connect for authentication.

```
Authorization Code Flow:
1. Client redirects user to authorization server
2. User authenticates and grants permissions
3. Authorization server returns authorization code
4. Client exchanges code for access token
5. Client uses access token to access protected resources

Security Best Practices:
- Use PKCE (Proof Key for Code Exchange) for public clients
- Implement proper redirect URI validation
- Use short-lived access tokens with refresh tokens
- Validate token signatures and claims
```

---

## Authorization Patterns

### Role-Based Access Control (RBAC)
> **Common Pattern:** Assign permissions to roles, then assign roles to users.

```
Example RBAC Structure:
Roles:
- admin: [read, write, delete, manage_users]
- editor: [read, write]
- viewer: [read]

Users:
- alice: [admin]
- bob: [editor]
- charlie: [viewer]

API Authorization Check:
if user.hasRole('admin') or user.hasPermission('write'):
    allow_operation()
else:
    deny_access()
```

### Attribute-Based Access Control (ABAC)
> **Advanced Pattern:** Fine-grained access control based on attributes and policies.

```
ABAC Policy Example:
Allow if:
- Subject.department == "Finance"
- Resource.type == "financial_report"
- Action == "read"
- Environment.time >= "09:00" AND Environment.time <= "17:00"
- Environment.location == "office_network"

Benefits:
- Fine-grained control
- Dynamic policies
- Context-aware decisions
```

---

## Secure Communication

### TLS/SSL Implementation
> **Mandatory:** All API communications must use TLS 1.2 or higher.

```
TLS Configuration Best Practices:
- Use TLS 1.2 or 1.3 (disable older versions)
- Implement proper certificate validation
- Use strong cipher suites
- Enable HTTP Strict Transport Security (HSTS)
- Implement certificate pinning for mobile apps

Example HSTS Header:
Strict-Transport-Security: max-age=31536000; includeSubDomains; preload
```

### Certificate Management
> **Critical:** Proper certificate lifecycle management prevents security incidents.

```
Certificate Best Practices:
- Use certificates from trusted CAs
- Implement automated certificate renewal
- Monitor certificate expiration
- Use wildcard certificates judiciously
- Implement certificate transparency monitoring

Certificate Pinning (Mobile):
- Pin to specific certificates or public keys
- Implement backup pins for rotation
- Handle pinning failures gracefully
```

---

## Input Validation and Output Encoding

### Input Validation Strategies
> **Defense:** Validate all input at API boundaries to prevent injection attacks.

```
Validation Layers:
1. Schema Validation:
   - JSON Schema validation
   - Required field checks
   - Data type validation

2. Business Logic Validation:
   - Range checks (age: 0-150)
   - Format validation (email, phone)
   - Cross-field validation

3. Security Validation:
   - SQL injection patterns
   - XSS payload detection
   - Path traversal attempts

Example Validation:
{
  "username": {
    "type": "string",
    "pattern": "^[a-zA-Z0-9_]{3,20}$",
    "required": true
  },
  "email": {
    "type": "string",
    "format": "email",
    "required": true
  }
}
```

### Output Encoding
> **Prevention:** Encode output data to prevent XSS and data injection attacks.

```
Encoding Strategies:
- HTML encoding for web display
- JSON encoding for API responses
- URL encoding for query parameters
- Base64 encoding for binary data

Example Output Encoding:
Input: <script>alert('xss')</script>
HTML Encoded: &lt;script&gt;alert(&#x27;xss&#x27;)&lt;/script&gt;
JSON Encoded: "<script>alert('xss')</script>"
```

---

## Rate Limiting and DDoS Protection

### Rate Limiting Strategies
> **Protection:** Implement rate limiting to prevent abuse and ensure fair usage.

```
Rate Limiting Algorithms:
1. Token Bucket:
   - Tokens added at fixed rate
   - Requests consume tokens
   - Allows burst traffic

2. Fixed Window:
   - Fixed time windows (e.g., per minute)
   - Simple but can allow bursts at window boundaries

3. Sliding Window:
   - More accurate than fixed window
   - Higher memory usage

4. Leaky Bucket:
   - Smooth request rate
   - Good for protecting downstream services

Implementation Example:
Rate-Limit-Limit: 1000
Rate-Limit-Remaining: 999
Rate-Limit-Reset: 1640995200
```

### DDoS Protection
> **Layered Defense:** Implement multiple layers of DDoS protection.

```
Protection Layers:
1. Network Layer (L3/L4):
   - Firewall rules
   - Rate limiting by IP
   - Geo-blocking

2. Application Layer (L7):
   - Request pattern analysis
   - CAPTCHA challenges
   - Behavioral analysis

3. CDN/WAF Protection:
   - Cloudflare, AWS WAF
   - Bot detection
   - Traffic filtering

Monitoring Metrics:
- Request rate per IP
- Error rate patterns
- Response time degradation
- Resource utilization
```

---

## API Security Testing

### Security Testing Approaches
> **Continuous:** Integrate security testing into CI/CD pipelines.

```
Testing Types:
1. Static Analysis (SAST):
   - Code vulnerability scanning
   - Dependency vulnerability checks
   - Configuration analysis

2. Dynamic Analysis (DAST):
   - Runtime vulnerability testing
   - Penetration testing
   - Fuzzing

3. Interactive Analysis (IAST):
   - Real-time vulnerability detection
   - Code coverage analysis

Tools:
- OWASP ZAP for dynamic testing
- SonarQube for static analysis
- Burp Suite for manual testing
- Postman for API testing
```

### Penetration Testing
> **Validation:** Regular penetration testing validates security controls.

```
Penetration Testing Checklist:
□ Authentication bypass attempts
□ Authorization escalation tests
□ Input validation testing
□ Session management testing
□ Error handling analysis
□ Business logic testing
□ Infrastructure testing

Common Test Cases:
- SQL injection attempts
- XSS payload injection
- CSRF token validation
- Rate limiting bypass
- Authentication brute force
- Privilege escalation
```

---

## Compliance and Governance

### Regulatory Compliance
> **Requirements:** Many industries have specific API security requirements.

| Regulation | Key Requirements | API Impact |
|------------|------------------|------------|
| `GDPR` | Data protection, consent, right to deletion | Data encryption, audit logs, consent APIs |
| `HIPAA` | Healthcare data protection | Encryption, access controls, audit trails |
| `PCI-DSS` | Payment card data security | Tokenization, encryption, network segmentation |
| `SOX` | Financial reporting controls | Data integrity, access controls, audit logs |

### Security Governance
> **Framework:** Establish security governance for API lifecycle management.

```
Governance Framework:
1. Security Policies:
   - API security standards
   - Authentication requirements
   - Data classification policies

2. Risk Assessment:
   - Threat modeling
   - Vulnerability assessments
   - Risk scoring

3. Incident Response:
   - Security incident procedures
   - Breach notification processes
   - Recovery procedures

4. Compliance Monitoring:
   - Regular security audits
   - Compliance reporting
   - Continuous monitoring
```

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

5. Compliance:
   - PCI-DSS compliance
   - Regulatory reporting
   - Data residency requirements
```

### Example 2: API Gateway Security

**Question**: "How would you implement security in an API gateway for microservices?"

> **Important:** API gateways are the first line of defense and must implement comprehensive security.

**Solution**:
```
Gateway Security Features:
1. Authentication:
   - JWT token validation
   - OAuth 2.0 integration
   - API key management

2. Authorization:
   - Route-level permissions
   - Rate limiting per client
   - IP whitelisting/blacklisting

3. Security Policies:
   - Input validation
   - Output filtering
   - Request/response transformation

4. Threat Protection:
   - DDoS protection
   - Bot detection
   - Anomaly detection

5. Monitoring:
   - Security event logging
   - Metrics collection
   - Alert generation

Implementation:
- Use Kong, AWS API Gateway, or Istio
- Implement circuit breakers
- Enable distributed tracing
- Configure health checks
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

4. Data Protection:
   - Tenant-specific encryption keys
   - Data residency compliance
   - Backup isolation

5. Monitoring:
   - Tenant-specific metrics
   - Security event correlation
   - Compliance reporting per tenant

Implementation Considerations:
- Use tenant ID as partition key
- Implement tenant context propagation
- Validate tenant access on every request
- Use separate encryption keys per tenant
```
[[end_hide]]

### Problem 2: API Security for IoT Devices
**Scenario**: Secure APIs for millions of IoT devices with limited computational resources.

[[start_hide]]
**Solution**:
```
IoT API Security Strategy:
1. Device Authentication:
   - Pre-shared keys (PSK)
   - Certificate-based authentication
   - Device identity attestation

2. Lightweight Protocols:
   - CoAP with DTLS
   - MQTT with TLS
   - Compressed JWT tokens

3. Key Management:
   - Device provisioning service
   - Key rotation mechanisms
   - Secure key storage (TPM/HSM)

4. Communication Security:
   - End-to-end encryption
   - Message integrity checks
   - Replay attack prevention

5. Scalability Considerations:
   - Connection pooling
   - Message batching
   - Edge computing for processing

Security Challenges:
- Limited computational power
- Intermittent connectivity
- Physical device access
- Firmware update security
- Battery life constraints
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
| API Security Testing | https://owasp.org/www-project-web-security-testing-guide/ | OWASP testing methodology |