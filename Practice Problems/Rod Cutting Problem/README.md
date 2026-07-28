# Rod Cutting Problem using Dynamic Programming (C++)

## Overview

This project solves the **Rod Cutting Problem** using **Dynamic Programming**. Given a rod of a certain length and the prices of different piece lengths, the program determines the **maximum obtainable profit** by cutting the rod into pieces.

Each piece length can be used multiple times, making this an **Unbounded Knapsack** problem.

## Algorithm

1. Read the total rod length.
2. Read the number of available piece lengths.
3. Input the lengths and their corresponding prices.
4. Initialize a DP table:
   - Rows represent available piece lengths.
   - Columns represent rod lengths.
5. For each piece:
   - If the piece length is less than or equal to the current rod length:
     - Choose the maximum between:
       - Cutting the rod using the current piece again.
       - Skipping the current piece.
6. The final answer is stored in `dp[n][L]`.

## Time Complexity

- **Time Complexity:** O(n × L)
- **Space Complexity:** O(n × L)

Where:
- **n** = Number of available piece lengths
- **L** = Total rod length

## Input

- Rod length
- Number of available piece lengths
- Length of each piece
- Price of each piece

### Example Input

```
ENTER ROPE LENGTH:
8

ENTER PIECES NUMBER:
8

ENTER LENGTHS:
1 2 3 4 5 6 7 8

ENTER PRICES OF LENGTHS:
1 5 8 9 10 17 17 20
```

## Example Output

```
Maximum Obtainable Profit = 22
```

## How to Compile

```bash
g++ main.cpp -o main
```

## How to Run

### Linux/macOS

```bash
./main
```

### Windows

```bash
main.exe
```

## Features

- User input for rod length, piece lengths, and prices
- Dynamic Programming solution
- Solves the Rod Cutting (Unbounded Knapsack) problem
- Calculates the maximum obtainable profit
- Efficient O(n × L) implementation
- Simple C++ program
