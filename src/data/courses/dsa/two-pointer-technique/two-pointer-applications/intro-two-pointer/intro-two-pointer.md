## Overview

Two pointers is a common interview technique often used to solve certain problems involving an iterable data structure, such as an array. As the name suggests, this technique uses two (or more) pointers that traverse through the structure. It does not have to be physically using two pointers. As long as the other pointer can be easily calculated from existing values, such as the index of the other pointer, it counts as a two pointer question.

## How Two Pointer Technique Works

Since "two pointers" is kind of a broad topic, there is no singular way to implement it. Depending on the questions you encounter, you need to implement the answer differently. Generally speaking, a two pointer algorithm has these characteristics:

1. **Two moving pointers** - regardless of directions, moving dependently or independently
2. **A function that utilizes the entries** - referenced by the two pointers, which relates to the answer in a way
3. **An easy way of deciding which pointer to move** - clear logic for pointer movement
4. **A way to process the array** - when the pointers are moved

## Classifications

Two pointer problems can be classified in different ways:

- **Same Directions** - Both pointers move in the same direction
- **Opposite Directions** - Pointers move towards each other

## Why Use Two Pointers?

Two pointers are helpful because it often offers a more efficient solution than the naive solution. From the examples above, if we use the naive solution and use two loops to iterate through the array, the time complexity would typically be **O(n²)**, which is generally insufficient.

If we use two pointers for this type of problem, we are often only passing through the array once with the two pointers, which means that the time complexity is often **O(n)**.

This makes two pointers a powerful optimization technique for array-based problems where naive approaches would be too slow.

---

## Constraints

- `1 ≤ n ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **Single element:** No pair possible
2. **Two elements:** One pair to check
3. **All same elements:** Depends on problem target

<br>
