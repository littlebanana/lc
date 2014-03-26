// Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
// You have the following 3 operations permitted on a word:
// a) Insert a character
// b) Delete a character
// c) Replace a character

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int minDistance(string word1, string word2) {
            if (word1.empty())
            {
                return word2.length();
            }
            if (word2.empty())
            {
                return word1.length();
            }

            int l1 = word1.length();
            int l2 = word2.length();

            // Dynamic programming
            // step[i][j] = min ( step[i-1][j-1] + (word1[i]==word2[j] ? 0 : 1), step[i][j-1]+1, step[i-1][j]+1 )
            int step[l1+1][l2+1];
            for (int i = 0; i <= l1; i++)
            {
                for (int j = 0; j <= l2; j++)
                {
                    if (i == 0 && j == 0)
                    {
                        step[i][j] = 0;
                    }
                    else if (i == 0)
                    {
                        step[i][j] = j;
                    }
                    else if (j == 0)
                    {
                        step[i][j] = i;
                    }
                    else
                    {
                        step[i][j] = step[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1);
                        step[i][j] = min(step[i][j], step[i][j-1]+1);
                        step[i][j] = min(step[i][j], step[i-1][j]+1);
                    }
                }
            }
            return step[l1][l2];
        }
};

int main()
{
    string s1 = "abcde";
    string s2 = "abe";

    Solution solu;
    cout << solu.minDistance(s1, s2) << endl;

    return 0;
}
