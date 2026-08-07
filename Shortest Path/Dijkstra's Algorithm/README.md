## Dijkstra's Algorithm

**Dijkstra's Algorithm** is a shortest path algorithm used to find the minimum distance from a source vertex to all other vertices in a **weighted graph**.

It works only when the graph has **non-negative edge weights**.

## How It Works

1. Set the distance of every vertex to infinity.

2. Set the distance of the source vertex to `0`.

3. Store the source vertex in a priority queue.

4. Take the vertex with the smallest distance from the priority queue.

5. Check all adjacent vertices of the current vertex.

6. Calculate the new possible distance.

```text
newDistance = currentDistance + edgeWeight
```

7. Compare the new distance with the previous distance.

```text
if newDistance < distance[next]
```

8. If the new distance is smaller, update the distance.

9. Push the updated vertex into the priority queue.

10. Continue the process until the priority queue becomes empty.

## Dijkstra Flow

```text
Source Vertex
     |
     v
Set Distance = 0
     |
     v
Push into Priority Queue
     |
     v
Take Vertex with
Smallest Distance
     |
     v
Check Adjacent Vertices
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
Push into Priority Queue
   |
   v
Repeat Until Queue is Empty
```

## Relaxation

The process of checking whether a shorter path exists is called **Relaxation**.

```text
if distance[current] + weight < distance[next]
```

Then:

```text
distance[next] = distance[current] + weight
```

## Time Complexity

Using a priority queue:

```text
O((V + E) log V)
```

Where:

- `V` = Number of vertices
- `E` = Number of edges

## Space Complexity

```text
O(V + E)
```

## Important Points

- Dijkstra's Algorithm finds the **shortest path**.
- It is used for **weighted graphs**.
- Edge weights must be **non-negative**.
- It uses a **Priority Queue** to select the vertex with the minimum distance.
- The source vertex starts with distance `0`.
- Other vertices initially have infinite distance.
- The process of updating a shorter distance is called **Relaxation**.
- Dijkstra's Algorithm does not work correctly with negative edge weights.
