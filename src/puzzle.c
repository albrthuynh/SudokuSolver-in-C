#include "sudoku.h"

Sudoku * createSudoku(Square *** squares, Box ** boxes) {
  Sudoku * sudoku;
  sudoku = malloc(sizeof(Sudoku));

  sudoku->squares = squares;
  sudoku->boxes = boxes;

  return sudoku;
}

int updateSudoku(Square *** sudoku, int row, int col) {
  int x;
  int number = sudoku[row][col]->number;

  for (x = 0; x < SIZE_ROWS; x++) {
    if (sudoku[x][col]->possible[number - 1] == 0) {
      sudoku[x][col]->solvable -= 1;
    }
    sudoku[x][col]->possible[number - 1] = 1;
  }
  
  for (x = 0; x < SIZE_COLUMNS; x++) {
    if (sudoku[row][x]->possible[number - 1] == 0) {
      sudoku[row][x]->solvable -= 1;
    }
    sudoku[row][x]->possible[number - 1] = 1;
  } 
  return 1;
}

Sudoku * setUpPuzzle(int ** puzzle) {
  Square *** sudoku;
  Box ** boxes;
  int i, j;
  int currBox = 0;
  
  sudoku = malloc(sizeof(Square**)*9);
  boxes = createBoxes();

  // loop through rows
  for (int i = 0; i < SIZE_ROWS; i++) {
    sudoku[i] = malloc(sizeof(Square*)*9);
  
    // loop through columns
    for(int j = 0; j < SIZE_COLUMNS; j++) {
      // malloc space for each square
      sudoku[i][j] = malloc(sizeof(Square)*9);
      
      // assign number to sudoku puzzle
      sudoku[i][j]->number = puzzle[i][j];
      
      // assign row and column numbers to each square
      sudoku[i][j]->row = i;
      sudoku[i][j]->column = j;
      sudoku[i][j]->solvable = 9;

      boxes[currBox]->squares[boxes[currBox]->numbers] = sudoku[i][j];
      sudoku[i][j]->box = boxes[currBox];
      boxes[currBox]->numbers += 1;


      for (int x = 0; x < SIZE_ROWS; x++) {
        sudoku[i][j]->possible[x] = 0; // initializes the possible array to 0
      }

      // check if we are still in the current box
      if (j == 2) {
        currBox += 1;
      }
      if (j == 5) {
        currBox += 1;
      }
    }

    currBox -= 2;
    // changing the box to the next row if it gets to the end
    if (i == 2) {
      currBox = 3;
    }
    if (i == 5) {
      currBox = 6;
    }
  }

  // loop through the rows again
  for (i = 0; i < SIZE_ROWS; i++) {
    // loop through the columns again
    for (j = 0; j < SIZE_COLUMNS; j++) {
      if (sudoku[i][j]->number != 0) { // if it has a number
        sudoku[i][j]->solvable = 0; // set solvable to 0 since it has a number
        updateSudoku(sudoku, i, j);
        updateBoxes(sudoku, i, j);
        UNSOLVED--;
      } 
    }
  }
  return createSudoku(sudoku, boxes);
}



int checkPuzzle(Square *** sudoku, Box ** boxes) {
  int i, j, x;

  // loop through the rows
  for (i = 0; i < SIZE_ROWS; i++) {
    for (j = 0; j < SIZE_COLUMNS; j++) {
      if (sudoku[i][j]->solvable == 1) {
        solveSquare(sudoku[i][j]); 
        updateSudoku(sudoku, i, j);
        updateBoxes(sudoku, i, j);

        return 1;
      }
    }
  }

  if (boxSingles(sudoku, boxes)) {
    return 1;
  }

  return checkRows(sudoku, boxes);
}

int ** createPuzzle() {
  int ** puzzle; 
  int i, j;
  int array[9][9] = {0, 1, 9,       0, 0, 2,       0, 0, 0,
                     4, 7, 0,       6, 9, 0,       0, 0, 1,
                     0, 0, 0,       4, 0, 0,       0, 9, 0,

                     8, 9, 4,       5, 0, 7,       0, 0, 0,
                     0, 0, 0,       0, 0, 0,       0, 0, 0,
                     0, 0, 0,       2, 0, 1,       9, 5, 8,

                     0, 5, 0,       0, 0, 6,       0, 0, 0,
                     6, 0, 0,       0, 2, 8,       0, 7, 9,
                     0, 0, 0,       1, 0, 0,       8, 6, 0};


  puzzle = (int**)malloc(sizeof(int*) * 9); // created 9 arrays
  
  for (i = 0; i < SIZE_ROWS; i++) {
    puzzle[i] = (int*)malloc(sizeof(int)*9);

    for (j = 0; j < SIZE_COLUMNS; j++) {
      puzzle[i][j] = array[i][j];
    }
  }

  return puzzle;
}


void printPuzzle(Square *** puzzle) {
  printf("--------------------------------\n");
  for (int i = 0; i < SIZE_ROWS; i++) {
    printf("|");
    for(int j = 0; j < SIZE_COLUMNS; j++) {
      printf(" %d ", puzzle[i][j]->number);

      if ( (j + 1) % 3 == 0) {
         printf("|");
      }
    }
    printf("\n");
    if ((i + 1) % 3 == 0) {
      printf("--------------------------------\n");
    }
  }
}
