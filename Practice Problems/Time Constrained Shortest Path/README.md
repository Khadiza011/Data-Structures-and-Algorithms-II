# Time Constrained Shortest Path

## Problem Description

Given a weighted graph where each edge contains:

- **Cost** → The cost required to travel through the edge
- **Time** → The time required to travel through the edge

The goal is to find the **minimum cost path** from a source node to a destination node while satisfying a given maximum time constraint.

If there is no possible path within the allowed time limit, the output should be `-1`.

---

## Algorithm Used

## Modified Dijkstra Algorithm

This problem is solved using a modified version of **Dijkstra's Algorithm**.

In normal Dijkstra's Algorithm, we only track the shortest distance from the source node.

However, in this problem, we need to consider two factors:

1. Total travelling cost
2. Total travelling time

A path with lower cost may take more time, while another path with higher cost may reach earlier.

Therefore, we store the state as: {cost, current node, current time}


and process the minimum cost path using a priority queue.

---

# Data Structure Used

## 1. Graph Representation

The graph is stored using an adjacency list.

Each edge stores: (destination, cost, time)


Example: 0 -> 2 (Cost = 5, Time = 2)


Meaning:

- Starting node: 0
- Destination node: 2
- Travelling cost: 5
- Travelling time: 2

---

## 2. Priority Queue

A minimum priority queue is used to process the path with the lowest current cost first.

Each state contains: {cost, node, time}


Example: {12, 4, 8}


means:

- Current cost = 12
- Current node = 4
- Total time used = 8

---

# Working Procedure

1. Take the number of vertices and edges as input.

2. Build the graph using adjacency list.

3. Take:
   - Source node
   - Destination node
   - Maximum allowed time

4. Create a distance table: distance[node][time]

This stores the minimum cost required to reach a specific node at a specific time.

5. Start from the source node with: cost = 0 time = 0


6. Use priority queue to explore possible paths.

7. For every connected node:
   - Calculate new cost
   - Calculate new time

8. Ignore paths where: new time > maximum allowed time


9. Update the answer if a lower cost path is found.

10. Print the minimum cost.

---

# Example Input

5 6

0 1 10 5

0 2 5 2

1 3 2 3

2 3 4 4

3 4 3 2

1 4 20 8

0

4

10

---

# Input Explanation

First line: 5 6

means: Number of vertices = 5 Number of edges = 6

---

Each edge input format: source destination cost time

Example: 0 2 5 2

means: 
Source Node = 0
Destination Node = 2
Cost = 5
Time = 2

---

After graph input: 
Source = 0
Destination = 4
Maximum Time = 10

---

# Possible Paths

## Path 1  
0 → 1 → 3 → 4

Cost: 10 + 2 + 3 = 15

Time: 5 + 3 + 2 = 10

---

## Path 2   
0 → 2 → 3 → 4

Cost:  5 + 4 + 3 = 12

Time:  2 + 4 + 2 = 8

---

Path 2 has lower cost and is within the time limit.

Therefore:  Minimum Cost = 12

---

# Output  
12

---

# Complexity Analysis

Let:

- `V` = Number of vertices
- `E` = Number of edges
- `T` = Maximum allowed time

## Time Complexity
O((V × T + E × T) log(V × T))


## Space Complexity
O(V × T)


---

# Learning Outcome

After completing this problem, will understand:

- How Dijkstra Algorithm works
- How to modify shortest path algorithms for additional constraints
- How to use priority queue in graph problems
- How to maintain multiple states while finding optimal paths


