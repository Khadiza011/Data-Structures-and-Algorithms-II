## Divide and Conquer

## Introduction

Divide and Conquer is an algorithmic technique where a large problem is divided into smaller subproblems. Each smaller problem is solved separately, and their results are combined to get the final answer.

This technique is useful when the original problem is difficult to solve directly.

## Main Steps

A Divide and Conquer algorithm normally follows three steps:

## 1. Divide

Divide the original problem into two or more smaller subproblems.

## 2. Conquer

Solve the smaller subproblems recursively.

If a subproblem becomes small enough, solve it directly. This is called the base case.

## 3. Combine

Combine the results of the smaller subproblems to produce the final result.

## When to Use Divide and Conquer

Divide and Conquer can be useful when:

- A problem can be divided into smaller problems of the same type.
- The smaller subproblems can be solved independently.
- The results of the subproblems can be combined.
- Recursion can reduce the problem size.
- A simple base case exists.
- Dividing the problem improves the total running time.

## Important Points

- Every recursive solution must contain a base case.
- The problem size should become smaller after every recursive call.
- The middle position is commonly calculated using:

## int mid = left + (right - left) / 2; ##

This method is safer than:

## int mid = (left + right) / 2; ##

because it reduces the possibility of integer overflow.

- The combine step depends on the problem.
- Some algorithms perform most of their work during division.
- Some algorithms perform most of their work during combination.

## Applications of Divide and Conquer

Divide and Conquer is used in many important algorithms and real-life problems.

* **Binary Search** for searching in sorted data
* **Merge Sort** and **Quick Sort** for sorting
* Finding **minimum, maximum, second minimum, and second maximum**
* **Maximum Subarray Problem**
* **Strassen’s Matrix Multiplication**
* **Karatsuba Multiplication** for large numbers
* **Closest Pair of Points**
* **Image processing and computer graphics**
* **Database searching**
* **Parallel computing**

