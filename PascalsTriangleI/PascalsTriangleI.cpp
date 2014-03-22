// Given numRows, generate the first numRows of Pascal's triangle.
// For example, given numRows = 5,
// Return
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int> > generate(int numRows) {
            if (numRows < 1)
            {
                return vector<vector<int> >();
            }

            vector<vector<int> > triangles;
            triangles.push_back(vector<int>(1,1));
            for (int i = 2; i <= numRows; i++)
            {
                vector<int> level(i,1);
                for (int j = 1; j < i-1; j++)
                {
                    level[j] = triangles.back()[j-1]+triangles.back()[j];
                }
                triangles.push_back(level);
            }
            return triangles;
        }
};

int main()
{
    Solution solu;

    int n = 3;
    cout << "n = " << n << endl;

    vector<vector<int> > triangles = solu.generate(n);

    for (int i = 0; i < triangles.size(); i++)
    {
        for (int j = 0; j < triangles[i].size(); j++)
        {
            cout << triangles[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
