// Given a string S, find the longest palindromic substring in S.
// You may assume that the maximum length of S is 1000,
// and there exists one unique longest palindromic substring.

#include <iostream>

using namespace std;

class Solution
{
    public:
        // Approach 1: Dynamic Programming
        // O(N^2) space and complexity
        string longestPalindrome1(string s)
        {
            if (s.empty())
            {
                return "";
            }

            int L = s.length();

            // tab[i][j] = if s[i...j] is palindrome
            int start = 0;
            int len = 1;
            bool tab[L][L];
            for (int l = 1; l <= L; l++)
            {
                for (int i = 0; i < L-l+1; i++)
                {
                    int j = i + l - 1;
                    if (i == j)
                    {
                        tab[i][j] = true;
                    }
                    else if (j == i+1)
                    {
                        tab[i][j] = (s[i] == s[j]);
                    }
                    else
                    {
                        tab[i][j] = (s[i] == s[j] && tab[i+1][j-1]);
                    }
                    if (tab[i][j] && l > len)
                    {
                        len = l;
                        start = i;
                    }
                }
            }
            return s.substr(start, len);
        }

        // Approach 2: Scan N+(N-1) strings with different centers
        // O(1) space, O(N^2) complexity
        string longestPalindrome2(string s) 
        {
            int len = 0;
            int start = 0;
            int l = s.length();
            for (int i = 0; i < 2*l-1; i++)
            {
                int p = (i % 2 == 0 ? (i/2-1) : i/2);
                int q = i/2 + 1;
                while (p >= 0 && q < l && s[p] == s[q])
                {
                    p--;
                    q++;
                }
                if (len < q-p-1)
                {
                    start = p+1;
                    len = q-p-1;
                }
            }
            return s.substr(start,len);
        }

        // Approach 3: Manacher's algorithm
        // O(N) space and complexity
        // TODO
};

int main()
{
    Solution solu;

    string s("abccba");

    cout << solu.longestPalindrome1(s) << endl;
    cout << solu.longestPalindrome2(s) << endl;

    return 0;
}
