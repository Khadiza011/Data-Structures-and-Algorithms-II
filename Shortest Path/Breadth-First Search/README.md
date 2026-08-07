## Breadth-First Search Shortest Path

BFS is a graph traversal algorithm that visits the vertices of a graph **level by level**.

It uses a **Queue** to keep track of the vertices that need to be visited.

## Shortest Path Using BFS

BFS is used to find the **shortest path in an unweighted graph**.

The shortest path means the minimum number of edges required to reach a vertex from a given source vertex.

## How It Works

1. Start from the **source vertex**.
2. Mark the source as visited.
3. Set the distance of the source to `0`.
4. Push the source vertex into a **Queue**.
5. Take the front vertex from the queue.
6. Visit all of its unvisited adjacent vertices.
7. Set the distance of each newly visited vertex:

```text
distance[next] = distance[current] + 1
```

8. Push the newly visited vertices into the queue.
9. Repeat the process until the queue becomes empty.
10. After BFS is completed, the distance array contains the shortest distance from the source to every reachable vertex.

## BFS Flow

```text
Source Vertex
     |
     v
Push into Queue
     |
     v
Take Front Vertex
     |
     v
Visit Adjacent Vertices
     |
     v
Are They Unvisited?
   /       \
 Yes        No
  |          |
  v          v
Set       Ignore
Distance
  |
  v
Push into Queue
  |
  v
Repeat Until Queue is Empty
```

## Time Complexity

```text
O(V + E)
```

Where:

- `V` = Number of vertices
- `E` = Number of edges

## Space Complexity

```text
O(V)
```

## Important Points

- BFS uses a **Queue**.
- BFS explores the graph **level by level**.
- BFS can find the shortest path in an **unweighted graph**.
- The distance increases by `1` when moving through one edge.
- A visited vertex should not be visited again.
