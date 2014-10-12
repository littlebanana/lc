// Given a collection of integers that might contain duplicates, S, return all possible subsets.
// Note:
//    Elements in a subset must be in non-descending order.
//    The solution set must not contain duplicate subsets.
// For example,
// If S = [1,2,2], a solution is:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
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
        vector<vector<int> > subsetsWithDup1(vector<int> &S) {
            vector<int> sorted = S;
            sort(sorted.begin(), sorted.end());
            vector<int> empty;
            vector<vector<int> > sets;
            sets.push_back(empty);
            int N = S.size();
            int idx = 0;      // start index to intersect
            for (int i = 0; i < N; i++) {
                int n = sets.size();
                idx = (i > 0 && sorted[i] == sorted[i-1]) ? idx : 0;
                for (int j = idx; j < n; j++) {
                    vector<int> tmp = sets[j];
                    tmp.push_back(sorted[i]);
                    sets.push_back(tmp);
                }
                idx = n;
            }
            return sets;
        }

        void generate(const vector<int> &S, int left, vector<int> &subset, vector<vector<int> > &sets) {
            sets.push_back(subset);

            int n = S.size();
            for (int i = left; i < n; i++) {
                // only allow head to intersect with the same element
                if (i > left && S[i] == S[i-1]) {
                    continue;
                }
                vector<int> tmp = subset;
                tmp.push_back(S[i]);
                generate(S, i+1, tmp, sets);
            }
        }

        // Approach 2: recursive generate
        vector<vector<int> > subsetsWithDup2(vector<int> &S) {
            vector<int> sorted = S;
            sort(sorted.begin(), sorted.end());
            vector<vector<int> > sets;
            vector<int> empty;
            generate(sorted, 0, empty, sets);
            return sets;
        }
};

int main() {
    vector<int> S(3);
    S[0] = 1;
    S[1] = 2;
    S[2] = 2;
    Solution solu;

    vector<vector<int> > sets = solu.subsetsWithDup1(S);

    for (int i = 0; i < sets.size(); i++) {
        cout << "[";
        for (int j = 0; j < sets[i].size(); j++) {
            cout << sets[i][j];
            if (j < sets[i].size()-1) {
                cout << " ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
