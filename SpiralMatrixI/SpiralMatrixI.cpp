// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
// For example, given the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5]. 


#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int> > &matrix) {
            if (matrix.empty() || matrix[0].empty())
            {
                return vector<int>();
            }

            int m = matrix.size();
            int n = matrix[0].size();
            int N = m*n;
            vector<int> spiral(N);
            int top = 0;
            int bottom = m-1;
            int left = 0;
            int right = n-1;
            char direction = 0;     // 0 = go right, 1 = go down, 2 = go left, 3 = go up
            int i = 0;
            while (i < N)
            {
                if (direction == 0)
                {
                    for (int j = left; j <= right; j++)
                    {
                        spiral[i++] = matrix[top][j];
                    }
                    top++;
                    direction = 1;
                }
                else if (direction == 1)
                {
                    for (int j = top; j <= bottom; j++)
                    {
                        spiral[i++] = matrix[j][right];
                    }
                    right--;
                    direction = 2;
                }
                else if (direction == 2)
                {
                    for (int j = right; j >= left; j--)
                    {
                        spiral[i++] = matrix[bottom][j];
                    }
                    bottom--;
                    direction = 3;
                }
                else
                {
                    for (int j = bottom; j >= top; j--)
                    {
                        spiral[i++] = matrix[j][left];
                    }
                    left++;
                    direction = 0;
                }
            }
            return spiral;
        }
};

int main()
{
    vector<vector<int> > matrix;
    vector<int> row(3);
    row[0] = 1;
    row[1] = 2;
    row[2] = 3;
    matrix.push_back(row);
    row[0] = 4;
    row[1] = 5;
    row[2] = 6;
    matrix.push_back(row);
    row[0] = 7;
    row[1] = 8;
    row[2] = 9;
    matrix.push_back(row);

    Solution solu;
    vector<int> spiral = solu.spiralOrder(matrix);

    for (int i = 0; i < spiral.size(); i++)
    {
        cout << spiral[i] << " ";
    }
    cout << endl;

    return 0;
}
