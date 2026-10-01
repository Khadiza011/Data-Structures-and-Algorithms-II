# K Stops Shortest Path

## Problem Description

Find the minimum cost path from a source node to a destination node with at most **K stops** in a weighted graph.

If no valid path exists within the given stop limit, return `-1`.

---

## Algorithm Used

**Modified Bellman-Ford Algorithm**

Instead of relaxing edges `V-1` times, we relax them only `K+1` times because the number of stops is limited.

---

## Approach

- Store graph edges as: source, destination, cost

  - Maintain a distance array to store minimum cost.
- Relax all edges for every allowed stop.
- Update the minimum cost if a cheaper path is found.
- Print the final shortest cost.

---

## Complexity Analysis

**Time Complexity:**
O(K × E)


**Space Complexity:**
O(V)

