#include "sudoku.h"

char UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main() {
  int ** puzzle;
  int progress = 0;
  Sudoku * sudoku;

  puzzle = createPuzzle();

  sudoku = setUpPuzzle(puzzle); // Returns an array of an array of pointers
  
  printPuzzle(sudoku->squares); // printing the puzzle
  while (UNSOLVED > 0) {
    progress = checkPuzzle(sudoku->squares, sudoku->boxes); // checks the puzzle
    
    if (progress == 0) {
      printf("\nFailed to solve the puzzle\n\n");
      break;
    }
  }

  printf("\n\n");
  
  printPuzzle(sudoku->squares);
  return 0;
}
