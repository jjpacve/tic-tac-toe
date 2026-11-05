# Tic-Tac-Toe

A console Tic-Tac-Toe game in C++. You play as X against a computer
that uses the Minimax algorithm, so it never loses.

## Technologies

- C++
- Standard library only (`iostream`)

## Rules

- The board has 9 cells, numbered from 1 to 9:

```
 1 | 2 | 3
----------
 4 | 5 | 6
----------
 7 | 8 | 9
```

- You play X and move first. The computer plays O.
- The first to get three in a row (horizontally, vertically or
  diagonally) wins.
- If all cells are filled and nobody has three in a row, it's a draw.

## How to run

### macOS

```bash
clang++ -std=c++11 main.cpp -o tic_tac_toe
./tic_tac_toe
```

### Windows (MinGW)

```bash
g++ -std=c++11 main.cpp -o tic_tac_toe.exe
tic_tac_toe.exe
```

## How the computer plays

The computer uses Minimax. For each free cell, it tries the move,
simulates all possible replies until the end of the game, and scores
the result:

| Result        | Score |
|---------------|-------|
| Computer wins | +1    |
| Draw          | 0     |
| Player wins   | -1    |

The computer picks the move with the highest score, assuming the
player always answers with their best move. A perfect player can
only get a draw.

## Invalid input

The game asks again instead of crashing:

| Input         | Result                      |
|---------------|-----------------------------|
| `0`, `10`     | `Enter a number from 1 to 9` |
| `abc`         | `Enter a number from 1 to 9` |
| Occupied cell | `The cell is occupied`       |
