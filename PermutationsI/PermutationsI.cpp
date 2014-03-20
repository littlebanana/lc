// Given a collection of numbers, return all possible permutations.
// For example,
// [1,2,3] have the following permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 

#include <iostream>
#include <vector>
#include <algorithm>    // swap

using namespace std;

class Solution {
    public:
        void generate(vector<int> &num, int left, vector<vector<int> > &perms)
        {
            int n = num.size();
            if (left > n-1)     // empty num set
            {
                return;
            }
            if (left == n-1)    // no other element to permute
            {
                perms.push_back(num);
                return;
            }

            // put every element after in turn at the begining, and recursively permute it
            for (int i = left; i < n; i++)
            {
                swap(num[left], num[i]);
                generate(num, left+1, perms);
                swap(num[left], num[i]);
            }
        }

        vector<vector<int> > permute(vector<int> &num) {
            vector<vector<int> > perms;
            generate(num, 0, perms);
            return perms;
        }
};

int main()
{
    vector<int> num(3);
    num[0] = 1;
    num[1] = 2;
    num[2] = 3;

    Solution solu;
    vector<vector<int> > perms = solu.permute(num);

    for (int i = 0; i < perms.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < perms[i].size(); j++)
        {
            cout << perms[i][j];
            if (j < perms[i].size()-1)
            {
                cout << " ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
