// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
// Each number in C may only be used once in the combination.
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, бн , ak) must be in non-descending order. (ie, a1 <= a2 <= бн <= ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 10,1,2,7,6,1,5 and target 8,
// A solution set is:
// [1, 7]
// [1, 2, 5]
// [2, 6]
// [1, 1, 6] 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        void generate(const vector<int> &num, int target, int i, vector<int> set, vector<vector<int> > &combs)
        {
            if (target == 0)
            {
                combs.push_back(set);
            }
            else if (target > 0)
            {
                int n = num.size();
                for (int j = i; j < n; j++)
                {
                    // skip the duplicates
                    if (j > i && num[j] == num[j-1])
                    {
                        continue;
                    }
                    vector<int> tmp = set;
                    tmp.push_back(num[j]);
                    generate(num, target-num[j], j+1, tmp, combs);
                }
            }
        }

        vector<vector<int> > combinationSum2(vector<int> &num, int target) {
            vector<vector<int> > combs;
            vector<int> set;

            vector<int> sorted = num;
            sort(sorted.begin(), sorted.end());

            generate(sorted, target, 0, set, combs);

            return combs;
        }
};

int main()
{
    Solution solu;

    int candidates[] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> num(candidates, candidates+7);

    vector<vector<int> > combs = solu.combinationSum2(num, 8);

    for (int i = 0; i < combs.size(); i++)
    {
        for (int j = 0; j < combs[i].size(); j++)
        {
            cout << combs[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
