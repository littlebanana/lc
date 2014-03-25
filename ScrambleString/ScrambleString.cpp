// Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
// Below is one possible representation of s1 = "great":
//     great
//    /    \
//   gr    eat
//  / \    /  \
// g   r  e   at
//            / \
//           a   t
// To scramble the string, we may choose any non-leaf node and swap its two children.
// For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
//     rgeat
//    /    \
//   rg    eat
//  / \    /  \
// r   g  e   at
//            / \
//           a   t
// We say that "rgeat" is a scrambled string of "great".
// Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
//     rgtae
//    /    \
//   rg    tae
//  / \    /  \
// r   g  ta  e
//        / \
//       t   a
// We say that "rgtae" is a scrambled string of "great".
// Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1. 

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        // Approach 1: Recurrsion
        // trim the impossible cases at the beginning to speed up
        bool checkRecurrsion(string s1, string s2)
        {
            if (s1.compare(s2) == 0)
            {
                return true;
            }

            int l = s1.length();
            if (l == 1)
            {
                return false;
            }
            if (l == 2)
            {
                return (s1[0] == s2[1] && s1[1] == s2[0]);
            }

            string tmp1(s1);
            string tmp2(s2);
            sort(tmp1.begin(), tmp1.end());
            sort(tmp2.begin(), tmp2.end());
            if (tmp1.compare(tmp2) != 0)
            {
                return false;
            }

            for (int i = 1; i < l; i++)
            {
                if (checkRecurrsion(s1.substr(0,i), s2.substr(0,i)) && checkRecurrsion(s1.substr(i), s2.substr(i)))
                {
                    return true;
                }
                else if (checkRecurrsion(s1.substr(0,i), s2.substr(l-i)) && checkRecurrsion(s1.substr(i), s2.substr(0,l-i)))
                {
                    return true;
                }
            }
            return false;
        }

        bool checkDP(string s1, string s2)
        {
            int L = s1.length();

            // tab[l][i][j] = if s1[i...(i+l)] is a scramble of s2[j...(j+l)]
            bool tab[L][L][L];  // be aware of this compiler-dependent syntax

            for (int l = 0; l < L; l++)     // length of substring is l+1
            {
                for (int i = 0; i < L-l; i++)
                {
                    for (int j = 0; j < L-l; j++)
                    {
                        if (l == 0)
                        {
                            tab[l][i][j] = (s1[i] == s2[j]);
                        }
                        else
                        {
                            tab[l][i][j] = false;
                            for (int k = 1; k <= l; k++)    // partition
                            {
                                if (tab[k-1][i][j] && tab[l-k][i+k][j+k])
                                {
                                    tab[l][i][j] = true;
                                    break;
                                }
                                if (tab[k-1][i][j+(l+1-k)] && tab[l-k][i+k][j])
                                {
                                    tab[l][i][j] = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            return tab[L-1][0][0];
        }

        bool isScramble(string s1, string s2) {
            if (s1.empty() || s2.empty())
            {
                return false;
            }
            return checkDP(s1, s2);
        }
};

int main()
{
    string s1 = "abc";
    string s2 = "bca";

    Solution solu;
    cout << "s1 = " << s1 << ", s2 = " << s2 << endl;
    cout << (solu.isScramble(s1, s2) ? "true" : "false") << endl;

    return 0;
}
