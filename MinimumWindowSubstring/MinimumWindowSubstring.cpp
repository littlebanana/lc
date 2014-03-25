// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".
// Note:
// If there is no such window in S that covers all characters in T, return the emtpy string "".
// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 

#include <iostream>
#include <string>

using namespace std;

class Solution
{
    public:
        string minWindow(string S, string T)
        {
            int ls = S.length();
            int lt = T.length();

            int needToFind[256] = {0};
            int hasFound[256] = {0};
            for (int i = 0; i < lt; i++)
            {
                needToFind[T[i]]++;
            }

            int idx = 0;
            int start = 0;
            int len = 0;
            int count = 0;
            for (int i = 0; i < ls; i++)
            {
                // skip irrelavant characters
                if (needToFind[S[i]] == 0)
                {
                    continue;
                }

                // find one matched character
                if (hasFound[S[i]] < needToFind[S[i]])
                {
                    count++;
                }
                hasFound[S[i]]++;

                if (count == lt)
                {
                    // find one substring satisfies the constraint
                    // try to skrink it to produce narrrow substring
                    while (needToFind[S[start]] == 0 || hasFound[S[start]] > needToFind[S[start]])
                    {
                        if (hasFound[S[start]] > needToFind[S[start]])
                        {
                            hasFound[S[start]]--;
                        }
                        start++;
                    }

                    int thislen = i - start + 1;
                    if (len == 0 || thislen < len)
                    {
                        idx = start;
                        len = thislen;
                    }

                    hasFound[S[start]]--;
                    start++;
                    count--;
                }
            }
            return (len == 0 ? "" : S.substr(idx, len));
        }
};

int main()
{
    string S = "ab";
    string T = "b";

    Solution solu;
    cout << solu.minWindow(S, T) << endl;

    return 0;
}
