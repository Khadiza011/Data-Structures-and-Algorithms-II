# Rabin-Karp String Matching Algorithm (C++)

## Overview

This project implements the **Rabin-Karp String Matching Algorithm** to detect occurrences of a suspicious token within a network log. The program removes spaces from the input text, computes hash values for the pattern and text windows, and verifies matches to avoid false positives caused by hash collisions.

## Algorithm

1. Read the network log (text).
2. Remove all spaces from the text.
3. Read the suspicious token (pattern).
4. Calculate the hash value of the pattern and the first window of the text.
5. Slide the window through the text:
   - Compare hash values.
   - If the hashes match, perform character-by-character verification.
   - If verified, report a valid occurrence.
   - Otherwise, report a hash collision.
6. Display the total number of valid occurrences.

## Time Complexity

- **Best/Average Case:** O(n + m)
- **Worst Case:** O(n × m) (when many hash collisions occur)

Where:
- **n** = Length of the text
- **m** = Length of the pattern

## Input

- Network log (text)
- Suspicious token (pattern)

### Example Input

```
Network Log:
ABCD ABCD XYZ ABCD

Suspicious Token:
ABCD
```

## Example Output

```
Pattern Hash = 66

Position 0: Hash Match -> Verified
Position 4: Hash Match -> Verified
Position 10: Hash Match -> Verified

Total Valid Occurrences = 3
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

- Implements the Rabin-Karp string matching algorithm
- Removes spaces from the input text before searching
- Uses rolling hash for efficient pattern searching
- Detects and reports hash collisions
- Counts and displays all valid pattern occurrences
- Simple C++ implementation
