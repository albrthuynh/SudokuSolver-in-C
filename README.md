# Sudoku Solver in C

A command-line Sudoku solver implemented in C that uses constraint propagation techniques to solve 9x9 Sudoku puzzles.

## Features

- Solves Sudoku puzzles using constraint propagation algorithms
- Implements multiple solving strategies:
  - Single candidate elimination (naked singles)
  - Box constraint checking (hidden singles in boxes)
  - Row constraint checking (hidden singles in rows)
- Clean, modular C code with proper data structures
- Memory-efficient implementation with dynamic allocation

## Building

To build the project, use the included Makefile:

```bash
make
```

This will compile the solver and run it automatically.

To compile only:

```bash
make sudoku
```

To clean up compiled files:

```bash
make clean
```

## Usage

Run the compiled executable:

```bash
./sudoku
```

The solver will display the initial puzzle, attempt to solve it, and then display the solved puzzle (or indicate if it couldn't be solved).

## Algorithm

The solver uses a constraint propagation approach:

1. **Initialization**: Sets up the puzzle structure with boxes, rows, and columns
2. **Constraint Propagation**: Updates possible values based on existing numbers
3. **Iterative Solving**: Repeatedly applies solving techniques:
   - Finds squares with only one possible value
   - Identifies hidden singles in boxes
   - Identifies hidden singles in rows
4. **Termination**: Stops when the puzzle is solved or no further progress can be made

## Project Structure

```
├── src/
│   ├── box.c       # Box constraint logic
│   ├── puzzle.c    # Main puzzle setup and solving logic
│   ├── row.c       # Row constraint checking
│   ├── square.c    # Square solving logic
│   └── sudoku.c    # Main entry point
├── include/
│   └── sudoku.h    # Header file with data structures and function declarations
└── makefile        # Build configuration
```

## Data Structures

- `Square`: Represents a single cell in the puzzle with its value, possible values, and constraints
- `Box`: Represents a 3x3 box in the Sudoku grid
- `Sudoku`: Main puzzle structure containing squares and boxes

## Requirements

- GCC compiler
- Make utility
- Standard C library

## License

This project is open source and available for educational purposes.

