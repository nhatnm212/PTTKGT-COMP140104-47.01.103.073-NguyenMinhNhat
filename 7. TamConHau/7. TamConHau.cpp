#include <iostream>
#include <cmath>

using namespace std;

int board[8];

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solve(int row) {
    if (row == 8) {
        // Print the solution
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i] == j) {
                    cout << " Q ";
                } else {
                    cout << " - ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < 8; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row+1);
            board[row] = 0;
        }
    }
}

int main() {
    solve(0);
    return 0;
}

