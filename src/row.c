#include "sudoku.h"

int checkRows(Square *** sudoku, Box ** boxes) {
  int i, j, k;

  int sum[9]; // keep an array of sums to keep track of the number for each number
  int place[9];

  // loop through all rows
  for (i = 0; i < 9; i++) {
    // initialize sum and place to 0
    for (j = 0; j < 9; j++) {
      place[j] = 0;
      sum[j] = 0;
    }
    // loop through each square in the row
    for (j = 0; j < 9; j++) {
      if (sudoku[i][j]->number != 0) {
        continue; // if there is already a value then skip
      }

      // loop through all possibles
      for (k = 0; k < 9; k++) {
        // check if number k is possible
        if (sudoku[i][j]->possible[k] == 0) {
          sum[k] += 1;
          place[k] = j;
        }
      }
    }

    for (k = 0; k < 9; k++) {
      if (sum[k] == 1) {
        sudoku[i][place[k]]->number = k + 1;
        sudoku[i][place[k]]->solvable = 0;
        UNSOLVED--;

        updateSudoku(sudoku, i, place[k]);
        updateBoxes(sudoku, i, place[k]);
        return 1;
      }
    }
  }
  return 0;
}
