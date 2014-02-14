#include <iostream>
#include <vector>
#include <cstdlib>  // abs

using namespace std;

class Solution {
    public:
        void solve(vector<string> board, int n, int row, vector<pair<int,int> > Qs, vector<vector<string> > &solutions)
        {
            if (row == n)
            {
                solutions.push_back(board);
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

                    solve(board, n, row+1, Qs, solutions);

                    Qs.pop_back();
                    board[row][j] = '.';
                }
            }
        }

        vector<vector<string> > solveNQueens(int n)
        {
            vector<vector<string> > solutions;
            vector<string> board(n, string(n, '.'));
            vector<pair<int,int> > Qs;

            solve(board, n, 0, Qs, solutions);

            return solutions;
        }
};

int main()
{
    Solution solu;

    vector<vector<string> > solutions = solu.solveNQueens(8);

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
