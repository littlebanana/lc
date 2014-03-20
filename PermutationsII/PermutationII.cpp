// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
// For example,
// [1,1,2] have the following unique permutations:
// [1,1,2], [1,2,1], and [2,1,1]. 

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
    public:
        // Approach 1: use hash table
        void generateUnique(vector<int> &num, int left, vector<vector<int> > & perms)
        {
            int n = num.size();
            if (left == n)
            {
                perms.push_back(num);
                return;
            }

            unordered_set<int> tab;
            for (int i = left; i < n; i++)
            {
                auto it = tab.find(num[i]);
                if (it == tab.end())
                {
                    tab.insert(num[i]);
                    swap(num[left], num[i]);
                    generateUnique(num, left+1, perms);
                    swap(num[left], num[i]);
                }
            }
        }

        // Approach 2: sorting, notice can not pass by reference, after sorting, order messed up
        void generateUnique2(vector<int> num, int left, vector<vector<int> > &perms)
        {
            int n = num.size();
            if (left == n)
            {
                perms.push_back(num);
                return;
            }

            sort(num.begin()+left, num.end());
            for (int i = left; i < n; i++)
            {
                if (i > left && num[i] == num[i-1])
                {
                    continue;
                }

                swap(num[left], num[i]);
                generateUnique(num, left+1, perms);
                swap(num[left], num[i]);
            }
        }


        vector<vector<int> > permuteUnique(vector<int> &num) {
            if (num.empty())
            {
                return vector<vector<int> >();
            }
            vector<vector<int> > perms;
            generateUnique(num, 0, perms);
            return perms;
        }
};

int main()
{
    vector<int> num(3);
    num[0] = 1;
    num[1] = 1;
    num[2] = 2;

    Solution solu;
    vector<vector<int> > perms = solu.permuteUnique(num);

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
