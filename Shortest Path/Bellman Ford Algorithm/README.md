# Bellman-Ford Shortest Path Algorithm (C++)

## Overview

This project implements the **Bellman-Ford Algorithm** to find the **shortest path** from a source vertex to a destination vertex in a weighted graph. Unlike Dijkstra's algorithm, Bellman-Ford can handle graphs containing **negative edge weights** (as long as there is no negative weight cycle).

The program computes the minimum cost from the source vertex to the destination vertex and displays the corresponding path.

## Algorithm

1. Read the number of vertices and edges.
2. Input all edges in the form:
   - Source vertex
   - Destination vertex
   - Edge weight
3. Initialize:
   - Distance of the source vertex as `0`.
   - Distance of all other vertices as infinity.
   - Parent array to reconstruct the shortest path.
4. Relax every edge `V - 1` times.
5. Store the predecessor of each vertex whenever a shorter path is found.
6. Print:
   - Minimum cost from the source to the destination.
   - The shortest path.

## Time Complexity

- **Time Complexity:** O(V × E)
- **Space Complexity:** O(V + E)

Where:
- **V** = Number of vertices
- **E** = Number of edges

## Input

- Number of vertices (`V`)
- Number of edges (`E`)
- `E` lines containing:
  - Source vertex
  - Destination vertex
  - Edge weight

### Example Input

```
5 8
1 2 6
1 3 7
2 3 8
2 4 5
2 5 -4
3 4 -3
4 5 9
5 4 7
```

## Example Output

```
Shortest Cost = 2

Path:
1 3 4 5
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

- Implements the Bellman-Ford shortest path algorithm
- Supports graphs with negative edge weights
- Computes the minimum path cost
- Reconstructs and displays the shortest path
- Simple C++ implementation using vectors
