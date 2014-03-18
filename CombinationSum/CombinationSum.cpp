//  Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
// The same repeated number may be chosen from C unlimited number of times.
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, бн , ak) must be in non-descending order. (ie, a1 <= a2 <= бн <= ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2,3,6,7 and target 7,
// A solution set is:
// [7]
// [2, 2, 3] 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        void generate1(const vector<int> &candidates, int target, int i, vector<int> set, vector<vector<int> > &combs)
        {
            int n = candidates.size();
            if (target == 0)
            {
                combs.push_back(set);
            }
            else if (target > 0 && i < n)
            {
                int num = candidates[i];
                // not include current item
                generate(candidates, target, i+1, set, combs);
                // include one or more current item
                while (target > 0)
                {
                    set.push_back(num);
                    target -= num;
                    generate(candidates, target, i+1, set, combs);
                }
            }
        }

        void generate2(const vector<int> &candidates, int target, int i, vector<int> set, vector<vector<int> > &combs)
        {
            if (target == 0)
            {
                combs.push_back(set);
            }
            else if (target > 0)
            {
                int n = candidates.size();
                for (int j = i; j < n; j++)
                {
                    vector<int> tmp = set;
                    tmp.push_back(candidates[j]);
                    generate(candidates, target-candidates[j], j, tmp, combs);  // take care of the multiple items with the same value
                }
            }
        }

        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            vector<vector<int> > combs;
            vector<int> set;

            vector<int> sorted = candidates;
            sort(sorted.begin(), sorted.end());

            generate1(sorted, target, 0, set, combs);

            return combs;
        }
};

int main()
{
    vector<int> candidates(1,1);

    Solution solu;
    vector<vector<int> > result = solu.combinationSum(candidates, 1);

    return 0;
}
