// Follow up for "Unique Paths":
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// The total number of unique paths is 2.
// Note: m and n will be at most 100.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();

            // num[i][j] = num[i-1][j] + num[i][j-1]
            int num[n];     // num[i]
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (obstacleGrid[i][j] == 1) {
                        num[j] = 0;
                        continue;
                    }

                    if (i == 0) {
                        num[j] = (j == 0 ? 1 : num[j-1]);
                    } else {
                        num[j] += (j == 0 ? 0 : num[j-1]);
                    }
                }
            }
            return num[n-1];
        }
};

int main() {
    vector<vector<int> > obstacleGrid;
    int r1[] = {0, 0, 0};
    obstacleGrid.push_back(vector<int>(r1,r1+3));
    int r2[] = {0, 1, 0};
    obstacleGrid.push_back(vector<int>(r2,r2+3));
    int r3[] = {0, 0, 0};
    obstacleGrid.push_back(vector<int>(r3,r3+3));

    Solution solu;
    cout << solu.uniquePathsWithObstacles(obstacleGrid);

    return 0;
}
