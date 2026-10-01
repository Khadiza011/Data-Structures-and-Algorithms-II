# Skill Matching Between Players and Coaches

## Problem Description

Given the skill levels of players and the required skill levels of coaches, find the maximum number of possible matches.

A player can be matched with a coach if the player's skill level is greater than or equal to the coach's requirement.

---

## Algorithm Used

**Greedy Approach + Sorting**

### Approach:
- Sort player skills in ascending order.
- Sort coach requirements in ascending order.
- Use two pointers to find the maximum number of valid matches.
- Match the smallest suitable player with each coach.


---

## Sample Input

5

3 1 5 2 4

3

2 4 6


## Sample Output

2

---

## Complexity Analysis

Time Complexity: O(N log N + M log M)

Space Complexity: O(1)

