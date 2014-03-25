// Given a set of distinct integers, S, return all possible subsets.
// Note:
//     Elements in a subset must be in non-descending order.
//     The solution set must not contain duplicate subsets.
// For example,
// If S = [1,2,3], a solution is:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        // Approach 1: iterative growing
        // [] => [], [1] => [], [1], [2], [1,2] => [], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3]
        vector<vector<int> > subsets1(vector<int> &S) {
            int N = S.size();
            vector<int> sorted = S;
            sort(sorted.begin(), sorted.end());
            vector<int> empty;
            vector<vector<int> > sets;
            sets.push_back(empty);
            for (int i = 0; i < N; i++)
            {
                int n = sets.size();
                for (int j = 0; j < n; j++)
                {
                    vector<int> tmp = sets[j];
                    tmp.push_back(sorted[i]);
                    sets.push_back(tmp);
                }
            }
            return sets;
        }

        // Approach 2: recursive selection
        void chooseK(const vector<int> &S, int left, int k, vector<int> &subset, vector<vector<int> > &sets)
        {
            if (k == 0)
            {
                sets.push_back(subset);
                return;
            }

            int n = S.size();
            for (int i = left; i < n; i++)
            {
                vector<int> tmp = subset;
                tmp.push_back(S[i]);
                chooseK(S, i+1, k-1, tmp, sets);
            }
        }

        vector<vector<int> > subsets2(vector<int> &S) {
            vector<int> sorted = S;
            sort(sorted.begin(), sorted.end());
            vector<vector<int> > sets;
            int n = sorted.size();
            for (int k = 0; k <= n; k++)
            {
                vector<int> tmp;
                chooseK(sorted, 0, k, tmp, sets);
            }
            return sets;
        }

        // Approach 3: recursive generation
        void generate(const vector<int> &S, int left, vector<int> &subset, vector<vector<int> > &sets)
        {
            sets.push_back(subset);

            int n = S.size();
            for (int i = left; i < n; i++)
            {
                vector<int> tmp = subset;
                tmp.push_back(S[i]);
                generate(S, i+1, tmp, sets);
            }
        }

        vector<vector<int> > subsets3(vector<int> &S) {
            vector<int> sorted = S;
            sort(sorted.begin(), sorted.end());
            vector<vector<int> > sets;
            vector<int> empty;
            generate(sorted, 0, empty, sets);
            return sets;
        }
};

int main()
{
    vector<int> S(3);
    S[0] = 0;
    S[1] = 4;
    S[2] = 1;

    Solution solu;
    vector<vector<int> > sets = solu.subsets1(S);

    for (int i = 0; i < sets.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < sets[i].size(); j++)
        {
            cout << sets[i][j];
            if (j < sets[i].size()-1)
            {
                cout << " ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
