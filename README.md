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

## 📂 File Structure

The project is organized into the following files:

### 🏗 Core Files  
- **`push_swap.h`** - Header file with function prototypes  
- **`main.c`** - Entry point of the program  

### ✅ Input & Validation  
- **`validation.c`** - Handles input validation  

### 📌 Stack Operations  
- **`stack.c`** - Stack initialization and management  
- **`stack_utils.c`** - Helper functions for stack manipulation  
- **`swap.c`** - Swap operations (`sa`, `sb`, `ss`)  
- **`push.c`** - Push operations (`pa`, `pb`)  
- **`rotate.c`** - Rotate operations (`ra`, `rb`, `rr`)  
- **`reverse_rotate.c`** - Reverse rotate operations (`rra`, `rrb`, `rrr`)  

## 📊 Sorting Algorithm

The sorting strategy is optimized based on the number of elements:

- 🏆 **3 elements:** Uses a minimal set of swaps and rotations to achieve the correct order.
- 🎯 **5 elements:** Implements a more efficient small-sort strategy to minimize operations.
- 🚀 **More elements:** Uses a **range-based sorting algorithm**, pushing elements in sorted chunks to optimize the move count.


### 🔢 Sorting Algorithms  
- **`sort_small.c`** - Sorting logic for small stacks  
- **`algo.c`** - Main sorting algorithm  
- **`move_to_top.c`** - Functions to move elements to the top efficiently  
- **`find_min_max.c`** - Finds min/max values in the stack  
- **`range_utils.c`** - Utilities for range-based sorting  

### 🛠 Utilities & Compilation  
- **`utils.c`** - General utility functions  
- **`Makefile`** - Compilation instructions  
