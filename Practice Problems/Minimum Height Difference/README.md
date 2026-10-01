# Minimum Height Difference

## Problem Description

Given the heights of `N` students, select `M` students such that the difference between the tallest and shortest selected students is minimum.

---

## Algorithm Used

**Greedy Approach + Sorting**

### Approach:
- Sort all heights in ascending order.
- Check every group of `M` consecutive students.
- Calculate the height difference.
- Select the minimum difference.

---

## Complexity Analysis

Time Complexity:
O(N log N)


Space Complexity:
O(1)


**Topic:**
Greedy Algorithm
Sorting
Sliding Window

