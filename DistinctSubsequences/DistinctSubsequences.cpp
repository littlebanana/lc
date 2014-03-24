// Given a string S and a string T, count the number of distinct subsequences of T in S.
// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.
// (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
// Here is an example:
// S = "rabbbit", T = "rabbit"
// Return 3. 

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        // Time: O(Ls*Lt), Space: O(Ls*Lt)
        int numDistinct1(string S, string T) {
            if (T.empty())
            {
                return 1;
            }
            if (S.empty())
            {
                return 0;
            }

            // Dynamic programming 1
            // num[i][j] = # of distinct subsequences of T[0..j] in S[0...i]
            // num[i][j] += num[i-1][j-1] if S[i] == T[j]
            //           += num[i-1][j]

            int Ls = S.length();
            int Lt = T.length();
            int num[Ls][Lt];
            for (int i = 0; i < Ls; i++)
            {
                for (int j = 0; j < Lt; j++)
                {
                    if (i < j)
                    {
                        num[i][j] = 0;
                    }
                    else
                    {
                        num[i][j] = (i == 0 ? 0 : num[i-1][j]);
                        if (S[i] == T[j])
                        {
                            num[i][j] += (j == 0 ? 1 : num[i-1][j-1]);
                        }
                    }
                }
            }
            return num[Ls-1][Lt-1];
        }

        // Time: O(Ls*Lt), Space: O(Lt)
        int numDistinct2(string S, string T) {
            if (T.empty())
            {
                return 1;
            }
            if (S.empty())
            {
                return 0;
            }

            // Dynamic programming 2
            // num[i][j] = # of distinct subsequences of T[0..j] in S[0...i]
            // num[i][j]  = num[i-1][j]
            //           += num[i-1][j-1] if S[i] == T[j]

            // update squence (i,j):
            // (0,0) -> (1,1), (1,0) -> (2,2), (2,1), (2,0) -> (3,3), (3,2), (3,1), (3,0) -> ...

            int Ls = S.length();
            int Lt = T.length();
            int num[Lt];        // num[i-1]
            for (int j = 0; j < Lt; j++)
            {
                num[j] = 0;
            }
            for (int i = 0; i < Ls; i++)
            {
                for (int j = min(Lt-1, i); j >= 0; j--)
                {
                    if (S[i] == T[j])
                    {
                        num[j] += (j == 0 ? 1 : num[j-1]);
                    }
                }
            }
            return num[Lt-1];
        }
};

int main()
{
    string S = "rabbbit";
    string T = "rabbit";

    Solution solu;
    cout << solu.numDistinct2(S, T) << endl;

    return 0;
}
