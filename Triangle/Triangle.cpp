// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
// For example, given the following triangle
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
// Note:
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int minimumTotal(vector<vector<int> > &triangle) {
            if (triangle.empty())
            {
                return 0;
            }

            int n = triangle.size();
            vector<int> tab(n,0);
            tab[0] = triangle[0][0];
            for (int i = 1; i < n; i++)
            {
                // be careful about the order of assignment in avoid value mess up
                tab[i] = tab[i-1] + triangle[i][i];
                for (int j = i-1; j >= 1; j--)
                {
                    tab[j] = min(tab[j], tab[j-1]) + triangle[i][j];
                }
                tab[0] += triangle[i][0];
            }
            int minSum = tab[0];
            for (int i = 1; i < n; i++)
            {
                minSum = min(minSum, tab[i]);
            }
            return minSum;
        }
};

int main()
{
    vector<vector<int> > triangles;
    vector<int> level1(1, 2);
    triangles.push_back(level1);
    int l2[] = {3, 4};
    vector<int> level2(l2, l2+2);
    triangles.push_back(level2);
    int l3[] = {6, 5, 7};
    vector<int> level3(l3, l3+2);
    triangles.push_back(level3);
    int l4[] = {4, 1, 8, 3};
    vector<int> level4(l4, l4+2);
    triangles.push_back(level4);

    Solution solu;
    cout << solu.minimumTotal(triangles) << endl;

    return 0;
}
