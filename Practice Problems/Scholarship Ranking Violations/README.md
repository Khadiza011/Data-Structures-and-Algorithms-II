## Scholarship Ranking Violations

A university publishes scholarship candidates according to **descending GPA**, so that the strongest candidates appear first.

Because of a software error, some lower GPAs may appear before higher GPAs. Each such out-of-order pair is called a **ranking violation**.

Given the GPA list:

```text
GPA = [3.20, 3.85, 3.10, 3.70, 2.95]
```

Design a **Divide and Conquer** algorithm to determine the total number of ranking violations.

### Sample Input

```text
5
3.20 3.85 3.10 3.70 2.95
```

### Sample Output

```text
Total ranking violations = 2
