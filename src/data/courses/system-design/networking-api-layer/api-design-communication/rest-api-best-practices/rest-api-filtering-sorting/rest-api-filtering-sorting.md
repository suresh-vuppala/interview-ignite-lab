# REST API Best Practices — Filtering and Sorting

In modern REST APIs, **filtering** and **sorting** are essential features that help clients retrieve data efficiently and in a meaningful order.  
Instead of fetching all records and handling them client-side, APIs should allow controlled queries that return only the **relevant subset** of data.

---

## 🎯 Why Filtering and Sorting Matter

> Efficient filtering and sorting make APIs faster, more user-friendly, and scalable.

- Reduce **data load** and **network bandwidth**.  
- Improve **query performance** and **user experience**.  
- Enable **precise data retrieval** without client-side post-processing.  
- Promote a **RESTful, declarative style** for flexible data access.

---

## 🔍 Filtering in REST APIs

Filtering allows clients to narrow down results by specifying conditions in the query string.

### 🧠 Basic Syntax
Use query parameters to define filters:
> GET /api/users?role=admin&status=active

This retrieves only active users with the role `admin`.

### 💡 Common Filtering Examples

| **Use Case** | **Example** |
|---------------|-------------|
| Filter users by role | `/api/users?role=admin` |
| Filter products by category and availability | `/api/products?category=books&inStock=true` |
| Search by keyword | `/api/posts?search=python` |
| Date-based filtering | `/api/orders?fromDate=2024-01-01&toDate=2024-01-31` |

---

### 🧱 Best Practices for Filtering

> Keep filters **intuitive**, **consistent**, and **flexible**.

🔹 Use **clear, descriptive parameter names** (e.g., `status`, `type`, `createdAfter`).  
🔹 Support **multiple filters** — clients should be able to combine conditions.  
🔹 Use **boolean filters** for true/false fields (`isActive=true`).  
🔹 Allow **range queries** where relevant (e.g., `price[min]=100&price[max]=500`).  
🔹 Implement **partial matching** or **fuzzy search** where applicable (`name_like=john`).  
🔹 Validate filter parameters to prevent invalid or malicious queries.

---

### ❌ Common Mistakes to Avoid in Filtering

- Hardcoding limited filter combinations (reduces flexibility).  
- Returning unfiltered data when parameters are invalid — respond with `400 Bad Request`.  
- Not documenting available filters in API docs.  
- Using complex nested JSON for filters instead of simple query parameters.  

---

## 🔢 Sorting in REST APIs

Sorting determines the **order** in which results are returned.  
Clients can specify one or more fields to sort by — ascending or descending.

### 🧠 Basic Syntax
> GET /api/products?sort=price

Sorts products by price in ascending order by default.

---

### ⚙️ Sorting with Direction

Use prefixes or keywords to control sort direction:

| **Format** | **Meaning** |
|-------------|-------------|
| `/api/products?sort=price` | Sort ascending by price. |
| `/api/products?sort=-price` | Sort descending by price (using `-` prefix). |
| `/api/users?sort=name,-age` | Sort by name (A→Z), then by age (descending). |
| `/api/posts?sort=createdAt:desc` | Sort descending by creation date (alternative style). |

---

### 🧱 Best Practices for Sorting

🔹 Support **multiple sort fields** for flexible ordering.  
🔹 Default sorting should be **stable and predictable** (e.g., by `createdAt` or `id`).  
🔹 Validate sort fields to prevent invalid column references.  
🔹 Combine sorting with filtering and pagination for optimal API efficiency.  
🔹 Return **consistent ordering** for identical values (tie-breaker field).

---

### ❌ Common Mistakes to Avoid in Sorting

- Allowing arbitrary fields (can expose internal database structure).  
- Returning inconsistent results for unsorted queries.  
- Ignoring client-provided sort parameters.  
- Failing to document supported sort keys.  

---

## 🔗 Combining Filtering, Sorting, and Pagination

> These three techniques often work **together** to optimize large dataset queries.

**Example:**
> GET /api/products?category=electronics&price[min]=500&price[max]=2000&sort=-rating&page=2&limit=20

This query:
- Filters products in the `electronics` category  
- Limits results to prices between ₹500 and ₹2000  
- Sorts them by highest rating first  
- Returns the **second page** of results with **20 items per page**

---

## 💡 Example API Response

**Request:**
> GET /api/books?author=doe&sort=-publishedYear&page=1&limit=3

**Response:**
```json
{
  "page": 1,
  "limit": 3,
  "total": 25,
  "filters": {
    "author": "doe"
  },
  "sort": "-publishedYear",
  "data": [
    { "id": 9, "title": "Advanced REST APIs", "publishedYear": 2024 },
    { "id": 5, "title": "Mastering JSON", "publishedYear": 2023 },
    { "id": 3, "title": "Designing Modern APIs", "publishedYear": 2021 }
  ]
}

This response clearly communicates:

Applied filters (author=doe)

Sorting (publishedYear descending)

Pagination details (page, limit, total)

🧩 Implementation Tips

Use query builders or ORM filters (e.g., JPA, Sequelize, Django ORM) for secure and dynamic filtering.

Sanitize query parameters to prevent SQL injection.

Cache frequent queries to improve performance.

Provide metadata (like totalCount) to aid UI pagination.

Consider using OData-style query parameters ($filter, $orderby) for complex enterprise APIs.