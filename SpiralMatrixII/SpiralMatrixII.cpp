// Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
// For example, given n = 3,
// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int> > generateMatrix(int n) {
            int N = n*n;
            int top = 0;
            int bottom = n-1;
            int left = 0;
            int right = n-1;
            char direction = 0;
            vector<vector<int> > spiral(n, vector<int>(n));
            int i = 1;
            while (i <= N)
            {
                if (direction == 0)
                {
                    for (int j = left; j <= right; j++)
                    {
                        spiral[top][j] = i++;
                    }
                    top++;
                    direction = 1;
                }
                else if (direction == 1)
                {
                    for (int j = top; j <= bottom; j++)
                    {
                        spiral[j][right] = i++;
                    }
                    right--;
                    direction = 2;
                }
                else if (direction == 2)
                {
                    for (int j = right; j >= left; j--)
                    {
                        spiral[bottom][j] = i++;
                    }
                    bottom--;
                    direction = 3;
                }
                else
                {
                    for (int j = bottom; j >= top; j--)
                    {
                        spiral[j][left] = i++;
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
    Solution solu;
    vector<vector<int> > spiral = solu.generateMatrix(3);

    for (int i = 0; i < spiral.size(); i++)
    {
        for (int j = 0; j < spiral[i].size(); j++)
        {
            cout << spiral[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
