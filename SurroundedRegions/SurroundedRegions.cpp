// Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
// For example,
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:
// X X X X
// X X X X
// X X X X
// X O X X

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    public:
        // TODO: DFS

        void BFS(vector<vector<char> > &board, int ii, int jj)
        {
            int m = board.size();
            int n = board[0].size();
            if (ii < 0 || ii >= m || jj < 0 || jj >= n || board[ii][jj] != 'O')
            {
                return;
            }

            board[ii][jj] = '+';        // need to mark it before pushed into the queue, essentially used as the visited flag
            queue<pair<int,int> > Q;
            Q.push(pair<int,int>(ii,jj));
            while (!Q.empty())
            {
                int i = Q.front().first;
                int j = Q.front().second;
                Q.pop();

                if (i+1 < m && board[i+1][j] == 'O')
                {
                    board[i+1][j] = '+';
                    Q.push(pair<int,int>(i+1,j));
                }
                if (i-1 >= 0 && board[i-1][j] == 'O')
                {
                    board[i-1][j] = '+';
                    Q.push(pair<int,int>(i-1,j));
                }
                if (j+1 < n && board[i][j+1] == 'O')
                {
                    board[i][j+1] = '+';
                    Q.push(pair<int,int>(i,j+1));
                }
                if (j-1 >= 0 && board[i][j-1] == 'O')
                {
                    board[i][j-1] = '+';
                    Q.push(pair<int,int>(i,j-1));
                }
            }
        }

        void solve(vector<vector<char> > &board) {
            if (board.empty() || board[0].empty())
            {
                return;
            }
            int m = board.size();
            int n = board[0].size();
            for (int i = 0; i < m; i++)
            {
                BFS(board, i, 0);
                BFS(board, i, n-1);
            }
            for (int j = 0; j < n; j++)
            {
                BFS(board, 0, j);
                BFS(board, m-1, j);
            }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] == '+')
                    {
                        board[i][j] = 'O';
                    }
                    else if (board[i][j] == 'O')
                    {
                        board[i][j] = 'X';
                    }
                }
            }
        }
};

void printMatrix(const vector<vector<char> > &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<char> > board;
    char r1[] = {'X', 'X', 'X', 'X'};
    board.push_back(vector<char>(r1, r1+4));
    char r2[] = {'X', 'O', 'O', 'X'};
    board.push_back(vector<char>(r2, r2+4));
    char r3[] = {'X', 'X', 'O', 'X'};
    board.push_back(vector<char>(r3, r3+4));
    char r4[] = {'X', 'O', 'X', 'X'};
    board.push_back(vector<char>(r4, r4+4));

    printMatrix(board);

    Solution solu;
    solu.solve(board);

    printMatrix(board);

    return 0;
}
