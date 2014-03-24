// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int minPathSum(vector<vector<int> > &grid) {
            int m = grid.size();
            int n = grid[0].size();

            int sum[n];
            sum[0] = grid[0][0];
            for (int j = 1; j < n; j++)         // sum[i=0][j]
            {
                sum[j] = sum[j-1] + grid[0][j];
            }
            for (int i = 1; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (j == 0)
                    {
                        sum[j] += grid[i][j];
                    }
                    else
                    {
                        sum[j] = min(sum[j-1], sum[j]) + grid[i][j];
                    }
                }
            }
            return sum[n-1];
        }
};

int main()
{
    vector<vector<int> > grid;
    int r1[] = {1, 2, 3};
    grid.push_back(vector<int>(r1,r1+3));
    int r2[] = {4, 1, 3};
    grid.push_back(vector<int>(r2,r2+3));
    int r3[] = {2, 2, 8};
    grid.push_back(vector<int>(r3,r3+3));

    Solution solu;
    cout << solu.minPathSum(grid) << endl;

    return 0;
}
