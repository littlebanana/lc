// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
// For example,
// If n = 4 and k = 2, a solution is:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void select(int k, int left, int right, vector<int> &set, vector<vector<int> > &combs) {
            int l = set.size();
            if (l == k) {
                combs.push_back(set);
                return;
            }

            for (int i = left; i <= right; i++) {
                vector<int> tmp = set;
                tmp.push_back(i);
                select(k, i+1, right, tmp, combs);
            }
        }

        vector<vector<int> > combine(int n, int k) {
            vector<vector<int> > combs;
            vector<int> set;
            select(k, 1, n, set, combs);
            return combs;
        }

        void generate(const int n, int k, int start, vector<int> &curr, vector<vector<int> > &sets) {
            if (k == 0) {
                sets.push_back(curr);
            } else {
                for (int i = start; i <= n; i++) {
                    curr.push_back(i);
                    generate(n, k - 1, i + 1, curr, sets);
                    curr.pop_back();
                }
            }
        }

        vector<vector<int> > combine2(int n, int k) {
            vector<vector<int> > sets;
            vector<int> curr;
            generate(n, k, 1, curr, sets);
            return sets;
        }
};

int main() {
    Solution solu;
    vector<vector<int> > combs = solu.combine(4, 2);

    for (int i = 0; i < combs.size(); i++) {
        for (int j = 0; j < combs[i].size(); j++) {
            cout << combs[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
