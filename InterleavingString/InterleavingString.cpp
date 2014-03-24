// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
// For example,
// Given: s1 = "aabcc", s2 = "dbbca",
// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false. 

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        // Time: O(l1*l2), Space: O(l1*l2);
        bool isInterleave1(string s1, string s2, string s3) {
            int l1 = s1.length();
            int l2 = s2.length();
            int l3 = s3.length();
            if (l1 + l2 != l3)
            {
                return false;
            }

            // Dynamic programming
            // tab[i][j] = whether s3[0...(i+j-1)] is formed by s1[0...(i-1)] and s2[0...(j-1)]
            // tab[i][j] = true if (tab[i-1][j] && s3[i+j-1] == s1[i-1]) || (tab[i][j-1] && s3[i+j-1] == s2[j-1])

            bool tab[l1+1][l2+1];
            tab[0][0] = true;
            for (int i = 1; i <= l1; i++)
            {
                tab[i][0] = (tab[i-1][0] && s1[i-1] == s3[i-1]);
            }
            for (int j = 1; j <= l2; j++)
            {
                tab[0][j] = (tab[0][j-1] && s2[j-1] == s3[j-1]);
            }
            for (int i = 1; i <= l1; i++)
            {
                for (int j = 1; j <= l2; j++)
                {
                    tab[i][j] = ((tab[i-1][j] && s1[i-1] == s3[i+j-1]) || (tab[i][j-1] && s2[j-1] == s3[i+j-1]));
                }
            }
            return tab[l1][l2];
        }

        // Time: O(l1*l2), Space O(min(l1,l2)), (in the following O(l2))
        bool isInterleave2(string s1, string s2, string s3) {
            int l1 = s1.length();
            int l2 = s2.length();
            int l3 = s3.length();
            if (l1 + l2 != l3)
            {
                return false;
            }

            // Dynamic programming 2
            // tab[i][j] = whether s3[0...(i+j-1)] is formed by s1[0...(i-1)] and s2[0...(j-1)]
            // tab[i][j] = true if (tab[i-1][j] && s3[i+j-1] == s1[i-1]) || (tab[i][j-1] && s3[i+j-1] == s2[j-1])

            bool tab[l2+1];     // tab[i]
            tab[0] = true;
            for (int j = 1; j <= l2; j++)   // tab[0][j]
            {
                tab[j] = (tab[j-1] && s2[j-1] == s3[j-1]);
            }
            for (int i = 1; i <= l1; i++)
            {
                for (int j = 0; j <= l2; j++)
                {
                    if (j == 0)
                    {
                        tab[j] = (tab[j] && s1[i-1] == s3[i+j-1]);
                    }
                    else
                    {
                        tab[j] = ((tab[j-1] && s2[j-1] == s3[i+j-1]) || (tab[j] && s1[i-1] == s3[i+j-1]));
                    }
                }
            }
            return tab[l2];
        }
};

int main()
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    string s4 = "aadbbbaccc";

    Solution solu;
    cout << "s1 = " << s1 << ", s2 = " << s2 << ", s3 = " << s3 << ", ";
    cout << (solu.isInterleave2(s1, s2, s3) ? "true" : "false")  << endl;
    cout << "s1 = " << s1 << ", s2 = " << s2 << ", s4 = " << s4 << ", ";
    cout << (solu.isInterleave2(s1, s2, s4) ? "true" : "false")  << endl;
    return 0;
    return 0;
}
