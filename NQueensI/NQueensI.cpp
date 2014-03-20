// The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
// For example,
// There exist two distinct solutions to the 4-queens puzzle:
//[
// [".Q..",  // Solution 1
//  "...Q",
//  "Q...",
//  "..Q."],
// ["..Q.",  // Solution 2
//  "Q...",
//  "...Q",
//  ".Q.."]
//]

#include <iostream>
#include <vector>
#include <cstdlib>  // abs

using namespace std;

class Solution {
    public:
        void solve1(vector<string> board, int n, int row, vector<pair<int,int> > Qs, vector<vector<string> > &solutions)
        {
            if (row == n)
            {
                solutions.push_back(board);
                return;
            }

            int K = Qs.size();
            for (int j = 0; j < n; j++)
            {
                bool jpass = false;
                for (int k = 0; k < K; k++)
                {
                    if (j == Qs[k].second || abs(Qs[k].first-row) == abs(Qs[k].second-j))
                    {
                        jpass = true;
                        break;
                    }
                }
                if (!jpass && board[row][j] == '.')
                {
                    board[row][j] = 'Q';
                    Qs.push_back(pair<int,int>(row,j));

                    solve1(board, n, row+1, Qs, solutions);

                    Qs.pop_back();
                    board[row][j] = '.';
                }
            }
        }

        vector<vector<string> > solveNQueens1(int n)
        {
            vector<vector<string> > solutions;
            vector<string> board(n, string(n, '.'));
            vector<pair<int,int> > Qs;

            solve1(board, n, 0, Qs, solutions);

            return solutions;
        }

        bool isValidSite(const vector<string> &board, int ii, int jj)
        {
            // skip row check, gauranteed before the function all

            int n = board.size();

            // column check
            for (int i = 0; i < n; i++)
            {
                if (i != ii && board[i][jj] == 'Q')
                {
                    return false;
                }
            }

            // diagonal check
            int p = ii-1;
            int q = jj-1;
            while (p >= 0 && q >= 0)
            {
                if (board[p][q] == 'Q')
                {
                    return false;
                }
                p--;
                q--;
            }
            p = ii+1;
            q = jj-1;
            while (p < n && q >= 0)
            {
                if (board[p][q] == 'Q')
                {
                    return false;
                }
                p++;
                q--;
            }
            p = ii-1;
            q = jj+1;
            while (p >= 0 && q < n)
            {
                if (board[p][q] == 'Q')
                {
                    return false;
                }
                p--;
                q++;
            }
            p = ii+1;
            q = jj+1;
            while (p < n && q < n)
            {
                if (board[p][q] == 'Q')
                {
                    return false;
                }
                p++;
                q++;
            }
            return true;
        }

        void solve2(vector<string> &board, int row, vector<vector<string> > &solu)
        {
            int n = board.size();
            if (row == n)
            {
                solu.push_back(board);
                return;
            }

            // place one queen and solve the left recursively
            for (int j = 0; j < n; j++)
            {
                if (board[row][j] == '.' && isValidSite(board, row, j))
                {
                    board[row][j] = 'Q';
                    solve2(board, row+1, solu);
                    board[row][j] = '.';
                }
            }
        }

        vector<vector<string> > solveNQueens2(int n) {
            vector<string> board(n, string(n, '.'));
            vector<vector<string> > solu;
            solve2(board, 0, solu);
            return solu;
        }
};

int main()
{
    Solution solu;

    vector<vector<string> > solutions = solu.solveNQueens2(4);

    for (int i = 0; i < solutions.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < solutions[0].size(); j++)
        {
            if (j != 0)
            {
                cout << " ";
            }
            cout << solutions[i][j];
            if (j == solutions[0].size()-1)
            {
                cout << "]";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
