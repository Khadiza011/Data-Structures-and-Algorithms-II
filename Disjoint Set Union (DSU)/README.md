# Disjoint Set Union (DSU)

# Disjoint Set Union (Union-Find) using Path Compression and Union by Rank (C++)

## Overview

This project implements the **Disjoint Set Union (DSU)**, also known as the **Union-Find** data structure. The program provides a **menu-driven interface** where users can perform multiple **Union** and **Find** operations until they choose to exit.

The implementation uses **Path Compression** and **Union by Rank** to optimize the performance of the operations.

## Algorithm

### Initialization

1. Create `n` separate sets.
2. Each element is initially its own parent.
3. Initialize the rank of every set to `0`.

### Union Operation

1. Find the representative (root) of both elements.
2. If they belong to different sets:
   - Attach the tree with the smaller rank to the tree with the larger rank.
   - If both trees have the same rank, attach one to the other and increase the rank of the new root.

### Find Operation

1. Find the representative (root) of an element.
2. Apply **Path Compression** so future searches become faster.
3. Two elements belong to the same set if they have the same representative.

## Menu Options

1. **Union** – Merge the sets containing two elements.
2. **Find (Check Same Set)** – Determine whether two elements belong to the same set.
3. **Display Parent Array** – Display the current parent of each element.
4. **Exit** – Terminate the program.

## Time Complexity

| Operation | Time Complexity |
|-----------|-----------------|
| Initialization | O(n) |
| Find | O(α(n)) |
| Union | O(α(n)) |

> **α(n)** (Inverse Ackermann Function) grows extremely slowly and is considered nearly constant for practical input sizes.

## Input

- Number of elements
- Menu choice
- Elements for Union operation
- Elements for Find operation

## Example Run

### Input

```
Enter the number of elements:
6

Choice: 1
Enter two elements:
0 1

Choice: 1
Enter two elements:
2 3

Choice: 2
Enter two elements:
1 3

Choice: 1
Enter two elements:
0 2

Choice: 2
Enter two elements:
1 3

Choice: 4
```

### Output

```
Union operation completed.
Union operation completed.

1 and 3 are in different sets.

Union operation completed.

1 and 3 are in the same set.

Exiting program...
```

## How to Compile

```bash
g++ main.cpp -o main
```

## How to Run

### Linux/macOS

```bash
./main
```

### Windows

```bash
main.exe
```

## Features

- Interactive menu-driven program
- Supports multiple Union operations
- Supports multiple Find (connectivity) queries
- Uses Path Compression for efficient Find operations
- Uses Union by Rank for balanced trees
- Displays the parent array
- Continues execution until the user selects **Exit**
- Simple C++ implementation using vectors


## Topics

- Make Set
- Find Set
- Union Set
- Path Compression
- Union by Rank
