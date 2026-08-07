# Depth-First Search (Shortest Path)

DFS is a graph traversal algorithm that explores one path of the graph as deeply as possible before moving to another path.

DFS can be implemented using:

- Recursion
- Stack

## Shortest Path Using DFS

Normally, DFS is mainly used for graph traversal and does not directly guarantee the shortest path.

However, DFS can be modified to find the shortest distance by updating the distance whenever a shorter path to a vertex is found.

For an unweighted graph, **BFS is generally preferred for shortest path problems**.

## How It Works

1. Start from the **source vertex**.
2. Set the distance of the source vertex to `0`.
3. Start DFS from the source vertex.
4. Visit each adjacent vertex.
5. Calculate the new distance:

```text
new distance = current distance + 1
```

6. Compare the new distance with the previous distance of that vertex.
7. If the new distance is smaller, update the distance.

```text
if distance[next] > distance[current] + 1
```

8. Continue DFS from that vertex.
9. Repeat the process until no shorter distance can be found.
10. The distance array will contain the shortest distances from the source.

## DFS Flow

```text
Source Vertex
     |
     v
Set Distance = 0
     |
     v
Start DFS
     |
     v
Visit Adjacent Vertex
     |
     v
Calculate New Distance
     |
     v
Is New Distance Smaller?
    /        \
  Yes         No
   |           |
   v           v
Update       Ignore
Distance
   |
   v
Call DFS Again
   |
   v
Continue Until All Possible
Shorter Paths Are Checked
```

## Time Complexity

The time complexity can be higher than normal DFS because a vertex may be visited again when a shorter path is found.

Normal DFS traversal:

```text
O(V + E)
```

But this modified DFS may take more time depending on the graph.

## Space Complexity

```text
O(V)
```

The recursive call stack and distance array require additional memory.

## Important Points

- DFS normally uses **recursion or a stack**.
- DFS explores one path deeply before trying another path.
- Normal DFS does not guarantee the shortest path.
- DFS can be modified by updating distances when a shorter path is found.
- For shortest paths in an unweighted graph, **BFS is usually the better choice**.
