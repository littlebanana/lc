// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//   1. Integers in each row are sorted from left to right.
//   2. The first integer of each row is greater than the last integer of the previous row.
// For example,
// Consider the following matrix:
// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// Given target = 3, return true.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool binarySearch(const vector<int> &row, const int target, int left, int right)
        {
            if (left > right)
            {
                return false;
            }

            int mid = left + (right-left)/2;
            if (target == row[mid])
            {
                return true;
            }
            else if (target < row[mid])
            {
                return binarySearch(row, target, left, mid-1);
            }
            else
            {
                return binarySearch(row, target, mid+1, right);
            }
        }

        bool search(const vector<vector<int> > &matrix, const int target, int top, int bottom)
        {
            if (top > bottom)
            {
                return false;
            }

            int n = matrix[0].size();
            int mid = top + (bottom-top)/2;
            if (target < matrix[mid][0])
            {
                return search(matrix, target, top, mid-1);
            }
            else if (target > matrix[mid][n-1])
            {
                return search(matrix, target, mid+1, bottom);
            }
            else
            {
                return binarySearch(matrix[mid], target, 0, n-1);
            }
        }

        // Recursion
        bool searchMatrix1(vector<vector<int> > &matrix, int target) {
            return search(matrix, target, 0, matrix.size()-1);
        }

        // Iterative
        bool searchMatrix2(vector<vector<int> > &matrix, int target) {
            if (matrix.empty() || matrix[0].empty())
            {
                return false;
            }

            int m = matrix.size();
            int n = matrix[0].size();
            int top = 0;
            int bottom = m-1;
            while (top <= bottom)
            {
                int midr = top + (bottom-top)/2;
                if (target < matrix[midr][0])
                {
                    bottom = midr-1;
                }
                else if (target > matrix[midr][n-1])
                {
                    top = midr+1;
                }
                else
                {
                    int left = 0;
                    int right = n-1;
                    while (left <= right)
                    {
                        int midc = left + (right-left)/2;
                        if (target == matrix[midr][midc])
                        {
                            return true;
                        }
                        else if (target < matrix[midr][midc])
                        {
                            right = midc-1;
                        }
                        else
                        {
                            left = midc+1;
                        }
                    }
                    return false;
                }
            }
            return false;
        }
};

int main()
{
    vector<vector<int> > matrix;

    int r1[] = {1,   3,  5,  7};
    int r2[] = {10, 11, 16, 20};
    int r3[] = {23, 30, 34, 50};

    matrix.push_back(vector<int>(r1, r1+4));
    matrix.push_back(vector<int>(r2, r2+4));
    matrix.push_back(vector<int>(r3, r3+4));

    Solution solu;
    cout << (solu.searchMatrix1(matrix, 3) ? "true" : "false") << endl;

    return 0;
}
