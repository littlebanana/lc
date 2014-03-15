// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.
// For example, given array S = {-1 2 1 -4}, and target = 1.
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
    public:
        int threeSumClosest(vector<int> &num, int target) {
            assert(num.size() >= 3);

            vector<int> sorted = num;
            sort(sorted.begin(), sorted.end());

            int diff = 0;
            int n = num.size();
            int opt = sorted[0] + sorted[1] + sorted[2];
            for (int i = 0; i < n; i++)
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
                    if (target == sum)
                    {
                        return target;
                    }
                    else
                    {
                        if (diff == 0 || abs(sum-target) < diff)
                        {
                            opt = sum;
                            diff = abs(sum-target);
                        }
                        if (target < sum)
                        {
                            q--;
                        }
                        else
                        {
                            p++;
                        }
                    }
                }
            }
            return opt;
        }
};

int main()
{
    int data[] = {-1, 2, 1, -4};
    vector<int> num;
    num.assign(data, data+2);

    Solution solu;
    cout << solu.threeSumClosest(num, 1) << endl;

    return 0;
}
