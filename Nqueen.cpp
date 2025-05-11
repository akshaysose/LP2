#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;

    // Function to check if placing a queen at (row, col) is valid
    bool isValid(vector<string>& board, int row, int col) {
        // Look upwards
        for (int i = row; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check left diagonal upwards
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check right diagonal upwards
        for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    // Function to solve the N-Queens problem using backtracking
    void solve(vector<string>& board, int row) {
        if (row == board.size()) {
            result.push_back(board);
            return;
        }

        for (int i = 0; i < board.size(); i++) {
            if (isValid(board, row, i)) {
                board[row][i] = 'Q';      // Place queen
                solve(board, row + 1);    // Recurse for next row
                board[row][i] = '.';      // Backtrack
            }
        }
    }

    // Function to solve N-Queens problem and return all solutions
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        if (n == 0)
            return {};
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        return result;
    }
};

int main() {
    int n;
    cout << "Enter the value of n for N-Queens problem: ";
    cin >> n;

    Solution obj;
    vector<vector<string>> result = obj.solveNQueens(n);

    cout << "Possible solutions for " << n << "-Queens problem are:\n";
    for (const auto& board : result) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl; // To separate each solution
    }

    return 0;
}
