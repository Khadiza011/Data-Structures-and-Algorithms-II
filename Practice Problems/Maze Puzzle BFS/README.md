# Shortest Path in a Maze using Breadth-First Search (BFS) in C++

## Overview

This project implements the **Breadth-First Search (BFS)** algorithm to find the **shortest path** in a maze represented as a 2D grid.

The maze consists of:
- `0` → Open cell (can be visited)
- `1` → Blocked cell (wall)

The program computes the minimum number of steps required to move from the **top-left cell (0,0)** to the **bottom-right cell (R-1, C-1)**. If no path exists, it returns `-1`.

## Algorithm

1. Read the number of rows and columns.
2. Read the maze grid.
3. Check whether the start or destination cell is blocked.
4. Initialize:
   - `visited` array
   - `distance` array
   - Queue for BFS
5. Start BFS from cell `(0,0)`.
6. Visit all valid neighboring cells in four directions:
   - Up
   - Down
   - Left
   - Right
7. Store the shortest distance for every reachable cell.
8. Output the minimum number of steps to reach the destination.

## Time Complexity

- **Time Complexity:** O(R × C)
- **Space Complexity:** O(R × C)

Where:
- **R** = Number of rows
- **C** = Number of columns

## Input

- Number of rows (`R`)
- Number of columns (`C`)
- Maze grid containing `0`s and `1`s

### Example Input

```
5 5

0 0 1 0 0
0 0 0 0 1
1 1 0 1 0
0 0 0 0 0
1 1 1 0 0
```

## Example Output

```
Minimum steps: 8
```

If no valid path exists:

```
Minimum steps: -1
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

- Implements Breadth-First Search (BFS)
- Finds the shortest path in an unweighted maze
- Uses a circular queue implementation
- Supports movement in four directions
- Detects unreachable destinations
- Simple C++ implementation without STL queue
