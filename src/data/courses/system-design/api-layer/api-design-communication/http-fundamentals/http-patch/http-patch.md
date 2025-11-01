The **PATCH** method is used to **partially update** an existing resource on the server.  
Unlike `PUT`, which replaces the entire resource, `PATCH` only modifies the **specific fields** provided in the request body.

This makes it ideal for updating a subset of data efficiently, without sending or overwriting the entire resource representation.

---

## Understanding the PATCH Method

When a client sends a `PATCH` request, it includes only the fields that need to be updated.  
The server then applies these changes to the existing resource, leaving all other fields untouched.

> Think of `PATCH` as “update just these fields and leave the rest as they are.”

### Key Characteristics

| Property | Description |
|-----------|-------------|
| **Not Safe** | It modifies existing data on the server. |
| **Idempotent (usually)** | It can be idempotent if implemented correctly, but this depends on how the server processes the patch. |
| **Efficient** | Only sends modified data — ideal for bandwidth-sensitive operations. |

Because it’s lightweight, `PATCH` is often preferred for **incremental updates** in modern REST APIs.

---

## Common Use Cases

Here are typical scenarios where the `PATCH` method is used:

**1. Updating a user’s email address**  
> PATCH /api/users/42  
> Body:  
> 
> {
>   "email": "new.email@example.com"
> }
> 
Only the `email` field of user ID `42` is updated; all other user details remain the same.

---

**2. Modifying a product’s price**  
> PATCH /api/products/10  
> Body:  
> 
> {
>   "price": 89.99
> }
> 
Updates only the product price — other product fields like name or brand stay unchanged.

---

**3. Updating order status**  
> PATCH /api/orders/12345  
> Body:  
> 
> {
>   "status": "shipped"
> }
> 
Changes only the order’s status, leaving other details intact.

---

## ✅ Best Practices for Using PATCH

> The PATCH method should be used for **partial resource updates** to optimize network and data efficiency.

🔹 **Use PATCH for partial updates** — when only a few attributes change.  
🔹 **Include only the fields that need to be updated** in the request body.  
🔹 **Return clear and consistent responses**, such as the updated resource or a success message.  
🔹 **Support idempotency**, ensuring the same PATCH request produces the same final result.  
🔹 **Validate all input fields** before applying updates to prevent inconsistent data states.  
🔹 **Use proper HTTP status codes**:  
- `200 OK` — if the updated resource is returned.  
- `204 No Content` — if the update succeeded with no response body.  
- `400 Bad Request` — for invalid input.  

---

## ❌ Common Mistakes to Avoid

**1. Using PATCH for full replacements**  
> PATCH should modify only parts of the resource. For full updates, use `PUT`.

**2. Sending unchanged fields**  
> Sending all fields defeats the purpose of PATCH and may lead to accidental overwrites.

**3. Making PATCH non-idempotent**  
> Ensure repeated identical PATCH requests lead to the same final result.

**4. Not validating input data**  
> Partial updates can easily introduce inconsistent states if validation is skipped.

---

## 💡 Example in Action

**Request:**  
> PATCH /api/users/7  
> Body:  
> 
> {
>   "role": "editor",
>   "isActive": true
> }
> 

**Response:**  
> Status: 200 OK  
> Body:  
> 
> {
>   "id": 7,
>   "name": "Robert King",
>   "email": "robert.king@example.com",
>   "role": "editor",
>   "isActive": true,
>   "updatedAt": "2025-10-30T18:05:00Z"
> }
> 

This request updates only the `role` and `isActive` fields for the user with ID `7`.  
All other fields, such as `name` and `email`, remain unchanged.