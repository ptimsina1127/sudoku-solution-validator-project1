# sudoku-solution-validator-project1

This C++ program checks the validity of a given Sudoku solution by examining the rows, columns, and subgrids.

## Sudoku Rules

A standard Sudoku puzzle must satisfy the following conditions:
1. Each row must contain the numbers 1 through 9 with no repetition.
2. Each column must contain the numbers 1 through 9 with no repetition.
3. Each of the nine 3x3 subgrids must contain the numbers 1 through 9 with no repetition.

## Code Structure

The code consists of the following functions:

### `column_check`
bool column_check(int array[][9]);

This function checks for duplicate values in each column.
### `row_check`
bool row_check(int array[][9]);
This function checks for duplicate values in each row.

### `subgrid_check`
bool subgrid_check(int array[][9]);
This function checks for duplicate values in each 3x3 subgrid.

### `main`
The main function initializes a sample Sudoku puzzle and spawns three threads to concurrently check columns, rows, and subgrids. The results are then combined to determine the overall validity of the Sudoku solution.

### `Sample Sudoku`
int sudoku[9][9] = {
    
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
};
### `How to Run`
Compile and run the program using your preferred C++ compiler. The program will output whether the given Sudoku solution is valid or invalid.

$ g++ sudoku_validator.cpp -o sudoku_validator

$ ./sudoku_validator

### `Output`
The program will print either "The sudoku is Valid" or "The sudoku is Invalid" based on the validity check results.
Feel free to modify and adapt the code as needed for your use case.
