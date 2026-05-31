*This project has been created as part of the 42 curriculum by alfeofan.*

# *This project has been created as part of the 42 curriculum by <your_login>.*

# Push Swap

## Description

Push Swap is a sorting algorithm project from the 42 curriculum.

The objective is to sort a stack of integers in ascending order using two stacks (`a` and `b`) and a limited set of stack operations. The challenge is not only to sort the numbers correctly, but also to minimize the total number of operations performed.

The program receives a list of unique integers as command-line arguments, validates the input, and outputs the sequence of operations required to sort the stack.

### Features

* Input parsing and validation
* Detection of invalid values and duplicates
* Stack implementation using linked lists
* Support for all mandatory push_swap operations:

  * `sa`, `sb`, `ss`
  * `pa`, `pb`
  * `ra`, `rb`, `rr`
  * `rra`, `rrb`, `rrr`
* Index assignment for optimized sorting
* Dedicated sorting algorithms for small stacks:

  * 3 elements
  * 5 elements
* K Sort algorithm for larger datasets
* Memory management and error handling

---

## Project Structure

```text
.
├── push_swap.h
├── operations/
├── simple_sort.c
├── k_sort.c
├── validate_and_convert.c
├── utils.c
├── ft_split.c
├── check_error.c
└── ...
```

### Data Structure

```c
typedef struct s_stack
{
    int                 value;
    int                 index;
    struct s_stack      *next;
} t_stack;
```

Each node stores:

* `value` — original integer value
* `index` — normalized rank used by the sorting algorithm
* `next` — pointer to the next node

---

## Algorithm

### Small Stacks

For stacks containing up to five numbers, dedicated sorting strategies are used:

* `sort_three()`
* `sort_five()`

These implementations minimize the number of operations for small inputs.

### K Sort

For larger datasets, the project uses the **K Sort** algorithm.

The process consists of:

1. Assigning an index to each value according to its position in the sorted sequence.
2. Moving elements from stack `a` to stack `b` following the K formation strategy.
3. Moving elements back to stack `a` in descending index order.
4. Producing a fully sorted stack with a competitive number of operations.

---

## Instructions

### Compilation

Compile the project using:

```bash
make
```

or

```bash
cc -Wall -Wextra -Werror *.c -o push_swap
```

### Usage

```bash
./push_swap 4 67 3 87 23
```

Example output:

```text
pb
ra
pb
sa
pa
pa
```

The output represents the sequence of operations required to sort the stack.

### Error Handling

The program prints:

```text
Error
```

for:

* Non-numeric arguments
* Integer overflow/underflow
* Duplicate values
* Invalid input format

Examples:

```bash
./push_swap 1 2 2
```

```bash
./push_swap 2147483648
```

```bash
./push_swap hello
```

---

## Technical Choices

### Linked Lists

Stacks are implemented as singly linked lists to allow efficient push and pop operations.

### Index Compression

Each value receives an index representing its rank in the sorted order.

Example:

```text
Values: 40 10 30 20

Sorted: 10 20 30 40

Indexes:
40 -> 3
10 -> 0
30 -> 2
20 -> 1
```

This simplifies comparisons and improves sorting efficiency.

---
## Resources

### Documentation
- https://www.geeksforgeeks.org/c/implement-stack-in-c/
- https://www.geeksforgeeks.org/dsa/understanding-time-complexity-simple-examples/
- https://en.cppreference.com/w/c
- https://stackoverflow.com/
- https://www.geeksforgeeks.org/

---

### AI Usage

Artificial Intelligence tools were used as learning and documentation assistants during the project.

AI assistance was limited to:

* Understanding project requirements
* Reviewing algorithm concepts
* Explaining linked-list operations
* Improving code documentation
* Drafting and proofreading the README

All design decisions, implementation, debugging, testing, and final code were completed manually.

