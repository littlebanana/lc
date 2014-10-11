// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//  The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable.
// Only the filled cells need to be validated.

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
    public:
        bool isValidSite(const vector<vector<char> > &board, int ii, int jj) {
            // check row and row
            for (int k = 0; k < 9; k++) {
                if (k != ii && board[k][jj] == board[ii][jj]) {
                    return false;
                }
                if (k != jj && board[ii][k] == board[ii][jj]) {
                    return false;
                }
            }

            // check squares
            int idx_i = ii / 3;
            int idx_j = jj / 3;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int p = 3*idx_i + i;
                    int q = 3*idx_j + j;

                    if ((p != ii || q != jj) && board[p][q] == board[ii][jj]) {
                        return false;
                    }
                }
            }

            return true;
        }

        // at worst case, O(N^4) ??
        bool isValidSudoku(vector<vector<char> > &board) {
            assert(board.size() == 9 && board[0].size() == 9);

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] != '.' && !isValidSite(board, i, j)) {
                        return false;
                    }
                }
            }

            return true;
        }

        bool isValidSudoku2(vector<vector<char> > &board) {
            assert(board.size() == 9 && board[0].size() == 9);

            char checker[9] = {0};

            // check rows
            for (int i = 0; i < 9; i++) {
                // clear table;
                for (int j = 0; j < 9; j++) {
                    checker[j] = 0;
                }

                for (int j = 0; j < 9; j++) {
                    if (board[i][j] != '.') {
                        char c = board[i][j];
                        if (checker[c-'1'] != 0) {
                            return false;
                        } else {
                            checker[c-'1'] = 1;
                        }
                    }
                }
            }

            // check columns
            for (int j = 0; j < 9; j++) {
                // clear table;
                for (int i = 0; i < 9; i++) {
                    checker[i] = 0;
                }

                for (int i = 0; i < 9; i++) {
                    if (board[i][j] != '.') {
                        char c = board[i][j];
                        if (checker[c-'1'] != 0) {
                            return false;
                        } else {
                            checker[c-'1'] = 1;
                        }
                    }
                }
            }

            // check squares
            for (int i = 0; i < 9; i += 3) {
                for (int j = 0; j < 9; j += 3) {
                    for (int k = 0; k < 9; k++) {
                        checker[k] = 0;
                    }

                    for (int p = 0; p < 3; p++) {
                        for (int q = 0; q < 3; q++) {
                            if (board[i+p][j+q] != '.') {
                                char c = board[i+p][j+q];
                                if (checker[c-'1'] != 0) {
                                    return false;
                                } else {
                                    checker[c-'1'] = 1;
                                }
                            }
                        }
                    }
                }
            }

            return true;
        }
};

int main() {
    vector<vector<char> > board(9);
    char row1[] = {'.', '.', '.', '.', '.', '.', '.', '.', '1'};
    board[0].assign(row1, row1+9);
    char row2[] = {'.', '.', '.', '.', '.', '.', '.', '.', '2'};
    board[1].assign(row2, row2+9);
    char row3[] = {'.', '.', '.', '.', '.', '.', '.', '.', '3'};
    board[2].assign(row3, row3+9);
    char row4[] = {'.', '.', '.', '.', '.', '.', '.', '.', '4'};
    board[3].assign(row4, row4+9);
    char row5[] = {'.', '.', '.', '.', '.', '.', '.', '.', '5'};
    board[4].assign(row5, row5+9);
    char row6[] = {'.', '.', '.', '.', '.', '.', '.', '.', '6'};
    board[5].assign(row6, row6+9);
    char row7[] = {'.', '.', '.', '.', '.', '.', '.', '.', '7'};
    board[6].assign(row7, row7+9);
    char row8[] = {'.', '.', '.', '.', '.', '.', '.', '.', '8'};
    board[7].assign(row8, row8+9);
    char row9[] = {'.', '.', '.', '.', '.', '.', '.', '.', '9'};
    board[8].assign(row9, row9+9);

    Solution solu;
    cout << solu.isValidSudoku(board) << endl;

    return 0;
}
