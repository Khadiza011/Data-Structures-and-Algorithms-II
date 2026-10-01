# Maximum Rides With Income

## Problem Description

Given multiple rides with:

- Starting time
- Ending time
- Income

Select non-overlapping rides to get the maximum possible total income.

---

## Algorithm Used

**Dynamic Programming + Greedy Approach**

### Approach:
- Sort rides based on ending time.
- Use DP to choose between:
  - Taking the current ride
  - Skipping the current ride
- Find the maximum possible income.


---

## Sample Input

4

1 3 50

2 5 20

4 6 70

6 8 60


## Sample Output

180

---

## Complexity Analysis

Time Complexity:  O(N log N)

Space Complexity:  O(N)


**Topic:**

Greedy Algorithm
Weighted Interval Scheduling
Dynamic Programming
