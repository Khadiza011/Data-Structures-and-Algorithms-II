# Rabin-Karp Algorithm

# Rabin-Karp String Matching Algorithm (C++)

## Overview

This project implements the **Rabin-Karp Algorithm** for pattern searching. It uses a rolling hash technique to efficiently search for all occurrences of a pattern within a given text.

The program accepts both the text and pattern as user input and prints the starting index of every occurrence.

## Algorithm

1. Read the text and pattern from the user.
2. Compute the hash value of the pattern.
3. Compute the hash value of the first window of the text.
4. Compare the hash values:
   - If they match, perform character-by-character verification.
   - If verified, report the pattern occurrence.
5. Slide the text window by one character.
6. Update the hash using the rolling hash formula.
7. Repeat until the end of the text.

## Time Complexity

- **Best/Average Case:** O(n + m)
- **Worst Case:** O(n × m)

Where:
- **n** = Length of the text
- **m** = Length of the pattern

## Input

- Text
- Pattern

### Example Input

```
Enter the text:
aabaacaadaabaaba

Enter the pattern:
aaba
```

## Example Output

```
Pattern found at index: 0
Pattern found at index: 9
Pattern found at index: 12
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

- User input for text and pattern
- Implements the Rabin-Karp string matching algorithm
- Uses rolling hash for efficient searching
- Detects multiple occurrences of the pattern
- Simple C++ implementation


## Topics

- String Hashing
- Rolling Hash
- Pattern Matching
- Time Complexity Analysis
