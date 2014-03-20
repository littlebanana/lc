// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
// Follow up:
// Did you use extra space?
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void setZeroes(vector<vector<int> > &matrix) {
            if (matrix.empty() || matrix[0].empty())
            {
                return;
            }

            int m = matrix.size();
            int n = matrix[0].size();

            // mark
            bool row = false;
            for (int j = 0; j < n; j++)
            {
                if (matrix[0][j] == 0)
                {
                    row = true;
                    break;
                }
            }
            bool col = false;
            for (int i = 0; i < m; i++)
            {
                if (matrix[i][0] == 0)
                {
                    col = true;
                    break;
                }
            }
            for (int i = 1; i < m; i++)
            {
                for (int j = 1; j < n; j++)
                {
                    if (matrix[i][j] == 0)
                    {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }

            // replace
            for (int j = 1; j < n; j++)
            {
                if (matrix[0][j] == 0)
                {
                    for (int i = 1; i < m; i++)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
            for (int i = 1; i < m; i++)
            {
                if (matrix[i][0] == 0)
                {
                    for (int j = 1; j < n; j++)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
            if (row)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[0][j] = 0;
                }
            }
            if (col)
            {
                for (int i = 0; i < m; i++)
                {
                    matrix[i][0] = 0;
                }
            }
        }
};

void printMatrix(const vector<vector<int> > &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int> > matrix(4, vector<int>(4,0));
    matrix[0][1] = 1;
    matrix[0][2] = 1;
    matrix[0][3] = 1;
    matrix[1][0] = 1;
    matrix[1][1] = 1;
    matrix[1][2] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = 1;
    matrix[3][0] = 1;
    matrix[3][1] = 1;
    matrix[3][2] = 1;
    matrix[3][3] = 1;

    printMatrix(matrix);

    Solution solu;
    solu.setZeroes(matrix);

    printMatrix(matrix);

    return 0;
}
