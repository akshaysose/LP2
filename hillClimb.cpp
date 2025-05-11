#include <bits/stdc++.h>
using namespace std;

const int SIZE = 9;
typedef vector<vector<int>> Board;

bool isFixed[SIZE][SIZE]; // To mark pre-filled cells

// Print the Sudoku board
void printBoard(const Board &board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

// Count the number of conflicts in rows and columns
int calculateConflicts(const Board &board) {
    int conflicts = 0;

    // Row conflicts
    for (int i = 0; i < SIZE; ++i) {
        vector<int> count(10, 0);
        for (int j = 0; j < SIZE; ++j)
            count[board[i][j]]++;
        for (int k = 1; k <= 9; ++k)
            if (count[k] > 1)
                conflicts += count[k] - 1;
    }

    // Column conflicts
    for (int j = 0; j < SIZE; ++j) {
        vector<int> count(10, 0);
        for (int i = 0; i < SIZE; ++i)
            count[board[i][j]]++;
        for (int k = 1; k <= 9; ++k)
            if (count[k] > 1)
                conflicts += count[k] - 1;
    }

    return conflicts;
}

// Fill each 3x3 box with random values for empty cells
void fillBoard(Board &board) {
    random_device rd;
    mt19937 g(rd());

    for (int boxRow = 0; boxRow < 3; ++boxRow) {
        for (int boxCol = 0; boxCol < 3; ++boxCol) {
            vector<int> nums;
            for (int i = 1; i <= 9; ++i)
                nums.push_back(i);

            // Remove already fixed values from the nums
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int r = boxRow * 3 + i;
                    int c = boxCol * 3 + j;
                    if (isFixed[r][c]) {
                        nums.erase(remove(nums.begin(), nums.end(), board[r][c]), nums.end());
                    }
                }
            }

            shuffle(nums.begin(), nums.end(), g);

            int idx = 0;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int r = boxRow * 3 + i;
                    int c = boxCol * 3 + j;
                    if (!isFixed[r][c]) {
                        board[r][c] = nums[idx++];
                    }
                }
            }
        }
    }
}

// Try swapping 2 non-fixed cells in a box and keep swap if it improves
bool swapInBox(Board &board, int boxRow, int boxCol) {
    vector<pair<int, int>> cells;

    // Get all non-fixed cells in the box
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int r = boxRow * 3 + i;
            int c = boxCol * 3 + j;
            if (!isFixed[r][c])
                cells.push_back({r, c});
        }
    }

    int currentConflicts = calculateConflicts(board);

    for (int i = 0; i < cells.size(); ++i) {
        for (int j = i + 1; j < cells.size(); ++j) {
            swap(board[cells[i].first][cells[i].second], board[cells[j].first][cells[j].second]);

            int newConflicts = calculateConflicts(board);
            if (newConflicts < currentConflicts)
                return true; // Kept the better swap
            else
                swap(board[cells[i].first][cells[i].second], board[cells[j].first][cells[j].second]); // Undo
        }
    }

    return false; // No improvement
}

// Hill Climbing algorithm
void hillClimb(Board &board, int maxSteps = 10000) {
    for (int step = 0; step < maxSteps; ++step) {
        bool improved = false;

        for (int boxRow = 0; boxRow < 3; ++boxRow) {
            for (int boxCol = 0; boxCol < 3; ++boxCol) {
                if (swapInBox(board, boxRow, boxCol))
                    improved = true;
            }
        }

        if (!improved)
            break;
    }
}

// Sample puzzle (0 = empty)
Board puzzle = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

int main() {
    Board board = puzzle;

    // Mark fixed cells
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            isFixed[i][j] = (puzzle[i][j] != 0);

    fillBoard(board); // Fill empty cells with random values per 3x3 box

    cout << "Initial Board with Filled Cells:\n";
    printBoard(board);

    hillClimb(board); // Run hill climbing optimization

    cout << "\nSolved Board (or local minimum):\n";
    printBoard(board);

    cout << "\nFinal Heuristic (Conflicts): " << calculateConflicts(board) << endl;

    return 0;
}
