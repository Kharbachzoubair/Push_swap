# Push_swap

## Overview
Push_swap is a project from 42 School that involves sorting a list of integers using two stacks and a limited set of operations. The goal is to implement an efficient sorting algorithm that minimizes the number of operations.

## Features
- Validates input and ensures correct formatting.
- Implements stack operations for sorting.
- Optimized sorting strategies for different input sizes.
- Handles edge cases such as duplicates and invalid inputs.

## Compilation
To compile the project, run:
```bash
make
```
This will generate the `push_swap` executable.

## Running the Program
To run the program with a list of numbers:

```bash
./push_swap 4 67 3 87 23
```

## Stack Operations
The following stack operations are implemented:

- `sa`, `sb`, `ss` → Swap top two elements of the stack(s).
- `pa`, `pb` → Push top element from one stack to another.
- `ra`, `rb`, `rr` → Rotate stack (shift elements up).
- `rra`, `rrb`, `rrr` → Reverse rotate stack (shift elements down).

## File Structure

├── push_swap.h            # Header file with function prototypes
├── main.c                 # Entry point of the program
├── validation.c           # Input validation functions
├── stack.c                # Stack management functions
├── stack_utils.c          # Stack-related utilities
├── sort_small.c           # Sorting algorithm for small inputs
├── algo.c                 # Main sorting algorithm
├── move_to_top.c          # Functions to move elements to the top
├── find_min_max.c         # Find min/max values in the stack
├── range_utils.c          # Utilities for range-based sorting
├── rotate.c               # Rotate operations
├── reverse_rotate.c       # Reverse rotate operations
├── swap.c                 # Swap operations
├── push.c                 # Push operations
├── utils.c                # General utility functions
├── Makefile               # Compilation instructions

