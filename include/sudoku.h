#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern char UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;

typedef struct Sudoku {
  struct Square *** squares;
  struct Box ** boxes;
} Sudoku;

typedef struct Box {
  struct Square ** squares;
  int numbers;
  int possible[9];
  int solvable;
  struct Box * next;  
} Box;

typedef struct Square {
  int number;
  /* [1] [1] [1] [1] [1] [1] [1] [1] [1] -- 
   * [9] [8] [7] [6] [5] [4] [3] [2] [1]-- 9 Digit Array to Represent the number which exists (index) */ 
  char possible[9]; 
  int solvable;
  Box * box;
  int row;
  int column;
} Square;

int updateSudoku(Square *** sudoku, int row, int column);
int solveSquare(Square * square);
int checkPuzzle(Square *** sudoku, Box ** boxes);
int ** createPuzzle();
void printPuzzle(Square *** puzzle);
Sudoku * setUpPuzzle(int ** puzzle);

Sudoku * createSudoku(Square *** puzzle, Box ** boxes);

// box functions
Box ** createBoxes();
int updateBoxes(Square *** sudoku, int row, int col);
int boxSingles(Square *** sudoku, Box ** boxes);

int checkRows(Square *** sudoku, Box ** boxes);

#endif
