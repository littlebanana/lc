// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return the minimum cuts needed for a palindrome partitioning of s.
// For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut. 

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int minCut(string s) {
            int l = s.length();

            bool tab[l][l];     // tab[i][j] = whether s[i...j] is a palindrome
            int cut[l];         // cut[i]    = min # of cut for s[i...(l-1)]
            for (int i = l-1; i >= 0; i--)
            {
                cut[i] = l-1-i;
                for (int j = i; j < l; j++)
                {
                    if (i == j)
                    {
                        tab[i][j] = true;
                    }
                    else if (i+1 == j)
                    {
                        tab[i][j] = (s[i] == s[j]);
                    }
                    else
                    {
                        tab[i][j] = (tab[i+1][j-1] && (s[i] == s[j]));
                    }

                    if (tab[i][j])
                    {
                        cut[i] = (j == l-1 ? 0 : min(cut[i], cut[j+1]+1));
                    }
                }
            }
            return cut[0];
        }
};

int main()
{
    string s = "aab";
    Solution solu;
    cout << solu.minCut(s) << endl;

    return 0;
}
