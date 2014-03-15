// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
// Find all unique quadruplets in the array which gives the sum of target.
// Note:
//    Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a <= b <= c <= d)
//    The solution set must not contain duplicate quadruplets.
//    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
//    A solution set is:
//    (-1,  0, 0, 1)
//    (-2, -1, 1, 2)
//    (-2,  0, 0, 2)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            int n = num.size();
            if (n < 4)
            {
                return vector<vector<int> >();
            }

            vector<int> sorted = num;
            sort(sorted.begin(), sorted.end());

            vector<vector<int> > quad;
            for (int i = 0; i < n-3; i++)
            {
                if (i > 0 && sorted[i] == sorted[i-1])
                {
                    continue;
                }

                for (int j = i+1; j < n-2; j++)
                {
                    if (j > i+1 && sorted[j] == sorted[j-1])
                    {
                        continue;
                    }

                    int p = j+1;
                    int q = n-1;
                    while (p < q)
                    {
                        if (p > j+1 && sorted[p] == sorted[p-1])
                        {
                            p++;
                            continue;
                        }
                        if (q < n-1 && sorted[q] == sorted[q+1])
                        {
                            q--;
                            continue;
                        }

                        int sum = sorted[i] + sorted[j] + sorted[p] + sorted[q];
                        if (sum == target)
                        {
                            vector<int> tmp(4);
                            tmp[0] = sorted[i];
                            tmp[1] = sorted[j];
                            tmp[2] = sorted[p];
                            tmp[3] = sorted[q];
                            quad.push_back(tmp);
                            p++;
                            q--;
                        }
                        else if (sum < target)
                        {
                            p++;
                        }
                        else
                        {
                            q--;
                        }
                    }
                }
            }
            return quad;
        }
};

int main()
{
    int data[] = {1, 0, -1, 0, -2, 2};
    vector<int> num(data, data+sizeof(data)/sizeof(int));

    Solution solu;
    vector<vector<int> > quad = solu.fourSum(num, 0);

    for (int i = 0; i < quad.size(); i++)
    {
        for (int j = 0; j < quad[i].size(); j++)
        {
            cout << quad[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}
