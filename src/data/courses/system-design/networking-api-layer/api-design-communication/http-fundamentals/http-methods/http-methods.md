
**HTTP methods** (also known as **HTTP verbs**) define the type of **action** that should be performed on a **resource**.  
In simple terms, they tell the server **what to do** with the data being **requested** or **sent**.

Understanding these methods is essential for designing clean, predictable, and efficient APIs.

---

## Commonly Used HTTP Methods

Below are the most widely used HTTP methods and their purposes:

| **Method** | **Purpose** | **Description** |
|-------------|--------------|-----------------|
| `GET` [->](https://openai.com) | Retrieve data | Requests data from the server without modifying it. |
| `POST` | Create new data | Sends new data to the server to create a resource. |
| `PUT` | Update or replace data | Replaces an existing resource entirely with new data. |
| `PATCH` | Partially update data | Updates specific fields of an existing resource. |
| `DELETE` | Remove data | Deletes a specified resource from the server. |
| `OPTIONS` | Retrieve allowed methods | Returns the HTTP methods supported by the resource. |
| `HEAD`[->](https://openai.com) | Retrieve [headers](https://openai.com) only | Same as `GET` but returns only headers, not the body. |

---

## Summary

Each HTTP method serves a unique purpose in RESTful API design.  
Using them correctly ensures **clarity**, **predictability**, and **efficiency** in communication between client and server.
