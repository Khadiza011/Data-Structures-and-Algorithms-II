# Multi-Array-Min-Max-Problem (Department Score Analysis Using Divide And Conquer)

## Overview

This project implements a **Divide and Conquer Algorithm** in C++ to efficiently determine:

- The highest score among all departments
- The lowest score among all departments
- The department containing the highest score
- The department containing the lowest score
- Total number of comparisons performed

Instead of scanning every element sequentially, the algorithm recursively divides the data into smaller parts and combines the results, reducing unnecessary comparisons.

---

## Features

- User input for department names
- User input for student scores
- Finds minimum and maximum score in each department
- Finds overall minimum and maximum among all departments
- Displays corresponding department names
- Counts total comparisons made during execution

---

## Algorithm

### Step 1

Input:

- Number of departments
- Number of students in each department
- Department names
- Student scores

### Step 2

Use Divide and Conquer to find the minimum and maximum score within each department.

### Step 3

Recursively compare departmental results to determine:

- Overall highest score
- Overall lowest score

### Step 4

Display:

- Highest score
- Lowest score
- Department containing the highest score
- Department containing the lowest score
- Total comparisons

---

## Time Complexity

Finding min and max in one department:

**O(n)**

Finding overall result among departments:

**O(d)**

Overall complexity:

**O(d × n)**

where

- **d** = Number of departments
- **n** = Students per department

---

## Space Complexity

**O(log n + log d)**

due to recursive function calls.

---

## Sample Input

```
Enter the number of departments: 3
Enter the number of students in each department: 4

Enter name of Department 1:
CSE
Enter 4 student scores:
78 85 92 67

Enter name of Department 2:
EEE
Enter 4 student scores:
88 76 95 82

Enter name of Department 3:
ME
Enter 4 student scores:
70 88 79 91
```

---

## Sample Output

```
Highest Score: 95 (Department: EEE)
Lowest Score: 67 (Department: CSE)
Total Comparisons: 14
```

---

## Project Structure

```
.
├── main.cpp
└── README.md
```

## Concepts Used

- Divide and Conquer
- Recursion
- Min-Max Algorithm
- STL Vector
- Time Complexity Analysis
- Space Complexity Analysis

---

## Author

**Khadiza Rehan**
