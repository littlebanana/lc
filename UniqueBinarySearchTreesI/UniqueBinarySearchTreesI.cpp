// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
// For example,
// Given n = 3, there are a total of 5 unique BST's.
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // Dynamic programming
        // num[i] = # of BST for i nodes
        // num[i] = sum_{j} ( num[j]*num[i-1-j] )
        
        int num[n+1];
        num[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            num[i] = 0;
            for (int j = 0; j < i; j++)    // # of nodes in the left subtree
            {
                num[i] += (num[j]*num[i-1-j]);
            }
        }
        return num[n];
    }
};

int main()
{
    Solution solu;
    cout << solu.numTrees(3) << endl;

    return 0;
}
