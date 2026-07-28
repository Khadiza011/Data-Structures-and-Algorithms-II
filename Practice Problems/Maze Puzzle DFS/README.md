# Connected Region Detection in a Maze using Depth-First Search (DFS) in C++

## Overview

This project uses the **Depth-First Search (DFS)** algorithm to identify all connected open regions in a 2D maze.

The maze consists of:
- `0` → Open cell
- `1` → Blocked cell (wall)

The program traverses the maze, counts the total number of connected regions, and calculates the size (number of cells) of each region.

## Algorithm

1. Read the number of rows and columns.
2. Read the maze grid.
3. Initialize the `visited` array.
4. Traverse every cell in the maze.
5. If an unvisited open cell (`0`) is found:
   - Perform DFS starting from that cell.
   - Count all connected open cells.
   - Store the region size.
6. Repeat until all cells have been visited.
7. Display:
   - Total number of connected regions.
   - Size of each region.

## Time Complexity

- **Time Complexity:** O(R × C)
- **Space Complexity:** O(R × C)

Where:
- **R** = Number of rows
- **C** = Number of columns

## Input

- Number of rows (`R`)
- Number of columns (`C`)
- Maze grid consisting of `0`s and `1`s

### Example Input

```
5 5

0 0 1 1 0
0 1 1 0 0
1 1 0 0 1
0 0 1 1 1
0 1 0 0 0
```

## Example Output

```
Number of regions: 4
Region sizes: 3 4 3 3
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

- Implements Depth-First Search (DFS)
- Detects all connected open regions
- Calculates the size of each region
- Uses recursive DFS traversal
- Supports four-directional movement (up, down, left, right)
- Simple C++ implementation without STL graph libraries
