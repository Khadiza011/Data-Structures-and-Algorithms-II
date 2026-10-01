# Multiple Thieves Fractional Knapsack

## Problem Description

Given multiple items with:

- Weight
- Value

and multiple thieves with limited bag capacities, find the maximum total value that can be collected.

A thief can take a fraction of an item if the complete item cannot fit.

---

## Algorithm Used

**Fractional Knapsack + Greedy Approach**

### Approach:
- Calculate value-to-weight ratio for each item.
- Sort items based on the highest ratio.
- For each thief, take items with the maximum value density first.
- Take full items whenever possible; otherwise take the required fraction.


---

## Sample Input

3

10 60

20 100

30 120

2

50

20


## Sample Output

240

---

## Complexity Analysis

Time Complexity: O(N log N + N × T)

Space Complexity: O(N)
