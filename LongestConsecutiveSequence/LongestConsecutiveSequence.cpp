// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4].
// Return its length: 4.
// Your algorithm should run in O(n) complexity. 

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        int longestConsecutive(vector<int> &num) {
            int n = num.size();

            unordered_set<int> tab;
            for (int i = 0; i < n; i++)
            {
                tab.insert(num[i]);
            }

            int len = 0;
            for (int i = 0; i < n; i++)
            {
                int l = 0;
                int v = num[i];
                auto it = tab.find(v);
                while (it != tab.end())
                {
                    l++;
                    tab.erase(it);
                    it = tab.find(--v);
                }
                v = num[i]+1;
                it = tab.find(v);
                while (it != tab.end())
                {
                    l++;
                    tab.erase(it);
                    it = tab.find(++v);
                }
                len = max(len, l);
            }
            return len;
        }
};

int main()
{
    int A[] = {-1, 4, 2, 0, 1};
    vector<int> num(A, A+5);

    Solution solu;
    cout << solu.longestConsecutive(num) << endl;

    return 0;
}
