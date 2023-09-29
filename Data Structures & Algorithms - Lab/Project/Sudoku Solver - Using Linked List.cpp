// Purpose: Solves a Sudoku puzzle using linked lists


#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Node structure for each cell of the Sudoku grid
struct Node 
{
    int data;
    Node* next;
};

// Sudoku grid class
class SudokuGrid 
{
private:
    Node* grid[9][9]; // 9x9 grid of linked list nodes 
    // this is a 2D array of pointers to nodes

public:
    SudokuGrid() 
    {
        // Initialize the grid with empty cells
        for (int i = 0; i < 9; i++) 
            for (int j = 0; j < 9; j++) 
                grid[i][j] = createNode(0);
    }

    // Function to create a new linked list node
    Node* createNode(int data) 
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        return newNode;
    }

    // Function to insert a value into the grid at the specified row and column
    void insertValue(int row, int col, int value) 
    {
        if (row >= 0 && row < 9 && col >= 0 && col < 9) 
            grid[row][col]->data = value;
    }

    // Function to get the value at the specified row and column
    int getValue(int row, int col) 
    {
        if (row >= 0 && row < 9 && col >= 0 && col < 9)
            return grid[row][col]->data;

        return -1;
    }

    // Function to display the Sudoku grid
    void displayGrid() 
    {
        for (int i = 0; i < 9; i++) 
        {
            if (i % 3 == 0 && i != 0)
                cout << "---------------------" << endl;
         
            for (int j = 0; j < 9; j++) 
            {
                if (j % 3 == 0 && j != 0)
                    cout << "| ";
                cout << grid[i][j]->data << " ";
            }
            cout << endl;
        }
    }

    // Function to check if a value can be placed in a particular cell
    bool isSafe(int row, int col, int value) 
    {
        // Check if the value already exists in the current row
        for (int i = 0; i < 9; i++)
            if (grid[row][i]->data == value)
                return false;
       

        // Check if the value already exists in the current column
        for (int i = 0; i < 9; i++)
            if (grid[i][col]->data == value)
                return false;

        // Check if the value already exists in the current 3x3 box
        int startRow = row - row % 3;
        int startCol = col - col % 3;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (grid[startRow + i][startCol + j]->data == value)
                    return false;

        // If the value doesn't violate any constraints, it's safe to place
        return true;
    }

    // Function to solve the Sudoku grid using backtracking
    bool solveSudoku() 
    {
        int row, col;

        // If there are no empty cells, the Sudoku is solved
        if (!findEmptyCell(row, col))
            return true;

        // Try assigning numbers from 1 to 9
        for (int num = 1; num <= 9; num++) 
        {
            if (isSafe(row, col, num)) 
            {
                // Assign the number to the current cell
                grid[row][col]->data = num;

                // Recursively solve for the next cell
                if (solveSudoku())
                    return true;

                // If the assignment doesn't lead to a solution, backtrack and try a different number
                grid[row][col]->data = 0;
            }
        }

        // If no number can be assigned to the current cell, backtrack
        return false;
    }

    // Function to find the next empty cell in the Sudoku grid
    bool findEmptyCell(int& row, int& col) 
    {
        for (row = 0; row < 9; row++)
            for (col = 0; col < 9; col++)
                if (grid[row][col]->data == 0)
                    return true;
  
        return false;
    }
};

// Function to validate user input
bool validateInput(int row, int col, int value) 
{
    if (row >= 0 && row < 9 && col >= 0 && col < 9 && value >= 0 && value <= 9)
        return true;

    return false;
}

// Function to convert a string to an integer
int stringToInt(const string& str) 
{
    stringstream ss(str);
    int num;
    ss >> num;
    return num;
}

// Function to check if a string contains only digits
bool isStringDigits(const string& str)
{
    for (char ch : str)
        if (!isdigit(ch))
            return false;

    return true;
}

// Function to input the Sudoku grid from the user
void inputGrid(SudokuGrid& sudoku) 
{
    cout << "Enter the Sudoku grid (Enter 0 for empty cells):" << endl;
    for (int i = 0; i < 9; i++)  // Iterate over each row
    {
        cout << "Row " << i + 1 << ":" << endl;
        for (int j = 0; j < 9; j++) // Iterate over each column
        {
            int row, col, value;
            string input;
            cout << "(" << i << "," << j << ") : ";
            cin >> input;

            if (!isStringDigits(input))  // Check if the input contains only digits
            {
                cout << "Invalid input! Please enter a number between 0 and 9." << endl;
                j--;
                continue;
            }

            try  // Convert the string to an integer
            {
                value = stringToInt(input);
            }
            catch (...)  // Catch any exceptions that may occur
            {
                cout << "Invalid input! Please enter a number between 0 and 9." << endl;
                j--;
                continue;
            }

            if (!validateInput(i, j, value))  // Validate the input
            {
                cout << "Invalid input! Please enter a number between 0 and 9." << endl;
                j--;
                continue;
            }
            sudoku.insertValue(i, j, value);  // Insert the value into the grid
        }
    }
}


int main() 
{
    SudokuGrid sudoku;

    // Input the Sudoku grid from the user
    inputGrid(sudoku);

    // Display the input Sudoku grid
    cout << "\n\nInput Sudoku grid:\n" << endl;
    sudoku.displayGrid();

    // Solve the Sudoku grid
    if (sudoku.solveSudoku()) 
    {
        cout << "\n\nSudoku solved successfully!" << endl;
        cout << "\nSolution:\n" << endl;
        sudoku.displayGrid();
    }
    else 
       cout << "\nNo solution exists for the given Sudoku." << endl;

    return 0;
}