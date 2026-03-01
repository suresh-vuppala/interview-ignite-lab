## Functional Requirements:

> WHAT the System DO
**Restaurant Analogy:**
These are the core actions of the restaurant.

> - Show the menu
> - Take customer orders
> - Cook food
> - Serve food
> - Process payments
> - Provide a bill
> - Handle delivery orders
> - Handle reservation requests

These are direct actions — without them, the restaurant cannot fulfill its purpose.

In software, these are

> - login
> - search
> - upload
> - delete
> - checkout 
<br>
---
## Non-Functional Requirements:

>  HOW the System BEHAVES

These are not actions.
They are the qualities of your restaurant.

What customers remember is usually non-functional:

😋 “Food came fast”
😍 “Staff was polite”
🙂 “Place was clean”
👀 “Ambience was nice”
🧊 “AC worked well”

These determine the experience, not the function.

> - Food must arrive within 10 minutes (Low Latency)
> - Restaurant must be open 24/7 (High Availability)
> - Waiter must respond within 2 minutes (Responsiveness)
> - Kitchen must be clean and safe (Security)
> - Flavor must be consistent across branches (Reliability)
> - Restaurant must handle rush hours (Scalability)
> - Guests should find it easy to navigate the menu (Usability)

These qualities make your restaurant good or bad, not functional or non-functional.

<br>
### FAILURE:
**If a functional requirement fails:**

> The waiter cannot take orders.
> → The restaurant cannot function.
<br>
**If a non-functional requirement fails:**

> Food takes 40 minutes instead of 10 minutes.
> → Restaurant still functions, but customers hate it.

