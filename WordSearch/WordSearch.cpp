// Given a 2D board and a word, find if the word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.
// The same letter cell may not be used more than once.
// For example,
// Given board =
// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool DFS(const vector<vector<char> > &board, const string &word, int left, int ii, int jj, vector<vector<bool> > &visited)
        {
            int l = word.length();
            if (left == l)
            {
                return true;
            }
            int m = board.size();
            int n = board[0].size();
            if (ii < 0 || ii >= m || jj < 0 || jj >= n || visited[ii][jj] || word[left] != board[ii][jj])
            {
                return false;
            }

            visited[ii][jj] = true;
            bool find = (DFS(board, word, left+1, ii+1, jj, visited) || DFS(board, word, left+1, ii-1, jj, visited)
                    || DFS(board, word, left+1, ii, jj+1, visited) || DFS(board, word, left+1, ii, jj-1, visited));
            visited[ii][jj] = false;
            return find;
        }

        bool exist(vector<vector<char> > &board, string word) {
            if (board.empty() || board[0].empty())
            {
                return false;
            }
            int m = board.size();
            int n = board[0].size();
            vector<vector<bool> > visited(m, vector<bool>(n,false));
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (DFS(board, word, 0, i, j, visited))
                    {
                        return true;
                    }
                }
            }
            return false;
        }
};

int main()
{
    vector<vector<char> > board(3, vector<char>(4));
    board[0][0] = 'A';
    board[0][1] = 'B';
    board[0][2] = 'C';
    board[0][3] = 'E';
    board[1][0] = 'S';
    board[1][1] = 'F';
    board[1][2] = 'C';
    board[1][3] = 'S';
    board[2][0] = 'A';
    board[2][1] = 'D';
    board[2][2] = 'E';
    board[2][3] = 'E';

    Solution solu;
    cout << (solu.exist(board, "ABCCED") ? "true" : "false") << endl;
    cout << (solu.exist(board, "ABCB") ? "true" : "false") << endl;

    return 0;
}
