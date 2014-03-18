// Write a program to solve a Sudoku puzzle by filling the empty cells.
// Empty cells are indicated by the character '.'.
// You may assume that there will be only one unique solution. 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isValidSite(const vector<vector<char> > &board, int ii, int jj)
        {
            // board[ii][jj] is filled with a number

            // check rows and columns
            for (int k = 0; k < 9; k++)
            {
                if (k != ii && board[k][jj] == board[ii][jj])
                {
                    return false;
                }
                if (k != jj && board[ii][k] == board[ii][jj])
                {
                    return false;
                }
            }

            // check squares
            int ci = ii / 3;
            int cj = jj / 3;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    int p = ci*3 + i;
                    int q = cj*3 + j;
                    if ((p != ii || q != jj) && board[p][q] == board[ii][jj])
                    {
                        return false;
                    }
                }
            }

            return true;
        }

        bool solve(vector<vector<char> > &board, int ii, int jj)
        {
            for (int k = 0; k < 9; k++)
            {
                // try one number
                board[ii][jj] = k + '1';

                // go deeper and see if the overall board is valid
                if (isValidSite(board, ii, jj))
                {
                    bool ok = true;
                    for (int i = 0; i < 9; i++)
                    {
                        for (int j = 0; j < 9; j++)
                        {
                            if (board[i][j] == '.')
                            {
                                ok = solve(board, i, j);
                                if (!ok)
                                {
                                    break;
                                }
                            }
                        }
                        if (!ok)
                        {
                            break;
                        }
                    }
                    if (ok)
                    {
                        return true;
                    }
                }

                // reset board[ii][jj] for next try
                board[ii][jj] = '.';
            }
            return false;
        }

        void solveSudoku(vector<vector<char> > &board) {
            bool ok = true;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (board[i][j] == '.')
                    {
                        ok = solve(board, i, j);
                    }
                }
            }
        }
};

void printSudoku(const vector<vector<char> > &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<char> > board(9);
    char row1[] = {'5', '3', '.', '.', '7', '.', '.', '.', '.'};
    board[0].assign(row1, row1+9);
    char row2[] = {'6', '.', '.', '1', '9', '5', '.', '.', '.'};
    board[1].assign(row2, row2+9);
    char row3[] = {'.', '9', '8', '.', '.', '.', '.', '6', '.'};
    board[2].assign(row3, row3+9);
    char row4[] = {'8', '.', '.', '.', '6', '.', '.', '.', '3'};
    board[3].assign(row4, row4+9);
    char row5[] = {'4', '.', '.', '8', '.', '3', '.', '.', '1'};
    board[4].assign(row5, row5+9);
    char row6[] = {'7', '.', '.', '.', '2', '.', '.', '.', '6'};
    board[5].assign(row6, row6+9);
    char row7[] = {'.', '6', '.', '.', '.', '.', '2', '8', '.'};
    board[6].assign(row7, row7+9);
    char row8[] = {'.', '.', '.', '4', '1', '9', '.', '.', '5'};
    board[7].assign(row8, row8+9);
    char row9[] = {'.', '.', '.', '.', '8', '.', '.', '7', '9'};
    board[8].assign(row9, row9+9);

    printSudoku(board);

    Solution solu;
    solu.solveSudoku(board);

    printSudoku(board);

    return 0;
}
