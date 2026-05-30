*This project has been created as part of the 42 curriculum by alfeofan.*

# Push_swap

## Description

The **push_swap** project is part of the 42 curriculum and focuses on sorting a list of integers using a limited set of operations and two stacks.

The goal is to sort numbers in ascending order using the **smallest number of operations possible**. The challenge is not only correctness but also **efficiency and optimization**.

This project introduces key concepts such as:
- algorithm design
- time complexity optimization
- stack data structures
- problem-solving under constraints

The program receives integers as arguments and outputs a sequence of operations that will sort them.

---

## Instructions

### Requirements

- C compiler (`cc`)
- Make
- Unix-based system (Linux / macOS)

---

### Compilation

Clone the repository:

```bash
git clone https://github.com/<your_username>/push_swap.git
cd push_swap
```

Compile the project:

```bash
make
```
---

### Usage

```bash
./push_swap 3 2 1 6 5 8
```

Example output:

```bash
pb
pb
sa
pa
pa
```

Each operation modifies the stacks to progressively sort the data.

---
### Allowed Operations

| Operation	| Description |
|-----------|-------------|
| sa |	swap the first two elements of stack a |
| sb |	swap the first two elements of stack b |
| ss |	perform sa and sb simultaneously |
| pa |	push top element from b to a | 
| pb |	push top element from a to b |
| ra |	rotate stack a (first element becomes last) |
| rb |	rotate stack b |
| rr |	perform ra and rb simultaneously |
| rra |	reverse rotate stack a |
| rrb |	reverse rotate stack b |
| rrr |	perform rra and rrb simultaneously |

---

## Algorithm and Design Choices

### Data Structure

The program uses two stacks:

- Stack A → contains initial values
- Stack B → auxiliary stack used during sorting

Stacks can be implemented using:

- linked lists (flexible, commonly used)
- arrays (faster access, less flexible)

---

## Sorting Strategy

Different approaches are used depending on input size.

---

## Small Inputs (≤ 5 numbers)

Hardcoded sorting logic

Minimal number of operations

Direct comparisons and swaps

## Large Inputs

Two main strategies are commonly used:

### Radix Sort (Binary)

This is one of the most efficient approaches.

Steps:

1. Normalize values (replace numbers with their sorted index)
2. Process numbers bit by bit (binary representation)
3. For each bit:
    - If bit = 0 → push to stack B (pb)
    - If bit = 1 → rotate stack A (ra)
4. Push all elements back to stack A (pa)
5. Repeat for each bit

Advantages:
- Predictable performance
- Works efficiently for large datasets
- Easy to implement

### Chunking Algorithm

Steps:
1. Divide the dataset into chunks (ranges)
2. Push elements from A to B based on chunk range
3. Optimize rotations to minimize moves
4. Push elements back from B to A in sorted order

Advantages:
- More optimized for specific input sizes
- Reduces unnecessary operations

### Why These Algorithms?

They respect project constraints

They minimize the number of operations

They scale well with large inputs

They are widely used in stack-based sorting problems

---

## Complexity Analysis

| Case         | Complexity  |
| ------------ | ----------- |
| Small inputs | O(1)        |
| Radix sort   | O(n log n)  |
| Chunking     | ~O(n log n) |

---

## Optimization Techniques

- Minimize rotations (ra vs rra)
- Use combined operations (rr, rrr)
- Avoid unnecessary pushes
- Pre-index values for faster processing

---

## Edge Cases

The program correctly handles:
- already sorted input
- duplicate numbers (returns error)
- invalid input (non-integer values)
- empty input
- very large intege

---

## Example

Input:

```bash
./push_swap 2 1 3
```

Output:

```bash
sa
```

---

## Resources

### Documentation
- https://www.geeksforgeeks.org/c/implement-stack-in-c/
- https://www.geeksforgeeks.org/dsa/understanding-time-complexity-simple-examples/
- https://en.cppreference.com/w/c
- https://stackoverflow.com/
- https://www.geeksforgeeks.org/

---

## AI Usage

AI tools were used for:
- understanding sorting algorithms (radix, chunking)
- improving documentation structure
- clarifying optimization strategies
- All code and algorithm implementations were written, tested, and optimized manually.
