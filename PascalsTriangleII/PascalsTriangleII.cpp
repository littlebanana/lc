// Given an index k, return the kth row of the Pascal's triangle.
// For example, given k = 3,
// Return [1,3,3,1].
// Note:
// Could you optimize your algorithm to use only O(k) extra space? 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> level(rowIndex+1, 1);
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = i-1; j >= 1; j--) {
                level[j] = level[j] + level[j-1];
            }
        }
        return level;
    }
};

int main()
{
    int n = 3;
    cout << "n = " << n << endl;

    Solution solu;
    vector<int> level = solu.getRow(n);

    for (int i = 0; i < level.size(); i++) {
        cout << level[i] << " ";
    }
    cout << endl;

    return 0;
}
