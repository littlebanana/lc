// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.
// Note:
//    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a <= b <= c)
//    The solution set must not contain duplicate triplets.
//     For example, given array S = {-1 0 1 2 -1 -4},
//     A solution set is:
//     (-1, 0, 1)
//     (-1, -1, 2)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            if (num.size() < 3)
            {
                return vector<vector<int> > ();
            }

            vector<int> sorted = num;
            sort(sorted.begin(), sorted.end());

            vector<vector<int> > tri;
            int n = sorted.size();
            for (int i = 0; i < n-2; i++)
            {
                if (i > 0 && sorted[i] == sorted[i-1])
                {
                    continue;
                }

                int p = i+1;
                int q = n-1;
                while (p < q)
                {
                    if (p > i+1 && sorted[p] == sorted[p-1])
                    {
                        p++;
                        continue;
                    }
                    if (q < n-1 && sorted[q] == sorted[q+1])
                    {
                        q--;
                        continue;
                    }

                    int sum = sorted[i] + sorted[p] + sorted[q];
                    if (sum == 0)
                    {
                        vector<int> tmp(3);
                        tmp[0] = sorted[i];
                        tmp[1] = sorted[p];
                        tmp[2] = sorted[q];
                        tri.push_back(tmp);
                        p++;
                        q--;
                    }
                    else if (sum > 0)
                    {
                        q--;
                    }
                    else
                    {
                        p++;
                    }
                }
            }
            return tri;
        }
};

int main()
{
    int data[] = {-1, 0, 1, 2, -1, -4};
    vector<int> num;
    num.assign(data, data+6);

    Solution solu;
    vector<vector<int> > tri = solu.threeSum(num);

    for (int i = 0; i < tri.size(); i++)
    {
        for (int j = 0; j < tri[i].size(); j++)
        {
            cout << tri[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
