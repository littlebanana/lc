#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    public:
        int maximalRectangleUnderHistorgram(vector<int> histogram)
        {
            if (histogram.empty())
            {
                return 0;
            }
            int L = histogram.size();
            if (L == 1)
            {
                return histogram[0];
            }

            int maxarea = histogram[0];
            stack<int> stk;
            histogram.push_back(0);
            for (int i = 0; i < L+1; i++)
            {
                if (stk.empty() || histogram[stk.top()] <= histogram[i])
                {
                    stk.push(i);
                }
                else
                {
                    int h = histogram[stk.top()];
                    stk.pop();
                    int thisarea = h * ((stk.empty()) ? i : (i-(stk.top()+1)));
                    maxarea = max(thisarea, maxarea);
                    i--;
                }
            }
            histogram.pop_back();
            return maxarea;
        }

        int maximalRectangle(vector<vector<char> > &matrix) {
            if (matrix.empty() || matrix[0].empty())
            {
                return 0;
            }

            int M = matrix.size();
            int N = matrix[0].size();


            // heights[i][j] = possible height of the rectangle with left-bottom corner at (i,j)
            // 0 0 0 0 1           0 0 0 0 1
            // 0 1 1 0 0           0 1 1 0 0
            // 1 1 1 1 0    --->   1 2 2 1 0
            // 0 1 0 0 1           0 3 0 0 1
            // 0 1 1 1 0           0 4 1 1 0

            vector<vector<int> > heights(M, vector<int>(N,0));
            for (int j = 0; j < N; j++)
            {
                for (int i = 0; i < M; i++)
                {
                    if (matrix[i][j] == '1')
                    {
                        heights[i][j] = ((i == 0) ? 1 : (heights[i-1][j]+1));
                    }
                }
            }

            int maxarea = 0;
            for (int i = 0; i < M; i++)
            {
                int thisarea = maximalRectangleUnderHistorgram(heights[i]);
                maxarea = max(thisarea, maxarea);
            }
            return maxarea;
        }
};

int main()
{
    char row1[] = {'0', '0', '0', '0', '1'};
    char row2[] = {'0', '1', '1', '0', '0'};
    char row3[] = {'1', '1', '1', '1', '0'};
    char row4[] = {'0', '1', '0', '0', '1'};
    char row5[] = {'0', '1', '1', '1', '0'};

    vector<vector<char> > board(5);
    board[0].assign(row1, row1+5);
    board[1].assign(row2, row2+5);
    board[2].assign(row3, row3+5);
    board[3].assign(row4, row4+5);
    board[4].assign(row5, row5+5);

    Solution solu;
    cout << solu.maximalRectangle(board) << endl;

    return 0;
}
