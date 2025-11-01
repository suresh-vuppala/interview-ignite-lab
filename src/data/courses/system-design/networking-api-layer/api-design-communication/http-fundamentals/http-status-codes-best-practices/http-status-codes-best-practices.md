
**HTTP Status Codes** are standardized numeric responses sent by the server to indicate the result of a client’s request.  
They help clients understand whether a request **succeeded**, **failed**, or requires **further action**.

Understanding and using these codes correctly is essential for building clear, predictable, and professional APIs.

---

## Understanding HTTP Status Codes

Each HTTP response includes a **status line** that contains a **three-digit code** and a short **reason phrase** (e.g., `200 OK`, `404 Not Found`).  
These codes are grouped into **five categories** based on their first digit.

| **Category** | **Range** | **Meaning** |
|---------------|-----------|-------------|
| **1xx** | 100–199 | Informational — request received, continuing process. |
| **2xx** | 200–299 | Success — the request was successfully received and processed. |
| **3xx** | 300–399 | Redirection — further action is needed to complete the request. |
| **4xx** | 400–499 | Client error — the request contains bad syntax or cannot be fulfilled. |
| **5xx** | 500–599 | Server error — the server failed to fulfill a valid request. |

---

## Commonly Used HTTP Status Codes

### 🟢 2xx — Success

| **Code** | **Meaning** | **Description** |
|-----------|--------------|-----------------|
| **200 OK** | Success | Standard response for successful `GET`, `PUT`, or `PATCH` requests. |
| **201 Created** | Resource Created | Used after `POST` when a new resource is successfully created. |
| **202 Accepted** | Request Accepted | The request has been received and will be processed asynchronously. |
| **204 No Content** | No Response Body | Used after a successful `DELETE` or update when no content is returned. |

---

### 🟡 3xx — Redirection

| **Code** | **Meaning** | **Description** |
|-----------|--------------|-----------------|
| **301 Moved Permanently** | Permanent Redirect | The resource has been permanently moved to a new URL. |
| **302 Found** | Temporary Redirect | Resource temporarily resides under a different URI. |
| **304 Not Modified** | Cached Resource | Indicates that the resource has not changed since the last request. |

---

### 🔴 4xx — Client Errors

| **Code** | **Meaning** | **Description** |
|-----------|--------------|-----------------|
| **400 Bad Request** | Invalid Request | The server cannot process the request due to client error (e.g., malformed JSON). |
| **401 Unauthorized** | Authentication Required | The client must authenticate itself to get the requested response. |
| **403 Forbidden** | Access Denied | The client is authenticated but not allowed to access the resource. |
| **404 Not Found** | Resource Missing | The requested resource does not exist on the server. |
| **405 Method Not Allowed** | Invalid HTTP Method | The method is not supported for the requested resource. |
| **409 Conflict** | Conflict Detected | The request could not be completed due to a conflict with the current state (e.g., duplicate data). |
| **422 Unprocessable Entity** | Validation Error | The request was well-formed but contains semantic errors. |
| **429 Too Many Requests** | Rate Limit Exceeded | The client has sent too many requests in a short time. |

---

### ⚫ 5xx — Server Errors

| **Code** | **Meaning** | **Description** |
|-----------|--------------|-----------------|
| **500 Internal Server Error** | Generic Server Failure | The server encountered an unexpected condition. |
| **501 Not Implemented** | Feature Unsupported | The server does not support the functionality required to fulfill the request. |
| **502 Bad Gateway** | Invalid Upstream Response | The server received an invalid response from an upstream server. |
| **503 Service Unavailable** | Temporarily Overloaded | The server is temporarily unable to handle the request (maintenance, overload). |
| **504 Gateway Timeout** | Upstream Timeout | The upstream server failed to respond in time. |

---

## 💡 Examples in Action

### Example 1 — Successful Resource Creation
**Request:**
> POST /api/users

**Response:**
```json
{
  "id": 101,
  "name": "John Doe",
  "email": "john@example.com"
}
Status Code: 201 Created

Example 2 — Resource Not Found

Request:

GET /api/products/9999

Response:

{
  "error": "Product not found",
  "code": 404
}


Status Code: 404 Not Found

Example 3 — Validation Error

Request:

POST /api/orders

{
  "quantity": -3
}


Response:

{
  "error": "Quantity must be a positive number",
  "code": 422
}


Status Code: 422 Unprocessable Entity

⚙️ Best Practices for Using Status Codes

Clear and consistent use of status codes improves API usability and debugging efficiency.

✅ Do’s

Use the most specific status code that fits the situation.

Return 2xx codes only for successful operations.

Include a meaningful message or error object in response bodies.

Use 201 Created when a resource is newly created via POST.

Use 204 No Content for successful DELETE or PUT requests with no response data.

Log 4xx and 5xx responses for debugging and monitoring.

❌ Don’ts

Don’t return 200 OK for every response — it hides error semantics.

Don’t use custom codes outside the standard HTTP specification.

Don’t expose internal server details or stack traces in error messages.

Don’t misuse 500 — reserve it for unexpected server errors only.

🧩 Recommended Error Response Structure

Standardize your error responses to maintain consistency across APIs:

{
  "success": false,
  "status": 404,
  "error": {
    "code": "RESOURCE_NOT_FOUND",
    "message": "The requested user was not found",
    "details": {
      "userId": 789
    }
  }
}


This format ensures the client always knows how to parse and handle error responses gracefully.