// Follow up for N-Queens problem.
// Now, instead outputting board configurations, return the total number of distinct solutions.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    public:
        bool isValidSite(const vector<string> &board, int ii, int jj) {
            // skip row check, gauranteed before the function all

            int n = board.size();

            // column check
            for (int i = 0; i < n; i++) {
                if (i != ii && board[i][jj] == 'Q') {
                    return false;
                }
            }

            // diagonal check
            int p = ii-1;
            int q = jj-1;
            while (p >= 0 && q >= 0) {
                if (board[p][q] == 'Q') {
                    return false;
                }
                p--;
                q--;
            }
            p = ii+1;
            q = jj-1;
            while (p < n && q >= 0) {
                if (board[p][q] == 'Q') {
                    return false;
                }
                p++;
                q--;
            }
            p = ii-1;
            q = jj+1;
            while (p >= 0 && q < n) {
                if (board[p][q] == 'Q') {
                    return false;
                }
                p--;
                q++;
            }
            p = ii+1;
            q = jj+1;
            while (p < n && q < n) {
                if (board[p][q] == 'Q') {
                    return false;
                }
                p++;
                q++;
            }
            return true;
        }

        void solve(vector<string> &board, int row, int &cnt) {
            int n = board.size();
            if (row == n) {
                cnt++;
                return;
            }

            // place one queen and solve the left recursively
            for (int j = 0; j < n; j++) {
                if (board[row][j] == '.' && isValidSite(board, row, j)) {
                    board[row][j] = 'Q';
                    solve(board, row+1, cnt);
                    board[row][j] = '.';
                }
            }
        }

        int totalNQueens(int n) {
            vector<string> board(n, string(n, '.'));
            int cnt = 0;
            solve(board, 0, cnt);
            return cnt;
        }

        bool check2(const vector<int> &tab, int r, int c) {
            int n = tab.size();
            for (int i = 0; i < n; i++) {
                if (tab[i] != -1 && abs(i - r) == abs(tab[i] - c)) {
                    return false;
                }
            }
            return true;
        }

        void solve2(const int n, int c, vector<int> &tab, int &sol) {
            if (c == n) {
                sol++;
            } else {
                for (int r = 0; r < n; r++) {
                    if (tab[r] == -1 && check2(tab, r, c)) {
                        tab[r] = c;
                        solve2(n, c + 1, tab, sol);
                        tab[r] = -1;
                    }
                }
            }
        }

        int totalNQueens2(int n) {
            // tab[i] = column index of the Queen at i-th row, -1 if no Queen
            vector<int> tab(n, -1);
            int sol = 0;
            solve2(n, 0, tab, sol);
            return sol;
        }
};

int main()
{
    Solution solu;

    int cnt = solu.totalNQueens(4);
    cout << cnt << endl;

    return 0;
}
